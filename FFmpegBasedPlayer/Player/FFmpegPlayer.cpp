#include "stdafx.h"
#include "FFmpegPlayer.h"

// Calculate actual buffer size keeping in mind not cause too frequent audio callbacks
#define SDL_AUDIO_MAX_CALLBACKS_PER_SEC 30;

#pragma comment(lib, "SDL2")

#pragma warning(push)
#pragma warning(disable: 4127)
#ifdef _DEBUG
#define DEBUG_MSG(str) do { std::clog << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
#pragma warning(pop)

CFFmpegPlayer::CFFmpegPlayer(PCHAR pchFileName,
	FDecodeCallback fOnFrame,
	FFileEndCallback fOnEof,
	FEndInitCallback fOnInit,
	FErrorCallback fOnError,
	int timeout,
	HWND h_MainWindow)
	: CBasePlayer(pchFileName, fOnFrame, fOnEof, fOnInit, h_MainWindow)
	, m_fileName(pchFileName)
	, m_cbOnInit(fOnInit)
	, m_cbOnFrame(fOnFrame)
	, m_cbOnEof(fOnEof)
{
	m_cbOnError = fOnError;
	m_timeout = timeout;
	m_decoder.deleterPicture = [](AVPicture* pic)
	{
		avpicture_free(pic);
		av_free(pic);
	};
}

