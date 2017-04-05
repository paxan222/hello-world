#include "Player.h"

void CPlayerSdl::Log(std::string message)
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
	std::clog << message << "\n";
}

void CPlayerSdl::LogAv(int ret)
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
	char err_buf[255];
	av_strerror(ret, err_buf, sizeof(err_buf));
	std::clog << err_buf << "\n";
}

BOOL CPlayerSdl::OpenStream()
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
	Log("OpenStream has called");
	Log(m_filename);
	static CAVInitializer sAVInit;

	if (m_filename.find("rtsp://") != std::string::npos)
	{
		//m_online = true;
		if (0 > av_dict_set(&m_options, "rtsp_transport", "tcp", 0))
		{
			LogAv(AVERROR(ENOMEM));
			return FALSE;
		}
	}
	else
	{
		m_online = false;
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
	picture.mutex = SDL_CreateMutex();
	picture.condition = SDL_CreateCond();
	render_mutex = SDL_CreateMutex();
	av_init_packet(&flush_pkt);
	flush_pkt.data = reinterpret_cast<uint8_t*>("FLUSH");

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

		sdlWindow = SDL_CreateWindowFrom(m_hMainWindow);
		assert(sdlWindow != nullptr);
		sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_TARGETTEXTURE);
		assert(sdlRenderer != nullptr);
		picture.texture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STREAMING, m_videoCodecContext->width, m_videoCodecContext->height);
		assert(picture.texture != nullptr);
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
		m_audioDesiredSpec.format = AUDIO_S16SYS;
		m_audioDesiredSpec.silence = 0;
		m_audioDesiredSpec.samples = FFMAX(SDL_AUDIO_MIN_BUFFER_SIZE, 2 << av_log2(m_audioDesiredSpec.freq / SDL_AUDIO_MAX_CALLBACKS_PER_SEC));
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
	RingBufferRead(&pPlayer_sdl->m_audio_frame_buffer, stream, len, 1, true);
}

