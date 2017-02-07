#include "stdafx.h"
#include "Export.h"

BOOL CExport::OpenFile(AVFormatContext **inputFmtCtx, std::string inputFileName){
	*inputFmtCtx = avformat_alloc_context();
	if (avformat_open_input(&*inputFmtCtx, inputFileName.c_str(), nullptr, nullptr) != 0){
		/*if (m_fErrCb){
			std::thread([this]{
				ERROR_INFO ei;
				ei.errorCode = ErrorCode::EC_OPENINPUT;
				ei.message = ErrorMessage(ei.errorCode);
				m_fErrCb(ei); }).detach();
		}*/
		return FALSE;
	}
	//Find stream info
	avformat_find_stream_info(*inputFmtCtx, nullptr);
	return TRUE;
}

BOOL CExport::Init(){
	av_register_all();
	/*-------------Open first file-----------------*/
	if (!OpenFile(&m_inputFmtCtx, m_inputFilename))
		return FALSE;

	if (!CheckRequirements()){											// Check boundary conditions of start and end cutting time
		/*if (m_fErrCb){
			std::thread([this]{												// If check is not valid, asynch call error and exit.
				ERROR_INFO ei;
				ei.errorCode = ErrorCode::EC_BOUNDARYERROR;
				ei.message = ErrorMessage(ei.errorCode);
				m_fErrCb(ei); }).detach();
		}*/
		return FALSE;
	}
	/*-------------Open second file-----------------*/
	//If inputFilename2 is empty, than we check that it is cut procedure, if not than return FALSE
	if (m_procedure == Procedure::Merge){
		if (!OpenFile(&m_inputFmtCtx2, m_inputFilename2))
			return FALSE;
	}

	// Write to file
	//Guess outputformat
	if ((m_outputFmt = av_guess_format(nullptr, m_outputFilename.c_str(), nullptr)) == nullptr) {
		/*if (m_fErrCb){
			std::thread([this]{
				ERROR_INFO ei;
				ei.errorCode = ErrorCode::EC_GUESSOUTPUTFORMAT;
				ei.message = ErrorMessage(ei.errorCode);
				m_fErrCb(ei);
			}).detach();
		}*/
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
		/*if (m_fErrCb){
			std::thread([this]{
				ERROR_INFO ei;
				ei.errorCode = ErrorCode::EC_OPENOUTPUT;
				ei.message = ErrorMessage(ei.errorCode);
				m_fErrCb(ei); }).detach();
		}*/
		return FALSE;
	}
	//Write header of outputFile
	avformat_write_header(m_outputFmtCtx, nullptr);

	return TRUE;
}

BOOL CExport::CheckRequirements(){
	//If merge procedure
	if (m_procedure == Procedure::Merge){
		if (m_inputFilename2 != ""){
			return TRUE;
		}
	}
	//if cut procedure choose
	auto duration = m_inputFmtCtx->duration * CONVERT_TIME_TO_MS / AV_TIME_BASE;
	auto deltaPts = (m_inputVideoStream->time_base.den * m_inputVideoStream->r_frame_rate.den) / (m_inputVideoStream->time_base.num * m_inputVideoStream->r_frame_rate.num);
	if (m_startCutTime < 0 || m_startCutTime > duration || m_endCutTime <0 || m_endCutTime >duration || m_startCutTime > m_endCutTime - deltaPts)
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

	if (m_procedure == Procedure::Merge){
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
	m_procedure = Procedure::Cut;
	m_inputFilename = inputFilename;
	m_outputFilename = outputFilename;
	m_startCutTime = startCutTime;
	m_endCutTime = endCutTime;
	/*m_fProgCb = fProgressCallback;
	m_fEofCb = fEofCallback;
	m_fErrCb = fErrorCallback;*/
	//Open input file, alloc formats, open output file
	//All errors are captured by asynch error callback
	//If there was some errors than we call CleanUp Method(destructor);
	if (!Init()){
		CleanUp();
		return FALSE;
	}
	Cutting();
	return TRUE;
}

BOOL CExport::Merge(PCHAR inputFilename, PCHAR inputFilename2, PCHAR outputFilename/*, FProgressCallback fProgressCallback, FEndOfOperationCallback fEofCallback, FErrorCallback fErrorCallback*/){
	//Init all parameters
	m_procedure = Procedure::Merge;
	m_inputFilename = inputFilename;
	m_inputFilename2 = inputFilename2;
	m_outputFilename = outputFilename;
	m_startCutTime = NULL;
	m_endCutTime = NULL;
	/*m_fProgCb = fProgressCallback;
	m_fEofCb = fEofCallback;
	m_fErrCb = fErrorCallback;*/
	//Open input file, alloc formats, open output file
	//All errors are captured by asynch error callback
	if (!Init()){
		CleanUp();
		return FALSE;
	}
	Merging();
	return TRUE;
}

void CExport::RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset){
	packet->pts = av_rescale_q(packet->pts, inputTimeBase, outputTimeBase) + offset;
	packet->dts = AV_NOPTS_VALUE;
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
				/*if (m_fProgCb)
					std::thread([this]{m_fProgCb(m_outputFileDuration, m_currentPts - m_startCutTime); }).detach();*/
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
		CleanUp();
		/*if (m_fEofCb)
			std::thread([this]{m_fEofCb(); }).detach();*/
	}).detach();
}