CFFmpegPlayer::~CFFmpegPlayer()
{

	m_quit = true;
	m_paused = false;

	try
	{
		m_decoder.qAudioFrames.Terminate();
		m_decoder.qVideoFrames.Terminate();
		m_decoder.qAudioPackets.Terminate();
		m_decoder.qVideoPackets.Terminate();

		while (m_decoder.demux_state == state::InProgress
			|| m_decoder.aDecode_state == state::InProgress
			|| m_decoder.vDecode_state == state::InProgress
			|| m_rendererState == state::InProgress)
		{
			m_unpause.notify_all();
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
	catch (...)
	{
		// swallow any exception in destructor
	}
	if (&m_resampleCtx != NULL)
		swr_free(&m_resampleCtx);
	if (m_audioCtx != NULL)
		avcodec_close(m_audioCtx);
	if (m_videoCtx != NULL)
		avcodec_close(m_videoCtx);
	if (&m_options != NULL)
		av_dict_free(&m_options); // очищаем словарь
	if (&m_fmtCtx != NULL)
		avformat_close_input(&m_fmtCtx);
}



std::wstring StringToWString(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

// Открытие файла с видео
BOOL CFFmpegPlayer::Open()
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
#ifdef _DEBUG
	av_log_set_level(AV_LOG_VERBOSE);
#else
	av_log_set_level(AV_LOG_QUIET);
#endif
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
	static Logging log;

	if (m_fileName.find("rtsp://") != std::string::npos)
	{
		if (0 > av_dict_set(&m_options, "rtsp_transport", "tcp", 0))
			return FALSE;
	}
	else
	{
		m_options = nullptr;
	}
	if (Init() == FALSE){
		return FALSE;
	}
	return TRUE;
}

int CFFmpegPlayer::Interrupt_cb(void* opaque){
	CFFmpegPlayer* pPlayer = static_cast<CFFmpegPlayer*>(opaque);

	if (pPlayer->m_skipCheckTimeoutFlag) return 0;

	auto diff = (GetTickCount() - pPlayer->m_timeoutPrev);
	if (diff >= pPlayer->m_timeout)
	{
		return 1;
	}
	return 0;
}

BOOL CFFmpegPlayer::Init()
{
	if (m_timeout != 0){
		m_fmtCtx = avformat_alloc_context();
		m_fmtCtx->interrupt_callback.callback = Interrupt_cb;
		m_fmtCtx->interrupt_callback.opaque = this;
		m_timeoutPrev = GetTickCount();
	}
	if (!av_dict_get(m_options, "scan_all_pmts", nullptr, AV_DICT_MATCH_CASE)) {
		av_dict_set(&m_options, "scan_all_pmts", "1", AV_DICT_DONT_OVERWRITE);
	}
	if (avformat_open_input(&m_fmtCtx, m_fileName.c_str(), nullptr, &m_options))
	{
		auto ret = AVERROR(ENOMEM);
		char err_buf[255];
		av_strerror(ret, err_buf, sizeof(err_buf));
		_RPT1(0, "Open_Error:%s\n", err_buf);
		return FALSE;
	}
	av_format_inject_global_side_data(m_fmtCtx);
	if (0 > avformat_find_stream_info(m_fmtCtx, nullptr))
		return FALSE;
	av_dump_format(m_fmtCtx, 0, m_fileName.c_str(), 0);
	m_skipCheckTimeoutFlag = true;
	m_fileName = "";
	try	{
		streamsDetect();
		streamsOpen();
	}
	catch (...)	{
		return FALSE;
	}
	if (hasAudio())
	{
		if (SDL_Init(SDL_INIT_AUDIO))
			return FALSE;
		SDL_memset(&m_audioDesiredSpec, 0, sizeof(m_audioDesiredSpec));
		m_audioDesiredSpec.channels = m_audioCtx->channels;
		m_audioDesiredSpec.freq = m_audioCtx->sample_rate;
		m_decoder.audioSilent = true;
	}
	else
	{
		m_audioDesiredSpec.channels = 1;
		m_audioDesiredSpec.freq = 11025;
		//m_decoder.audioSilent = true;
	}

	m_audioDesiredSpec.silence = 0;
	m_audioDesiredSpec.format = AUDIO_S16SYS;
	m_audioDesiredSpec.samples = m_audioDesiredSpec.freq / SDL_AUDIO_MAX_CALLBACKS_PER_SEC;
	m_audioDesiredSpec.userdata = this;
	m_audioDesiredSpec.callback = [](void* userdata, Uint8* stream, int want_bytes)
	{
		//want_bytes = len
		static int64_t begin_ts;
		auto last_frame = begin_ts;
		begin_ts = av_gettime_relative();
		last_frame = last_frame ? begin_ts - last_frame : 0;

		assert(want_bytes && stream && userdata);
		auto player = static_cast<CFFmpegPlayer*>(userdata);
		auto decoder = static_cast<Decoder*const>(&player->m_decoder);
		auto frames_queue = &decoder->qAudioFrames;

		decoder->syncInfo.mut.lock();
		decoder->syncInfo.audio_probe_ts = begin_ts;
		decoder->syncInfo.playback_ts += last_frame;
		decoder->syncInfo.mut.unlock();

		//std::cout
		//<< "Audio frame: " << last_frame << std::endl
		//<< "Wants: " << want_bytes << std::endl
		//<< "Audio TS: " << decoder->syncInfo.playback_ts << std::endl
		//<< "Audio probe: " << now_ts << std::endl
		;

		if (!player->hasAudio())
		{
			SDL_memset(stream, 0, want_bytes);
			decoder->syncInfo.global_timestamp += last_frame / 1000;
			return;
		}

		if (!frames_queue->Wait(72))
			return; // probably empty
		//frames_queue->Wait();
		if (!decoder->syncInfo.pending_buf)
		{
			decoder->syncInfo.pending_buf = frames_queue->Front()->Raw()->data[0];
			decoder->syncInfo.got_in_buf = av_samples_get_buffer_size(
				nullptr, frames_queue->Front()->Raw()->channels,
				frames_queue->Front()->Raw()->nb_samples,
				static_cast<AVSampleFormat>(frames_queue->Front()->Raw()->format),
				0);
		}

		if (decoder->syncInfo.got_in_buf < want_bytes)
		{
			if (decoder->syncInfo.got_in_buf > 0)
			{
				//assert(decoder->syncInfo.pending_buf == frames_queue->Front()->Raw()->data[0]);

				if (!decoder->audioSilent){
					try{
						std::memcpy(stream, decoder->syncInfo.pending_buf, decoder->syncInfo.got_in_buf);
					}
					catch (...){
						return;
					}
				}
				else
					SDL_memset(stream, 0, decoder->syncInfo.got_in_buf);

				want_bytes -= decoder->syncInfo.got_in_buf;
				stream += decoder->syncInfo.got_in_buf;
			}
			frames_queue->Eat();

			if (!frames_queue->Wait(72))
				return;
			//frames_queue->Wait();
			decoder->syncInfo.global_timestamp +=
				av_frame_get_pkt_duration(frames_queue->Front()->Raw());

			decoder->syncInfo.pending_buf = frames_queue->Front()->Raw()->data[0];
			decoder->syncInfo.got_in_buf = av_samples_get_buffer_size(
				nullptr, frames_queue->Front()->Raw()->channels,
				frames_queue->Front()->Raw()->nb_samples,
				static_cast<AVSampleFormat>(frames_queue->Front()->Raw()->format),
				0);
		}

		if (want_bytes)
		{
			if (!decoder->audioSilent){
				try{
					std::memcpy(stream, decoder->syncInfo.pending_buf, want_bytes);

				}
				catch (...){
					return;
				}
			}
			else
				SDL_memset(stream, 0, want_bytes);
			decoder->syncInfo.got_in_buf -= want_bytes;
			decoder->syncInfo.pending_buf += want_bytes;
		}
	};


	m_audioDevice = SDL_OpenAudioDevice(nullptr, 0,
		&m_audioDesiredSpec, &m_audioSpec, 0);

	m_resampleCtx = swr_alloc();

	if (!QueryPerformanceFrequency(&m_decoder.syncInfo.perfFreq))
		return FALSE;

	try	{
		threadsCreate();
	}
	catch (...)	{
		return FALSE;
	}

	m_valid = true;

	if (m_cbOnInit)
		m_cbOnInit(&m_cbStreamInfo);

	return TRUE;
}

BOOL CFFmpegPlayer::Play()
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
	DEBUG_MSG("Play");

	if (!m_valid)
		return FALSE;

	if (m_paused) {
		unpause();
	}
	else
		return FALSE;

	DEBUG_MSG("++Play");
	return TRUE;
}

BOOL CFFmpegPlayer::Stop()
{
	std::lock_guard<std::recursive_mutex>lock_guard(m_lock);
	DEBUG_MSG("Stop");

	Pause();
	if (!SetPlaybackPosition(0))
		return FALSE;
	//cacheFlush();

	DEBUG_MSG("++Stop");
	return TRUE;
}

BOOL CFFmpegPlayer::Pause()
{
	DEBUG_MSG("Pause");
	if (!m_valid)
		return FALSE;

	try {
		//m_pauseMutex.lock();
		m_paused = true;
		//m_pauseMutex.unlock();
		if (hasAudio())
			stopAudio();
	}
	catch (...) {
		return FALSE;
	}

	DEBUG_MSG("++Pause");
	return TRUE;
}

BOOL CFFmpegPlayer::SwitchSound(BOOL bIsSoundSwitchedOn)
{
	m_decoder.audioSilent = !bIsSoundSwitchedOn;
	return TRUE;
}

BOOL CFFmpegPlayer::GetVolume(BYTE *pbVolumeLevel)
{
	return TRUE;
}

BOOL CFFmpegPlayer::SetVolume(BYTE bVolumeLevel)
{
	return TRUE;
}

BOOL CFFmpegPlayer::GetStreamInfo(PSTREAM_INFO pStreamInfo)
{
	DEBUG_MSG("Get stream info");

	if (!m_valid)
		return FALSE;

	std::memcpy(pStreamInfo, &m_cbStreamInfo, sizeof(*pStreamInfo));

	DEBUG_MSG("++Get stream info");
	return TRUE;
}

BOOL CFFmpegPlayer::SetPlaybackPosition(DWORD dwMilliseconds)
{
	DEBUG_MSG("Position SET");

	if (!m_valid)
		return FALSE;
	m_seekPos = static_cast<decltype(m_seekPos)>((dwMilliseconds / 1000.0) * AV_TIME_BASE);

	DEBUG_MSG("++Position SET");
	return TRUE;
}

DWORD CFFmpegPlayer::GetPlaybackPosition()
{
	DEBUG_MSG("Position GET");

	if (!m_valid)
		return 0;

	DEBUG_MSG("++Position GET");
	//return static_cast<DWORD>(m_decoder.syncInfo.global_timestamp);
	return static_cast<DWORD>(m_current_timestamp);
}

BOOL CFFmpegPlayer::MoveToNextFrame()
{
	if (!m_paused)
	{
		Pause();
	}
	else
	{
		m_oneShot = true;
		m_unpause.notify_one();
	}
	return TRUE;
}

BOOL CFFmpegPlayer::MoveToPreviousFrame()
{
	return TRUE;
}

void CFFmpegPlayer::streamsDetect()
{
	m_videoStreamIndex = av_find_best_stream(m_fmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	m_audioStreamIndex = av_find_best_stream(m_fmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (m_videoStreamIndex < 0)
	{
		if (m_cbOnError)
			std::thread([this]{m_cbOnError("No streams found"); }).detach();
		throw new std::exception("VideoStream not found");
	}
}

void CFFmpegPlayer::streamsOpen()
{
	if (hasVideo())
	{
		m_videoCtx = m_fmtCtx->streams[m_videoStreamIndex]->codec;
		m_codecVideo = avcodec_find_decoder(m_videoCtx->codec_id);
		if (m_codecVideo == nullptr){
			if (m_cbOnError)
				std::thread([this]{m_cbOnError("can't find video codec"); }).detach();
		}
		m_videoCtx->refcounted_frames = 1;
		if (avcodec_open2(m_videoCtx, m_codecVideo, nullptr)){
			if (m_cbOnError)
				std::thread([this]{m_cbOnError("can't open video codec"); }).detach();
		}

		if ((m_videoCtx->width <= 0) || (m_videoCtx->height <= 0) || (m_videoCtx->pix_fmt == AV_PIX_FMT_NONE)){
			if (m_cbOnError)
				std::thread([this]{m_cbOnError("incorrect sdp header"); }).detach();
		}
		m_width = m_videoCtx->width;
		m_height = m_videoCtx->height;
		m_fps = av_q2d(av_guess_frame_rate(m_fmtCtx, m_fmtCtx->streams[m_videoStreamIndex], nullptr));

		m_pixFmt = &m_videoCtx->pix_fmt;

		m_videoCtx->refs = 1;
	}

	if (hasAudio())
	{
		m_audioCtx = m_fmtCtx->streams[m_audioStreamIndex]->codec;

		m_codecAudio = avcodec_find_decoder(m_audioCtx->codec_id);
		if (m_codecAudio == nullptr){
			if (m_cbOnError)
				std::thread([this]{m_cbOnError("can't find audio codec"); }).detach();
		}

		m_audioCtx->refcounted_frames = 1;
		if (avcodec_open2(m_audioCtx, m_codecAudio, nullptr)){
			if (m_cbOnError)
				std::thread([this]{m_cbOnError("can't open video codec"); }).detach();
		}
	}
	m_cbStreamInfo.dwBitrate = m_fmtCtx->bit_rate;
	m_cbStreamInfo.dwFileLengthMilliseconds = static_cast<DWORD>
		((m_fmtCtx->duration != AV_NOPTS_VALUE ? m_fmtCtx->duration : 0) / (AV_TIME_BASE / 1000));
	m_cbStreamInfo.dwHeight = m_height;
	m_cbStreamInfo.dwWidth = m_width;
	m_cbStreamInfo.nFps = static_cast<decltype(m_cbStreamInfo.nFps)>(rint(m_fps));
}

void CFFmpegPlayer::threadsCreate()
{
	startDemuxer();
	if (hasVideo())
		startDecoderVideo();
	if (hasAudio())
		startDecoderAudio();
	//startRenderer();
}

void CFFmpegPlayer::startDemuxer()
{
	std::thread([this]()
	{
		DEBUG_MSG("Demuxer started");

		try
		{
			m_decoder.demux_state = state::InProgress;

			Packet::Ptr aborted_pkt;
			int iFrameCount = 0;
			int defaultSize = DEMUXER_QUEUE_SIZE;
			while (!m_quit)
			{
				std::unique_lock<decltype(m_pauseWorldMutex)> lk(m_pauseWorldMutex);
				m_unpauseWorld.wait(lk, [this] {
					return !m_pausedWorld;
				});

				Packet::Ptr pkt;
				if (!aborted_pkt)
				{
					pkt = Packet::New();
					m_timeout = 1000;
					m_timeoutPrev = GetTickCount();
					m_skipCheckTimeoutFlag = false;

					auto ret = av_read_frame(m_fmtCtx, pkt->Raw());

					if ((ret == AVERROR_EOF || avio_feof(m_fmtCtx->pb))) {
						auto errnum = AVERROR(ENOMEM);
						char err_buf[255];
						av_strerror(errnum, err_buf, sizeof(err_buf));
						clog << "Error:" << err_buf << "\n";
						m_decoder.demux_state = state::Finished;
						m_decoder.qVideoPackets.Abort();
						m_decoder.qAudioPackets.Abort();
						break;	// Eof or error
					}
					m_skipCheckTimeoutFlag = true;
				}
				else {
					pkt = std::move(aborted_pkt);
				}

				try
				{
					if (!m_startDecodeAndRender){
						if (pkt->Raw()->flags == AV_PKT_FLAG_KEY ||
							pkt->Raw()->flags == AV_PKT_FLAG_KEY + AV_PKT_FLAG_CORRUPT ||
							pkt->Raw()->flags == AV_PKT_FLAG_KEY + AV_PKT_FLAG_CORRUPT + AV_PKT_FLAG_DISCARD)
						{
							m_startDecodeAndRender = iFrameCount > 0;
							iFrameCount++;
						}
						if (m_decoder.qVideoPackets.Size() >= defaultSize - 5)
						{
							auto currentSize = m_decoder.qVideoPackets.Size();
							defaultSize = currentSize + 50;
							m_decoder.qVideoPackets.SetCapacity(defaultSize);
							clog << "Demuxer Video: " << m_decoder.qVideoPackets.Size() << "\n";
						}
					}

					/*auto minAudio = m_decoder.qAudioPackets.Size() <= m_decoder.qVideoPackets.Size();
					auto capacityVideo = 0,
					capacityAudio = 0;
					if (minAudio)
					{
					capacityAudio = QUEUE_SIZE_THRESH;
					}
					else
					{
					capacityVideo = QUEUE_SIZE_THRESH;
					}

					m_decoder.qAudioPackets.SetCapacity(capacityAudio);
					m_decoder.qVideoPackets.SetCapacity(capacityVideo);*/


					if (pkt->Raw()->stream_index == m_videoStreamIndex)
					{
						//_RPT1(0, "Demuxer_PTS: %i\n", pkt->Raw()->pts);
						m_decoder.qVideoPackets.Push(std::move(pkt));
						//_RPT0(0, "VPACKETPUSH\n");
					}
					else if (pkt->Raw()->stream_index == m_audioStreamIndex && IsAudioEnabled())
					{
						//std::clog << "Audio PACKET push" << std::endl;
						m_decoder.qAudioPackets.Push(std::move(pkt));
					}
				}
				catch (const Queue::abort &)
				{
					aborted_pkt = std::move(pkt);
				}
			}
			if (m_quit)
				m_decoder.demux_state = state::Interrupted;
		}

		catch (const Queue::terminate&)
		{	// safe quit
			assert(m_quit);
			m_decoder.demux_state = state::Interrupted;
		}
		catch (const std::exception &e)
		{
			std::cerr << "An error occurred in demuxing thread: " << e.what() << std::endl;
			std::abort();
		}

		DEBUG_MSG("Demuxer stopped");
	}).detach();
}

void CFFmpegPlayer::startDecoderVideo()
{
	std::thread([this]()
	{
		DEBUG_MSG("Video decoder started");

		int frame_finished;
		Decoder::PicturePtr /*aborted_pic,*/ pic;
		m_decoder.vDecode_state = state::InProgress;
		AVFrame *frame = av_frame_alloc();
		auto StartTimePlayback = av_gettime_relative();
		try
		{
			SDL_Init(SDL_INIT_VIDEO);
			SDL_Window *screen = SDL_CreateWindowFrom(m_hMainWindow);
			SDL_Renderer *sdlRenderer = SDL_CreateRenderer(screen, -1, 0);
			SDL_Texture *sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STATIC, m_videoCtx->width, m_videoCtx->height);

			while (!m_quit)
			{
				if (m_startDecodeAndRender){
					std::unique_lock<decltype(m_pauseMutex)> lk(m_pauseMutex);
					m_unpause.wait(lk, [this] {
						return !m_paused || m_oneShot;
					});
					if (m_seekPos >= 0)
						seek();

					if (m_decoder.qVideoPackets.Empty() && m_decoder.demux_state == state::Finished)
					{
						if (m_cbOnEof != nullptr){
							_RPT1(0, "Disconnect!", 0);
							m_cbOnEof();
						}
						break;
					}

					Packet::Ptr pkt;



					try{
						pkt = m_decoder.qVideoPackets.Pop();
					}
					catch (const Queue::abort &){
						continue;
					}

					if (!pkt){
						if (m_cbOnError)
							std::thread([this]{m_cbOnError("empty packet in video queue"); }).detach();
					}

					auto startTime = av_gettime_relative();
					auto ret = avcodec_decode_video2(m_videoCtx, frame, &frame_finished, pkt->Raw());

					if (ret < 0 && ret != AVERROR(EAGAIN) && ret != AVERROR_EOF){
						auto errnum = AVERROR(ENOMEM);
						char err_buf[255];
						av_strerror(errnum, err_buf, sizeof(err_buf));
						clog << "Error:%s\n" << err_buf;
						break;
					}
					if (frame_finished){
						try{
							Render(startTime, sdlTexture, sdlRenderer, frame);
						}
						catch (const Queue::abort &){
						}
					}
				}
			}
		}
		catch (const Queue::terminate &)
		{	// safe quit
			assert(m_quit);
		}
		catch (const std::exception &e)
		{
			std::cerr << "An error occurred in video decoding thread: " << e.what() << std::endl;
			std::abort();
		}
		_RPT1(0, "PlaybackTime: %i", ((av_gettime_relative() - StartTimePlayback) / AV_TIME_BASE));
		if (m_quit)
			m_decoder.vDecode_state = state::Interrupted;
		else
			m_decoder.vDecode_state = state::Finished;

		DEBUG_MSG("Video decoder stopped");
	}).detach();
}

void CFFmpegPlayer::startDecoderAudio()
{
	std::thread([this]()
	{
		DEBUG_MSG("Audio decoder started");

		try
		{
			int frame_finished;

			m_decoder.aDecode_state = state::InProgress;
			//Frame::Ptr aborted_frame;

			while (!m_quit)
			{
				if (m_decoder.qAudioPackets.Empty() && m_decoder.demux_state == state::Finished)
					break;

				Packet::Ptr pkt;

				try	{
					pkt = m_decoder.qAudioPackets.Pop();
				}
				catch (const Queue::abort &){ continue; }

				if (!pkt){
					if (m_cbOnError)
						std::thread([this]{m_cbOnError("empty packet in audio queue"); }).detach();
				}

				auto frame = Frame::New();

				auto decoded = avcodec_decode_audio4(m_audioCtx, frame->Raw(), &frame_finished, pkt->Raw());
				if (0 > decoded){
					if (m_cbOnError)
						std::thread([this]{m_cbOnError("can't decode audio packet"); }).detach();
				}
				assert(decoded == pkt->Raw()->size);

				if (frame_finished)
				{
					try {
						//if (aborted_frame)
						//	m_decoder.qAudioFrames.Push(std::move(aborted_frame));

						if (frame->Raw()->format != m_dstSndFmt)
							frame = resampleAudio(std::move(frame));

						auto msec = av_q2d(m_fmtCtx->streams[m_audioStreamIndex]->time_base) * 1000;
						frame->Raw()->pkt_duration = av_frame_get_pkt_duration(frame->Raw()) * static_cast<int64_t>(msec);

						//std::clog << "Audio FRAME push" << std::endl;
						m_decoder.qAudioFrames.Push(std::move(frame));
					}
					catch (const Queue::abort &) {
						//aborted_frame = std::move(frame);
					}
				}
			}
		}
		catch (const Queue::terminate&)
		{	// safe quit
			assert(m_quit);
		}
		catch (const std::exception &e)
		{
			std::cerr << "An error occurred in audio decoding thread: " << e.what() << std::endl;
			std::abort();
		}
		if (hasAudio())
			stopAudio();

		SDL_CloseAudioDevice(m_audioDevice);

		if (m_quit)
			m_decoder.aDecode_state = state::Interrupted;
		else
			m_decoder.aDecode_state = state::Finished;

		DEBUG_MSG("Audio decoder stopped");
	}).detach();
}

Frame::Ptr CFFmpegPlayer::resampleAudio(Frame::Ptr frame)
{
	frame->Raw()->channel_layout =
		!m_audioCtx->channel_layout ?
		av_get_default_channel_layout(m_audioCtx->channels) :
		m_audioCtx->channel_layout;

	auto resampled = Frame::New();

	resampled->Raw()->channel_layout = frame->Raw()->channel_layout;
	resampled->Raw()->sample_rate = frame->Raw()->sample_rate/* * m_speedScaleFactor*/;
	resampled->Raw()->format = m_dstSndFmt;

	if (auto err = swr_convert_frame(m_resampleCtx, resampled->Raw(), frame->Raw()))
		throw std::exception("cannot resample audio");

	//	auto msec = av_q2d(m_fmtCtx->streams[m_audioStreamIndex]->time_base) * 1000;
	//
	//resampled->Raw()->pkt_dts					= frame->Raw()->pkt_dts;
	//resampled->Raw()->pkt_pts					= frame->Raw()->pkt_pts;
	//resampled->Raw()->pts						= frame->Raw()->pts;
	//resampled->Raw()->best_effort_timestamp		= av_frame_get_best_effort_timestamp(frame->Raw());
	resampled->Raw()->pkt_duration = av_frame_get_pkt_duration(frame->Raw());

	return resampled;
}

void CFFmpegPlayer::Render(int64_t startTime, SDL_Texture *sdlTexture, SDL_Renderer *sdlRenderer, AVFrame *frame)
{
	auto frameDuration = AV_TIME_BASE / av_q2d(av_guess_frame_rate(m_fmtCtx, m_fmtCtx->streams[m_videoStreamIndex], nullptr));
	SDL_UpdateYUVTexture(sdlTexture, nullptr, frame->data[0], frame->linesize[0], frame->data[1], frame->linesize[1], frame->data[2], frame->linesize[2]);
	SDL_RenderCopy(sdlRenderer, sdlTexture, nullptr, nullptr);
	SDL_RenderPresent(sdlRenderer);
	auto endRender = av_gettime_relative();
	auto renderTime = static_cast<double>(endRender - startTime);
	auto delay = frameDuration - renderTime;
	if (delay > 0)
		std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(rint(delay))));
}

