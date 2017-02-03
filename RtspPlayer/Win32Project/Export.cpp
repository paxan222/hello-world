#include "stdafx.h"
#include "Export.h"

BOOL CExport::Init(){
	av_register_all();

	m_inputFmtCtx = avformat_alloc_context();
	if (avformat_open_input(&m_inputFmtCtx, m_inputFilename.c_str(), nullptr, nullptr) != 0){
		/*std::thread([this]{
			ERROR_INFO ei;
			ei.errorCode = ErrorCode::EC_OPENINPUT;
			ei.message = ErrorMessage(ei.errorCode);
			m_fErrCb(ei); }).detach();*/
		return FALSE;
	}
	//Find stream info
	avformat_find_stream_info(m_inputFmtCtx, nullptr);

	m_inputFmtCtx2 = avformat_alloc_context();
	if (avformat_open_input(&m_inputFmtCtx2, m_inputFilename2.c_str(), nullptr, nullptr) != 0){
		/*std::thread([this]{
		ERROR_INFO ei;
		ei.errorCode = ErrorCode::EC_OPENINPUT;
		ei.message = ErrorMessage(ei.errorCode);
		m_fErrCb(ei); }).detach();*/
		return FALSE;
	}
	//Find stream info
	avformat_find_stream_info(m_inputFmtCtx2, nullptr);

	if (!CheckRequirements()){											// Check boundary conditions of start and end cutting time
		//std::thread([this]{												// If check is not valid, asynch call error and exit.
		//	ERROR_INFO ei;
		//	ei.errorCode = ErrorCode::EC_BOUNDARYERROR;
		//	ei.message = ErrorMessage(ei.errorCode);
		//	m_fErrCb(ei); }).detach();
		return FALSE;
	}


	// Write to file
	//Guess outputformat
	if ((m_outputFmt = av_guess_format(nullptr, m_outputFilename.c_str(), nullptr)) == nullptr) {
		/*std::thread([this]{
			ERROR_INFO ei;
			ei.errorCode = ErrorCode::EC_GUESSOUTPUTFORMAT;
			ei.message = ErrorMessage(ei.errorCode);
			m_fErrCb(ei); }).detach();*/
		return FALSE;
	}
	//Alloc OutputFormatContext
	m_outputFmtCtx = avformat_alloc_context();
	m_outputFmtCtx->oformat = m_outputFmt;
	//Copy outputfilename to outputCtx
	strcpy_s(m_outputFmtCtx->filename, sizeof(m_outputFmtCtx->filename), m_outputFilename.c_str());

	if (m_outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
	{
		m_outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}

	CreateStreams();

	//Open outputfile, if return "<0" exit
	if (avio_open(&m_outputFmtCtx->pb, m_outputFilename.c_str(), AVIO_FLAG_WRITE) < 0){
		/*std::thread([this]{
			ERROR_INFO ei;
			ei.errorCode = ErrorCode::EC_OPENOUTPUT;
			ei.message = ErrorMessage(ei.errorCode);
			m_fErrCb(ei); }).detach();*/
		return FALSE;
	}
	//Write header of outputFile
	avformat_write_header(m_outputFmtCtx, nullptr);

	return TRUE;
}

BOOL CExport::CheckRequirements(){
	if (m_startCutTime == NULL && m_endCutTime == NULL && m_inputFilename2 !=""){
		return TRUE;
	}
	auto duration = m_inputFmtCtx->duration * CONVERT_TIME_TO_MS / AV_TIME_BASE;
	auto deltaPts = (m_inputVideoStream->time_base.den * m_inputVideoStream->r_frame_rate.den) / (m_inputVideoStream->time_base.num * m_inputVideoStream->r_frame_rate.num);
	if (m_startCutTime < 0 || m_startCutTime > duration || m_endCutTime <0 || m_endCutTime >duration || m_startCutTime < m_endCutTime - deltaPts)
	{
		return FALSE;
	}
	return TRUE;
}

void CExport::CreateStreams(){
	//Finding inputStreams and creating outPutStreams
	//Video
	m_videoStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (m_videoStreamIndex >= 0){
		m_inputVideoStream = m_inputFmtCtx->streams[m_videoStreamIndex];
		auto codec = avcodec_find_encoder(m_outputFmt->video_codec);
		m_outputVideoStream = avformat_new_stream(m_outputFmtCtx, codec);
		avcodec_copy_context(m_outputVideoStream->codec, m_inputVideoStream->codec);
	}
	//Audio
	m_audioStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (m_audioStreamIndex >= 0){
		m_inputAudioStream = m_inputFmtCtx->streams[m_audioStreamIndex];
		auto codec = avcodec_find_encoder(m_outputFmt->audio_codec);
		m_outputAudioStream = avformat_new_stream(m_outputFmtCtx, codec);
		avcodec_copy_context(m_outputAudioStream->codec, m_inputAudioStream->codec);
	}

	if (m_inputFmtCtx2 != nullptr){
		m_videoStreamIndex2 = av_find_best_stream(m_inputFmtCtx2, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
		if (m_videoStreamIndex2 >= 0){
			m_inputVideoStream2 = m_inputFmtCtx2->streams[m_videoStreamIndex2];
		}
		m_audioStreamIndex2 = av_find_best_stream(m_inputFmtCtx2, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
		if (m_audioStreamIndex2 >= 0){
			m_inputAudioStream2 = m_inputFmtCtx2->streams[m_audioStreamIndex2];
		}
	}
}

BOOL CExport::Cut(PCHAR inputFilename, PCHAR outputFilename, int startCutTime, int endCutTime/*, FProgressCallback fProgressCallback, FEndOfOperationCallback fEofCallback, FErrorCallback fErrorCallback*/){
	//Init all parameters
	m_inputFilename = inputFilename;
	m_outputFilename = outputFilename;
	m_startCutTime = startCutTime;
	m_endCutTime = endCutTime;
	/*m_fProgCb = fProgressCallback;
	m_fEofCb = fEofCallback;
	m_fErrCb = fErrorCallback;*/
	//Open input file, alloc formats, open output file
	//All errors are captured by asynch error callback
	if (!Init())
		return FALSE;
	Cutting();
	return TRUE;
}

BOOL CExport::Merge(PCHAR inputFilename, PCHAR inputFilename2, PCHAR outputFilename/*, FProgressCallback fProgressCallback, FEndOfOperationCallback fEofCallback, FErrorCallback fErrorCallback*/){
	//Init all parameters
	m_startCutTime = NULL;
	m_endCutTime = NULL;
	m_inputFilename = inputFilename;
	m_inputFilename2 = inputFilename2;
	m_outputFilename = outputFilename;
	/*m_fProgCb = fProgressCallback;
	m_fEofCb = fEofCallback;
	m_fErrCb = fErrorCallback;*/
	//Open input file, alloc formats, open output file
	//All errors are captured by asynch error callback
	if (!Init())
		return FALSE;
	Merging();
	return TRUE;
}
void CExport::RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset){
	packet->pts = av_rescale_q(packet->pts, inputTimeBase, outputTimeBase) + offset;
	packet->dts = packet->pts;
	packet->duration = av_rescale_q(packet->duration, inputTimeBase, outputTimeBase);
}

int CExport::RecalculatedDuration(){
	return m_endCutTime - m_startCutTime;
}

void CExport::Cutting(){
	std::thread([this]{
		while (!m_cancel){
			av_init_packet(&m_packet);
			if (av_read_frame(m_inputFmtCtx, &m_packet)){
				//End of packets
				break;
			}
			//Init packet
			//Recalculate pts, dts and duration
			if (m_packet.stream_index == m_videoStreamIndex)
			{
				RecalculateTimeStamps(&m_packet, m_inputVideoStream->time_base, m_outputVideoStream->time_base);
				m_packet.stream_index = m_outputVideoStream->index;
				m_currentPts = m_packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputVideoStream->time_base);
			}
			if (m_packet.stream_index == m_audioStreamIndex)
			{
				RecalculateTimeStamps(&m_packet, m_inputAudioStream->time_base, m_outputAudioStream->time_base);
				m_packet.stream_index = m_outputAudioStream->index;
				m_currentPts = m_packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputAudioStream->time_base);
			}
			//Write the packet that meets all requirements
			
			m_outputFileDuration = RecalculatedDuration();
			if (m_currentPts >= m_startCutTime && m_currentPts <= m_endCutTime){
				av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
				//std::thread([this]{m_fProgCb(m_outputFileDuration, m_currentPts - m_startCutTime); }).detach();
			}
			//Free packet
			av_free_packet(&m_packet);
			//If pts bigger than endCutTime free packet and quit cycle
			if (m_currentPts > m_endCutTime){
				break;
			}
		}
		//Write trailer of outputFile and close input and output
		av_write_trailer(m_outputFmtCtx);
		avio_close(m_outputFmtCtx->pb);
		//std::thread([this]{m_fEofCb(); }).detach();
	}).detach();
}

