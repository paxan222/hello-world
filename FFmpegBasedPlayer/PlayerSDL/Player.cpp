#include "Player.h"

void CPlayerSdl::Log(std::string message)
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
	std::clog << message;
}
void CPlayerSdl::LogAv(int ret)
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
	char err_buf[255];
	av_strerror(ret, err_buf, sizeof(err_buf));
	std::clog << err_buf;
	//delete err_buf;
}

BOOL CPlayerSdl::OpenStream()
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
	Log("OpenStream has called");
	Log(m_filename);
	static CAVInitializer sAVInit;

	if (m_filename.find("rtsp://") != std::string::npos)
	{
		if (0 > av_dict_set(&m_options, "rtsp_transport", "tcp", 0))
		{
			LogAv(AVERROR(ENOMEM));
			return FALSE;
		}
	}
	else
	{
		m_options = nullptr;
	}

	if (avformat_open_input(&m_format_context, m_filename.c_str(), nullptr, &m_options))
	{
		LogAv(AVERROR(ENOMEM));
		return FALSE;
	}

	if (0 > avformat_find_stream_info(m_format_context, nullptr))
	{
		LogAv(AVERROR(ENOMEM));
		return FALSE;
	}

	av_dump_format(m_format_context, 0, m_filename.c_str(), 0);

	m_videoStreamIndex = av_find_best_stream(m_format_context, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	//m_audioStreamIndex = av_find_best_stream(m_format_context, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (m_videoStreamIndex < 0)
	{
		throw new std::exception("VideoStream not found");
		//if (m_cbOnError)
		//	std::thread([this]{m_cbOnError("No streams found"); }).detach();
	}

	if (HasVideo())
	{
		SDL_Init(SDL_INIT_VIDEO);
		m_videoCodecContext = m_format_context->streams[m_videoStreamIndex]->codec;
		m_videoCodec = avcodec_find_decoder(m_videoCodecContext->codec_id);
		if (m_videoCodec == nullptr)
		{
			throw new std::exception("VideoCodec not found");
		}
		m_videoCodecContext->refcounted_frames = 1;

		if (0 > avcodec_open2(m_videoCodecContext, m_videoCodec, nullptr))
		{
			throw new std::exception("VideoCodecContext could not initialize");
			//if (m_cbOnError)
			//	std::thread([this]{m_cbOnError("can't open video codec"); }).detach();
		}

		if ((m_videoCodecContext->width <= 0) || (m_videoCodecContext->height <= 0) || (m_videoCodecContext->pix_fmt == AV_PIX_FMT_NONE))
		{
			throw new std::exception("Incorrect sdp header");
			//if (m_cbOnError)
			//	std::thread([this]{m_cbOnError("incorrect sdp header"); }).detach();
		}
		m_videoCodecContextWidth = m_videoCodecContext->width;
		m_videoCodecContextHeight = m_videoCodecContext->height;
		m_fps = av_q2d(av_guess_frame_rate(m_format_context, m_format_context->streams[m_videoStreamIndex], nullptr));
		m_pixelFormat = &m_videoCodecContext->pix_fmt;
		m_videoCodecContext->refs = 1;

		PacketQueueInit(&m_video_packet_queue);
	}
	if (HasAudio())
	{
		m_audioCodecContext = m_format_context->streams[m_audioStreamIndex]->codec;

		m_audioCodec = avcodec_find_decoder(m_audioCodecContext->codec_id);
		if (m_audioCodec == nullptr)
		{
			throw new std::exception("AudioCodec not found");
			//if (m_cbOnError)
			//	std::thread([this]{m_cbOnError("can't find audio codec"); }).detach();
		}
		m_audioCodecContext->refcounted_frames = 1;
		if (0 > avcodec_open2(m_audioCodecContext, m_audioCodec, nullptr))
		{
			throw new std::exception("AudioCodecContext could not initialize");
			//if (m_cbOnError)
			//	std::thread([this]{m_cbOnError("can't open audio codec"); }).detach();
		}
		if (SDL_Init(SDL_INIT_AUDIO))
			return FALSE;
		/*SDL_memset(&m_audioDesiredSpec, 0, sizeof(m_audioDesiredSpec));
		m_audioDesiredSpec.channels = m_audioCtx->channels;
		m_audioDesiredSpec.freq = m_audioCtx->sample_rate;
		m_decoder.audioSilent = true;*/
	}

	return TRUE;
}

