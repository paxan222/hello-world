#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#include <memory>
#include <condition_variable>
#include <thread>
#include <cassert>
#include <iostream>
#include <atomic>
#include <string>
#include <SDL.h>

#undef main

extern "C" {
#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libavformat\avio.h>
#include <libavutil\time.h>
#include <libswresample\swresample.h>
}
#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avutil.lib")
#pragma comment (lib, "swresample.lib");

#include "PlayerSdlApi.h"
#pragma comment(lib, "SDL2")

#define SDL_AUDIO_MIN_BUFFER_SIZE 512
#define SDL_AUDIO_MAX_CALLBACKS_PER_SEC 30

#define AUDIO_BUF_SIZE ((48100 * 3)/2)
#define MAX_AUDIO_BUF_SIZE (48100 * 4)
#define FF_REFRESH_EVENT (SDL_USEREVENT + 1)
/* no AV sync correction is done if below the AV sync threshold */
#define AV_SYNC_THRESHOLD 0.01
/* no AV correction is done if too big error */
#define AV_NOSYNC_THRESHOLD 10.0

class CAVInitializer {
public:
	CAVInitializer() {
		av_register_all();
		avformat_network_init();
	}
	~CAVInitializer() {
		avformat_network_deinit();
	}
};

class CPlayerSdl
{
	typedef int (SDLCALL *ThreadProc)(void *);

	typedef struct PacketQueue {
		AVPacketList *first_pkt, *last_pkt;
		int nb_packets;
		int size;
		int eof;
		SDL_mutex* mutex;
		SDL_cond* cond;
	}PacketQueue;

	typedef struct RingBuffer {
		uint8_t* data;
		int size;
		int max_size;
		int rindex;  // Read position
		int windex;  // Write position
		int eof;  // EOF flag
		int lastop;  // last operation flag: 0 - read, 1 - write
		SDL_mutex* mutex;
		SDL_cond* rcond;
		SDL_cond* wcond;
	}RingBuffer;

	typedef struct Picture{
		SDL_cond* condition;
		SDL_mutex* mutex;
		SDL_Texture *texture{ nullptr };
		int ready{ 0 };
		double pts{ 0 };
	}Picture;

	std::recursive_mutex m_lock;
	HWND m_hMainWindow;
	std::string m_filename;
	AVDictionary* m_options{ nullptr };
	AVFormatContext* m_format_context{ nullptr };
	int m_videoStreamIndex{ -1 };
	int m_audioStreamIndex{ -1 };
	AVCodecContext* m_videoCodecContext{ nullptr };
	AVCodec* m_videoCodec{ nullptr };
	int m_videoCodecContextWidth{ -1 };
	int m_videoCodecContextHeight{ -1 };
	double m_fps;
	AVPixelFormat *m_pixelFormat{ nullptr };
	AVCodecContext* m_audioCodecContext{ nullptr };
	AVCodec* m_audioCodec{ nullptr };

	SDL_Thread* demux_sdl_thread;
	SDL_Thread* video_decode_sdl_thread;
	SDL_Thread* audio_decode_sdl_thread;

	PacketQueue m_video_packet_queue;
	PacketQueue m_audio_packet_queue;
	RingBuffer m_audio_frame_buffer;
	Picture picture;
	bool m_quit{ false };
	SDL_AudioSpec m_audioDesiredSpec;
	SDL_AudioSpec m_audioSpec;

	double audio_clock{ 0 };
	double video_clock{ 0 };

	double frame_timer{ 0 };
	double frame_last_pts{ 0 };
	double frame_last_delay{ 40e-30 };
	SDL_Window *sdlWindow;
	SDL_Renderer *sdlRenderer;
	double video_current_pts;
	double video_current_pts_time;

	SDL_mutex *render_mutex;
	int seek_req{ 0 };
	int64_t seek_pos;
	int seek_flags;
	AVPacket flush_pkt;
	bool m_renderOn{ true };
	bool m_online{false};
public:
	CPlayerSdl(PCHAR filename, HWND h_MainWindow)
	{
		m_filename = filename;
		m_hMainWindow = h_MainWindow;
	}

	~CPlayerSdl()
	{
		if (m_options)
			av_dict_free(&m_options);
		if (m_videoCodecContext)
			avcodec_free_context(&m_videoCodecContext);
		if (m_audioCodecContext)
			avcodec_free_context(&m_audioCodecContext);


		if (m_format_context)
			avformat_close_input(&m_format_context);
	}
	BOOL OpenStream();
	BOOL Play();
	BOOL Stop();
private:
	void Log(std::string message);
	void LogAv(int ret);
	BOOL HasVideo() const;
	BOOL HasAudio() const;
	static void AudioCallback(void* userdata, uint8_t* stream, int len);

	static void PacketQueueInit(PacketQueue* q);
	static void PacketQueueDeinit(PacketQueue* q);
	static int PacketQueuePush(PacketQueue* q, AVPacket* pkt);
	static int PacketQueuePop(PacketQueue* q, AVPacket* pkt, int block);
	static void PacketQueueFlush(PacketQueue* q);
	static void PacketQueueEof(PacketQueue* q);

	static int RingBufferInit(RingBuffer* rb, int initial_size, int max_size);
	static void RingBufferDeinit(RingBuffer* rb);
	static int RingBufferWrite(RingBuffer* rb, void* buffer, int len, int block);
	static int RingBufferRead(RingBuffer* rb, void* buffer, int len, int block, bool soundOn);
	static int RingBufferSize(RingBuffer* rb);
	static void RingBufferEof(RingBuffer* rb);

	static SDL_Thread* ThreadStart(ThreadProc fn, void* userdata, const char* name);
	static int ThreadWait(SDL_Thread* thread, const char* name);
	void Clear();
	static int DemuxSdlThread(void* opaque);
	static double SynchronizeVideo(CPlayerSdl* pPlayerSdl, AVFrame* frame, double pts);
	static int VideoDecodeSdlThread(void* opaque);
	static void AudioCallback2(void* userdata, uint8_t* stream, int len);
	static int AudioDecodeSdlThread(void* opaque);
	static uint32_t SdlRefreshTimer(uint32_t interval, void* opaque);
	static void ScheduleRefresh(CPlayerSdl* pPlayerSdl, int delay);
	static double GetExternalClock();
	static double GetVideoClock(CPlayerSdl* pPlayerSdl);
	static double GetAudioClock(CPlayerSdl* pPlayerSdl);
	static double ComputeDelay(CPlayerSdl* pPlayerSdl);
	static void VideoDisplay(CPlayerSdl* pPlayerSdl);
	static void VideoRefreshTimer(CPlayerSdl* pPlayerSdl);
	static void Quit(CPlayerSdl* pPlayerSdl);
	static void StreamSeek(CPlayerSdl* pPlayerSdl, int64_t pos, int rel);
	static void EventLoop(CPlayerSdl* pPlayerSdl);
};