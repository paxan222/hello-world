#include "stdafx.h"
#include "ConcatenateOperation.h"

/*-----------------Public----------------------------------------*/

//Constructor
CConcatenateOperation::CConcatenateOperation(PCHAR firstInputFilename, PCHAR secondInputFilename, PCHAR outputFilename
	/*, FProgressCallback fProgressCallback = nullptr,
	FEndOfOperationCallback fEofCallback = nullptr,
	FErrorCallback fErrorCallback = nullptr*/) :CBaseOperation()
{
	std::thread([=]{
		Init(firstInputFilename, secondInputFilename, outputFilename);
		AVPacket packet;
		auto videoIndex = m_inputVideoStream->index;
		auto audioIndex = m_inputAudioStream->index;
		AVStream *outVideoStream = m_outputFmtCtx->streams[m_outputVideoStreamIndex];
		AVStream *outAudioStream = m_outputFmtCtx->streams[m_outputAudioStreamIndex];
		int64_t lastPts = 0; // last pts for first input file
		auto outputFileDuration = m_inputFmtCtx->duration + m_secondInputFmtCtx->duration; // duration of result output file
		
		while (!m_cancel){
			av_init_packet(&packet);
			//read First
			while (!av_read_frame(m_inputFmtCtx, &packet)){
				//Init packet
				//Recalculate pts, dts and duration
				if (packet.stream_index == m_videoStreamIndex)
				{
					RecalculateTimeStamps(&packet, m_inputVideoStream->time_base, m_outputVideoStream->time_base);
					packet.stream_index = m_outputVideoStream->index;
					m_currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputVideoStream->time_base);
					//Write the packet
					lastPts = packet.pts;
					av_interleaved_write_frame(m_outputFmtCtx, &packet);
				}
				if (packet.stream_index == m_audioStreamIndex)
				{
					RecalculateTimeStamps(&packet, m_inputAudioStream->time_base, m_outputAudioStream->time_base);
					packet.stream_index = m_outputAudioStream->index;
					m_currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputAudioStream->time_base);
					//Write the packet
					lastPts = packet.pts;
					av_interleaved_write_frame(m_outputFmtCtx, &packet);
				}
				/*if (m_fProgCb)
				std::thread([this]{m_fProgCb(m_outputFileDuration, m_currentPts); }).detach();*/
				//Free packet
				av_free_packet(&packet);
				av_init_packet(&packet);
			}
			while (!av_read_frame(m_inputFmtCtx2, &packet)){
				//Init packet
				//Recalculate pts, dts and duration		
				if (packet.stream_index == m_videoStreamIndex2)
				{
					RecalculateTimeStamps(&packet, m_inputVideoStream2->time_base, m_outputVideoStream->time_base, lastPts);
					packet.stream_index = m_outputVideoStream->index;
					m_currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputVideoStream->time_base);
					//Write the packet
					av_interleaved_write_frame(m_outputFmtCtx, &packet);
				}

				if (packet.stream_index == m_audioStreamIndex2)
				{
					RecalculateTimeStamps(&packet, m_inputAudioStream2->time_base, m_outputAudioStream->time_base, lastPts);
					packet.stream_index = m_outputAudioStream->index;
					m_currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputAudioStream->time_base);
					//Write the packet
					av_interleaved_write_frame(m_outputFmtCtx, &packet);
				}
				/*if (m_fProgCb)
				std::thread([this]{m_fProgCb(m_outputFileDuration, m_currentPts); }).detach();*/
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
		delete this;
		/*if (m_fEofCb)
		std::thread([this]{m_fEofCb(); }).detach();*/
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
	if (firstInputFilename == "" || secondInputFilename =="" || outputFilename == "")
		//if (m_fErrCb){
		//	std::thread([this]{
		//		ERROR_INFO ei;
		//		ei.errorCode = ErrorCode::EC_OPENINPUT;
		//		ei.message = ErrorMessage(ei.errorCode);
		//		m_fErrCb(ei); }).detach();
		//}
		return FALSE;
	av_register_all();

	/*First input file*/
	if (!OpenInputFile(&m_inputFmtCtx, firstInputFilename))
		return FALSE;
	// Find input video stream, if there is no stream than callback and exit
	auto streamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_inputVideoStream = m_inputFmtCtx->streams[streamIndex];
	else{
		//if (m_fErrCb){
		//	std::thread([this]{
		//		ERROR_INFO ei;
		//		ei.errorCode = ErrorCode::EC_OPENINPUT;
		//		ei.message = ErrorMessage(ei.errorCode);
		//		m_fErrCb(ei); }).detach();
		//}
		return FALSE;
	}
	// Find input audio stream, if threre is no stream than work only with video
	streamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_inputAudioStream = m_inputFmtCtx->streams[streamIndex];

	/*Second input file*/
	if (!OpenInputFile(&m_secondInputFmtCtx, secondInputFilename))
		return FALSE;
	// Find input video stream, if there is no stream than callback and exit
	streamIndex = av_find_best_stream(m_secondInputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_secondInputVideoStream = m_secondInputFmtCtx->streams[streamIndex];
	else{
		//if (m_fErrCb){
		//	std::thread([this]{
		//		ERROR_INFO ei;
		//		ei.errorCode = ErrorCode::EC_OPENINPUT;
		//		ei.message = ErrorMessage(ei.errorCode);
		//		m_fErrCb(ei); }).detach();
		//}
		return FALSE;
	}
	// Find input audio stream, if threre is no stream than work only with video
	streamIndex = av_find_best_stream(m_secondInputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_secondInputAudioStream = m_secondInputFmtCtx->streams[streamIndex];

	// If we couldnt open output file - exit
	if (!OpenOutputFile(outputFilename)){
		return FALSE;
	}

	return TRUE;
}

void CConcatenateOperation::CreateOutputStream(){
	auto codec = avcodec_find_encoder(m_outputFmtCtx->oformat->video_codec);
	auto outVideoStream = avformat_new_stream(m_outputFmtCtx, codec);
	avcodec_copy_context(outVideoStream->codec, m_inputVideoStream->codec);
	m_outputVideoStreamIndex = outVideoStream->index;
	//Create Audio stream if we have input audio stream
	if (m_inputAudioStream != nullptr){
		codec = avcodec_find_encoder(m_outputFmtCtx->oformat->audio_codec);
		auto outAudioStream = avformat_new_stream(m_outputFmtCtx, codec);
		avcodec_copy_context(outAudioStream->codec, m_inputAudioStream->codec);
		m_outputAudioStreamIndex = outAudioStream->index;
	}
	else{
		if (m_secondInputAudioStream != nullptr){
			codec = avcodec_find_encoder(m_outputFmtCtx->oformat->audio_codec);
			auto outAudioStream = avformat_new_stream(m_outputFmtCtx, codec);
			avcodec_copy_context(outAudioStream->codec, m_secondInputAudioStream->codec);
			m_outputAudioStreamIndex = outAudioStream->index;
		}
	}
}