void CFFmpegPlayer::startRenderer()
{
	std::thread([this]()
	{
		DEBUG_MSG("Renderer started");
		int numBytes;
		uint8_t* buffer = nullptr;
		auto starttime = av_gettime_relative();
		SwsContext* sws_context = nullptr;
		try
		{
			m_rendererState = state::InProgress;
			const auto frame_q = AV_TIME_BASE / m_fps;

			int64_t playback_video_ts{ 0 };
			//int64_t drift{ 0 };
			int64_t begin_ts{ 0 };

			int count = 0;
			// warm up the buffer
			while (m_decoder.qVideoFrames.Size() < DEMUXER_QUEUE_SIZE)
			{
				Sleep(50);
				clog << "Waiting for buffer: " << count
					<< " Size: " << m_decoder.qVideoFrames.Size() << "\n";
				count++;
			}
			if (hasAudio()){
				while (!m_decoder.syncInfo.audio_probe_ts && !m_quit)
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}

			SDL_Init(SDL_INIT_VIDEO);
			SDL_Window *screen = SDL_CreateWindowFrom(m_hMainWindow);
			SDL_Renderer *sdlRenderer = SDL_CreateRenderer(screen, -1, 0);
			SDL_Texture *sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STATIC, m_videoCtx->width, m_videoCtx->height);

			while (!m_quit)
			{
				begin_ts = av_gettime_relative();

				std::unique_lock<decltype(m_pauseMutex)> lk(m_pauseMutex);
				m_unpause.wait(lk, [this] {
					return !m_paused || m_oneShot;
				});
				m_oneShot = false;

				if (m_seekPos >= 0)
					seek();

				if (m_decoder.qVideoFrames.Empty()){
					if (m_decoder.vDecode_state == state::Finished) {
						//if (!m_cbOnEof)
						//	//если возникает непредвиденный разрыв то выкидываем ошибку
						//	throw std::exception("Playback stopped!");
						if (m_cbOnEof != nullptr){
							_RPT1(0, "Disconnect!", 0);
							m_cbOnEof();
						}
						break;
					}
					continue;
				}

				Frame::Ptr frame;
				try
				{
					/*if (m_decoder.qVideoFrames.Size()<20)
					{
					_RPT0(0, "Video frames size less than 20\n");
					m_decoder.qVideoFrames.Wait(10);
					continue;
					}*/
					frame = m_decoder.qVideoFrames.Pop();
					clog << "Render Video: " << m_decoder.qVideoFrames.Size() << "\n";
					//_RPT0(0, "VFRAMEPOP\n");
				}
				catch (const Queue::abort&)
				{
					_RPT0(0, "Abort Pop!\n");
					continue;
				}

				if (!frame){
					if (m_cbOnError)
						std::thread([this]{m_cbOnError("empty frame"); }).detach();
				}

				//_RPT1(0, "DELTA: %i", pic->pts - playback_video_ts);
				playback_video_ts = frame->Raw()->pts;

				//_RPT1(0, "Render_PTS: %i\n", playback_video_ts);


				SDL_UpdateYUVTexture(sdlTexture, NULL, frame->Raw()->data[0], frame->Raw()->linesize[0], frame->Raw()->data[1], frame->Raw()->linesize[1], frame->Raw()->data[2], frame->Raw()->linesize[2]);
				SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
				SDL_RenderPresent(sdlRenderer);

				auto end_ts = av_gettime_relative();
				auto render_ts = static_cast<double>(end_ts - begin_ts) / AV_TIME_BASE;
				auto delay = (frame_q - render_ts)/* * m_speedScaleFactor*/;
				//if (delay > 0)
				//std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(rint(delay))));
				m_current_timestamp = playback_video_ts;
			}
			sws_freeContext(sws_context);
		}
		catch (const Queue::terminate&)
		{	// safe quit
			assert(m_quit);
		}
		catch (const std::exception &e)
		{
			std::cerr << "An error occurred in rendering thread: " << e.what() << std::endl;
		}

		if (hasAudio())
			stopAudio();

		av_free(buffer);

		SDL_CloseAudioDevice(m_audioDevice);

		_RPT1(0, "Playback Time: %i", (av_gettime_relative() - starttime) / AV_TIME_BASE);

		if (m_quit)
			m_rendererState = state::Interrupted;
		else
			m_rendererState = state::Finished;


		DEBUG_MSG("Renderer stopped");

	}).detach();
}

