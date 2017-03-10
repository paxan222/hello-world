#include "stdafx.h"

#include "BaseRecorder.h"

/*private*/
int CBaseRecorder::Interrupt_cb(void *opaque){
	CBaseRecorder* recorder = static_cast<CBaseRecorder*>(opaque);
	int time = GetTickCount();
	if ((time - recorder->m_timePrev) > recorder->m_connectionTimeout && !recorder->m_interrupDisable){
		//_RPT1(0, "Interrupt:%i\n");
		return 1;
	}
	return 0;
}

BOOL CBaseRecorder::CheckIFrame(AVPacket packet){

	if (packet.flags == AV_PKT_FLAG_KEY ||
		packet.flags == AV_PKT_FLAG_KEY + AV_PKT_FLAG_CORRUPT /*||
															  packet.flags == AV_PKT_FLAG_KEY + AV_PKT_FLAG_CORRUPT + AV_PKT_FLAG_DISCARD*/)
															  return TRUE;
	else
		return FALSE;
}

void CBaseRecorder::WritePacket(AVPacket *srcPacket, AVStream *srcStream, AVFormatContext *&dstFmtCtx, int dstStreamIndex){
	RecalculateTimeStamps(&*srcPacket, srcStream->time_base, dstFmtCtx->streams[dstStreamIndex]->time_base);
	srcPacket->stream_index = dstFmtCtx->streams[dstStreamIndex]->index;
	av_write_frame(dstFmtCtx, &*srcPacket);
}

void CBaseRecorder::RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase){
	packet->pts = av_rescale_q(packet->pts, inputTimeBase, outputTimeBase);
	packet->dts = packet->pts;
	packet->duration = av_rescale_q(packet->duration, inputTimeBase, outputTimeBase);
}

/*public*/

std::mutex mutex;

clock_t defTime;
int timer(clock_t start){
	clock_t stop = clock();
	return (stop - start);
}

CBaseRecorder::CBaseRecorder(/*FErrorCallback fErrorCallback, FStartRecordCallback fStartRecordCallback*/)
{
	/*m_ErrCb = fErrorCallback;
	m_StartRecCb = fStartRecordCallback;*/
	//_RPT1(0, "MutexLock: %i\n", timer());
	//mutex.lock();
	//av_register_all();
	//_RPT1(0, "MutexUnlock: %i\n", timer());
	//mutex.unlock();
}

CBaseRecorder::~CBaseRecorder()
{
	avformat_close_input(&m_inputFmtCtx);
}

BOOL CBaseRecorder::StartRecord(){
	std::thread([this]{
		AVPacket packet{ nullptr };
		int64_t lastPtsVideo = 0;
		int64_t lastPtsAudio = 0;
		while (!m_stop){
			av_init_packet(&packet);
			//Read packet
			if (av_read_frame(m_inputFmtCtx, &packet)){
				//EOF
				/*if (m_ErrCb)
					std::thread([this]{m_ErrCb(ErrorCode::Disconnect); }).detach();*/
				_RPT0(0, "EnfOfFFrame\n");
				break;
			}
			//Write header from IFrame
			if (m_writeHeader){
				if (CheckIFrame(packet) && (packet.stream_index == m_inputVideoStream->index)){
					m_writeHeader = false;
					WriteHeaderTo(m_outputFmtCtx);
				}
				else continue; //Skip frame until IFrame to start write header
			}
			//Start record callback
			/*if (m_StartRecCb)
				std::thread([this]{m_StartRecCb(); }).detach();*/
			//Start write packet to output

			if (packet.stream_index == m_inputVideoStream->index){

				packet.pts -= lastPtsVideo;
				//_RPT1(0, "VIDEOPTS_ORIG:\t%i\n", packet.pts);
				WritePacket(&packet, m_inputVideoStream, m_outputFmtCtx, m_outputVideoStreamIndex);
				//_RPT1(0, "VIDEOPTS_RECL:\t%i\n", packet.pts);
				lastPtsVideo = packet.pts;
			}
			else{
				if (m_inputAudioStream != nullptr){
					if (packet.stream_index == m_inputAudioStream->index){
						packet.pts -= lastPtsAudio;
						//_RPT1(0, "AUDIOPTS_ORIG:\t%i\n", packet.pts);
						WritePacket(&packet, m_inputAudioStream, m_outputFmtCtx, m_outputAudioStreamIndex);
						//_RPT1(0, "AUDIOPTS_RECL:\t%i\n", packet.pts);
						lastPtsAudio = packet.pts;
					}
				}
			}
			av_free_packet(&packet);
			//End write packet
		}
		//Write trailer of outputFile and close input and output
		if (m_outputFmtCtx)
			WriteTrailer(m_outputFmtCtx);
	}).detach();
	return TRUE;
}

BOOL CBaseRecorder::StopRecord(){
	return m_stop = true;
}

