#pragma once
#include "BasePlayer.h"
#include "Queue.h"
#include <gdiplus.h>
#include <fstream>

class Frame	final
{
public:
	using Ptr = std::unique_ptr < Frame >;

	Frame() :
		m_frame{ av_frame_alloc() }
	{
		if (!m_frame)
			throw std::bad_alloc();
	}

	~Frame()
	{
		//std::clog << "Frame DESTROY" << std::endl;
		av_frame_unref(m_frame);
		av_frame_free(&m_frame);
	}

	AVFrame* Raw() const
	{
		return m_frame;
	}

	static Ptr New()
	{
		//std::clog << "Frame CREATE" << std::endl;
		return std::make_unique<Frame>();
	}

private:
	AVFrame *m_frame;
};

class Packet final
{
public:
	using Ptr = std::unique_ptr < Packet >;

	Packet() :
		m_packet{ static_cast<decltype(m_packet)>(av_malloc(sizeof(*m_packet))) }
	{
		if (!m_packet)
			throw std::bad_alloc();
	}

	~Packet()
	{
		//std::clog << "Packet DESTROY" << std::endl;
		av_free_packet(m_packet);
		av_free(m_packet);
	}

	AVPacket* Raw() const
	{
		return m_packet;
	}

	bool Valid() const
	{
		return !!m_packet->buf;
	}

	static Ptr New()
	{
		//std::clog << "Packet CREATE" << std::endl;
		return std::make_unique<Packet>();
	}

private:
	AVPacket *m_packet;
};

class Logging
{
	streambuf* savedBufferCLOG;
	std::ofstream mylog;
public:
	Logging::Logging()
	{
		savedBufferCLOG = clog.rdbuf();
		mylog.open("ffmpegplayer.txt");
		clog.rdbuf(mylog.rdbuf());
	}

	Logging::~Logging()
	{
		clog.rdbuf(savedBufferCLOG);
		mylog.close();
	}
};

class CFFmpegPlayer : public CBasePlayer
{
	int										m_timeout = 0;
	bool									m_skipCheckTimeoutFlag{ false };
	unsigned long							m_timeoutPrev = 0;
	const AVPixelFormat						m_dstPixFmt{ AV_PIX_FMT_YUV420P };
	const AVSampleFormat					m_dstSndFmt{ AV_SAMPLE_FMT_S16 };
	const Uint16							AUDIO_SAMPLES{ 1024 };
	static const std::size_t				DEMUXER_QUEUE_SIZE{ 10 };
	static const std::size_t				VIDEO_QUEUE_SIZE{ 60 };
	static const std::size_t				AUDIO_QUEUE_SIZE{ 60 };
	static const std::size_t				QUEUE_SIZE_THRESH{ 20 };

	std::string								m_fileName;
	bool									m_startDecodeAndRender{ false };
	AVFormatContext							*m_fmtCtx{ nullptr };
	AVDictionary							*m_options{ NULL }; // словарь с опциями для поднятия rtp соединения
	AVCodec									*m_codecAudio{ nullptr }, *m_codecVideo{ nullptr };
	AVCodecContext							*m_audioCtx{ nullptr }, *m_videoCtx{ nullptr };
	int										m_videoStreamIndex{ -1 }, m_audioStreamIndex{ -1 };

	AVPixelFormat							*m_pixFmt{ nullptr };
	int										m_width{ 0 }, m_height{ 0 };
	double									m_fps;

	//float									m_speedScaleFactor{ 1.0 };

	SwrContext								*m_resampleCtx{ nullptr };

	SDL_AudioSpec							m_audioSpec, m_audioDesiredSpec{};
	SDL_AudioDeviceID						m_audioDevice;

	std::recursive_mutex					m_lock;

	enum class state
	{
		None,
		InProgress,
		Finished,
		Interrupted
	};

	struct Decoder
	{
		std::function<void(AVPicture*)>		deleterPicture;

		using PicturePtr = std::unique_ptr < AVPicture, decltype(deleterPicture) >;

