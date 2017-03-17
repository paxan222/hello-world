#include "CutOperation.h"
/*-----------------Public----------------------------------------*/

//Constructor
CCutOperation::CCutOperation(PCHAR inputFilename, PCHAR outputFilename, int startTimeMilliseconds, int endTimeMilliseconds,
	FProgressCallback fProgressCallback, FEndOfOperationCallback fEofCallback, FErrorCallback fErrorCallback) :CBaseOperation()
{
	m_firstInputFilename = inputFilename;
	m_outputFilename = outputFilename;
	std::thread([=]{
		if (Init(const_cast<PCHAR>(m_firstInputFilename.c_str()), const_cast<PCHAR>(m_outputFilename.c_str()), startTimeMilliseconds, endTimeMilliseconds)){
			AVPacket packet;
			AVStream *outVideoStream = m_outputFmtCtx->streams[m_outputVideoStreamIndex];
			AVStream *outAudioStream = m_outputFmtCtx->streams[m_outputAudioStreamIndex];
			int64_t currentPts = 0;

			av_init_packet(&packet);
			while (!av_read_frame(m_inputFmtCtx, &packet) && !m_cancel){
				//Check packet stream index
				if (packet.stream_index == m_inputVideoStream->index){
					RecalculateTimeStamps(&packet, m_inputVideoStream->time_base, outVideoStream->time_base);
					packet.stream_index = m_outputVideoStreamIndex;
					currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(outVideoStream->time_base);
					if (currentPts >= startTimeMilliseconds && currentPts <= endTimeMilliseconds){
						packet.pts -= startTimeMilliseconds / (CONVERT_TIME_TO_MS * av_q2d(outVideoStream->time_base));
						packet.dts = packet.pts;
						av_write_frame(m_outputFmtCtx, &packet);
						if (fProgressCallback)
							std::thread([=]{fProgressCallback(endTimeMilliseconds - startTimeMilliseconds, currentPts - startTimeMilliseconds); }).detach();
					}
				}
				else
				{
					if (m_inputAudioStream != nullptr){
						if (packet.stream_index == m_inputAudioStream->index)
						{
							RecalculateTimeStamps(&packet, m_inputAudioStream->time_base, outAudioStream->time_base);
							packet.stream_index = m_outputAudioStreamIndex;
							currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(outAudioStream->time_base);
							//Write the packet that meets all requirements
							if (currentPts >= startTimeMilliseconds && currentPts <= endTimeMilliseconds){
								packet.pts -= startTimeMilliseconds / (CONVERT_TIME_TO_MS * av_q2d(outAudioStream->time_base));
								packet.dts = packet.pts;
								av_write_frame(m_outputFmtCtx, &packet);
								if (fProgressCallback)
									std::thread([=]{fProgressCallback(endTimeMilliseconds - startTimeMilliseconds, currentPts - startTimeMilliseconds); }).detach();
							}
						}
					}
				}
				//Free packet
				av_free_packet(&packet);
				av_init_packet(&packet);
				//If pts bigger than endCutTime free packet and quit cycle
				if (currentPts > endTimeMilliseconds){
					break;
				}
			}
			//Free packet
			av_free_packet(&packet);
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
CCutOperation::~CCutOperation()
{
}

/*-----------------Private---------------------------------------*/

// Open input file => Fill input streams => Check time conditions => Open output file
BOOL CCutOperation::Init(PCHAR inputFilename, PCHAR outputFilename, int startTimeMilliseconds, int endTimeMilliseconds){
	if (inputFilename == "" || outputFilename == ""){
		m_errorCode = ErrorCode::EmptyFilename;
		return FALSE;
	}
	av_register_all();

	// If we couldn't open input file - exit
	if (!OpenInputFile(m_inputFmtCtx, inputFilename))
		return FALSE;

	// Find input video stream, if there is no stream than callback and exit
	auto videoStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (videoStreamIndex >= 0)
		m_inputVideoStream = m_inputFmtCtx->streams[videoStreamIndex];
	else{
		m_errorCode = ErrorCode::VideoStreamNotExist;
		return FALSE;
	}
	// Find input audio stream, if threre is no stream than work only with video
	auto audioStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (audioStreamIndex >= 0)
		m_inputAudioStream = m_inputFmtCtx->streams[audioStreamIndex];

	if (!CheckTimeConditions(inputFilename, startTimeMilliseconds, &endTimeMilliseconds)){
		m_errorCode = ErrorCode::ArgumentOutOfRange;
		return FALSE;
	}

	// If we couldnt open output file - exit
	if (!OpenOutputFile(outputFilename)){
		//Error code is setting up in OpenOutputFile function
		return FALSE;
	}

	return TRUE;
}

//Create output streams
void CCutOperation::CreateOutputStreams(AVFormatContext *outputFmtCtx){
	m_outputVideoStreamIndex = CreateStream(outputFmtCtx->oformat->video_codec, m_inputVideoStream);
	//Create Audio stream if we have input audio stream
	if (m_inputAudioStream != nullptr){
		m_outputAudioStreamIndex = CreateStream(outputFmtCtx->oformat->audio_codec, m_inputAudioStream);
	}
}

// Calculate duration and deltaPts => Check start and end time is bigger than 0, less than duration and different between it is bigger than deltaPts
BOOL CCutOperation::CheckTimeConditions(PCHAR inputFilename ,int startTime, int *endTime){
	auto duration = GetFileDuration(inputFilename);
	//auto duration = m_inputFmtCtx->duration * CONVERT_TIME_TO_MS / AV_TIME_BASE;
	auto deltaPts = (m_inputVideoStream->time_base.den * m_inputVideoStream->r_frame_rate.den) / (m_inputVideoStream->time_base.num * m_inputVideoStream->r_frame_rate.num);
	if (*endTime > duration)
		*endTime = duration;
	if (startTime < 0 || startTime > duration || *endTime < 0  || startTime > *endTime - deltaPts)
	{
		return FALSE;
	}
	return TRUE;
}
