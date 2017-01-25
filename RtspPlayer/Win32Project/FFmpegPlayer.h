#pragma once
#include "BasePlayer.h"
#include "Queue.h"
#include <gdiplus.h>

class Frame	final
{
public:
	using Ptr = std::unique_ptr < Frame > ;

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
	using Ptr = std::unique_ptr < Packet > ;

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

static int								timeout;
static bool								timeoutFlag;
static unsigned long					timeoutPrev;

class CFFmpegPlayer : public CBasePlayer
{
	int										m_timeout;
	const AVPixelFormat						m_dstPixFmt{ AV_PIX_FMT_YUV420P };
	const AVSampleFormat					m_dstSndFmt{ AV_SAMPLE_FMT_S16 };
	const Uint16							AUDIO_SAMPLES{ 1024 };
	static const std::size_t				DEMUXER_QUEUE_SIZE{ 400 };
	static const std::size_t				VIDEO_QUEUE_SIZE{ 30 };
	static const std::size_t				AUDIO_QUEUE_SIZE{ 60 };
	static const std::size_t				QUEUE_SIZE_THRESH{ 3 };

	std::string								m_fileName;

	AVFormatContext							*m_fmtCtx{ nullptr };
	AVDictionary							*m_options{ NULL }; // словарь с опци€ми дл€ подн€ти€ rtp соединени€
	AVCodec									*m_codecAudio, *m_codecVideo;
	AVCodecContext							*m_audioCtx, *m_videoCtx;
	int										m_videoStreamIndex{ -1 }, m_audioStreamIndex{ -1 };

	AVFrame									*pFrame{ NULL };
	AVPacket								m_packet;
	AVPixelFormat							*m_pixFmt;
	int										m_width{ 0 }, m_height{ 0 };
	double									m_fps;

	//float									m_speedScaleFactor{ 1.0 };

	SwsContext								*m_scaleCtx{ NULL };
	SwrContext								*m_resampleCtx;

	SDL_AudioSpec							m_audioSpec, m_audioDesiredSpec{};
	SDL_AudioDeviceID						m_audioDevice;
	Gdiplus::GdiplusStartupInput			gdiplusStartupInput;
	ULONG_PTR								m_gdiplusToken;
	
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

		using PicturePtr = std::unique_ptr < AVPicture, decltype(deleterPicture) > ;

		Queue::ThreadSafe<Packet::Ptr>		qAudioPackets{ DEMUXER_QUEUE_SIZE };
		Queue::ThreadSafe<Packet::Ptr>		qVideoPackets{ DEMUXER_QUEUE_SIZE };
		Queue::ThreadSafe<Frame::Ptr>		qAudioFrames{ AUDIO_QUEUE_SIZE };
		Queue::ThreadSafe<Frame::Ptr>		qVideoFrames/*{ VIDEO_QUEUE_SIZE }*/;

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

	STREAM_INFO								m_callbackInfo;
	FEndInitCallback						m_cbOnInit;
	FDecodeCallback							m_cbOnFrame;
	FFileEndCallback						m_cbOnEof;

public:
	CFFmpegPlayer(PCHAR pchFileName,
		FDecodeCallback fOnFrame,
		FFileEndCallback fOnEof,
		FEndInitCallback fOnInit,
		int timeOut,
		HWND h_MainWindow)
		: CBasePlayer(pchFileName, fOnFrame, fOnEof, fOnInit, h_MainWindow)
		, m_fileName(pchFileName)
		, m_cbOnInit(fOnInit)
		, m_cbOnFrame(fOnFrame)
		, m_cbOnEof(fOnEof)
	{
		m_timeout = timeOut;
		m_decoder.deleterPicture = [](AVPicture* pic)
		{
			avpicture_free(pic);
			av_free(pic);
		};
	}

	~CFFmpegPlayer()
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
		swr_free(&m_resampleCtx);
		sws_freeContext(m_scaleCtx);
		avcodec_close(m_audioCtx);
		avcodec_close(m_videoCtx);
		av_dict_free(&m_options); // очищаем словарь
		avformat_close_input(&m_fmtCtx);
	}

	BOOL Open();

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

	// не используетс€
	virtual DWORD GetSourceBufferMaxSize() override { return 0; }

	// не используетс€
	virtual DWORD GetSourceBufferRemainSize() override { return 0; }

	// не используетс€
	virtual BOOL WINAPI ResetSourceBuffer() override { return FALSE; }

	//»нициализаци€ режима - отображение потока из файла
	virtual BOOL InitializationFileMode() override { return TRUE; }


private:
	void streamsDetect();
	void streamsOpen();

	Frame::Ptr resampleAudio(Frame::Ptr frame);
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
	bool IsAudioEnabled(); // состо€ние аудио дорожки

	void pauseWorld();
	void resumeWorld();

	void seek();

	void stopAudio();
	void startAudio();

	BOOL Init();
	static int Interrupt_cb(void *ctx);
	BOOL InputData(BYTE* pBuf, DWORD dwSize) override;
};