bool CFFmpegPlayer::IsAudioEnabled()
{
	return m_audioDevice > 0;
}

void CFFmpegPlayer::cacheFlush()
{
	DEBUG_MSG("Flushing cache");

	try {
		m_decoder.qVideoPackets.Clear();
		m_decoder.qAudioPackets.Clear();
		// get rid of pending pushes
		m_decoder.qVideoFrames.Abort();
		m_decoder.qAudioFrames.Abort();
		m_decoder.qVideoFrames.Clear();
		m_decoder.qAudioFrames.Clear();

		m_decoder.syncInfo.pending_buf = nullptr;
	}
	catch (const std::exception &e)
	{
		std::cerr << "can't flush cache: " << e.what() << std::endl;
	}

	DEBUG_MSG("++Flushing cache");
}

void CFFmpegPlayer::cacheAbortPending()
{
	DEBUG_MSG("Aborting cache");

	try {
		m_decoder.qVideoPackets.Abort();
		m_decoder.qAudioPackets.Abort();
		m_decoder.qVideoFrames.Abort();
		m_decoder.qAudioFrames.Abort();
	}
	catch (const std::exception &e)
	{
		std::cerr << "can't abort pending cache: " << e.what() << std::endl;
	}

	DEBUG_MSG("++Aborting cache");
}

