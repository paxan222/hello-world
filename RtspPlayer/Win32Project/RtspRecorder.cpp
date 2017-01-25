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

	AVCodecContext *videoCodec = nullptr;
	const char *filename = "D:\\test.ts";
	av_init_packet(&m_packet);



	//m_outputFmtCtx = avformat_alloc_context();
	//m_outputFmt = av_guess_format("mp4", NULL, NULL);
	////outFmtCtx->oformat = m_outputFmt;
	//avformat_alloc_output_context2(&m_outputFmtCtx, m_outputFmt, NULL, filename);
	//strcpy(m_outputFmtCtx->filename, filename);
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
	m_audioStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	videoCodec = m_inputFmtCtx->streams[m_videoStreamIndex]->codec;
	m_outputVideoStream = avformat_new_stream(m_outputFmtCtx, videoCodec->codec);
	m_outputVideoStream->sample_aspect_ratio = m_inputFmtCtx->streams[m_videoStreamIndex]->sample_aspect_ratio;
	avcodec_copy_context(m_outputVideoStream->codec, videoCodec);
	
	


	avio_open2(&m_outputFmtCtx->pb, filename, AVIO_FLAG_WRITE, nullptr, nullptr);

	avformat_write_header(m_outputFmtCtx, NULL);
	//if (m_videoStreamIndex >= 0){

	//	//m_outputVideoStream = avformat_new_stream(m_outputFmtCtx, m_inputFmtCtx->streams[m_videoStreamIndex]->codec->codec);
	//	//avcodec_copy_context(m_outputVideoStream->codec, m_inputFmtCtx->streams[m_videoStreamIndex]->codec);
	//	//m_outputVideoStream->sample_aspect_ratio = m_inputFmtCtx->streams[m_videoStreamIndex]->sample_aspect_ratio;	
	//}
	/*if (m_audioStreamIndex >= 0){
		m_outputAudioStream = avformat_new_stream(m_outputFmtCtx, m_inputFmtCtx->streams[m_audioStreamIndex]->codec->codec);
		avcodec_copy_context(m_outputAudioStream->codec, m_inputFmtCtx->streams[m_audioStreamIndex]->codec);
		m_outputAudioStream->sample_aspect_ratio = m_inputFmtCtx->streams[m_audioStreamIndex]->sample_aspect_ratio;
		}*/

	/*if (m_outputFmtCtx->oformat->flags && AVFMT_NOFILE){
		if (avio_open2(&m_outputFmtCtx->pb, filename, AVIO_FLAG_WRITE, NULL, NULL)){
			return FALSE;
		}
	}
	avformat_write_header(m_outputFmtCtx, NULL);*/
	return TRUE;
}
BOOL CRtspRecorder::StartReadAndWrite(){
	std::thread([this]{
		av_read_play(m_inputFmtCtx);
		while (!m_stop){
			if (av_read_frame(m_inputFmtCtx, &m_packet)){
				//End of packets
				break;
			}
			if (m_packet.stream_index == m_videoStreamIndex)
			{
				m_packet.stream_index = m_outputVideoStream->id;				
			}
			/*if (m_packet.stream_index == m_audioStreamIndex)
			{
				m_packet.stream_index = m_outputAudioStream->id;
			}*/
			try{
				av_write_frame(m_outputFmtCtx, &m_packet);
			}
			catch (...){
				break;
			}
			av_free_packet(&m_packet);
			av_init_packet(&m_packet);			

		}
		av_write_trailer(m_outputFmtCtx);
	}).detach();
	return TRUE;
}
BOOL CRtspRecorder::StopReadAndWrite(){
	return m_stop = true;
}