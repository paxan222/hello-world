#include "BaseRecorder.h"

/*private*/

int CBaseRecorder::Interrupt_cb(void *opaque){
	CBaseRecorder* recorder = static_cast<CBaseRecorder*>(opaque);
	int time = GetTickCount();
	if (((time - recorder->m_timePrev) > recorder->m_timeout) && !recorder->m_skipCheckTimeoutFlag){
		return 1;
	}
	return 0;
}

BOOL CBaseRecorder::CheckIFrame(AVPacket packet)
{
	if (packet.flags == AV_PKT_FLAG_KEY ||
		packet.flags == AV_PKT_FLAG_KEY + AV_PKT_FLAG_CORRUPT ||
		packet.flags == AV_PKT_FLAG_KEY + AV_PKT_FLAG_CORRUPT + AV_PKT_FLAG_DISCARD)
		return TRUE;
	return FALSE;
}

void CBaseRecorder::WritePacket(AVPacket *srcPacket, AVStream *srcStream, AVFormatContext *dstFmtCtx, int dstStreamIndex){
	RecalculateTimeStamps(&*srcPacket, srcStream->time_base, dstFmtCtx->streams[dstStreamIndex]->time_base);
	srcPacket->stream_index = dstFmtCtx->streams[dstStreamIndex]->index;
	av_write_frame(dstFmtCtx, srcPacket);
}

void CBaseRecorder::RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase){
	packet->pts = av_rescale_q(packet->pts, inputTimeBase, outputTimeBase);
	packet->dts = packet->pts;
	packet->duration = av_rescale_q(packet->duration, inputTimeBase, outputTimeBase);
}

/*public*/

CBaseRecorder::CBaseRecorder(FErrorCallback fErrorCallback)
{
	m_ErrCb = fErrorCallback;
}

CBaseRecorder::~CBaseRecorder()
{
	m_ErrCb = nullptr;
}

BOOL CBaseRecorder::StartRecord(){
	m_write_thread = new std::thread([this]{
		AVPacket packet{ nullptr };
		int64_t lastPtsVideo = 0;
		int64_t lastPtsAudio = 0;
		while (!m_stop){
			av_init_packet(&packet);
			packet.data = nullptr;
			packet.size = 0;
			if (m_writeHeader){
				if (!WriteHeaderTo(m_outputFmtCtx)){
					if (m_ErrCb)
						std::thread([this]{m_ErrCb(m_errorCode); }).detach();
					av_packet_unref(&packet);
					av_free_packet(&packet);
					break;
				}
				m_writeHeader = false;
			}
			//Read packet
			m_timeout = 1000;
			m_timePrev = GetTickCount();
			m_skipCheckTimeoutFlag = false;
			if (av_read_frame(m_inputFmtCtx, &packet)){
				//EOF
				if (m_ErrCb)
					std::thread([this]{m_ErrCb(ErrorCode::Disconnect); }).detach();
				break;
			}
			m_skipCheckTimeoutFlag = true;
			//Start write packet to output
			if (packet.stream_index == m_inputVideoStream->index){
				packet.pts -= lastPtsVideo;
				WritePacket(&packet, m_inputVideoStream, m_outputFmtCtx, m_outputVideoStreamIndex);
				lastPtsVideo = packet.pts;
			}
			else{
				if (m_inputAudioStream != nullptr){
					if (packet.stream_index == m_inputAudioStream->index){
						packet.pts -= lastPtsAudio;
						WritePacket(&packet, m_inputAudioStream, m_outputFmtCtx, m_outputAudioStreamIndex);
						lastPtsAudio = packet.pts;
					}
				}
			}
			av_packet_unref(&packet);
			av_free_packet(&packet);
			//End write packet
		}
		avformat_close_input(&m_inputFmtCtx);
		if (m_outputFmtCtx != nullptr){
			av_write_trailer(m_outputFmtCtx);
		}
	});
	m_write_thread->joinable();
	return TRUE;
}

BOOL CBaseRecorder::StopRecord(){
	m_stop = true;
	m_write_thread->join();
	return TRUE;
}

/*protected*/

BOOL CBaseRecorder::OpenInputStream(PCHAR rtspPath, int connectionTimeout){

	//Class for multithreading
	//Initialize all the muxers, demuxers and protocols only first time.
	class AVInitializer {
	public:
		AVInitializer() {
			av_register_all();
			avformat_network_init();
			av_log_set_level(AV_LOG_QUIET);
		}
		~AVInitializer() {
			avformat_network_deinit();

		}

	};
	static AVInitializer sAVInit;

	if (rtspPath == ""){
		m_errorCode = ErrorCode::EmptyFilename;
		return FALSE;
	}

	AVDictionary *dictionary{ nullptr };
	if (0 > av_dict_set(&dictionary, "rtsp_transport", "tcp", 0))
	{
		m_errorCode = ErrorCode::UnknownError;
		return FALSE;
	}
	m_inputFmtCtx = avformat_alloc_context();
	/*
	*	Interrupt callback
	*/
	//Connection with interrupt callback
	if (connectionTimeout > 0){
		m_inputFmtCtx->interrupt_callback.callback = Interrupt_cb;
		m_inputFmtCtx->interrupt_callback.opaque = this;
		m_timeout = connectionTimeout;
		m_timePrev = GetTickCount();
	}

	/*
	*	Open rtsp stream
	*/
	if (avformat_open_input(&m_inputFmtCtx, rtspPath, nullptr, &dictionary) != 0){
		m_errorCode = ErrorCode::OpenInputFileError;
		return FALSE;
	}

	av_dict_free(&dictionary);
	/*
	*	Find input Video/Audio streams
	*/

	//Find stream info
	avformat_find_stream_info(m_inputFmtCtx, nullptr);

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

	m_skipCheckTimeoutFlag = true;
	return TRUE;
}

AVStream* CBaseRecorder::CreateStream(AVStream *srcStream, AVFormatContext *&dstFmtCtx, AVCodecID dstCodecId){
	auto outputStream = avformat_new_stream(dstFmtCtx, avcodec_find_encoder(dstCodecId));
	//avcodec_copy_context(outputStream->codec, srcStream->codec);
	avcodec_parameters_copy(outputStream->codecpar, srcStream->codecpar);
	return outputStream;
}

void CBaseRecorder::FillOutputStreamIndex(AVFormatContext *&dstFmtCtx){
	//Create output video stream
	m_outputVideoStream = CreateStream(m_inputVideoStream, dstFmtCtx, dstFmtCtx->oformat->video_codec);
	m_outputVideoStreamIndex = m_outputVideoStream->id;
	//Create output audio stream
	if (m_inputAudioStream != nullptr){
		m_outputAudioStream = CreateStream(m_inputAudioStream, dstFmtCtx, dstFmtCtx->oformat->audio_codec);
		m_outputAudioStreamIndex = m_outputAudioStream->id;
	}
}