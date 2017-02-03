#include "stdafx.h"
#include "Record.h"

BOOL CRecord::Open(){

	av_register_all();
	avformat_network_init();
	if (m_inputFilename.find("rtsp://") != std::string::npos)
	{
		if (0 > av_dict_set(&m_dictionary, "rtsp_transport", "tcp", 0))
			return FALSE;
	}
	else
	{
		m_dictionary = nullptr;
	}

	if (Init() == FALSE){
		return FALSE;
	}
	return TRUE;
}

int CRecord::Interrupt_cb(void* opaque){
	CRecord* recorder = static_cast<CRecord*>(opaque);
	int time = GetTickCount();
	if ((time - recorder->m_timePrev) > recorder->m_connectionTimeout && !recorder->m_interruptFlag){
		return 1;
	}
	return 0;
}

int CRecord::ReceiveData_Cb(void* opaque, uint8_t *buf, int buf_size){
	CRecord* recorder = static_cast<CRecord*>(opaque);
	//recorder->m_RcvDtCb(buf, buf_size);
	return 0;
}
BOOL CRecord::Init(){
	m_inputFmtCtx = avformat_alloc_context();

	//Connection with interrupt callback
	if (m_connectionTimeout != 0){
		m_inputFmtCtx->interrupt_callback.callback = Interrupt_cb;
		m_inputFmtCtx->interrupt_callback.opaque = this;
		m_timePrev = GetTickCount();
	}

	if (avformat_open_input(&m_inputFmtCtx, m_inputFilename.c_str(), nullptr, &m_dictionary) != 0){
		return FALSE;
	}
	m_interruptFlag = true;

	//Find stream info
	avformat_find_stream_info(m_inputFmtCtx, nullptr);

	//If constructor with callback, else constructor with filename
	// m_RcvDtCb == nullptr means write in file
	if ((m_outputFilename == "") /*&& (m_RcvDtCb != nullptr)*/){ // запись через callback
		//Guess outputformat
		if ((m_outputFmt = av_guess_format("matroska", nullptr, nullptr)) == nullptr)
		{
			return FALSE;
		}
		//Alloc OutputFormatContext
		m_outputFmtCtx = avformat_alloc_context();
		m_outputFmtCtx->oformat = m_outputFmt;
		//WriteCallback for AvioContext
		m_receivedCtx = avio_alloc_context(m_buffer, m_bufSize, 1, this, nullptr, ReceiveData_Cb, nullptr);
		m_outputFmtCtx->pb = m_receivedCtx;
		m_outputFmtCtx->flags = AVFMT_FLAG_CUSTOM_IO;

		if (m_outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
		{
			m_outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
		}

		CreateStreams();
	}
	else{// запись напрямую в файл
		//Guess outputformat
		if ((m_outputFmt = av_guess_format(nullptr, m_outputFilename.c_str(), nullptr)) == nullptr) {
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
			return FALSE;
		}
	}

	//Write header of outputFile
	avformat_write_header(m_outputFmtCtx, nullptr);

	return TRUE;
}

void CRecord::CreateStreams(){
	//Finding inputStreams and creating outPutStreams
	//Video
	m_videoStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (m_videoStreamIndex >= 0){
		m_inputVideoStream = m_inputFmtCtx->streams[m_videoStreamIndex];
		m_videoCodec = m_inputVideoStream->codec;
		auto codec = avcodec_find_encoder(m_outputFmt->video_codec);
		m_outputVideoStream = avformat_new_stream(m_outputFmtCtx, codec);
		avcodec_copy_context(m_outputVideoStream->codec, m_videoCodec);
	}
	//Audio
	m_audioStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (m_audioStreamIndex >= 0){
		m_inputAudioStream = m_inputFmtCtx->streams[m_audioStreamIndex];
		m_audioCodec = m_inputAudioStream->codec;
		auto codec = avcodec_find_encoder(m_outputFmt->video_codec);
		m_outputAudioStream = avformat_new_stream(m_outputFmtCtx, codec);
		avcodec_copy_context(m_outputAudioStream->codec, m_audioCodec);
	}
}

void CRecord::RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase){
	packet->pts = av_rescale_q(packet->pts, inputTimeBase, outputTimeBase);
	packet->dts = AV_NOPTS_VALUE;
	packet->duration = av_rescale_q(packet->duration, inputTimeBase, outputTimeBase);
}

BOOL CRecord::StartRecord(){
	std::thread([this]{
		while (!m_stop){
			av_init_packet(&m_packet);
			if (av_read_frame(m_inputFmtCtx, &m_packet)){
				//End of packets
				/*if (m_EofCb != nullptr)
					std::thread([this]{m_EofCb(); }).detach();*/
				break;
			}
			//Init packet
			/*if (m_StartRecCb != nullptr)
				std::thread([this]{m_StartRecCb(); }).detach();*/
			//Recalculate pts, dts and duration
			if (m_packet.stream_index == m_videoStreamIndex){
				RecalculateTimeStamps(&m_packet, m_inputVideoStream->time_base, m_outputVideoStream->time_base);
				m_packet.stream_index = m_outputVideoStream->index;
			}
			if (m_packet.stream_index == m_audioStreamIndex){
				RecalculateTimeStamps(&m_packet, m_inputAudioStream->time_base, m_outputAudioStream->time_base);
				m_packet.stream_index = m_outputAudioStream->index;
			}
			//Write the packet
			av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
			//Free packet
			av_free_packet(&m_packet);
		}
		//Write trailer of outputFile and close input and output
		av_write_trailer(m_outputFmtCtx);
		if ((m_outputFilename != "")/* && (m_RcvDtCb == nullptr)*/){
			avio_close(m_outputFmtCtx->pb);
		}
	}).detach();
	return TRUE;
}

BOOL CRecord::StopRecord(){
	return m_stop = true;
}