void CExport::Merging(){
	std::thread([this]{
		FILE *ptsFile = fopen("D:\\TestVideo\\pts.txt", "w");
		int lastPts = 0;
		while (!m_cancel){
			auto duration = m_inputFmtCtx->duration + m_inputFmtCtx2->duration;
			av_init_packet(&m_packet);
			while (!av_read_frame(m_inputFmtCtx, &m_packet)){
				//Init packet
				//Recalculate pts, dts and duration
				if (m_packet.stream_index == m_videoStreamIndex)
				{
					RecalculateTimeStamps(&m_packet, m_inputVideoStream->time_base, m_outputVideoStream->time_base);
					m_packet.stream_index = m_outputVideoStream->index;
					//Write the packet
					lastPts = m_packet.pts;
					av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
				}
				if (m_packet.stream_index == m_audioStreamIndex)
				{
					RecalculateTimeStamps(&m_packet, m_inputAudioStream->time_base, m_outputAudioStream->time_base);
					m_packet.stream_index = m_outputAudioStream->index;
					//Write the packet
					lastPts = m_packet.pts;
					av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
				}

				//Free packet
				av_free_packet(&m_packet);
				av_init_packet(&m_packet);
			}
			while (!av_read_frame(m_inputFmtCtx2, &m_packet)){
				//Init packet
				//Recalculate pts, dts and duration		
				if (m_packet.stream_index == m_videoStreamIndex2)
				{
					//RecalculateTimeStamps(&m_packet, m_inputVideoStream2->time_base, m_inputVideoStream->time_base);
					RecalculateTimeStamps(&m_packet, m_inputVideoStream2->time_base, m_outputVideoStream->time_base, lastPts);
					m_packet.stream_index = m_outputVideoStream->index;
					fprintf(ptsFile, "---------------\n");
					fprintf(ptsFile, "Stream: %s\n", m_packet.stream_index == 0 ? "Video" : "Audio");
					fprintf(ptsFile, "PTS: %i\n", m_packet.pts);
					fprintf(ptsFile, "DTS: %i\n", m_packet.dts);
					fprintf(ptsFile, "DUR: %i\n", m_packet.duration);
					//Write the packet
					av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
				}

				if (m_packet.stream_index == m_audioStreamIndex2)
				{
					//RecalculateTimeStamps(&m_packet, m_inputAudioStream2->time_base, m_inputAudioStream->time_base);
					RecalculateTimeStamps(&m_packet, m_inputAudioStream2->time_base, m_outputAudioStream->time_base, lastPts);
					m_packet.stream_index = m_outputAudioStream->index;
					fprintf(ptsFile, "---------------\n");
					fprintf(ptsFile, "Stream: %s\n", m_packet.stream_index == 0 ? "Video" : "Audio");
					fprintf(ptsFile, "PTS: %i\n", m_packet.pts);
					fprintf(ptsFile, "DTS: %i\n", m_packet.dts);
					fprintf(ptsFile, "DUR: %i\n", m_packet.duration);
					//Write the packet
					av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
				}
				//Free packet
				av_free_packet(&m_packet);
				av_init_packet(&m_packet);
			}
			avformat_close_input(&m_inputFmtCtx2);
			break;
		}
		fclose(ptsFile);
		//Write trailer of outputFile and close input and output
		av_write_trailer(m_outputFmtCtx);
		avio_close(m_outputFmtCtx->pb);
		//std::thread([this]{m_fEofCb(); }).detach();
	}).detach();
}
BOOL CExport::CancelProcedure(){
	return m_cancel = true;
}