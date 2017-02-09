#include "stdafx.h"
#include "RtspPlayer.h"

#pragma comment(lib, "SDL2")
#ifdef _DEBUG
#endif

//std::wstring StringToWString(const std::string& s)
//{
//	int len;
//	int slength = (int)s.length() + 1;
//	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
//	wchar_t* buf = new wchar_t[len];
//	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
//	std::wstring r(buf);
//	delete[] buf;
//	return r;
//}

BOOL CRtspPlayer::Open(){
	OpenNew();
	//Initialization CodecContext, Codec
	InitNew();
	return TRUE;
}
//Open stream
BOOL CRtspPlayer::OpenNew(){
	//LOG(INFO) << "StartOpen";
	//Register all av libs
	av_register_all();
	//Parse m_filename and set up parametr "rtsp_transport" to value"tcp" (all packets received guarantee)
	if (m_fileName.find("rtsp://") != std::string::npos)
	{
		if (0 > av_dict_set(&m_options, "rtsp_transport", "tcp", 0)){
			//LOG(ERROR) << "AvDictionary failed to set up!";
			return FALSE;
		}
	}
	else
	{
		m_options = nullptr;
	}
	//Open the input
	if (avformat_open_input(&m_fmtCtx, m_fileName.c_str(), nullptr, &m_options) < 0){
		//LOG(ERROR) << "AvFormat Open Input error!";
		return FALSE;
	}
	//Find stream info
	if (avformat_find_stream_info(m_fmtCtx, nullptr) < 0){
		//LOG(ERROR) << "AvFormat Find StreamInfo error!";
		return FALSE;
	}
	//Dump format
	av_dump_format(m_fmtCtx, 0, m_fileName.c_str(), 0);
	//LOG(INFO) << "StopOpen";
	return TRUE;
}
//Init
BOOL CRtspPlayer::InitNew(){
	//LOG(INFO) << "StartInit";
	FindBestStreamNew();
	FindDecoderNew();
	PacketQueueInit(&m_videoq);
	PacketQueueInit(&m_audioq);
	//Initialize SDL Audio
	if (hasAudioNew())
	{
		ConfigAudioNew();
		if (SDL_OpenAudio(&m_audioWantedSpec, &m_audioSpec) < 0){
			//LOG(ERROR) << "SDL couldn't open audio: " << SDL_GetError();
			throw::exception();
		}
		SDL_PauseAudio(0);
	}
	m_scaleCtx = sws_getCachedContext(nullptr,
		m_width,
		m_height,
		*m_pixFmt,
		m_width,
		m_height,
		m_dstPixFmt,
		SWS_FAST_BILINEAR,
		nullptr,
		nullptr,
		nullptr);
	frame_timer = (double)av_gettime() / 1000000.0;
	ThreadStartNew();
	//LOG(INFO) << "StopInit";
	return TRUE;
}
//StreamsDetect
void CRtspPlayer::FindBestStreamNew(){
	//LOG(INFO) << "StartFindBestStream";
	//Find videoStream
	m_videoStreamIndex = av_find_best_stream(m_fmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (m_videoStreamIndex < 0){
		//LOG(INFO) << "Video stream did not found!";
		throw::exception("VideoStream did not found");
	}
	//Find
	m_audioStreamIndex = av_find_best_stream(m_fmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (m_audioStreamIndex < 0){
		//LOG(INFO) << "Audio stream did not found!";
	}
	//LOG(INFO) << "StopFindBestStream";
}
//Has Video flag
bool CRtspPlayer::hasVideoNew(){
	return m_videoStreamIndex >= 0;
}
//Has audio flag
bool CRtspPlayer::hasAudioNew(){
	//return m_audioStreamIndex >= 0;
	return FALSE;
}
//Find codec for stream
void CRtspPlayer::FindDecoderNew(){
	//LOG(INFO) << "StartFindDecoder";
	if (hasVideoNew())
	{
		m_videoCodecCtx = m_fmtCtx->streams[m_videoStreamIndex]->codec;
		m_videoCodec = avcodec_find_decoder(m_videoCodecCtx->codec_id);

		if (m_videoCodec == nullptr){
			//LOG(ERROR) << "Can't find video codec";
			throw::exception();
		}
		m_videoCodecCtx->refcounted_frames = 1;
		if (avcodec_open2(m_videoCodecCtx, m_videoCodec, nullptr) < 0){
			//LOG(ERROR) << "Can't open video codec";
			throw std::exception();
		}

		m_width = m_videoCodecCtx->width;
		m_height = m_videoCodecCtx->height;
		m_fps = av_q2d(av_guess_frame_rate(m_fmtCtx, m_fmtCtx->streams[m_videoStreamIndex], nullptr));
		m_pixFmt = &m_videoCodecCtx->pix_fmt;
	}
	if (hasAudioNew())
	{
		m_audioCodecCtx = m_fmtCtx->streams[m_audioStreamIndex]->codec;
		m_audioCodec = avcodec_find_decoder(m_audioCodecCtx->codec_id);

		if (m_audioCodec == nullptr){
			//LOG(ERROR) << "Can't find audio codec";
			throw::exception();
		}
		m_audioCodecCtx->refcounted_frames = 1;
		if (avcodec_open2(m_audioCodecCtx, m_audioCodec, nullptr) < 0){
			//LOG(ERROR) << "Can't open audio codec";
			throw std::exception();
		}
	}
	//LOG(INFO) << "StopFindDecoder";
}
//AudioCallback
void CRtspPlayer::AudioCallbackNew(uint8_t* stream, int len){
	RingBufferRead(&m_audioBuffer, stream, len, 1);
}
//Init SDL_AudioSpec
void CRtspPlayer::ConfigAudioNew(){
	//LOG(INFO) << "StartInitAudio";
	if (SDL_Init(SDL_INIT_AUDIO) < 0){
		//LOG(ERROR) << "SDL couldn't init audio: " << SDL_GetError();
		throw::exception();
	}
	m_audioWantedSpec.freq = m_audioCodecCtx->sample_rate;
	m_audioWantedSpec.format = AUDIO_S16SYS;
	m_audioWantedSpec.channels = m_audioCodecCtx->channels;
	m_audioWantedSpec.silence = 0;
	m_audioWantedSpec.samples = SDL_AUDIO_BUFFER_SIZE;
	//m_audioWantedSpec.callback = AudioCallbackNew;
	m_audioWantedSpec.userdata = this;
	//LOG(INFO) << "StopInitAudio";
}
//Demuxer
void CRtspPlayer::DemuxerNew(){
	std::thread([this]{
		//LOG(INFO) << "StartDemuxer";
		AVPacket packet;
		while (av_read_frame(m_fmtCtx, &packet) >= 0){
			if (m_quit){
				av_free_packet(&packet);
				break;
			}
			if (packet.stream_index == m_videoStreamIndex){
				//LOG(INFO) << "PUSH";
				PacketQueuePush(&m_videoq, &packet);
			}
			else{
				if (packet.stream_index == m_audioStreamIndex){
					PacketQueuePush(&m_audioq, &packet);
				}
				else{
					av_free_packet(&packet);
				}
			}
		}
		PacketQueueEof(&m_videoq);
		PacketQueueEof(&m_audioq);
		//LOG(INFO) << "StopDemuxer";
		//return 0;
	}).detach();
}
//DecoderVideo
void CRtspPlayer::VideoDecoderNew(){
	std::thread([this]{
		AVFrame *frame;
		frame = av_frame_alloc();
		while (!m_quit){
			//av_frame_unref(frame);
			AVPacket packet;
			//ToDO: If queue end
			//LOG(INFO) << "POP";
			if (PacketQueuePop(&m_videoq, &packet, 1) < 0) {
				// eof queue
				break;
			}
			int got_frame;
			int len = avcodec_decode_video2(m_videoCodecCtx, frame, &got_frame, &packet);
			if (len < 0){
				av_free_packet(&packet);
				//LOG(ERROR) << "Failed to decode video packet";
				break;
			}
			if (got_frame){
				double pts = frame->pkt_dts;
				if (pts == AV_NOPTS_VALUE) {
					pts = frame->pkt_pts;
				}
				if (pts == AV_NOPTS_VALUE) {
					pts = 0;
				}
				pts *= av_q2d(m_fmtCtx->streams[m_videoStreamIndex]->time_base);
				pts = SynchronizeVideoNew(frame, pts);
			}
			av_free_packet(&packet);
		}
		av_frame_free(&frame);
	}).detach();
}
//Synctime
double CRtspPlayer::SynchronizeVideoNew(AVFrame *src_frame, double pts) {
	assert(src_frame != NULL);
	if (pts != 0) {
		// if we have pts, set video clock to it
		m_videoClock = pts;
	}
	else {
		// if we aren't given a pts, set it to the clock
		pts = m_videoClock;
	}
	/* update the video clock */
	double frame_delay = av_q2d(m_videoCodecCtx->time_base);
	// if we are repeating a frame, adjust clock accordingly
	frame_delay += src_frame->repeat_pict * (frame_delay * 0.5);
	m_videoClock += frame_delay;
	return pts;
}
//DecoderAudio
void CRtspPlayer::AudioDecoderNew(){
	std::thread([this]{
		AVFrame frame;
		while (!m_quit){
			av_frame_unref(&frame);
			AVPacket packet;
			//ToDO: If queue end
			if (PacketQueuePop(&m_audioq, &packet, 1) < 0) {
				// eof queue
				break;
			}
			int got_frame;
			if (avcodec_decode_audio4(m_audioCodecCtx, &frame, &got_frame, &packet) < 0){
				av_free_packet(&packet);
				//LOG(ERROR) << "Failed to decode video packet";
				break;
			}
			if (got_frame){
				//TODO: Add frames to queue
				int data_size = av_samples_get_buffer_size(NULL, m_audioCodecCtx->channels, frame.nb_samples, m_audioCodecCtx->sample_fmt, 1);
				// Obtain audio clock
				if (packet.pts != AV_NOPTS_VALUE) {
					m_audioClock = av_q2d(m_fmtCtx->streams[m_audioStreamIndex]->time_base) * packet.pts;
				}
				else {
					/* if no pts, then compute it */
					m_audioClock += (double)data_size /
						(m_audioCodecCtx->channels *
						m_audioCodecCtx->sample_rate *
						av_get_bytes_per_sample(m_audioCodecCtx->sample_fmt));
				}
				RingBufferWrite(&m_audioBuffer, frame.data[0], data_size, 1);
			}
			av_free_packet(&packet);
		}
		RingBufferEof(&m_audioBuffer);
	}).detach();
}
//Отрисовка
BOOL CRtspPlayer::RenderNew(){
	std::thread([this]()
	{
		//LOG(INFO) << "StartRender";
		if (Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL) != Gdiplus::Ok){
			//LOG(ERROR) << "GDI+ failed to start up!";
			return FALSE;
		}
		while (!m_quit){

		}
		//LOG(INFO) << "StopRender";
		return TRUE;
	}).detach();
	return TRUE;
}

void CRtspPlayer::PacketQueueInit(PacketQueue* q) {
	assert(q != NULL);

	memset(q, 0, sizeof(PacketQueue));
	q->mutex = SDL_CreateMutex();
	q->cond = SDL_CreateCond();
}
void CRtspPlayer::PacketQueueDeinit(PacketQueue* q) {
	assert(q != NULL);
	assert(q->mutex != NULL);
	assert(q->cond != NULL);

	SDL_DestroyMutex(q->mutex);
	SDL_DestroyCond(q->cond);
}
int CRtspPlayer::PacketQueuePush(PacketQueue* q, AVPacket* pkt) {
	assert(q != NULL);
	assert(pkt != NULL);

	AVPacketList* pkt_list = (AVPacketList *)av_malloc(sizeof(AVPacketList));
	if (pkt_list == NULL) {
		return -1;
	}

	pkt_list->pkt = *pkt;
	pkt_list->next = NULL;

	SDL_LockMutex(q->mutex);

	if (!q->eof) {
		if (q->last_pkt == NULL) {
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
int CRtspPlayer::PacketQueuePop(PacketQueue* q, AVPacket* pkt, int block) {
	assert(q != NULL);
	assert(pkt != NULL);

	SDL_LockMutex(q->mutex);

	AVPacketList* pkt_list = q->first_pkt;
	if (!block && (pkt_list == NULL)) {
		SDL_UnlockMutex(q->mutex);
		return -1;
	}
	else {
		while ((pkt_list == NULL) && !q->eof) {
			// Wait for packets
			SDL_CondWait(q->cond, q->mutex);
			pkt_list = q->first_pkt;
		}
	}

	if ((pkt_list == NULL) && q->eof) {
		SDL_UnlockMutex(q->mutex);
		return -1;
	}

	q->first_pkt = pkt_list->next;
	if (q->first_pkt == NULL) {
		// No more packets
		q->last_pkt = NULL;
	}
	*pkt = pkt_list->pkt;
	q->nb_packets--;
	q->size -= pkt->size;
	av_free(pkt_list);

	SDL_UnlockMutex(q->mutex);
	return 0;
}
void CRtspPlayer::PacketQueueEof(PacketQueue* q) {
	assert(q != NULL);

	SDL_LockMutex(q->mutex);
	q->eof = 1;
	SDL_CondBroadcast(q->cond);
	SDL_UnlockMutex(q->mutex);
}

int CRtspPlayer::RingBufferInit(RingBuffer* rb, int initSize, int maxSize){
	assert(rb != NULL);
	assert(maxSize <= 0);
	assert(maxSize >= initSize);

	memset(rb, 0, sizeof(RingBuffer));

	rb->data = static_cast<uint8_t*>(av_malloc(initSize));
	if (rb->data == NULL) {
		return -1;
	}
	rb->size = initSize;
	rb->max_size = maxSize;
	rb->mutex = SDL_CreateMutex();
	rb->rcond = SDL_CreateCond();
	rb->wcond = SDL_CreateCond();
	return 0;
};
void CRtspPlayer::RingBufferDeinit(RingBuffer* rb){
	assert(rb != NULL);
	assert(rb->mutex != NULL);
	assert(rb->rcond != NULL);
	assert(rb->wcond != NULL);

	SDL_DestroyMutex(rb->mutex);
	SDL_DestroyCond(rb->rcond);
	SDL_DestroyCond(rb->wcond);
};
int CRtspPlayer::RingBufferWrite(RingBuffer* rb, void* buffer, int len, int block){
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
	return buffer_ptr - (uint8_t*)buffer;
};
int CRtspPlayer::RingBufferRead(RingBuffer* rb, void* buffer, int len, int block){
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

	int count = buffer_ptr - (uint8_t*)buffer;
	if ((count == 0) && rb->eof) {
		count = -1;
	}

	SDL_UnlockMutex(rb->mutex);
	return count;
};
int CRtspPlayer::RingBufferSize(RingBuffer* rb){
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
};
void CRtspPlayer::RingBufferEof(RingBuffer* rb){
	assert(rb != NULL);

	SDL_LockMutex(rb->mutex);
	rb->eof = 1;
	SDL_CondBroadcast(rb->wcond);
	SDL_UnlockMutex(rb->mutex);
};

static void StaticThreadProc(void *arg){
	return ((CRtspPlayer*)arg)->DemuxerNew();
}
static void StaticThreadProcDecoder(void *arg){
	return ((CRtspPlayer*)arg)->VideoDecoderNew();
}


void CRtspPlayer::ThreadStartNew(){
	/*SDL_Thread *thread;
	thread = SDL_CreateThread(StaticThreadProc, "demux", this);*/
	//SDL_Thread *thread2;
	//thread2 = SDL_CreateThread(StaticThreadProcDecoder, "decoder", this);

	DemuxerNew();
	VideoDecoderNew();
}


















//

//
//
//void CRtspPlayer::PlayMain()
//{
//	std::thread([this](){
//
//		int frameFinished;
//
//		auto scaledBmp = static_cast<AVPicture*>(av_malloc(sizeof(AVPicture)));
//
//		pFrame = av_frame_alloc();
//
//		while (av_read_frame(m_fmtCtx, &m_packet) >= 0)
//		{
//			// Is this a packet from the video stream?
//			if (m_packet.stream_index == m_videoStreamIndex) {
//				// Decode video frame
//				avcodec_decode_video2(m_videoCtx, pFrame, &frameFinished,
//					&m_packet);
//
//				// Did we get a video frame?
//				if (frameFinished) {
//
//					RECT rect;	GetWindowRect(m_hMainWindow, &rect);
//					Gdiplus::Rect gdiRect;
//					gdiRect.X = 0;
//					gdiRect.Y = 0;
//					gdiRect.Width = abs(rect.right - rect.left);
//					gdiRect.Height = abs(rect.bottom - rect.top);
//
//					avpicture_alloc(scaledBmp, AV_PIX_FMT_RGB32, gdiRect.Width, gdiRect.Height);
//
//					m_scaleCtx = sws_getCachedContext(m_scaleCtx, m_width, m_height, m_dstPixFmt, gdiRect.Width, gdiRect.Height, AV_PIX_FMT_RGB32, SWS_FAST_BILINEAR, nullptr, nullptr, nullptr);
//
//					// Convert the image from its native format to RGB
//					sws_scale(m_scaleCtx, (uint8_t const * const *)pFrame->data, pFrame->linesize, 0, m_videoCtx->height, scaledBmp->data, scaledBmp->linesize);
//					Gdiplus::Bitmap *bmp = new Gdiplus::Bitmap(gdiRect.Width, gdiRect.Height, scaledBmp->linesize[0], PixelFormat32bppRGB, scaledBmp->data[0]);
//
//					HDC wndHdc = GetDC(m_hMainWindow);
//
//					Gdiplus::Graphics graphics(wndHdc);
//
//					graphics.DrawImage(bmp, gdiRect);
//
//					ReleaseDC(m_hMainWindow, wndHdc);
//
//					avpicture_free(scaledBmp);
//					delete bmp;
//				}
//			}
//			// Free the packet that was allocated by av_read_frame
//			av_free_packet(&m_packet);
//		}
//		av_frame_free(&pFrame);
//	}).detach();
//}
//
////Открытие файла/птока m_filestream
//BOOL CRtspPlayer::Open()
//{
//	av_register_all();
//
//	if (m_fileName.find("rtsp://") != std::string::npos)
//	{
//		if (0 > av_dict_set(&m_options, "rtsp_transport", "tcp", 0))
//			LOG(ERROR) << "AvDictionary failed to set up!";
//		return FALSE;
//	}
//	else
//	{
//		m_options = nullptr;
//	}
//	Init();
//
//	return TRUE;
//}
//
//BOOL CRtspPlayer::Init()
//{
//	if (avformat_open_input(&m_fmtCtx, m_fileName.c_str(), nullptr, &m_options))
//		return FALSE;
//	if (0 > avformat_find_stream_info(m_fmtCtx, nullptr))
//		return FALSE;
//
//	av_dump_format(m_fmtCtx, 0, m_fileName.c_str(), 0);
//	m_fileName = "";
//	try	{
//		streamsDetect();
//		streamsOpen();
//	}
//	catch (...)	{
//		return FALSE;
//	}
//	if (hasAudio())
//	{
//		if (SDL_Init(SDL_INIT_AUDIO))
//			return FALSE;
//	}
//
//	if (hasAudio())
//	{
//		m_audioDesiredSpec.channels = m_audioCtx->channels;
//		m_audioDesiredSpec.freq = m_audioCtx->sample_rate;
//		//m_decoder.audioSilent = false;
//	}
//	else
//	{
//		m_audioDesiredSpec.channels = 1;
//		m_audioDesiredSpec.freq = 11025;
//		//m_decoder.audioSilent = true;
//	}
//	m_audioDesiredSpec.format = AUDIO_S16SYS;
//	m_audioDesiredSpec.samples = AUDIO_SAMPLES;
//	m_audioDesiredSpec.userdata = this;
//	m_audioDesiredSpec.callback = [](void* userdata, Uint8* stream, int want_bytes)
//	{
//		static int64_t begin_ts;
//		auto last_frame = begin_ts;
//		begin_ts = av_gettime_relative();
//		last_frame = last_frame ? begin_ts - last_frame : 0;
//
//		assert(want_bytes && stream && userdata);
//		auto player = static_cast<CRtspPlayer*>(userdata);
//		auto decoder = static_cast<Decoder*const>(&player->m_decoder);
//		auto frames_queue = &decoder->qAudioFrames;
//
//		decoder->syncInfo.mut.lock();
//		decoder->syncInfo.audio_probe_ts = begin_ts;
//		decoder->syncInfo.playback_ts += last_frame;
//		decoder->syncInfo.mut.unlock();
//
//		//std::cout
//		//<< "Audio frame: " << last_frame << std::endl
//		//<< "Wants: " << want_bytes << std::endl
//		//<< "Audio TS: " << decoder->syncInfo.playback_ts << std::endl
//		//<< "Audio probe: " << now_ts << std::endl
//		;
//
//		if (!player->hasAudio())
//		{
//			SDL_memset(stream, 0, want_bytes);
//			decoder->syncInfo.global_timestamp += last_frame / 1000;
//			return;
//		}
//
//		if (!frames_queue->Wait(72))
//			return; // probably empty
//		//frames_queue->Wait();
//		if (!decoder->syncInfo.pending_buf)
//		{
//			decoder->syncInfo.pending_buf = frames_queue->Front()->Raw()->data[0];
//			decoder->syncInfo.got_in_buf = av_samples_get_buffer_size(
//				nullptr, frames_queue->Front()->Raw()->channels,
//				frames_queue->Front()->Raw()->nb_samples,
//				static_cast<AVSampleFormat>(frames_queue->Front()->Raw()->format),
//				0);
//		}
//
//		if (decoder->syncInfo.got_in_buf < want_bytes)
//		{
//			if (decoder->syncInfo.got_in_buf > 0)
//			{
//				//assert(decoder->syncInfo.pending_buf == frames_queue->Front()->Raw()->data[0]);
//
//				if (!decoder->audioSilent)
//					std::memcpy(stream, decoder->syncInfo.pending_buf, decoder->syncInfo.got_in_buf);
//				else
//					SDL_memset(stream, 0, decoder->syncInfo.got_in_buf);
//
//				want_bytes -= decoder->syncInfo.got_in_buf;
//				stream += decoder->syncInfo.got_in_buf;
//			}
//			frames_queue->Eat();
//
//			if (!frames_queue->Wait(72))
//				return;
//			//frames_queue->Wait();
//			decoder->syncInfo.global_timestamp +=
//				av_frame_get_pkt_duration(frames_queue->Front()->Raw());
//
//			decoder->syncInfo.pending_buf = frames_queue->Front()->Raw()->data[0];
//			decoder->syncInfo.got_in_buf = av_samples_get_buffer_size(
//				nullptr, frames_queue->Front()->Raw()->channels,
//				frames_queue->Front()->Raw()->nb_samples,
//				static_cast<AVSampleFormat>(frames_queue->Front()->Raw()->format),
//				0);
//		}
//
//		if (want_bytes)
//		{
//			if (!decoder->audioSilent)
//				std::memcpy(stream, decoder->syncInfo.pending_buf, want_bytes);
//			else
//				SDL_memset(stream, 0, want_bytes);
//
//			decoder->syncInfo.got_in_buf -= want_bytes;
//			decoder->syncInfo.pending_buf += want_bytes;
//		}
//	};
//
//	m_audioDevice = SDL_OpenAudioDevice(nullptr, 0,
//		&m_audioDesiredSpec, &m_audioSpec,
//		0);
//
//	m_scaleCtx = sws_getCachedContext(m_scaleCtx, m_width, m_height, *m_pixFmt, m_width, m_height, m_dstPixFmt, SWS_FAST_BILINEAR, nullptr, nullptr, nullptr);
//	if (!m_scaleCtx)
//		return FALSE;
//
//	m_resampleCtx = swr_alloc();
//
//	if (!QueryPerformanceFrequency(&m_decoder.syncInfo.perfFreq))
//		return FALSE;
//
//	try	{
//		threadsCreate();
//	}
//	catch (...)	{
//		return FALSE;
//	}
//
//	m_valid = true;
//
//	if (m_cbOnInit)
//		m_cbOnInit(&m_callbackInfo);
//
//	return TRUE;
//}
//
//BOOL CRtspPlayer::Play()
//{
//	DEBUG_MSG("Play");
//
//
//
//	if (!m_valid)
//		return FALSE;
//
//	if (m_paused) {
//		unpause();
//	}
//	else
//		return FALSE;
//
//	DEBUG_MSG("++Play");
//	return TRUE;
//}
//
//BOOL CRtspPlayer::Stop()
//{
//	DEBUG_MSG("Stop");
//
//	Pause();
//	if (!SetPlaybackPosition(0))
//		return FALSE;
//	//cacheFlush();
//
//	DEBUG_MSG("++Stop");
//	return TRUE;
//}
//
//BOOL CRtspPlayer::Pause()
//{
//	DEBUG_MSG("Pause");
//	if (!m_valid)
//		return FALSE;
//
//	try {
//		//m_pauseMutex.lock();
//		m_paused = true;
//		//m_pauseMutex.unlock();
//		if (hasAudio())
//			stopAudio();
//	}
//	catch (...) {
//		return FALSE;
//	}
//
//	DEBUG_MSG("++Pause");
//	return TRUE;
//}
//
//BOOL CRtspPlayer::SwitchSound(BOOL bIsSoundSwitchedOn)
//{
//	m_decoder.audioSilent = !bIsSoundSwitchedOn;
//	return TRUE;
//}
//
//BOOL CRtspPlayer::GetVolume(BYTE *pbVolumeLevel)
//{
//	return TRUE;
//}
//
//BOOL CRtspPlayer::SetVolume(BYTE bVolumeLevel)
//{
//	return TRUE;
//}
//
//BOOL CRtspPlayer::GetStreamInfo(PSTREAM_INFO pStreamInfo)
//{
//	DEBUG_MSG("Get stream info");
//
//	if (!m_valid)
//		return FALSE;
//
//	std::memcpy(pStreamInfo, &m_callbackInfo, sizeof(*pStreamInfo));
//
//	DEBUG_MSG("++Get stream info");
//	return TRUE;
//}
//
//BOOL CRtspPlayer::SetPlaybackPosition(DWORD dwMilliseconds)
//{
//	DEBUG_MSG("Position SET");
//
//	if (!m_valid)
//		return FALSE;
//	m_seekPos = static_cast<decltype(m_seekPos)>((dwMilliseconds / 1000.0) * AV_TIME_BASE);
//
//	DEBUG_MSG("++Position SET");
//	return TRUE;
//}
//
//DWORD CRtspPlayer::GetPlaybackPosition()
//{
//	DEBUG_MSG("Position GET");
//
//	if (!m_valid)
//		return 0;
//
//	DEBUG_MSG("++Position GET");
//	//return static_cast<DWORD>(m_decoder.syncInfo.global_timestamp);
//	return static_cast<DWORD>(m_current_timestamp);
//}
//
//BOOL CRtspPlayer::MoveToNextFrame()
//{
//	if (!m_paused)
//	{
//		Pause();
//	}
//	else
//	{
//		m_oneShot = true;
//		m_unpause.notify_one();
//	}
//	return TRUE;
//}
//
//BOOL CRtspPlayer::MoveToPreviousFrame()
//{
//	return TRUE;
//}
//
//void CRtspPlayer::streamsDetect()
//{
//	m_videoStreamIndex = av_find_best_stream(m_fmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
//	m_audioStreamIndex = av_find_best_stream(m_fmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
//	if (m_audioStreamIndex < 0 && m_videoStreamIndex < 0)
//		throw std::exception("No streams found");
//}
//
//void CRtspPlayer::streamsOpen()
//{
//	if (hasVideo())
//	{
//		m_videoCtx = m_fmtCtx->streams[m_videoStreamIndex]->codec;
//
//		m_codecVideo = avcodec_find_decoder(m_videoCtx->codec_id);
//		if (m_codecVideo == nullptr)
//			throw std::exception("can't find video codec");
//
//		m_videoCtx->refcounted_frames = 1;
//		if (avcodec_open2(m_videoCtx, m_codecVideo, nullptr))
//			throw std::exception("can't open video codec");
//
//		m_width = m_videoCtx->width;
//		m_height = m_videoCtx->height;
//		m_fps = av_q2d(av_guess_frame_rate(m_fmtCtx, m_fmtCtx->streams[m_videoStreamIndex], nullptr));
//
//		m_pixFmt = &m_videoCtx->pix_fmt;
//	}
//
//	if (hasAudio())
//	{
//		m_audioCtx = m_fmtCtx->streams[m_audioStreamIndex]->codec;
//
//		m_codecAudio = avcodec_find_decoder(m_audioCtx->codec_id);
//		if (m_codecAudio == nullptr)
//			throw std::exception("can't find audio codec");
//
//		m_audioCtx->refcounted_frames = 1;
//		if (avcodec_open2(m_audioCtx, m_codecAudio, nullptr))
//			throw std::exception("can't open audio codec");
//	}
//
//	m_callbackInfo.dwBitrate = m_fmtCtx->bit_rate;
//	m_callbackInfo.dwFileLengthMilliseconds = static_cast<DWORD>
//		((m_fmtCtx->duration != AV_NOPTS_VALUE ? m_fmtCtx->duration : 0) / (AV_TIME_BASE / 1000));
//	m_callbackInfo.dwHeight = m_height;
//	m_callbackInfo.dwWidth = m_width;
//	m_callbackInfo.nFps = static_cast<decltype(m_callbackInfo.nFps)>(rint(m_fps));
//}
//
//void CRtspPlayer::threadsCreate()
//{
//	ThreeInOne();/*
//				 startDemuxer();
//				 if (hasVideo())
//				 startDecoderVideo();
//				 if (hasAudio())
//				 startDecoderAudio();
//				 startRenderer();*/
//}
//
//void CRtspPlayer::ThreeInOne()
//{
//	std::thread([this]()
//	{
//		SwsContext* m_bmpScaleCtx = nullptr;
//
//		int frameFinished;
//		pFrame = av_frame_alloc();
//
//		while (av_read_frame(m_fmtCtx, &m_packet) >= 0)
//		{
//			// Is this a packet from the video stream?
//			if (m_packet.stream_index == m_videoStreamIndex) {
//				// Decode video frame
//				avcodec_decode_video2(m_videoCtx, pFrame, &frameFinished,
//					&m_packet);
//
//				// Did we get a video frame?
//				if (frameFinished) {
//
//					RECT rect;	GetWindowRect(m_hMainWindow, &rect);
//					Gdiplus::Rect gdiRect;
//					gdiRect.X = 0;
//					gdiRect.Y = 0;
//					gdiRect.Width = abs(rect.right - rect.left);
//					gdiRect.Height = abs(rect.bottom - rect.top);
//
//					auto scaledBmp = static_cast<AVPicture*>(av_malloc(sizeof(AVPicture)));
//
//					if (avpicture_alloc(scaledBmp, AV_PIX_FMT_RGB32, gdiRect.Width, gdiRect.Height))
//						throw std::bad_alloc();
//
//					m_bmpScaleCtx = sws_getCachedContext(m_bmpScaleCtx, m_width, m_height, m_dstPixFmt, gdiRect.Width, gdiRect.Height, AV_PIX_FMT_RGB32, SWS_FAST_BILINEAR, nullptr, nullptr, nullptr);
//
//					// Convert the image from its native format to RGB
//					sws_scale(m_bmpScaleCtx, (uint8_t const * const *)pFrame->data, pFrame->linesize, 0, m_videoCtx->height, scaledBmp->data, scaledBmp->linesize);
//					Gdiplus::Bitmap *bmp = new Gdiplus::Bitmap(gdiRect.Width, gdiRect.Height, scaledBmp->linesize[0], PixelFormat32bppRGB, scaledBmp->data[0]);
//
//					HDC wndHdc = GetDC(m_hMainWindow);
//
//					Gdiplus::Graphics graphics(wndHdc);
//
//					graphics.DrawImage(bmp, gdiRect);
//
//					ReleaseDC(m_hMainWindow, wndHdc);
//
//					avpicture_free(scaledBmp);
//					delete bmp;
//				}
//			}
//			// Free the packet that was allocated by av_read_frame
//			av_free_packet(&m_packet);
//		}
//		av_frame_free(&pFrame);
//	}).detach();
//}
//void CRtspPlayer::startDemuxer()
//{
//	std::thread([this]()
//	{
//		DEBUG_MSG("Demuxer started");
//
//		try
//		{
//			m_decoder.demux_state = state::InProgress;
//
//			Packet::Ptr aborted_pkt;
//			while (!m_quit)
//			{
//				std::unique_lock<decltype(m_pauseWorldMutex)> lk(m_pauseWorldMutex);
//				m_unpauseWorld.wait(lk, [this] {
//					return !m_pausedWorld;
//				});
//
//				//while (m_avpacket){
//				//	Sleep(2);
//				//}
//				//m_avpacket = (AVPacket*)av_malloc(sizeof(AVPacket));
//				//if (av_read_frame(m_fmtCtx, m_avpacket))
//				//{
//				//	m_decoder.demux_state = state::Finished;
//				//	break;	// Eof or error
//				//}
//
//				//else {
//				//	//pkt = std::move(aborted_pkt);
//				//}
//				//try
//				//{
//				//	/*auto minAudio = m_decoder.qAudioPackets.Size() <= m_decoder.qVideoPackets.Size();
//				//	auto capacityVideo = 0,
//				//		capacityAudio = 0;
//				//	if (minAudio)
//				//	{
//				//		capacityAudio = QUEUE_SIZE_THRESH;
//				//	}
//				//	else
//				//	{
//				//		capacityVideo = QUEUE_SIZE_THRESH;
//				//	}*/
//
//				//	/*m_decoder.qAudioPackets.SetCapacity(capacityAudio);
//				//	m_decoder.qVideoPackets.SetCapacity(capacityVideo);*/
//				//	//
//				//	//if (m_avpacket->stream_index == m_videoStreamIndex)
//				//	//{
//				//	//	std::clog << "Video PACKET push" << std::endl;
//				//	//	
//				//	//	//m_decoder.qVideoPackets.Push(std::move(pkt));
//				//	//}
//				//	//else if (m_avpacket->stream_index == m_audioStreamIndex && IsAudioEnabled())
//				//	//{
//				//	//	std::clog << "Audio PACKET push" << std::endl;
//				//	//	//m_decoder.qAudioPackets.Push(std::move(pkt));
//				//	//}
//				//}
//				//catch (const Queue::abort &)
//				//{
//				//	aborted_pkt = std::move(pkt);
//				//}
//			}
//			if (m_quit)
//				m_decoder.demux_state = state::Interrupted;
//		}
//
//		catch (const Queue::terminate&)
//		{	// safe quit
//			assert(m_quit);
//			m_decoder.demux_state = state::Interrupted;
//		}
//		catch (const std::exception &e)
//		{
//			std::cerr << "An error occurred in demuxing thread: " << e.what() << std::endl;
//			std::abort();
//		}
//
//		DEBUG_MSG("Demuxer stopped");
//	}).detach();
//}
//
//void CRtspPlayer::startDecoderVideo()
//{
//	std::thread([this]()
//	{
//		DEBUG_MSG("Video decoder started");
//
//		int frame_finished;
//		Decoder::PicturePtr /*aborted_pic,*/ pic;
//
//		m_decoder.vDecode_state = state::InProgress;
//
//		try
//		{
//			while (!m_quit)
//			{
//				auto frame = Frame::New();
//
//				/*if (m_decoder.qVideoPackets.Empty() && m_decoder.demux_state == state::Finished)
//				break;*/
//
//				///*try	{
//				//	pkt = m_decoder.qVideoPackets.Pop();
//				//}*/
//				//catch (const Queue::abort &) { continue; }
//
//				//if (!pkt)
//				//	throw std::exception("empty video packet in queue");
//				//
//				/*while (!m_avpacket)
//				{
//				Sleep(2);
//				}
//				avcodec_decode_video2(m_videoCtx, frame->Raw(), &frame_finished, m_avpacket);
//				av_free_packet(m_avpacket);
//				av_free(m_avpacket);
//				m_avpacket = nullptr;*/
//				/*throw std::exception("can't decode packet")*/;
//
//				if (frame_finished)
//				{
//					try
//					{
//						//if (aborted_pic)
//						//	m_decoder.qVideoFrames.Push(std::move(aborted_pic));
//
//						pic = convertColorSpace(std::move(frame));
//						//std::clog << "Video FRAME push" << std::endl;
//						m_decoder.qVideoFrames.Push(std::move(pic));
//					}
//					catch (const Queue::abort &)
//					{
//						//aborted_pic = std::move(pic);
//					}
//				}
//
//			}
//		}
//		catch (const Queue::terminate &)
//		{	// safe quit
//			assert(m_quit);
//		}
//		catch (const std::exception &e)
//		{
//			std::cerr << "An error occurred in video decoding thread: " << e.what() << std::endl;
//			std::abort();
//		}
//
//		if (m_quit)
//			m_decoder.vDecode_state = state::Interrupted;
//		else
//			m_decoder.vDecode_state = state::Finished;
//
//		DEBUG_MSG("Video decoder stopped");
//	}).detach();
//}
//
//void CRtspPlayer::startDecoderAudio()
//{
//	std::thread([this]()
//	{
//		DEBUG_MSG("Audio decoder started");
//
//		try
//		{
//			int frame_finished;
//
//			m_decoder.aDecode_state = state::InProgress;
//			//Frame::Ptr aborted_frame;
//
//			while (!m_quit)
//			{
//				if (m_decoder.qAudioPackets.Empty() && m_decoder.demux_state == state::Finished)
//					break;
//
//				Packet::Ptr pkt;
//
//				try	{
//					pkt = m_decoder.qAudioPackets.Pop();
//				}
//				catch (const Queue::abort &){ continue; }
//
//				if (!pkt)
//					throw std::exception("Empty packet!");
//
//				auto frame = Frame::New();
//
//				auto decoded = avcodec_decode_audio4(m_audioCtx, frame->Raw(), &frame_finished, pkt->Raw());
//				if (0 > decoded)
//					throw std::exception("can't decode audio frame");
//				assert(decoded == pkt->Raw()->size);
//
//				if (frame_finished)
//				{
//					try {
//						//if (aborted_frame)
//						//	m_decoder.qAudioFrames.Push(std::move(aborted_frame));
//
//						if (frame->Raw()->format != m_dstSndFmt)
//							frame = resampleAudio(std::move(frame));
//
//						auto msec = av_q2d(m_fmtCtx->streams[m_audioStreamIndex]->time_base) * 1000;
//						frame->Raw()->pkt_duration = av_frame_get_pkt_duration(frame->Raw()) * msec;
//
//						//std::clog << "Audio FRAME push" << std::endl;
//						m_decoder.qAudioFrames.Push(std::move(frame));
//					}
//					catch (const Queue::abort &) {
//						//aborted_frame = std::move(frame);
//					}
//				}
//			}
//		}
//		catch (const Queue::terminate&)
//		{	// safe quit
//			assert(m_quit);
//		}
//		catch (const std::exception &e)
//		{
//			std::cerr << "An error occurred in audio decoding thread: " << e.what() << std::endl;
//			std::abort();
//		}
//
//		if (m_quit)
//			m_decoder.aDecode_state = state::Interrupted;
//		else
//			m_decoder.aDecode_state = state::Finished;
//
//		DEBUG_MSG("Audio decoder stopped");
//	}).detach();
//}
//
//Frame::Ptr CRtspPlayer::resampleAudio(Frame::Ptr frame)
//{
//	frame->Raw()->channel_layout =
//		!m_audioCtx->channel_layout ?
//		av_get_default_channel_layout(m_audioCtx->channels) :
//		m_audioCtx->channel_layout;
//
//	auto resampled = Frame::New();
//
//	resampled->Raw()->channel_layout = frame->Raw()->channel_layout;
//	resampled->Raw()->sample_rate = frame->Raw()->sample_rate/* * m_speedScaleFactor*/;
//	resampled->Raw()->format = m_dstSndFmt;
//
//	if (auto err = swr_convert_frame(m_resampleCtx, resampled->Raw(), frame->Raw()))
//		throw std::exception("cannot resample audio");
//
//	//	auto msec = av_q2d(m_fmtCtx->streams[m_audioStreamIndex]->time_base) * 1000;
//	//
//	//resampled->Raw()->pkt_dts					= frame->Raw()->pkt_dts;
//	//resampled->Raw()->pkt_pts					= frame->Raw()->pkt_pts;
//	//resampled->Raw()->pts						= frame->Raw()->pts;
//	//resampled->Raw()->best_effort_timestamp		= av_frame_get_best_effort_timestamp(frame->Raw());
//	resampled->Raw()->pkt_duration = av_frame_get_pkt_duration(frame->Raw());
//
//	return resampled;
//}
//
//CRtspPlayer::Decoder::PicturePtr CRtspPlayer::convertColorSpace(Frame::Ptr frame)
//{
//	auto pic = static_cast<AVPicture*>(av_malloc(sizeof(AVPicture)));
//	if (!pic)
//		throw std::bad_alloc();
//
//	if (avpicture_alloc(pic, m_dstPixFmt, m_width, m_height))
//		throw std::bad_alloc();
//
//	Decoder::PicturePtr picture(pic, m_decoder.deleterPicture);
//
//	sws_scale(m_scaleCtx, frame->Raw()->data, frame->Raw()->linesize, 0, m_height, picture->data, picture->linesize);
//
//
//	return picture;
//}
//
//void CRtspPlayer::startRenderer()
//{
//	std::thread([this]()
//	{
//		DEBUG_MSG("Renderer started");
//
//		SwsContext* m_bmpScaleCtx = nullptr;
//		try
//		{
//			m_rendererState = state::InProgress;
//			const auto frame_q = AV_TIME_BASE / m_fps;
//
//			int64_t playback_video_ts{ 0 };
//			//int64_t drift{ 0 };
//			int64_t begin_ts{ 0 };
//			int64_t last_frame{ 0 };
//
//			// warm up the buffer
//			m_decoder.qVideoFrames.Wait(500);
//
//			if (hasAudio()){
//				while (!m_decoder.syncInfo.audio_probe_ts && !m_quit)
//					std::this_thread::sleep_for(std::chrono::milliseconds(1));
//			}
//
//
//			while (!m_quit)
//			{
//				last_frame = begin_ts;
//				begin_ts = av_gettime_relative();
//				if (last_frame)
//					last_frame = begin_ts - last_frame;
//
//				playback_video_ts += last_frame;
//
//				std::unique_lock<decltype(m_pauseMutex)> lk(m_pauseMutex);
//				m_unpause.wait(lk, [this] {
//					return !m_paused || m_oneShot;
//				});
//				m_oneShot = false;
//
//				if (m_seekPos >= 0)
//					seek();
//
//				if (m_decoder.qVideoFrames.Empty() && m_decoder.vDecode_state == state::Finished) {
//					if (!m_cbOnEof)
//						//если возникает непредвиденный разрыв то выкидываем ошибку
//						throw std::exception("Playback stopped!");
//					m_cbOnEof();
//					break;
//				}
//
//				Decoder::PicturePtr pic;
//				try
//				{
//					std::clog << "Video FRAME pop" << std::endl;
//					pic = m_decoder.qVideoFrames.Pop();
//				}
//				catch (const Queue::abort&){ continue; }
//
//				if (!pic)
//					throw std::exception("Empty frame");
//
//
//				RECT rect;	GetWindowRect(m_hMainWindow, &rect);
//				Gdiplus::Rect gdiRect;
//				gdiRect.X = 0;
//				gdiRect.Y = 0;
//				gdiRect.Width = abs(rect.right - rect.left);
//				gdiRect.Height = abs(rect.bottom - rect.top);
//
//				auto scaledBmp = static_cast<AVPicture*>(av_malloc(sizeof(AVPicture)));
//				if (!pic)
//					throw std::bad_alloc();
//
//				if (avpicture_alloc(scaledBmp, AV_PIX_FMT_RGB32, gdiRect.Width, gdiRect.Height))
//					throw std::bad_alloc();
//
//
//
//				m_bmpScaleCtx = sws_getCachedContext(m_bmpScaleCtx, m_width, m_height, m_dstPixFmt, gdiRect.Width, gdiRect.Height, AV_PIX_FMT_RGB32, SWS_FAST_BILINEAR, nullptr, nullptr, nullptr);
//
//				sws_scale(m_bmpScaleCtx, pic->data, pic->linesize, 0, m_height, scaledBmp->data, scaledBmp->linesize);
//
//
//				Gdiplus::Bitmap *bmp = new Gdiplus::Bitmap(gdiRect.Width, gdiRect.Height, scaledBmp->linesize[0], PixelFormat32bppRGB, scaledBmp->data[0]);
//
//				HDC wndHdc = GetDC(m_hMainWindow);
//
//				Gdiplus::Graphics graphics(wndHdc);
//
//				graphics.DrawImage(bmp, gdiRect);
//
//				ReleaseDC(m_hMainWindow, wndHdc);
//
//				avpicture_free(scaledBmp);
//
//				delete bmp;
//
//				//// Do render onto callback
//				//if (!m_cbOnFrame)
//				//	throw std::exception("Callback is null!");
//
//				////std::clog << "RENDERING..." << std::endl;
//				//m_cbOnFrame(pic->data[0], pic->linesize[0] * m_height,
//				//	pic->linesize[0], m_width, m_height, static_cast<DWORD>(playback_video_ts/1000));
//
//				auto end_ts = av_gettime_relative();
//
//				auto delay = (frame_q - (end_ts - begin_ts))/* * m_speedScaleFactor*/;
//				//std::cout << "delay: " << delay << std::endl;
//				if (delay > 0)
//					std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(rint(delay))));
//				m_current_timestamp = playback_video_ts / 1000;
//			}
//		}
//		catch (const Queue::terminate&)
//		{	// safe quit
//			assert(m_quit);
//		}
//		catch (const std::exception &e)
//		{
//			std::cerr << "An error occurred in rendering thread: " << e.what() << std::endl;
//		}
//
//		if (hasAudio())
//			stopAudio();
//
//		sws_freeContext(m_bmpScaleCtx);
//		SDL_CloseAudioDevice(m_audioDevice);
//
//
//		if (m_quit)
//			m_rendererState = state::Interrupted;
//		else
//			m_rendererState = state::Finished;
//
//		// ExitInstance
//		Gdiplus::GdiplusShutdown(m_gdiplusToken);
//
//		DEBUG_MSG("Renderer stopped");
//	}).detach();
//}
//
//bool CRtspPlayer::IsAudioEnabled()
//{
//	return m_audioDevice > 0;
//}
//
//void CRtspPlayer::cacheFlush()
//{
//	DEBUG_MSG("Flushing cache");
//
//	try {
//		m_decoder.qVideoPackets.Clear();
//		m_decoder.qAudioPackets.Clear();
//		// get rid of pending pushes
//		m_decoder.qVideoFrames.Abort();
//		m_decoder.qAudioFrames.Abort();
//		m_decoder.qVideoFrames.Clear();
//		m_decoder.qAudioFrames.Clear();
//
//		m_decoder.syncInfo.pending_buf = nullptr;
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << "can't flush cache: " << e.what() << std::endl;
//	}
//
//	DEBUG_MSG("++Flushing cache");
//}
//
//void CRtspPlayer::cacheAbortPending()
//{
//	DEBUG_MSG("Aborting cache");
//
//	try {
//		m_decoder.qVideoPackets.Abort();
//		m_decoder.qAudioPackets.Abort();
//		m_decoder.qVideoFrames.Abort();
//		m_decoder.qAudioFrames.Abort();
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << "can't abort pending cache: " << e.what() << std::endl;
//	}
//
//	DEBUG_MSG("++Aborting cache");
//}
//
//void CRtspPlayer::unpause()
//{
//	DEBUG_MSG("Unpause");
//
//	assert(m_paused);
//	m_paused = false;
//	m_unpause.notify_all();
//	//if (hasAudio())
//	startAudio();
//
//	DEBUG_MSG("++Unpause");
//}
//
//BOOL CRtspPlayer::InputData(BYTE* pBuf, DWORD dwSize)
//{
//	throw std::logic_error("The method or operation is not implemented.");
//}
//
//BOOL CRtspPlayer::IncreasePlaybackSpeed()
//{
//	return FALSE;
//}
//
//BOOL CRtspPlayer::DecreasePlaybackSpeed()
//{
//	return FALSE;
//}
//
//BOOL CRtspPlayer::SaveSnapshot(std::string path, std::string name)
//{
//	m_SnapshootPath = StringToWString(path);
//	m_SnapshootName = StringToWString(name);
//	m_saveSnapShoot = true;
//	return FALSE;
//}
//
//void CRtspPlayer::stopAudio()
//{
//	SDL_PauseAudioDevice(m_audioDevice, 1);
//}
//
//void CRtspPlayer::startAudio()
//{
//	// warm up the cache first
//	if (hasAudio())
//	{
//		m_decoder.qAudioFrames.Wait(300);
//	}
//	SDL_PauseAudioDevice(m_audioDevice, 0);
//}
//
//bool CRtspPlayer::hasAudio() const
//{
//	//return m_audioStreamIndex >= 0;
//	return FALSE;
//}
//
//bool CRtspPlayer::hasVideo() const
//{
//	return m_videoStreamIndex >= 0;
//}
//
//void CRtspPlayer::pauseWorld()
//{
//	m_pausedWorld = true;
//
//	m_decoder.qAudioPackets.Abort();
//	m_decoder.qVideoPackets.Abort();
//
//	stopAudio();
//}
//
//void CRtspPlayer::resumeWorld()
//{
//	m_pausedWorld = false;
//	m_unpauseWorld.notify_all();
//	startAudio();
//}
//
//void CRtspPlayer::seek()
//{
//	pauseWorld();
//
//	m_decoder.syncInfo.global_timestamp = (m_seekPos / 1000);
//	m_current_timestamp = static_cast<DWORD>(m_decoder.syncInfo.global_timestamp);
//	m_seekPos = av_rescale_q(m_seekPos, AVRational{ 1, AV_TIME_BASE },
//		m_fmtCtx->streams[m_videoStreamIndex]->time_base);
//
//	if (avformat_seek_file(m_fmtCtx, m_videoStreamIndex, INT64_MIN, m_seekPos, INT64_MAX, AVSEEK_FLAG_ANY) >= 0)
//	{
//		//avcodec_flush_buffers(m_videoCtx);
//		//avcodec_flush_buffers(m_audioCtx);
//		avformat_flush(m_fmtCtx);
//		cacheFlush();
//	}
//
//	m_seekPos = -1;
//
//	resumeWorld();
//}
//
