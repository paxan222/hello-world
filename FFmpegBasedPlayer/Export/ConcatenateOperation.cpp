#include "ConcatenateOperation.h"

/*-----------------Public----------------------------------------*/

//Constructor
CConcatenateOperation::CConcatenateOperation(PCHAR firstInputFilename, PCHAR secondInputFilename, PCHAR outputFilename,
	FProgressCallback fProgressCallback, FEndOfOperationCallback fEofCallback, FErrorCallback fErrorCallback) :CBaseOperation()
{
	std::thread([=]{
		if (Init(firstInputFilename, secondInputFilename, outputFilename)){
			AVPacket packet;
			auto videoIndex = m_inputVideoStream->index;
			auto audioIndex = m_inputAudioStream->index;
			auto videoIndex2 = m_secondInputVideoStream->index;
			auto audioIndex2 = m_secondInputAudioStream->index;
			AVStream *outVideoStream = m_outputFmtCtx->streams[m_outputVideoStreamIndex];
			AVStream *outAudioStream = m_outputFmtCtx->streams[m_outputAudioStreamIndex];
			int64_t lastPts = 0; // last pts for first input file
			int64_t currentPts = 0;
			auto outputFileDuration = m_inputFmtCtx->duration + m_secondInputFmtCtx->duration; // duration of result output file

			while (!m_cancel){
				av_init_packet(&packet);
				//read First
				while (!av_read_frame(m_inputFmtCtx, &packet)){
					if (packet.stream_index == videoIndex)
					{
						//Recalculate pts, dts and duration
						RecalculateTimeStamps(&packet, m_inputVideoStream->time_base, outVideoStream->time_base);
						packet.stream_index = outVideoStream->index;
						currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(outVideoStream->time_base);
						//Write the packet
						lastPts = packet.pts;
						av_write_frame(m_outputFmtCtx, &packet);
					}
					if (m_inputAudioStream != nullptr){
						if (packet.stream_index == audioIndex)
						{
							RecalculateTimeStamps(&packet, m_inputAudioStream->time_base, outAudioStream->time_base);
							packet.stream_index = outAudioStream->index;
							currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(outAudioStream->time_base);
							//Write the packet
							lastPts = packet.pts;
							av_write_frame(m_outputFmtCtx, &packet);
						}
					}
					if (fProgressCallback)
						std::thread([=]{fProgressCallback(outputFileDuration, currentPts); }).detach();
					//Free packet
					av_free_packet(&packet);
					av_init_packet(&packet);
				}
				while (!av_read_frame(m_secondInputFmtCtx, &packet)){
					//Recalculate pts, dts and duration		
					if (packet.stream_index == videoIndex2)
					{
						RecalculateTimeStamps(&packet, m_secondInputVideoStream->time_base, outVideoStream->time_base, lastPts);
						packet.stream_index = outVideoStream->index;
						currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(outVideoStream->time_base);
						//Write the packet
						av_write_frame(m_outputFmtCtx, &packet);
					}
					if (m_inputAudioStream != nullptr){
						if (packet.stream_index == audioIndex2)
						{
							RecalculateTimeStamps(&packet, m_secondInputAudioStream->time_base, outAudioStream->time_base, lastPts);
							packet.stream_index = outAudioStream->index;
							currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(outAudioStream->time_base);
							//Write the packet
							av_write_frame(m_outputFmtCtx, &packet);
						}
					}
					if (fProgressCallback)
						std::thread([=]{fProgressCallback(outputFileDuration, currentPts); }).detach();
					//Free packet
					av_free_packet(&packet);
					av_init_packet(&packet);
				}
				av_free_packet(&packet);
				break;
			}
			//Write trailer of outputFile and close input and output
			av_write_trailer(m_outputFmtCtx);
			avio_close(m_outputFmtCtx->pb);
		}
		//If Init return FALSE
		else{
			if (fErrorCallback != nullptr)
				std::thread([=]{ fErrorCallback(m_errorCode); }).detach();
		}
		delete this;
		if (fEofCallback)
			std::thread([=]{fEofCallback(); }).detach();
	}).detach();
}

//Destructor
CConcatenateOperation::~CConcatenateOperation()
{
	avformat_close_input(&m_secondInputFmtCtx);
}

/*-----------------Private---------------------------------------*/

//Open input files -> Fill input streams => Open output file
BOOL CConcatenateOperation::Init(PCHAR firstInputFilename, PCHAR secondInputFilename, PCHAR outputFilename){
	if (firstInputFilename == "" || secondInputFilename == "" || outputFilename == ""){
		m_errorCode = ErrorCode::EmptyFilename;
		return FALSE;
	}
	av_register_all();

	/*First input file*/
	if (!OpenInputFile(m_inputFmtCtx, firstInputFilename))
		return FALSE;
	// Find input video stream, if there is no stream than callback and exit
	auto streamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_inputVideoStream = m_inputFmtCtx->streams[streamIndex];
	else{
		m_errorCode = ErrorCode::VideoStreamNotExist;
		return FALSE;
	}
	// Find input audio stream, if threre is no stream than work only with video
	streamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_inputAudioStream = m_inputFmtCtx->streams[streamIndex];

	/*Second input file*/
	if (!OpenInputFile(m_secondInputFmtCtx, secondInputFilename))
		return FALSE;
	// Find input video stream, if there is no stream than callback and exit
	streamIndex = av_find_best_stream(m_secondInputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_secondInputVideoStream = m_secondInputFmtCtx->streams[streamIndex];
	else{
		m_errorCode = ErrorCode::VideoStreamNotExist;
		return FALSE;
	}
	// Find input audio stream, if threre is no stream than work only with video
	streamIndex = av_find_best_stream(m_secondInputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_secondInputAudioStream = m_secondInputFmtCtx->streams[streamIndex];

	// If we couldnt open output file - exit
	if (!OpenOutputFile(outputFilename)){
		//Error code is setting up in OpenOutputFile function
		return FALSE;
	}

	return TRUE;
}

//CreateOutputStreams
void CConcatenateOperation::CreateOutputStreams(AVFormatContext *outputFmtCtx){
	m_outputVideoStreamIndex = CreateStream(outputFmtCtx->oformat->video_codec, m_inputVideoStream);
	//Create Audio stream if we have input audio stream
	if (m_inputAudioStream != nullptr){
		m_outputAudioStreamIndex = CreateStream(outputFmtCtx->oformat->audio_codec, m_inputAudioStream);
	}
	else
	{
		if (m_secondInputAudioStream != nullptr){
			m_outputAudioStreamIndex = CreateStream(outputFmtCtx->oformat->audio_codec, m_secondInputAudioStream);
		}
	}
}