		Queue::ThreadSafe<Packet::Ptr>		qAudioPackets{ DEMUXER_QUEUE_SIZE };
		Queue::ThreadSafe<Packet::Ptr>		qVideoPackets{ DEMUXER_QUEUE_SIZE };
		Queue::ThreadSafe<Frame::Ptr>		qAudioFrames{ AUDIO_QUEUE_SIZE };
		Queue::ThreadSafe<Frame::Ptr>		qVideoFrames{ VIDEO_QUEUE_SIZE };

		state								demux_state{ state::None };
		state								aDecode_state{ state::None };
		state								vDecode_state{ state::None };
		std::atomic<bool>					audioSilent{ true };

		struct
		{
			int64_t					audio_probe_ts;
			int64_t					playback_ts;
			std::atomic<int64_t>	global_timestamp;
			LARGE_INTEGER			perfFreq;
			std::mutex				mut;
			Uint8*					pending_buf;
			int						got_in_buf;
		} syncInfo;
	} m_decoder;

	int64_t									m_seekPos{ -1 };
	LONGLONG								m_timestamp{ 0 };
	std::atomic<int64_t>					m_current_timestamp;

	bool									m_valid{ false };
	bool									m_quit{ false };
	std::condition_variable					m_unpause;
	std::condition_variable					m_unpauseWorld;
	std::mutex								m_pauseMutex;
	std::mutex								m_pauseWorldMutex;
	bool									m_paused{ true };
	bool									m_pausedWorld{ false };
	bool									m_oneShot{ false };
	state									m_rendererState{ state::None };

	STREAM_INFO								m_cbStreamInfo;
	FEndInitCallback						m_cbOnInit;
	FDecodeCallback							m_cbOnFrame;
	FFileEndCallback						m_cbOnEof;
	FErrorCallback							m_cbOnError;

public:

	CFFmpegPlayer(PCHAR pchFileName, FDecodeCallback fOnFrame, FFileEndCallback fOnEof, FEndInitCallback fOnInit, FErrorCallback fOnError, int timeout, HWND h_MainWindow);

	~CFFmpegPlayer();

	BOOL Open() override;

	BOOL Play() override;

	BOOL Stop() override;

	BOOL Pause() override;

	BOOL SwitchSound(BOOL bIsSoundSwitchedOn) override;

	BOOL GetVolume(BYTE *pbVolumeLevel) override;

	BOOL SetVolume(BYTE bVolumeLevel) override;

	BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo) override;

	BOOL SetPlaybackPosition(DWORD dwMilliseconds) override;

	DWORD GetPlaybackPosition() override;

	BOOL MoveToNextFrame() override;

	BOOL MoveToPreviousFrame() override;

	BOOL IncreasePlaybackSpeed() override;

	BOOL DecreasePlaybackSpeed() override;

	BOOL SaveSnapshot(std::string path, std::string name) override;

	// не используется
	virtual DWORD GetSourceBufferMaxSize() override { return 0; }

	// не используется
	virtual DWORD GetSourceBufferRemainSize() override { return 0; }

	// не используется
	virtual BOOL WINAPI ResetSourceBuffer() override { return FALSE; }

	//Инициализация режима - отображение потока из файла
	virtual BOOL InitializationFileMode() override { return TRUE; }


private:
	void streamsDetect();
	void streamsOpen();

	Frame::Ptr resampleAudio(Frame::Ptr frame);
	void Render(int64_t startTime, SDL_Texture* sdlTexture, SDL_Renderer* sdlRenderer, AVFrame* frame);

	Decoder::PicturePtr convertColorSpace(Frame::Ptr frame);

	void threadsCreate();
	void startDemuxer();
	void startDecoderVideo();
	void startDecoderAudio();

	void startRenderer();

	void cacheFlush();
	void cacheAbortPending();

	void unpause();
	bool hasAudio() const;
	bool hasVideo() const;
	bool IsAudioEnabled(); // состояние аудио дорожки

	void pauseWorld();
	void resumeWorld();

	void seek();

	void stopAudio();
	void startAudio();

	BOOL Init();

	static int Interrupt_cb(void *ctx);

	BOOL InputData(BYTE* pBuf, DWORD dwSize) override;
};