void CExport::Merging(){
	std::thread([this]{
		int64_t lastPts = 0; // last pts for first input file
		while (!m_cancel){
			m_outputFileDuration = m_inputFmtCtx->duration + m_inputFmtCtx2->duration; // duration of result output file
			av_init_packet(&m_packet);
			//read First
			while (!av_read_frame(m_inputFmtCtx, &m_packet)){
				//Init packet
				//Recalculate pts, dts and duration
				if (m_packet.stream_index == m_videoStreamIndex)
				{
					RecalculateTimeStamps(&m_packet, m_inputVideoStream->time_base, m_outputVideoStream->time_base);
					m_packet.stream_index = m_outputVideoStream->index;
					m_currentPts = m_packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputVideoStream->time_base);
					//Write the packet
					lastPts = m_packet.pts;
					av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
				}
				if (m_packet.stream_index == m_audioStreamIndex)
				{
					RecalculateTimeStamps(&m_packet, m_inputAudioStream->time_base, m_outputAudioStream->time_base);
					m_packet.stream_index = m_outputAudioStream->index;
					m_currentPts = m_packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputAudioStream->time_base);
					//Write the packet
					lastPts = m_packet.pts;
					av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
				}
				/*if (m_fProgCb)
					std::thread([this]{m_fProgCb(m_outputFileDuration, m_currentPts); }).detach();*/
				//Free packet
				av_free_packet(&m_packet);
				av_init_packet(&m_packet);
			}
			while (!av_read_frame(m_inputFmtCtx2, &m_packet)){
				//Init packet
				//Recalculate pts, dts and duration		
				if (m_packet.stream_index == m_videoStreamIndex2)
				{
					RecalculateTimeStamps(&m_packet, m_inputVideoStream2->time_base, m_outputVideoStream->time_base, lastPts);
					m_packet.stream_index = m_outputVideoStream->index;
					m_currentPts = m_packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputVideoStream->time_base);
					//Write the packet
					av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
				}

				if (m_packet.stream_index == m_audioStreamIndex2)
				{
					RecalculateTimeStamps(&m_packet, m_inputAudioStream2->time_base, m_outputAudioStream->time_base, lastPts);
					m_packet.stream_index = m_outputAudioStream->index;
					m_currentPts = m_packet.pts * CONVERT_TIME_TO_MS * av_q2d(m_outputAudioStream->time_base);
					//Write the packet
					av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
				}
				/*if (m_fProgCb)
					std::thread([this]{m_fProgCb(m_outputFileDuration, m_currentPts); }).detach();*/
				//Free packet
				av_free_packet(&m_packet);
				av_init_packet(&m_packet);
			}
			av_free_packet(&m_packet);
			break;
		}
		//Write trailer of outputFile and close input and output
		av_write_trailer(m_outputFmtCtx);
		avio_close(m_outputFmtCtx->pb);
		CleanUp();
		/*if (m_fEofCb)
			std::thread([this]{m_fEofCb(); }).detach();*/
	}).detach();
}

BOOL CExport::CancelProcedure(){
	return m_cancel = true;
}

void CExport::CleanUp(){
	avformat_close_input(&m_inputFmtCtx);
	if (m_procedure == Procedure::Merge)
		avformat_close_input(&m_inputFmtCtx2);
	m_outputFmt = nullptr;
	m_outputFmtCtx = nullptr;
	/*Constructor params*/
	m_inputFilename = "";
	m_inputFilename2 = "";
	m_outputFilename = "";
	m_startCutTime = NULL;
	m_endCutTime = NULL;
	/**/
	m_videoStreamIndex = -1;
	m_audioStreamIndex = -1;
	m_videoStreamIndex2 = -1;
	m_audioStreamIndex2 = -1;
	m_cancel = false;

	m_outputFileDuration = NULL;
	m_currentPts = NULL;
	m_procedure = Procedure::Unknown;
}