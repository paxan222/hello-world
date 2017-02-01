#include "stdafx.h"
#include "RtspRecorder.h"

BOOL CRtspRecorder::Open(){

	av_register_all();
	avformat_network_init();
	if (m_inputFilename.find("rtsp://") != std::string::npos)
	{
		if (0 > av_dict_set(&m_dictionary, "rtsp_transport", "tcp", 0))
			return FALSE;
	}
	else
	{
		m_dictionary = NULL;
	}

	if (Init() == FALSE){
		return FALSE;
	}
	return TRUE;
}

int CRtspRecorder::Interrupt_cb(void *ctx){
	/*Использовать тоже самое что и в writeCb*/
	int time = GetTickCount();
	if ((time - timePrev) > interruptTimeout && !interruptFlag){
		return 1;
	}
	return 0;
}
FILE *file = fopen("D:\\testByte.mkv", "wb");

int CRtspRecorder::WritePacket_cb(void* opaque, uint8_t *buf, int buf_size){
	/*Для избавления от статики надо использовать 
	CRtspRecorder* recorder = static_cast<CRtspRecorder*>(opaque);
	recorder->m_RcvDtCb(buf, buf_size);
	return 0;
	*/
	fwrite(buf, 1, buf_size, file);
	return 0;
}
BOOL CRtspRecorder::Init(){
	m_inputFmtCtx = avformat_alloc_context();

	//Connection with interrupt callback
	m_inputFmtCtx->interrupt_callback.callback = Interrupt_cb;
	m_inputFmtCtx->interrupt_callback.opaque = 0;
	timePrev = GetTickCount();
	interruptTimeout = m_connectionTimeout;

	if (avformat_open_input(&m_inputFmtCtx, m_inputFilename.c_str(), nullptr, &m_dictionary) != 0){
		return FALSE;
	}
	interruptFlag = true;

	//Find stream info
	avformat_find_stream_info(m_inputFmtCtx, nullptr);

	if (m_outputFilename == ""){
		//Guess outputformat
		if (!(m_outputFmt = av_guess_format("matroska", nullptr, nullptr))) {
			return FALSE;
		}
		//Alloc OutputFormatContext
		m_outputFmtCtx = avformat_alloc_context();
		m_outputFmtCtx->oformat = m_outputFmt;
		/*start*/
		const int iBufSize = 32 * 1024;
		BYTE* pBuffer = new BYTE[iBufSize];

		AVIOContext *avioContext = avio_alloc_context(pBuffer, iBufSize, 1, nullptr, nullptr, WritePacket_cb, nullptr);;
		m_outputFmtCtx->pb = avioContext;
		m_outputFmtCtx->flags = AVFMT_FLAG_CUSTOM_IO;
		/*end*/


		if (m_outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
		{
			m_outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
		}

		//Finding inputStreams and creating outPutStreams
		//Video
		m_videoStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
		m_inputVideoStream = m_inputFmtCtx->streams[m_videoStreamIndex];
		if (m_videoStreamIndex >= 0){
			m_videoCodec = m_inputVideoStream->codec;
			auto codec = avcodec_find_encoder(m_outputFmt->video_codec);
			m_outputVideoStream = avformat_new_stream(m_outputFmtCtx, codec);
			avcodec_copy_context(m_outputVideoStream->codec, m_videoCodec);
		}
		//Audio
		m_audioStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
		m_inputAudioStream = m_inputFmtCtx->streams[m_audioStreamIndex];
		if (m_audioStreamIndex >= 0){
			m_audioCodec = m_inputAudioStream->codec;
			auto codec = avcodec_find_encoder(m_outputFmt->video_codec);
			m_outputAudioStream = avformat_new_stream(m_outputFmtCtx, codec);
			avcodec_copy_context(m_outputAudioStream->codec, m_audioCodec);
		}

	}
	else{
		//Guess outputformat
		if (!(m_outputFmt = av_guess_format(nullptr, m_outputFilename.c_str(), nullptr))) {
			return FALSE;
		}
		//Alloc OutputFormatContext
		m_outputFmtCtx = avformat_alloc_context();
		m_outputFmtCtx->oformat = m_outputFmt;
		strcpy_s(m_outputFmtCtx->filename, sizeof(m_outputFmtCtx->filename), m_outputFilename.c_str());


		if (m_outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
		{
			m_outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
		}

		//Finding inputStreams and creating outPutStreams
		//Video
		m_videoStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
		m_inputVideoStream = m_inputFmtCtx->streams[m_videoStreamIndex];
		if (m_videoStreamIndex >= 0){
			m_videoCodec = m_inputVideoStream->codec;
			auto codec = avcodec_find_encoder(m_outputFmt->video_codec);
			m_outputVideoStream = avformat_new_stream(m_outputFmtCtx, codec);
			avcodec_copy_context(m_outputVideoStream->codec, m_videoCodec);
		}
		//Audio
		m_audioStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
		m_inputAudioStream = m_inputFmtCtx->streams[m_audioStreamIndex];
		if (m_audioStreamIndex >= 0){
			m_audioCodec = m_inputAudioStream->codec;
			auto codec = avcodec_find_encoder(m_outputFmt->video_codec);
			m_outputAudioStream = avformat_new_stream(m_outputFmtCtx, codec);
			avcodec_copy_context(m_outputAudioStream->codec, m_audioCodec);
		}
		//Open outputfile, if return "<0" exit
		if (avio_open(&m_outputFmtCtx->pb, m_outputFilename.c_str(), AVIO_FLAG_WRITE) < 0){
		return FALSE;
		}
	}
	//Write header of outputFile
	avformat_write_header(m_outputFmtCtx, nullptr);

	return TRUE;
}

BOOL CRtspRecorder::StartRecord(){
	std::thread([this]{
		while (!m_stop){
			av_init_packet(&m_packet);
			if (av_read_frame(m_inputFmtCtx, &m_packet)){
				//End of packets
				break;
			}
			//Init packet
			//Recalculate pts, dts and duration
			if (m_packet.stream_index == m_videoStreamIndex)
			{
				m_packet.pts = av_rescale_q(m_packet.pts, m_inputVideoStream->time_base, m_outputVideoStream->time_base);
				m_packet.dts = AV_NOPTS_VALUE;
				m_packet.duration = av_rescale_q(m_packet.duration, m_inputVideoStream->time_base, m_outputVideoStream->time_base);
				m_packet.stream_index = m_outputVideoStream->index;
			}
			if (m_packet.stream_index == m_audioStreamIndex)
			{
				m_packet.pts = av_rescale_q(m_packet.pts, m_inputFmtCtx->streams[m_audioStreamIndex]->time_base, m_outputAudioStream->time_base);
				m_packet.dts = AV_NOPTS_VALUE;
				m_packet.duration = av_rescale_q(m_packet.duration, m_inputFmtCtx->streams[m_audioStreamIndex]->time_base, m_outputAudioStream->time_base);
				m_packet.stream_index = m_outputAudioStream->index;
			}
			//Write the packet
			av_interleaved_write_frame(m_outputFmtCtx, &m_packet);
			//Free packet
			av_free_packet(&m_packet);
		}
		//Write trailer of outputFile and close input and output
		av_write_trailer(m_outputFmtCtx);
		if (m_outputFilename != ""){
			avio_close(m_outputFmtCtx->pb); 
		}
		else{
			fclose(file);
		}
	}).detach();
	return TRUE;
}

BOOL CRtspRecorder::StopRecord(){
	return m_stop = true;
}