void CFFmpegPlayer::unpause()
{
	DEBUG_MSG("Unpause");

	assert(m_paused);
	m_paused = false;
	m_unpause.notify_all();
	//if (hasAudio())
	startAudio();

	DEBUG_MSG("++Unpause");
}

BOOL CFFmpegPlayer::InputData(BYTE* pBuf, DWORD dwSize)
{
	throw std::logic_error("The method or operation is not implemented.");
}

BOOL CFFmpegPlayer::IncreasePlaybackSpeed()
{
	return FALSE;
}

BOOL CFFmpegPlayer::DecreasePlaybackSpeed()
{
	return FALSE;
}

BOOL CFFmpegPlayer::SaveSnapshot(std::string path, std::string name)
{
	m_SnapshootPath = StringToWString(path);
	m_SnapshootName = StringToWString(name);
	m_saveSnapShoot = true;
	return FALSE;
}

void CFFmpegPlayer::stopAudio()
{
	SDL_PauseAudioDevice(m_audioDevice, 1);
}

void CFFmpegPlayer::startAudio()
{
	// warm up the cache first
	if (hasAudio())
	{
		m_decoder.qAudioFrames.Wait(300);
	}
	SDL_PauseAudioDevice(m_audioDevice, 0);
}

bool CFFmpegPlayer::hasAudio() const
{
	return m_audioStreamIndex >= 0;
}