int CPlayerSdl::DemuxSdlThread(void *opaque)
{
	assert(opaque != nullptr);
	CPlayerSdl* pPlayerSdl = static_cast<CPlayerSdl*>(opaque);
	int video_stream_index = pPlayerSdl->m_videoStreamIndex;
	int audio_stream_index = pPlayerSdl->m_audioStreamIndex;
	AVPacket packet;
	FILE *file = fopen("D:\\test.txt", "w");
	while (!pPlayerSdl->m_quit){
		if (pPlayerSdl->seek_req){
			int stream_index = -1;
			int64_t seek_target = pPlayerSdl->seek_pos;

			if (pPlayerSdl->m_videoStreamIndex >= 0)
				stream_index = pPlayerSdl->m_videoStreamIndex;

			if (stream_index >= 0){
				AVRational avtimebaseq = { 1, AV_TIME_BASE };
				seek_target = av_rescale_q(seek_target, avtimebaseq, pPlayerSdl->m_format_context->streams[stream_index]->time_base);
			}
			if (avformat_seek_file(pPlayerSdl->m_format_context, stream_index, INT64_MIN, seek_target, INT64_MAX, pPlayerSdl->seek_flags) < 0){
				pPlayerSdl->Log("Couldn't seek file");
			}
			else {
				std::string message = "SeekTarget: " + std::to_string(seek_target);
				pPlayerSdl->Log(message);
				if (pPlayerSdl->m_audioStreamIndex >= 0) {
					PacketQueueFlush(&pPlayerSdl->m_audio_packet_queue);
					PacketQueuePush(&pPlayerSdl->m_audio_packet_queue, &pPlayerSdl->flush_pkt);
				}
				if (pPlayerSdl->m_videoStreamIndex >= 0) {
					PacketQueueFlush(&pPlayerSdl->m_video_packet_queue);
					PacketQueuePush(&pPlayerSdl->m_video_packet_queue, &pPlayerSdl->flush_pkt);
				}
			}
			pPlayerSdl->seek_req = 0;
		}

		if (pPlayerSdl->m_video_packet_queue.size > 1 * 1024 * 1024 || //100 310 720
			pPlayerSdl->m_audio_packet_queue.size > 2 * 1024 * 1024) {  //81 920
			SDL_Delay(10);
			continue;
		}
		int ret = av_read_frame((pPlayerSdl->m_format_context), &packet);
		if ((ret == AVERROR_EOF || avio_feof(pPlayerSdl->m_format_context->pb))) {
			pPlayerSdl->LogAv(AVERROR(ENOMEM));
			break;	// Eof or error
		}
		if (packet.stream_index == video_stream_index){
			std::string mes = "Video: " + std::to_string(packet.pts) + "\n";
			PacketQueuePush(&pPlayerSdl->m_video_packet_queue, &packet);
			fprintf(file, mes.c_str());
		}
		else{
			if (packet.stream_index == audio_stream_index && pPlayerSdl->HasAudio()){
				std::string mes = "Audio: " + std::to_string(packet.pts) + "\n";
				PacketQueuePush(&pPlayerSdl->m_audio_packet_queue, &packet);
				fprintf(file, mes.c_str());
			}
			else{
				av_packet_unref(&packet);
				av_free_packet(&packet);
			}
		}
	}
	av_packet_unref(&packet);
	av_free_packet(&packet);
	fclose(file);
	PacketQueueEof(&pPlayerSdl->m_video_packet_queue);
	PacketQueueEof(&pPlayerSdl->m_audio_packet_queue);
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
		if ((PacketQueuePop(&pPlayerSdl->m_video_packet_queue, &packet, 1) < 0) && pPlayerSdl->m_video_packet_queue.eof){
			//eof queue
			break;
		}
		if (!pPlayerSdl->m_renderOn){
			av_free_packet(&packet);
			av_frame_free(&frame);
			continue;
		}
		avcodec_decode_video2(pPlayerSdl->m_videoCodecContext, frame, &frame_finished, &packet);
		if ((pts = av_frame_get_best_effort_timestamp(frame)) == AV_NOPTS_VALUE) {
			pts = 0;
		}
		pts *= av_q2d(pPlayerSdl->m_format_context->streams[pPlayerSdl->m_videoStreamIndex]->time_base);
		if (frame_finished){
			pPlayerSdl->picture.pts = SynchronizeVideo(pPlayerSdl, frame, pts);

			// Wait until picture is released
			SDL_LockMutex(pPlayerSdl->picture.mutex);
			while (pPlayerSdl->picture.ready && !pPlayerSdl->m_quit) {
				SDL_CondWait(pPlayerSdl->picture.condition, pPlayerSdl->picture.mutex);
			}
			SDL_UnlockMutex(pPlayerSdl->picture.mutex);

			if (pPlayerSdl->m_quit) {
				break;
			}
			SDL_LockMutex(pPlayerSdl->render_mutex);
			SDL_UpdateYUVTexture(pPlayerSdl->picture.texture, nullptr, frame->data[0], frame->linesize[0], frame->data[1], frame->linesize[1], frame->data[2], frame->linesize[2]);
			SDL_UnlockMutex(pPlayerSdl->render_mutex);
			SDL_LockMutex(pPlayerSdl->picture.mutex);
			pPlayerSdl->picture.ready = 1;
			SDL_CondSignal(pPlayerSdl->picture.condition);
			SDL_UnlockMutex(pPlayerSdl->picture.mutex);
		}
		//lastPts = currentPts;
		av_frame_free(&frame);
	}
	if (pPlayerSdl->HasAudio())
		SDL_PauseAudio(1);
	return 0;
}

