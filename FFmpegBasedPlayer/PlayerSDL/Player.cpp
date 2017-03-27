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
	m_audioStreamIndex = av_find_best_stream(m_format_context, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (m_videoStreamIndex < 0)
	{
		throw new std::exception("VideoStream not found");
		//if (m_cbOnError)
		//	std::thread([this]{m_cbOnError("No streams found"); }).detach();
	}

	PacketQueueInit(&m_video_packet_queue);
	PacketQueueInit(&m_audio_packet_queue);
	RingBufferInit(&m_audio_frame_buffer, AUDIO_BUF_SIZE, MAX_AUDIO_BUF_SIZE);
	picture_.mutex_ = SDL_CreateMutex();
	picture_.condition_ = SDL_CreateCond();

	if (HasVideo())
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
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

		screen = SDL_CreateWindowFrom(m_hMainWindow);
		sdlRenderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_TARGETTEXTURE);
		picture_.texture_ = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STREAMING, m_videoCodecContext->width, m_videoCodecContext->height);

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
		SDL_memset(&m_audioDesiredSpec, 0, sizeof(m_audioDesiredSpec));
		m_audioDesiredSpec.channels = m_audioCodecContext->channels;
		m_audioDesiredSpec.freq = m_audioCodecContext->sample_rate;
		m_audioDesiredSpec.format = AUDIO_S16;
		m_audioDesiredSpec.silence = 0;
		m_audioDesiredSpec.samples = 1024;
		m_audioDesiredSpec.callback = AudioCallback;
		m_audioDesiredSpec.userdata = this;
		SDL_OpenAudio(&m_audioDesiredSpec, &m_audioSpec);
		SDL_PauseAudio(0);
	}

	return TRUE;
}