bool CFFmpegPlayer::hasVideo() const
{
	return m_videoStreamIndex >= 0;
}

void CFFmpegPlayer::pauseWorld()
{
	m_pausedWorld = true;

	m_decoder.qAudioPackets.Abort();
	m_decoder.qVideoPackets.Abort();

	stopAudio();
}

void CFFmpegPlayer::resumeWorld()
{
	m_pausedWorld = false;
	m_unpauseWorld.notify_all();
	startAudio();
}

void CFFmpegPlayer::seek()
{
	pauseWorld();

	m_decoder.syncInfo.global_timestamp = (m_seekPos / 1000);
	m_current_timestamp = static_cast<DWORD>(m_decoder.syncInfo.global_timestamp);
	m_seekPos = av_rescale_q(m_seekPos, AVRational{ 1, AV_TIME_BASE },
		m_fmtCtx->streams[m_videoStreamIndex]->time_base);

	if (avformat_seek_file(m_fmtCtx, m_videoStreamIndex, INT64_MIN, m_seekPos, INT64_MAX, AVSEEK_FLAG_ANY) >= 0)
	{
		//avcodec_flush_buffers(m_videoCtx);
		//avcodec_flush_buffers(m_audioCtx);
		avformat_flush(m_fmtCtx);
		cacheFlush();
	}

	m_seekPos = -1;

	resumeWorld();
}