int CPlayerSdl::AudioDecodeSdlThread(void* opaque)
{
	assert(opaque != NULL);

	CPlayerSdl* pPlayerSdl = static_cast<CPlayerSdl*>(opaque);

	AVFrame* frame = av_frame_alloc();
	AVFrame* resample_frame = av_frame_alloc();
	SwrContext *swr_context = swr_alloc();

	while (!pPlayerSdl->m_quit) {
		// Get packet from queue
		AVPacket packet;
		if ((PacketQueuePop(&pPlayerSdl->m_audio_packet_queue, &packet, 1) < 0) && pPlayerSdl->m_audio_packet_queue.eof){
			// eof queue
			break;
		}
		if (!pPlayerSdl->m_renderOn){
			av_free_packet(&packet);
			continue;
		}
		if (packet.data == pPlayerSdl->flush_pkt.data) {
			avcodec_flush_buffers(pPlayerSdl->m_audioCodecContext);
			continue;
		}
		// The audio packet can contain several frames
		int got_frame;
		int len = avcodec_decode_audio4(pPlayerSdl->m_audioCodecContext, frame, &got_frame, &packet);
		if (len < 0) {
			av_free_packet(&packet);
			break;
		}

		if (got_frame) {
			// Store frame
			// Get decoded buffer size
			int data_size = av_samples_get_buffer_size(nullptr, av_frame_get_channels(frame), frame->nb_samples, static_cast<AVSampleFormat>(frame->format), 1);
			frame->channel_layout = !pPlayerSdl->m_audioCodecContext->channel_layout ? av_get_default_channel_layout(pPlayerSdl->m_audioCodecContext->channels) : pPlayerSdl->m_audioCodecContext->channel_layout;
			resample_frame->channel_layout = frame->channel_layout;
			resample_frame->sample_rate = frame->sample_rate;
			resample_frame->format = AV_SAMPLE_FMT_S16;
			swr_convert_frame(swr_context, resample_frame, frame);
			//data_size = len * frame->channels * av_get_bytes_per_sample(AV_SAMPLE_FMT_S16);
			data_size = av_samples_get_buffer_size(nullptr, av_frame_get_channels(resample_frame), resample_frame->nb_samples, static_cast<AVSampleFormat>(resample_frame->format), 1);
			// Obtain audio clock
			RingBufferWrite(&pPlayerSdl->m_audio_frame_buffer, resample_frame->data[0], data_size, 1);
		}
	}
	av_frame_free(&frame);
	av_frame_free(&resample_frame);
	swr_free(&swr_context);
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
	//assert(delay > 0.0);
	if (pPlayerSdl->m_online)
		delay = 0;
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

double CPlayerSdl::ComputeDelay(CPlayerSdl* pPlayerSdl) {
	pPlayerSdl->video_current_pts = pPlayerSdl->picture.pts;
	pPlayerSdl->video_current_pts_time = av_gettime();
	double delay = pPlayerSdl->picture.pts - pPlayerSdl->frame_last_pts;
	if (delay <= 0.0 || delay >= 1.0) {
		// Delay incorrect - use previous one
		delay = pPlayerSdl->frame_last_delay;
	}
	// Save for next time
	pPlayerSdl->frame_last_pts = pPlayerSdl->picture.pts;
	pPlayerSdl->frame_last_delay = delay;

	// Update delay to sync to audio
	double ref_clock = GetExternalClock();
	double diff = pPlayerSdl->picture.pts - ref_clock;
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

	SDL_LockMutex(pPlayerSdl->render_mutex);
	SDL_RenderClear(pPlayerSdl->sdlRenderer);
	SDL_RenderCopy(pPlayerSdl->sdlRenderer, pPlayerSdl->picture.texture, nullptr, nullptr);
	SDL_RenderPresent(pPlayerSdl->sdlRenderer);
	SDL_UnlockMutex(pPlayerSdl->render_mutex);
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
		SDL_LockMutex(pPlayerSdl->picture.mutex);
		pPlayerSdl->picture.ready = 0;
		SDL_CondSignal(pPlayerSdl->picture.condition);
		SDL_UnlockMutex(pPlayerSdl->picture.mutex);
	}
}

void CPlayerSdl::Quit(CPlayerSdl* pPlayerSdl) {
	pPlayerSdl->m_quit = true;
	SDL_CondBroadcast(pPlayerSdl->picture.condition);
}

