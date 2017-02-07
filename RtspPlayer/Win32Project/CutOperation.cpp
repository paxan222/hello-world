#include "stdafx.h"
#include "CutOperation.h"
/*-----------------Public----------------------------------------*/

//Constructor
CCutOperation::CCutOperation(PCHAR inputFilename, PCHAR outputFilename,
	int startTimeMilliseconds, int endTimeMilliseconds
	/*,FProgressCallback fProgressCallback = nullptr,
	FEndOfOperationCallback fEofCallback = nullptr,
	FErrorCallback fErrorCallback = nullptr*/) :CBaseOperation()
{
	std::thread([=]{
		if (Init(inputFilename, outputFilename, startTimeMilliseconds, endTimeMilliseconds)){
			AVPacket packet;
			auto videoIndex = m_inputVideoStream->index;
			auto audioIndex = m_inputAudioStream->index;
			AVStream *outVideoStream = m_outputFmtCtx->streams[m_outputVideoStreamIndex];
			AVStream *outAudioStream = m_outputFmtCtx->streams[m_outputAudioStreamIndex];
			int currentPts = 0;

			av_init_packet(&packet);
			while (!av_read_frame(m_inputFmtCtx, &packet) && !m_cancel){
				//Check packet stream index
				if (packet.stream_index == videoIndex){
					RecalculateTimeStamps(&packet, m_inputVideoStream->time_base, outVideoStream->time_base);
					packet.stream_index = m_outputVideoStreamIndex;
					currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(outVideoStream->time_base);
					if (currentPts >= startTimeMilliseconds && currentPts <= endTimeMilliseconds){
						packet.pts -= startTimeMilliseconds / (CONVERT_TIME_TO_MS * av_q2d(outVideoStream->time_base));
						packet.dts = packet.pts;
						av_interleaved_write_frame(m_outputFmtCtx, &packet);
						//if (fProgressCallback)
						//	std::thread([this]{fProgressCallback(endTimeMilliseconds - startTimeMilliseconds, currentPts - startTimeMilliseconds); }).detach();
					}
				}
				else
				{
					if (packet.stream_index == audioIndex)
					{
						RecalculateTimeStamps(&packet, m_inputAudioStream->time_base, outAudioStream->time_base);
						packet.stream_index = m_outputAudioStreamIndex;
						currentPts = packet.pts * CONVERT_TIME_TO_MS * av_q2d(outAudioStream->time_base);
						//Write the packet that meets all requirements
						if (currentPts >= startTimeMilliseconds && currentPts <= endTimeMilliseconds){
							packet.pts -= startTimeMilliseconds / (CONVERT_TIME_TO_MS * av_q2d(outAudioStream->time_base));
							packet.dts = packet.pts;
							av_interleaved_write_frame(m_outputFmtCtx, &packet);
							//if (fProgressCallback)
							//	std::thread([this]{fProgressCallback(endTimeMilliseconds - startTimeMilliseconds, currentPts - startTimeMilliseconds); }).detach();
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
		else{

		}
		/*if (m_fEofCb)
		std::thread([this]{FEndOfOperationCallback(); }).detach();*/
		delete this;
	}).detach();
}

//Destructor
CCutOperation::~CCutOperation()
{
}

/*-----------------Private---------------------------------------*/

// Open input file => Fill input streams => Check time conditions => Open output file
BOOL CCutOperation::Init(PCHAR inputFilename, PCHAR outputFilename, int startTimeMilliseconds, int endTimeMilliseconds){
	if (inputFilename == "" || outputFilename == "")
		//if (m_fErrCb){
		//	std::thread([this]{
		//		ERROR_INFO ei;
		//		ei.errorCode = ErrorCode::EC_OPENINPUT;
		//		ei.message = ErrorMessage(ei.errorCode);
		//		m_fErrCb(ei); }).detach();
		//}
		return FALSE;
	av_register_all();

	// If we couldn't open input file - exit
	if (!OpenInputFile(&m_inputFmtCtx, inputFilename))
		return FALSE;

	// Find input video stream, if there is no stream than callback and exit
	auto videoStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (videoStreamIndex >= 0)
		m_inputVideoStream = m_inputFmtCtx->streams[videoStreamIndex];
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
	auto audioStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (audioStreamIndex >= 0)
		m_inputAudioStream = m_inputFmtCtx->streams[audioStreamIndex];

	if (!CheckTimeConditions(startTimeMilliseconds, endTimeMilliseconds)){
		//if (m_fErrCb){
		//	std::thread([this]{
		//		ERROR_INFO ei;
		//		ei.errorCode = ErrorCode::EC_OPENINPUT;
		//		ei.message = ErrorMessage(ei.errorCode);
		//		m_fErrCb(ei); }).detach();
		//}
		return FALSE;
	}

	// If we couldnt open output file - exit
	if (!OpenOutputFile(outputFilename)){
		return FALSE;
	}

	return TRUE;
}

// Calculate duration and deltaPts => Check start and end time is bigger than 0, less than duration and different between it is bigger than deltaPts
BOOL CCutOperation::CheckTimeConditions(int startTime, int endTime){
	auto duration = m_inputFmtCtx->duration * CONVERT_TIME_TO_MS / AV_TIME_BASE;
	auto deltaPts = (m_inputVideoStream->time_base.den * m_inputVideoStream->r_frame_rate.den) / (m_inputVideoStream->time_base.num * m_inputVideoStream->r_frame_rate.num);
	if (startTime < 0 || startTime > duration || endTime <0 || endTime >duration || startTime > endTime - deltaPts)
	{
		return FALSE;
	}
	return TRUE;
}