int CPlayerSdl::DemuxSdlThread(void *opaque)
{
	assert(opaque != nullptr);
	CPlayerSdl* pPlayerSdl = static_cast<CPlayerSdl*>(opaque);
	int video_stream_index = pPlayerSdl->m_videoStreamIndex;
	int audio_stream_index = pPlayerSdl->m_audioStreamIndex;
	AVPacket packet;
	while (!pPlayerSdl->m_quit){
		int ret = av_read_frame((pPlayerSdl->m_format_context), &packet);
		if ((ret == AVERROR_EOF || avio_feof(pPlayerSdl->m_format_context->pb))) {
			pPlayerSdl->LogAv(AVERROR(ENOMEM));
			break;	// Eof or error
		}

		if (packet.stream_index == video_stream_index){
			PacketQueuePush(&pPlayerSdl->m_video_packet_queue, &packet);
		}
		else{
			if (packet.stream_index == audio_stream_index){
				PacketQueuePush(&pPlayerSdl->m_audio_packet_queue, &packet);
			}
			else{
				av_packet_unref(&packet);
				av_free_packet(&packet);
			}
		}
	}
	av_packet_unref(&packet);
	av_free_packet(&packet);
	PacketQueueEof(&pPlayerSdl->m_video_packet_queue);
	//PacketQueueEof(&pPlayerSdl->m_audio_packet_queue);
	return 0;
}

int CPlayerSdl::VideoDecodeSdlThread(void* opaque)
{
	assert(opaque != nullptr);
	CPlayerSdl* pPlayerSdl = static_cast<CPlayerSdl*>(opaque);
	AVFrame *frame;
	AVPacket packet;
	SDL_Window *screen = SDL_CreateWindowFrom(pPlayerSdl->m_hMainWindow);
	SDL_Renderer *sdlRenderer = SDL_CreateRenderer(screen, -1, 0);
	SDL_Texture *sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STATIC, pPlayerSdl->m_videoCodecContext->width, pPlayerSdl->m_videoCodecContext->height);
	int64_t lastPts = 0;
	int64_t currentPts;
	int frame_finished;
	while (!pPlayerSdl->m_quit){
		av_init_packet(&packet);
		frame = av_frame_alloc();
		if (PacketQueuePop(&pPlayerSdl->m_video_packet_queue, &packet, 1) < 0){
			//eof queue
			break;
		}
		auto startTime = av_gettime_relative();

		auto ret = avcodec_decode_video2(pPlayerSdl->m_videoCodecContext, frame, &frame_finished, &packet);

		av_free_packet(&packet);
		currentPts = frame->pts;
		if (ret < 0 && ret != AVERROR(EAGAIN) && ret != AVERROR_EOF){
			pPlayerSdl->LogAv(AVERROR(ENOMEM));
			break;
		}
		auto endTime = av_gettime_relative();
		auto decoderTime = endTime - startTime;
		auto some = av_q2d(pPlayerSdl->m_format_context->streams[pPlayerSdl->m_videoStreamIndex]->time_base);
		double diffPts = (currentPts - lastPts)* some * AV_TIME_BASE;
		auto delay = (diffPts - decoderTime) / 1000; // convert to miliseconds
		if (delay > 1000)
			delay = 0;
		if (frame_finished){
			/*if (delay > 0){
				SDL_Delay(delay);
			}*/
			SDL_UpdateYUVTexture(sdlTexture, nullptr, frame->data[0], frame->linesize[0], frame->data[1], frame->linesize[1], frame->data[2], frame->linesize[2]);
			SDL_RenderCopy(sdlRenderer, sdlTexture, nullptr, nullptr);
			SDL_RenderPresent(sdlRenderer);
		}
		//lastPts = currentPts;
		av_frame_free(&frame);
	}
	return 0;
}

SDL_Thread* CPlayerSdl::ThreadStart(ThreadProc fn, void* userdata, const char* name)
{
	assert(fn != NULL);

	auto thread = SDL_CreateThread(fn, name, userdata);
	if (thread == nullptr) {
		throw new std::exception("could not create thread");
	}
	return thread;
}

int CPlayerSdl::ThreadWait(SDL_Thread* thread, const char* name)
{
	int status;
	SDL_WaitThread(thread, &status);
	return status;
}