void CPlayerSdl::StreamSeek(CPlayerSdl* pPlayerSdl, int64_t pos, int rel)
{
	if (!pPlayerSdl->seek_req) {
		pPlayerSdl->seek_pos = pos;
		pPlayerSdl->seek_flags = rel < 0 ? AVSEEK_FLAG_BACKWARD : 0;
		pPlayerSdl->seek_req = 1;
		auto message = "SeekPos: " + std::to_string(pos);
		pPlayerSdl->Log(message);
	}
}

void CPlayerSdl::EventLoop(CPlayerSdl* pPlayerSdl) {
	assert(pPlayerSdl != NULL);
	SDL_Event event;
	double incr, pos;
	HWND overlap_window_hwnd;
	HWND main_window_hwnd = pPlayerSdl->m_hMainWindow;
	RECT main_window_rect;
	RECT overlap_window_rect;
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
						SDL_LockMutex(pPlayerSdl->render_mutex);
						SDL_DestroyTexture(pPlayerSdl->picture.texture);
						SDL_DestroyRenderer(pPlayerSdl->sdlRenderer);
						pPlayerSdl->sdlRenderer = SDL_CreateRenderer(pPlayerSdl->sdlWindow, -1, SDL_RENDERER_TARGETTEXTURE);
						pPlayerSdl->picture.texture = SDL_CreateTexture(pPlayerSdl->sdlRenderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STREAMING, pPlayerSdl->m_videoCodecContext->width, pPlayerSdl->m_videoCodecContext->height);
						SDL_UnlockMutex(pPlayerSdl->render_mutex);
						VideoRefreshTimer(pPlayerSdl);
						break;
					case SDL_WINDOWEVENT_MINIMIZED:
						pPlayerSdl->m_renderOn = false;
						break;
					case SDL_WINDOWEVENT_RESTORED:
						pPlayerSdl->m_renderOn = true;
						break;/*
					default:
					VideoRefreshTimer(pPlayerSdl);
					break;*/
				}
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_LEFT:
						incr = -10.0;
						goto do_seek;
					case SDLK_RIGHT:
						incr = 10.0;
						goto do_seek;
					do_seek:
						pos = GetVideoClock(pPlayerSdl);
						pos += incr;
						StreamSeek(pPlayerSdl, static_cast<int64_t>(pos*AV_TIME_BASE), incr);
						break;
					default:
						break;
				}
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
	SDL_PauseAudio(1);
	SDL_CloseAudio();
	SDL_UnlockMutex(render_mutex);
	SDL_DestroyTexture(picture.texture);
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyMutex(picture.mutex);
	SDL_DestroyCond(picture.condition);
	SDL_DestroyMutex(render_mutex);
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
		video_current_pts_time = av_gettime();

		demux_sdl_thread = ThreadStart(DemuxSdlThread, this, "demux");
		video_decode_sdl_thread = ThreadStart(VideoDecodeSdlThread, this, "video_decode");
		if (HasAudio())
			audio_decode_sdl_thread = ThreadStart(AudioDecodeSdlThread, this, "audio_decode");

		ScheduleRefresh(this, 40);

		EventLoop(this);

		ThreadWait(demux_sdl_thread, "demux");
		ThreadWait(video_decode_sdl_thread, "video_decode");
		if (HasAudio())
			ThreadWait(audio_decode_sdl_thread, "audio_decode");

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
	//return FALSE;
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
	if (pkt->data != reinterpret_cast<uint8_t*>("FLUSH") && av_dup_packet(pkt) < 0) {
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

void CPlayerSdl::PacketQueueFlush(PacketQueue *q) {
	AVPacketList *pkt, *pkt1;

	SDL_LockMutex(q->mutex);
	for (pkt = q->first_pkt; pkt != nullptr; pkt = pkt1) {
		pkt1 = pkt->next;
		av_free_packet(&pkt->pkt);
		av_freep(&pkt);
	}
	q->last_pkt = nullptr;
	q->first_pkt = nullptr;
	q->nb_packets = 0;
	q->size = 0;
	SDL_UnlockMutex(q->mutex);
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
	if (rb->data == nullptr) {
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

int CPlayerSdl::RingBufferRead(RingBuffer* rb, void* buffer, int len, int block, bool soundOn)
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
		if (soundOn)
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
