#pragma once
#include "BasePlayer.h"
#include <gdiplus.h>

#define SDL_AUDIO_BUFFER_SIZE 1024
#define AUDIO_BUF_SIZE ((192000  * 3) / 2)
#define MAX_AUDIO_BUF_SIZE (192000  * 4)

typedef struct PacketQueue {
	AVPacketList *first_pkt, *last_pkt;
	int nb_packets;
	int size;
	int eof;
	SDL_mutex* mutex;
	SDL_cond* cond;
} PacketQueue;

class CRtspPlayer
{
	std::string								m_fileName;							//Filename
	HWND									m_hMainWindow;
	AVDictionary							*m_options{ nullptr };				//AVDictionary
	AVFormatContext							*m_fmtCtx{ nullptr };				//AVFormatContext
	int										m_videoStreamIndex{ -1 };			//VideoStreamIndex
	int										m_audioStreamIndex{ -1 };			//AudioStreamIndex
	AVCodecContext							*m_videoCodecCtx;					//AVCodecContext
	AVCodecContext							*m_audioCodecCtx;					//AVCodecContext
	AVCodec									*m_videoCodec;						//VidoCodec
	AVCodec									*m_audioCodec;						//AudioCodec
	int										m_width{ 0 };						//AVCodecContext->Width
	int										m_height{ 0 };						//AVCodecContext->Height
	double									m_fps;								//Frames per second
	AVPixelFormat							*m_pixFmt;							//AVPixelFormat
	SDL_AudioSpec							m_audioWantedSpec{};				//SDL_AudioSpec
	SDL_AudioSpec							m_audioSpec;						//SDL_AudioSpec
	SwsContext								*m_scaleCtx{ NULL };				//SwsContext
	const AVPixelFormat						m_dstPixFmt{ AV_PIX_FMT_YUV420P };	//Destination PixelFormat
	Gdiplus::GdiplusStartupInput			gdiplusStartupInput;
	double									m_videoClock;						//VideoRender freq
	double									m_audioClock;						//AudioPlay freq
	double									frame_timer;						//CurrentTime
	double									frame_last_pts;						//LastFrame PTS
	double									frame_last_delay;					//LastFrame delay
	bool									m_quit{ FALSE };
	
	struct RingBuffer {
		uint8_t*							data;
		int									size;
		int									max_size;
		int									rindex;  // Read position
		int									windex;  // Write position
		char								eof;  // EOF flag
		char								lastop;  // last operation flag: 0 - read, 1 - write
		SDL_mutex*							mutex;
		SDL_cond*							rcond;
		SDL_cond*							wcond;
	};
		
	PacketQueue								m_videoq;
	PacketQueue								m_audioq;
	RingBuffer								m_videoBuffer;
	RingBuffer								m_audioBuffer;

	SDL_Thread*								demux_tid;
	SDL_Thread*								video_decode_tid;
	SDL_Thread*								audio_decode_tid;
	
	STREAM_INFO								m_callbackInfo;
	FEndInitCallback						m_cbOnInit;
	FDecodeCallback							m_cbOnFrame;
	FFileEndCallback						m_cbOnEof;

	ULONG_PTR								m_gdiplusToken;
public:
	CRtspPlayer(PCHAR pchFileName,
		HWND h_MainWindow)
	{		
		m_fileName = pchFileName;
		m_hMainWindow = h_MainWindow;
	}

	~CRtspPlayer()
	{
		Gdiplus::GdiplusShutdown(m_gdiplusToken);
		sws_freeContext(m_scaleCtx);
		if (m_audioCodecCtx != NULL){
			avcodec_close(m_audioCodecCtx);
		}
		avcodec_close(m_videoCodecCtx);
		av_dict_free(&m_options); // очищаем словарь
		avformat_close_input(&m_fmtCtx);
	}


	BOOL Open();
	void DemuxerNew();
	void VideoDecoderNew();

private:
	void streamsDetect();
	void streamsOpen();


	void threadsCreate();
	void ThreeInOne();
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

	BOOL OpenNew();
	BOOL InitNew();
	void FindBestStreamNew();
	bool hasVideoNew();
	bool hasAudioNew();
	void FindDecoderNew();
	void ConfigAudioNew();
	void AudioCallbackNew(uint8_t* stream, int len);
	double SynchronizeVideoNew(AVFrame *src_frame, double pt);
	void AudioDecoderNew();
	BOOL RenderNew();
	void ThreadStartNew();


	void PacketQueueInit(PacketQueue* q);
	void PacketQueueDeinit(PacketQueue* q);
	int PacketQueuePush(PacketQueue* q, AVPacket* pkt);
	int PacketQueuePop(PacketQueue* q, AVPacket* pkt, int block);
	void PacketQueueEof(PacketQueue* q);

	int RingBufferInit(RingBuffer* rb, int initSize, int maxSize);
	void RingBufferDeinit(RingBuffer* rb);
	int RingBufferWrite(RingBuffer* rb, void* buffer, int len, int block);
	int RingBufferRead(RingBuffer* rb, void* buffer, int len, int block);
	int RingBufferSize(RingBuffer* rb);
	void RingBufferEof(RingBuffer* rb);


};