void CPlayerSdl::AudioCallback(void* userdata, uint8_t* stream, int len) {
	assert(userdata != NULL);

	CPlayerSdl* pPlayer_sdl = static_cast<CPlayerSdl*>(userdata);
	RingBufferRead(&pPlayer_sdl->m_audio_frame_buffer, stream, len, 1);
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

double CPlayerSdl::SynchronizeVideo(CPlayerSdl* pPlayerSdl, AVFrame* frame, double pts)
{
	assert(pPlayerSdl != NULL);
	assert(frame != NULL);

	if (pts != 0) {
		/* if we have pts, set video clock to it */
		pPlayerSdl->video_clock = pts;
	}
	else {
		/* if we aren't given a pts, set it to the clock */
		pts = pPlayerSdl->video_clock;
	}
	/* update the video clock */
	double frame_delay = av_q2d(pPlayerSdl->m_videoCodecContext->time_base);
	/* if we are repeating a frame, adjust clock accordingly */
	frame_delay += frame->repeat_pict * (frame_delay * 0.5);
	pPlayerSdl->video_clock += frame_delay;

	return pts;
}

int CPlayerSdl::VideoDecodeSdlThread(void* opaque)
{
	assert(opaque != nullptr);
	CPlayerSdl* pPlayerSdl = static_cast<CPlayerSdl*>(opaque);
	AVFrame *frame;
	AVPacket packet;
	int frame_finished;
	double pts;
	while (!pPlayerSdl->m_quit){
		av_init_packet(&packet);
		frame = av_frame_alloc();
		if (PacketQueuePop(&pPlayerSdl->m_video_packet_queue, &packet, 1) < 0){
			//eof queue
			break;
		}

		avcodec_decode_video2(pPlayerSdl->m_videoCodecContext, frame, &frame_finished, &packet);
		if ((pts = av_frame_get_best_effort_timestamp(frame)) == AV_NOPTS_VALUE) {
			pts = 0;
		}
		pts *= av_q2d(pPlayerSdl->m_format_context->streams[pPlayerSdl->m_videoStreamIndex]->time_base);
		av_free_packet(&packet);
		if (frame_finished){
			pPlayerSdl->picture_.pts_ = SynchronizeVideo(pPlayerSdl, frame, pts);

			// Wait until picture is released
			SDL_LockMutex(pPlayerSdl->picture_.mutex_);
			while (pPlayerSdl->picture_.ready_ && !pPlayerSdl->m_quit) {
				SDL_CondWait(pPlayerSdl->picture_.condition_, pPlayerSdl->picture_.mutex_);
			}
			SDL_UnlockMutex(pPlayerSdl->picture_.mutex_);

			if (pPlayerSdl->m_quit) {
				break;
			}
			SDL_UpdateYUVTexture(pPlayerSdl->picture_.texture_, nullptr, frame->data[0], frame->linesize[0], frame->data[1], frame->linesize[1], frame->data[2], frame->linesize[2]);
			SDL_LockMutex(pPlayerSdl->picture_.mutex_);
			pPlayerSdl->picture_.ready_ = 1;
			SDL_CondSignal(pPlayerSdl->picture_.condition_);
			SDL_UnlockMutex(pPlayerSdl->picture_.mutex_);
		}
		//lastPts = currentPts;
		av_frame_free(&frame);
	}
	return 0;
}

int CPlayerSdl::AudioDecodeSdlThread(void* opaque)
{
	assert(opaque != NULL);

	CPlayerSdl* pPlayerSdl = static_cast<CPlayerSdl*>(opaque);
	AVCodecContext* audio_codec_context = pPlayerSdl->m_format_context->streams[pPlayerSdl->m_audioStreamIndex]->codec;

	AVFrame* frame = av_frame_alloc();
	while (!pPlayerSdl->m_quit) {
		// Get packet from queue
		AVPacket packet;
		if (PacketQueuePop(&pPlayerSdl->m_audio_packet_queue, &packet, 1) < 0) {
			// eof queue
			break;
		}

		// The audio packet can contain several frames
		int got_frame;
		int len = avcodec_decode_audio4(audio_codec_context, frame, &got_frame, &packet);
		if (len < 0) {
			av_free_packet(&packet);
			fprintf(stderr, "Failed to decode audio frame\n");
			break;
		}

		if (got_frame) {
			// Store frame
			// Get decoded buffer size
			int data_size = av_samples_get_buffer_size(nullptr, audio_codec_context->channels, frame->nb_samples, audio_codec_context->sample_fmt, 1);

			// Obtain audio clock
			if (packet.pts != AV_NOPTS_VALUE) {
				pPlayerSdl->audio_clock = av_q2d(pPlayerSdl->m_format_context->streams[pPlayerSdl->m_audioStreamIndex]->time_base) * packet.pts;
			}
			else {
				/* if no pts, then compute it */
				pPlayerSdl->audio_clock += static_cast<double>(data_size) /
					(audio_codec_context->channels *
					audio_codec_context->sample_rate *
					av_get_bytes_per_sample(audio_codec_context->sample_fmt));
			}
			RingBufferWrite(&pPlayerSdl->m_audio_frame_buffer, frame->data[0], data_size, 1);
		}
		av_free_packet(&packet);
	}
	av_frame_free(&frame);
	RingBufferEof(&pPlayerSdl->m_audio_frame_buffer);
	return 0;
}

uint32_t CPlayerSdl::SdlRefreshTimer(uint32_t interval, void *opaque) {
	SDL_Event event;
	event.type = FF_REFRESH_EVENT;
	event.user.data1 = opaque;
	SDL_PushEvent(&event);
	return 0;
}

void CPlayerSdl::ScheduleRefresh(CPlayerSdl* pPlayerSdl, int delay) {
	assert(pPlayerSdl != nullptr);
	assert(delay > 0.0);

	SDL_AddTimer(delay, SdlRefreshTimer, pPlayerSdl);
}

double CPlayerSdl::GetExternalClock()
{
	return av_gettime() / AV_TIME_BASE;
}

double CPlayerSdl::GetVideoClock(CPlayerSdl* pPlayerSdl)
{
	assert(pPlayerSdl != nullptr);
	double delta;
	delta = (av_gettime() - pPlayerSdl->video_current_pts_time) / AV_TIME_BASE;
	return pPlayerSdl->video_current_pts + delta;
}

double CPlayerSdl::GetAudioClock(CPlayerSdl* pPlayerSdl) {

	assert(pPlayerSdl != NULL);

	AVCodecContext* audio_codec_context = pPlayerSdl->m_format_context->streams[pPlayerSdl->m_audioStreamIndex]->codec;
	double pts = pPlayerSdl->audio_clock;

	int bytes_per_sec = audio_codec_context->sample_rate *
		audio_codec_context->channels *
		av_get_bytes_per_sample(audio_codec_context->sample_fmt);
	int buffer_size = RingBufferSize(&pPlayerSdl->m_audio_frame_buffer);

	if (bytes_per_sec != 0) {
		pts -= static_cast<double>(buffer_size) / bytes_per_sec;
	}

	return pts;
}

double CPlayerSdl::ComputeDelay(CPlayerSdl* pPlayerSdl) {
	pPlayerSdl->video_current_pts = pPlayerSdl->picture_.pts_;
	pPlayerSdl->video_current_pts_time = av_gettime();
	double delay = pPlayerSdl->picture_.pts_ - pPlayerSdl->frame_last_pts;
	if (delay <= 0.0 || delay >= 1.0) {
		// Delay incorrect - use previous one
		delay = pPlayerSdl->frame_last_delay;
	}
	// Save for next time
	pPlayerSdl->frame_last_pts = pPlayerSdl->picture_.pts_;
	pPlayerSdl->frame_last_delay = delay;

	// Update delay to sync to audio
	double ref_clock = GetExternalClock();
	double diff = pPlayerSdl->picture_.pts_ - ref_clock;
	double sync_threshold = FFMAX(AV_SYNC_THRESHOLD, delay);
	if (fabs(diff) < AV_NOSYNC_THRESHOLD) {
		if (diff <= -sync_threshold) {
			delay = 0;
		}
		else if (diff >= sync_threshold) {
			delay = 2 * delay;
		}
	}

	pPlayerSdl->frame_timer += delay;

	double actual_delay = pPlayerSdl->frame_timer - (av_gettime() / 1000000.0);
	if (actual_delay < 0.010) {
		/* Really it should skip the picture instead */
		actual_delay = 0.010;
	}
	return actual_delay;
}

void CPlayerSdl::VideoDisplay(CPlayerSdl* pPlayerSdl) {
	SDL_RenderClear(pPlayerSdl->sdlRenderer);
	SDL_RenderCopy(pPlayerSdl->sdlRenderer, pPlayerSdl->picture_.texture_, nullptr, nullptr);
	SDL_RenderPresent(pPlayerSdl->sdlRenderer);
}

void CPlayerSdl::VideoRefreshTimer(CPlayerSdl* pPlayerSdl) {	
	if (pPlayerSdl->m_video_packet_queue.size == 0){
		ScheduleRefresh(pPlayerSdl, 1);
	}
	else{
		double delay = ComputeDelay(pPlayerSdl);
		ScheduleRefresh(pPlayerSdl, static_cast<int>(delay * 1000 + 0.5));
		// Show the picture
		VideoDisplay(pPlayerSdl);
		SDL_LockMutex(pPlayerSdl->picture_.mutex_);
		pPlayerSdl->picture_.ready_ = 0;
		SDL_CondSignal(pPlayerSdl->picture_.condition_);
		SDL_UnlockMutex(pPlayerSdl->picture_.mutex_);
	}
}

void CPlayerSdl::Quit(CPlayerSdl* pPlayerSdl) {
	SDL_PauseAudio(1);
	SDL_CloseAudio();
	pPlayerSdl->m_quit = true;
	SDL_CondBroadcast(pPlayerSdl->picture_.condition_);
}

void CPlayerSdl::EventLoop(CPlayerSdl* pPlayerSdl) {
	assert(pPlayerSdl != NULL);

	SDL_Event event;
	while (!pPlayerSdl->m_quit) {
		SDL_WaitEvent(&event);
		switch (event.type) {
			case SDL_QUIT:
				Quit(pPlayerSdl);
				break;
			case FF_REFRESH_EVENT:
				VideoRefreshTimer(pPlayerSdl);
				break;
			case SDL_WINDOWEVENT:
				switch (event.window.event){
					case SDL_WINDOWEVENT_RESIZED:
						VideoRefreshTimer(pPlayerSdl);
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
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

void CPlayerSdl::Clear()
{
	PacketQueueDeinit(&m_video_packet_queue);
	PacketQueueDeinit(&m_audio_packet_queue);
	RingBufferDeinit(&m_audio_frame_buffer);

	SDL_DestroyTexture(picture_.texture_);
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyMutex(picture_.mutex_);
	SDL_DestroyCond(picture_.condition_);
	if (m_options)
		av_dict_free(&m_options);
	if (m_videoCodecContext)
		avcodec_close(m_videoCodecContext);
	if (m_audioCodecContext)
		avcodec_close(m_audioCodecContext);
	if (m_format_context)
		avformat_close_input(&m_format_context);
}

BOOL CPlayerSdl::Play()
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
	std::thread([this]{
		frame_timer = static_cast<double>(av_gettime()) / 1000000.0;
		frame_last_delay = 0.04;
		video_current_pts_time = av_gettime();

		demux_sdl_thread_ = ThreadStart(DemuxSdlThread, this, "demux");
		video_decode_sdl_thread_ = ThreadStart(VideoDecodeSdlThread, this, "video_decode");
		if (HasAudio())
			audio_decode_sdl_thread_ = ThreadStart(AudioDecodeSdlThread, this, "audio_decode");

		ScheduleRefresh(this, 40);

		EventLoop(this);

		ThreadWait(demux_sdl_thread_, "demux");
		ThreadWait(video_decode_sdl_thread_, "video_decode");
		if (HasAudio())
			ThreadWait(audio_decode_sdl_thread_, "audio_decode");

		Clear();
		SDL_Quit();

	}).detach();
	return TRUE;
}

BOOL CPlayerSdl::Stop()
{
	return SDL_QUIT;
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

void CPlayerSdl::RingBufferDeinit(RingBuffer* rb)
{
	assert(rb != NULL);
	assert(rb->mutex != NULL);
	assert(rb->rcond != NULL);
	assert(rb->wcond != NULL);

	SDL_DestroyMutex(rb->mutex);
	SDL_DestroyCond(rb->rcond);
	SDL_DestroyCond(rb->wcond);
}

int CPlayerSdl::RingBufferWrite(RingBuffer* rb, void* buffer, int len, int block)
{
	assert(rb != NULL);
	assert(rb != NULL);

	if (len == 0) {
		return 0;
	}

	SDL_LockMutex(rb->mutex);

	if (rb->eof) {
		// Buffer ended
		SDL_UnlockMutex(rb->mutex);
		return -1;
	}

	uint8_t* buffer_ptr = static_cast<uint8_t*>(buffer);
	while (len > 0) {
		int step;
		if ((rb->rindex < rb->windex) ||  // write forward
			((rb->rindex == rb->windex) && (rb->lastop == 0))) {  // buffer must be free
			step = rb->size - rb->windex;
		}
		else if (rb->rindex > rb->windex) {
			step = rb->rindex - rb->windex;
		}
		else if (block) {
			SDL_CondWait(rb->rcond, rb->mutex);
			if (rb->eof) {
				break;
			}
			continue;
		}
		else {
			break;
		}

		if (len < step) {
			step = len;
		}
		memcpy(rb->data + rb->windex, buffer_ptr, step);

		rb->windex += step;
		assert(rb->windex <= rb->size);
		if (rb->windex == rb->size) {
			rb->windex = 0;
		}
		rb->lastop = 1;
		SDL_CondSignal(rb->wcond);

		buffer_ptr += step;
		len -= step;
	}

	SDL_UnlockMutex(rb->mutex);
	return buffer_ptr - static_cast<uint8_t*>(buffer);
}

int CPlayerSdl::RingBufferRead(RingBuffer* rb, void* buffer, int len, int block)
{
	assert(rb != NULL);
	assert(buffer != NULL);

	if (len == 0) {
		return 0;
	}

	SDL_LockMutex(rb->mutex);

	uint8_t* buffer_ptr = static_cast<uint8_t*>(buffer);
	while (len > 0) {
		int step;
		if (rb->rindex < rb->windex) {  // write forward
			step = rb->windex - rb->rindex;
		}
		else if ((rb->rindex > rb->windex) ||  // read forward
			((rb->rindex == rb->windex) && (rb->lastop == 1))) {  // buffer must be full
			step = rb->size - rb->rindex;
		}
		else if (block && !rb->eof) {
			SDL_CondWait(rb->wcond, rb->mutex);
			continue;
		}
		else {
			break;
		}

		if (len < step) {
			step = len;
		}
		memcpy(buffer_ptr, rb->data + rb->rindex, step);

		rb->rindex += step;
		assert(rb->rindex <= rb->size);
		if (rb->rindex == rb->size) {
			rb->rindex = 0;
		}
		rb->lastop = 0;
		SDL_CondSignal(rb->rcond);

		buffer_ptr += step;
		len -= step;
	}

	int count = buffer_ptr - static_cast<uint8_t*>(buffer);
	if ((count == 0) && rb->eof) {
		count = -1;
	}

	SDL_UnlockMutex(rb->mutex);
	return count;
}

int CPlayerSdl::RingBufferSize(RingBuffer* rb)
{
	assert(rb != NULL);

	int size;
	SDL_LockMutex(rb->mutex);
	if (rb->rindex < rb->windex) {
		size = rb->windex - rb->rindex;
	}
	else {
		size = rb->size - rb->rindex + rb->windex;
	}
	SDL_UnlockMutex(rb->mutex);
	return size;
}

void CPlayerSdl::RingBufferEof(RingBuffer* rb)
{
	assert(rb != NULL);

	SDL_LockMutex(rb->mutex);
	rb->eof = 1;
	SDL_CondBroadcast(rb->wcond);
	SDL_UnlockMutex(rb->mutex);
}
