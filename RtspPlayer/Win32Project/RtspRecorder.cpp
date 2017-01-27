#include "stdafx.h"
#include "RtspRecorder.h"

BOOL CRtspRecorder::Open(){

	av_register_all();
	av_log_set_level(AV_LOG_DEBUG);
	avformat_network_init();
	if (m_filename.find("rtsp://") != std::string::npos)
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
BOOL CRtspRecorder::Init(){
	m_inputFmtCtx = avformat_alloc_context();
	if (avformat_open_input(&m_inputFmtCtx, m_filename.c_str(), NULL, NULL) != 0){
		return FALSE;
	}
	avformat_find_stream_info(m_inputFmtCtx, NULL);
	av_dump_format(m_inputFmtCtx, 0, m_filename.c_str(), 0);
	const char *filename = "D:\\test.mkv";
	av_init_packet(&m_packet);

	if (!(m_outputFmt = av_guess_format(NULL, filename, NULL))) {
		throw std::exception("av_guess_format");
	}
	m_outputFmtCtx = avformat_alloc_context();
	m_outputFmtCtx->oformat = m_outputFmt;
	strcpy_s(m_outputFmtCtx->filename, sizeof(m_outputFmtCtx->filename), filename);

	if (m_outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
	{
		m_outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}

	m_videoStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	//m_audioStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);

	if (m_videoStreamIndex >= 0){
		m_videoCodec = m_inputFmtCtx->streams[m_videoStreamIndex]->codec;
		auto Codec = avcodec_find_encoder(m_outputFmt->video_codec);
		m_outputVideoStream = avformat_new_stream(m_outputFmtCtx, Codec);
		avcodec_copy_context(m_outputVideoStream->codec, m_videoCodec);
	}
	av_dump_format(m_outputFmtCtx, 0, filename, 1);
	/*if (m_audioStreamIndex >= 0){
		m_audioCodec = m_inputFmtCtx->streams[m_audioStreamIndex]->codec;
		m_outputAudioStream = avformat_new_stream(m_outputFmtCtx, m_audioCodec->codec);
		avcodec_copy_context(m_outputAudioStream->codec, m_audioCodec);
	}*/
	avio_open(&m_outputFmtCtx->pb, filename, AVIO_FLAG_WRITE);
	avformat_write_header(m_outputFmtCtx, NULL);
	//m_outputVideoStream->time_base = m_inputFmtCtx->streams[m_videoStreamIndex]->time_base;
	m_outputVideoStream->r_frame_rate = m_inputFmtCtx->streams[m_videoStreamIndex]->r_frame_rate;
	return TRUE;
}

BOOL CRtspRecorder::StartReadAndWrite(){
	std::thread([this]{
		while (!m_stop){
			if (av_read_frame(m_inputFmtCtx, &m_packet)){
				//End of packets
				break;
			}
			if (m_packet.stream_index == m_videoStreamIndex)
			{
				/*m_packet.pts *= 1/25;
				m_packet.dts *= 1 / 25;*/
				m_packet.stream_index = m_outputVideoStream->index;	
			}
			//if (m_packet.stream_index == m_audioStreamIndex)
			//{
			//	//m_packet.stream_index = m_outputAudioStream->index;
			//	
			//}
			av_write_frame(m_outputFmtCtx, &m_packet);
			av_free_packet(&m_packet);
			av_init_packet(&m_packet);

		}
		av_write_trailer(m_outputFmtCtx);
		avio_close(m_outputFmtCtx->pb);
	}).detach();
	return TRUE;
}
BOOL CRtspRecorder::StopReadAndWrite(){
	return m_stop = true;
}