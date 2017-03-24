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
}
#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avutil.lib")

#include "PlayerSdlApi.h"
#pragma comment(lib, "SDL2")

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
	} PacketQueue;

	typedef struct RingBuffer {
		uint8_t* data;
		int size;
		int max_size;
		int rindex;  // Read position
		int windex;  // Write position
		char eof;  // EOF flag
		char lastop;  // last operation flag: 0 - read, 1 - write
		SDL_mutex* mutex;
		SDL_cond* rcond;
		SDL_cond* wcond;
	} RingBuffer;

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

	SDL_Thread* demux_sdl_thread_;
	SDL_Thread* video_decode_sdl_thread_;

	PacketQueue m_video_packet_queue;
	PacketQueue m_audio_packet_queue;
	RingBuffer m_audio_frame_buffer;

	bool m_quit{ false };
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
	BOOL Stop() const;
private:
	void Log(std::string message);
	void LogAv(int ret);
	BOOL HasVideo() const;
	BOOL HasAudio() const;

	static void PacketQueueInit(PacketQueue* q);
	static void PacketQueueDeinit(PacketQueue* q);
	static int PacketQueuePush(PacketQueue* q, AVPacket* pkt);
	static int PacketQueuePop(PacketQueue* q, AVPacket* pkt, int block);
	static void PacketQueueEof(PacketQueue* q);

	int RingBufferInit(RingBuffer* rb, int initial_size, int max_size);
	void RingBufferDeinit(RingBuffer* rb);
	int RingBufferWrite(RingBuffer* rb, void* buffer, int len, int block);
	int RingBufferRead(RingBuffer* rb, void* buffer, int len, int block);
	int RingBufferSize(RingBuffer* rb);
	void RingBufferEof(RingBuffer* rb);

	static SDL_Thread* ThreadStart(ThreadProc fn, void* userdata, const char* name);
	static int ThreadWait(SDL_Thread* thread, const char* name);
	static int DemuxSdlThread(void* opaque);
	static int VideoDecodeSdlThread(void* opaque);
};