clock_t startTimer = clock();
int newtime = GetTickCount();
/*protected*/
BOOL CBaseRecorder::OpenInputStream(PCHAR rtspPath, int connectionTimeout, int counter){

	class AVInitializer {
		public:
			AVInitializer() {
				av_register_all();
				avformat_network_init();
				
			}
			~AVInitializer() {
				avformat_network_deinit();
				
			}
			
	};
	static AVInitializer sAVInit;

	if (rtspPath == ""){		
		//m_errorCode
		return FALSE;
	}
	_RPT3(0, "%i\t\%i\t%s\n", GetCurrentThreadId(), timer(startTimer), "StartOpen");
	//LOG("Start av_register_all");
	//mutex.lock();
	//avformat_network_init();
	//mutex.unlock();
	//LOG("++av_register_all");
	AVDictionary *dictionary{ nullptr };
	if (0 > av_dict_set(&dictionary, "rtsp_transport", "tcp", 0))
	{
		//_RPT1(0, "Dict_Error:%i\n");
		//m_errrorCode
		return FALSE;
	}

	m_inputFmtCtx = avformat_alloc_context();
	/*
	*	Interrupt callback
	*/
	//Connection with interrupt callback
	if (connectionTimeout > 0){
		m_inputFmtCtx->interrupt_callback.callback = [](void *opaque){
			CBaseRecorder* recorder = static_cast<CBaseRecorder*>(opaque);
			int time = GetTickCount();
			if ((time - recorder->m_timePrev) > recorder->m_connectionTimeout && !recorder->m_interrupDisable){
				_RPT1(0, "Time: %i\t", (time - recorder->m_timePrev));
				//LOG("Interrupt");
				return 1;
			}
			return 0;
			/*AVFormatContext* inpt = static_cast<AVFormatContext*>(opaque);
			int time = GetTickCount();
			if ((time - newtime) > 10000){
				LOG("Interrupt");
				return 1;
			}
			return 0;*/
		};
		m_inputFmtCtx->interrupt_callback.opaque = this;
		m_connectionTimeout = connectionTimeout;
		m_timePrev = GetTickCount();
	}

	/*
	*	Open rtsp stream
	*/	
	//AVInputFormat *inputfmt = av_find_input_format("rtsp");
	//m_inputFmtCtx->iformat = inputfmt;
	//LOG("Start avformat_open_input");
	if (avformat_open_input(&m_inputFmtCtx, rtspPath, nullptr, &dictionary) != 0){
		auto ret = AVERROR(ENOMEM);
		char err_buf[255];
		av_strerror(ret, err_buf, sizeof(err_buf));
		//LOG(err_buf);
		return FALSE;
	}
	//LOG("++avformat_open_input");

	av_dict_free(&dictionary);
	//av_dump_format(m_inputFmtCtx,0,rtspPath,0);
	/*
	*	Find input Video/Audio streams
	*/

	//Find stream info
	//LOG("avformat_find_stream_info");
	if (avformat_find_stream_info(m_inputFmtCtx, nullptr) < 0){
		auto ret = AVERROR(ENOMEM);
		char err_buf[255];
		av_strerror(ret, err_buf, sizeof(err_buf));
		//LOG(err_buf);
		return FALSE;
	}
	//LOG("++avformat_find_stream_info");


	// Find input video stream, if there is no stream than callback and exit
	auto streamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_inputVideoStream = m_inputFmtCtx->streams[streamIndex];
	else{
		//m_errorCode = ErrorCode::VideoStreamNotExist;
		
		//LOG("EmptyVideoStream");
		return FALSE;
	}
	// Find input audio stream, if threre is no stream than work only with video
	streamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (streamIndex >= 0)
		m_inputAudioStream = m_inputFmtCtx->streams[streamIndex];
	m_interrupDisable = true;

	_RPT3(0, "%i\t\%i\t%s\n", GetCurrentThreadId(), timer(startTimer), "EndOpen");
	return TRUE;
}

int CBaseRecorder::CreateStream(AVStream *srcStream, AVFormatContext *&dstFmtCtx, AVCodecID dstCodecId){
	auto tmpCodec = avcodec_find_encoder(dstCodecId);
	auto outputStream = avformat_new_stream(dstFmtCtx, tmpCodec);
	avcodec_copy_context(outputStream->codec, srcStream->codec);
	return outputStream->index;
}

void CBaseRecorder::FillOutputStreamIndex(AVFormatContext *&dstFmtCtx){
	//Create output video stream
	m_outputVideoStreamIndex = CreateStream(m_inputVideoStream, dstFmtCtx, dstFmtCtx->oformat->video_codec);
	//Create output audio stream
	if (m_inputAudioStream != nullptr)
		m_outputAudioStreamIndex = CreateStream(m_inputAudioStream, dstFmtCtx, dstFmtCtx->oformat->audio_codec);
}