BOOL CPlayerSdl::Play()
{
	std::thread([this]{
		demux_sdl_thread_ = ThreadStart(DemuxSdlThread, this, "demux");
		video_decode_sdl_thread_ = ThreadStart(VideoDecodeSdlThread, this, "video_decode");

		ThreadWait(demux_sdl_thread_, "demux");
		ThreadWait(video_decode_sdl_thread_, "demux");

		//PacketQueueDeinit(&m_video_packet_queue);
	}).detach();
	return TRUE;
}

BOOL CPlayerSdl::Stop() const
{
	return m_quit;
}

BOOL CPlayerSdl::HasVideo() const
{
	return m_videoStreamIndex >= 0;
}
BOOL CPlayerSdl::HasAudio() const
{
	return m_audioStreamIndex >= 0;
}

void CPlayerSdl::PacketQueueInit(PacketQueue* q)
{
	assert(q != NULL);

	memset(q, 0, sizeof(PacketQueue));
	q->mutex = SDL_CreateMutex();
	q->cond = SDL_CreateCond();
}

void CPlayerSdl::PacketQueueDeinit(PacketQueue* q)
{
	assert(q != NULL);
	assert(q->mutex != NULL);
	assert(q->cond != NULL);

	SDL_DestroyMutex(q->mutex);
	SDL_DestroyCond(q->cond);
}

int CPlayerSdl::PacketQueuePush(PacketQueue* q, AVPacket* pkt)
{
	assert(q != NULL);
	assert(pkt != NULL);

	// Duplicate current packet
	if (av_dup_packet(pkt) < 0) {
		return -1;
	}

	AVPacketList* pkt_list = static_cast<AVPacketList*>(av_malloc(sizeof(AVPacketList)));
	if (pkt_list == nullptr) {
		return -1;
	}

	pkt_list->pkt = *pkt;
	pkt_list->next = nullptr;

	SDL_LockMutex(q->mutex);

	if (!q->eof) {
		if (q->last_pkt == nullptr) {
			// It's a first packet in queue
			q->first_pkt = pkt_list;
		}
		else {
			// Append to the end of queue
			q->last_pkt->next = pkt_list;
		}
		q->last_pkt = pkt_list;
		q->nb_packets++;
		q->size += pkt->size;
	}
	SDL_CondSignal(q->cond);

	SDL_UnlockMutex(q->mutex);
	return 0;
}

int CPlayerSdl::PacketQueuePop(PacketQueue* q, AVPacket* pkt, int block)
{
	assert(q != NULL);
	assert(pkt != NULL);

	SDL_LockMutex(q->mutex);

	AVPacketList* pkt_list = q->first_pkt;
	if (!block && (pkt_list == nullptr)) {
		SDL_UnlockMutex(q->mutex);
		return -1;
	}
	else {
		while ((pkt_list == nullptr) && !q->eof) {
			// Wait for packets
			SDL_CondWait(q->cond, q->mutex);
			pkt_list = q->first_pkt;
		}
	}

	if ((pkt_list == nullptr) && q->eof) {
		SDL_UnlockMutex(q->mutex);
		return -1;
	}

	q->first_pkt = pkt_list->next;
	if (q->first_pkt == nullptr) {
		// No more packets
		q->last_pkt = nullptr;
	}
	*pkt = pkt_list->pkt;
	q->nb_packets--;
	q->size -= pkt->size;
	av_free(pkt_list);

	SDL_UnlockMutex(q->mutex);
	return 0;
}

void CPlayerSdl::PacketQueueEof(PacketQueue* q)
{
	assert(q != NULL);

	SDL_LockMutex(q->mutex);
	q->eof = 1;
	SDL_CondBroadcast(q->cond);
	SDL_UnlockMutex(q->mutex);
}

int CPlayerSdl::RingBufferInit(RingBuffer* rb, int initial_size, int max_size)
{
	assert(rb != NULL);
	assert((max_size <= 0) || (max_size >= initial_size));

	memset(rb, 0, sizeof(RingBuffer));

	rb->data = static_cast<uint8_t*>(av_malloc(initial_size));
	if (rb->data == NULL) {
		return -1;
	}
	rb->size = initial_size;
	rb->max_size = max_size;
	rb->mutex = SDL_CreateMutex();
	rb->rcond = SDL_CreateCond();
	rb->wcond = SDL_CreateCond();
	return 0;
}
