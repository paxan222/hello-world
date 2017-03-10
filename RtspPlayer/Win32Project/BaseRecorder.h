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
//#include "Logger.h"



#define LOG(msg) _RPT2(0,"%i\t\t%s\n", GetCurrentThreadId(), msg );

#undef main

extern "C" {
#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libavformat\avio.h>
}
#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avutil.lib")

//#include "RtspRecorder.h"

class CBaseRecorder
{
	bool m_interrupDisable{ false };	
public:
	/*
	*	Constructor
	*/
	CBaseRecorder(/*FErrorCallback fErrorCallback = nullptr, FStartRecordCallback fStartRecordCallback = nullptr*/);
	/*
	*	Destructor
	*/
	virtual ~CBaseRecorder();
	//Open stream
	virtual BOOL Open(int counter) abstract;
	BOOL StartRecord();
	BOOL StopRecord();

private:
	/*
	*	Callback for checking whether to abort blocking functions.
	*	During blocking operations, callback is called with
	*	opaque as parameter. If the callback returns 1, the
	*	blocking operation will be aborted.
	*/
	static int Interrupt_cb(void *opaque);
	/**
	*	return TRUE if the packet is I-Frame;
	*	return FALSE if not;
	*/
	BOOL CheckIFrame(AVPacket packet);

	/**
	*	Recalculate packet timestamps from input stream timebase to output stream timebase
	*	and interleaved write source packet to output format;
	*	@param srcPacket		- source packet to write to output;
	*	@param *srcStream		- source stream that contains source packet;
	*	@param *&dstFmtCtx		- output format context;
	*	@param dstStreamIndex	- output stream that will contain source packet;
	*/
	void WritePacket(AVPacket *srcPacket, AVStream *srcStream, AVFormatContext *&dstFmtCtx, int dstStreamIndex);

	/*
	*	Recalculate pts, dts and duration of source packet
	*	@param srcPacket	- packet in which recalculation from initial timebase to destination is
	*	@param srcTimeBase	- initial timebase
	*	@param dstTimeBase	- destination timebase
	*/
	void RecalculateTimeStamps(AVPacket *srcPacket, AVRational srcTimeBase, AVRational dstTimeBase);

protected:
	/*---------------Input-Variables--------------------------*/

	std::string m_rtspPath;	
	std::string m_outputFilename;

	//Input format context
	AVFormatContext *m_inputFmtCtx{ nullptr };
	//Input video stream
	AVStream *m_inputVideoStream{ nullptr };
	//Input audio stream
	AVStream *m_inputAudioStream{ nullptr };
	/*---------------Interrupt-Callback-Variables-------------*/
	//Time previous
	unsigned long m_timePrev{ 0 };
	//Connection timeout
	int m_connectionTimeout{ 0 };
	/*---------------Output-Variables-------------------------*/
	//Output format context
	AVFormatContext *m_outputFmtCtx{ nullptr };
	//Output video stream
	int m_outputVideoStreamIndex{ -1 };
	//Output audio stream
	int m_outputAudioStreamIndex{ -1 };

	//Stop operation flag
	bool m_stop{ false };
	//Write header flag
	bool m_writeHeader{ true };


	//Error callback
	//FErrorCallback m_ErrCb;
	//Start record callback
	//FStartRecordCallback m_StartRecCb;

	/*
	*	Check rtsp path, register av libs, open input and check input streams;
	*	@param rtspPath				- rtsp link;
	*	@param connectionTimeout	- time for interrupt callback on open input;
	*	return FALSE in next cases:
	*		rtspPath is empty;
	*		couldn't set avdictionary with "rtsp_transport=tcp";
	*		couldn't open rtsp stream by timeout or unavailible of source;
	*		no video stream from source;
	*	elsewhere return TRUE;
	*/
	BOOL OpenInputStream(PCHAR rtspPath, int connectionTimeout, int counter);

	/**
	*	Abstract function WriteHeaderTo is allocate output
	*	format context for Callback output or File output;
	*/
	virtual BOOL WriteHeaderTo(AVFormatContext *&dstFmtCtx) abstract;

	/**
	*	Create stream from source stream to destination stream
	*	with destination codec and source codec context
	*	@param *srcStream		- source stream
	*	@param *&dstFmtCtx		- destination format context
	*	@param dstCodecId		- destination oformat codec id
	*	return created stream index
	*
	*/
	int CreateStream(AVStream *srcStream, AVFormatContext *&dstFmtCtx, AVCodecID dstCodecId);

	/**
	*	Filling ouput streams using CreateStream for video and audio if it is
	*/	
	void FillOutputStreamIndex(AVFormatContext *&dstFmtCtx);

	/**
	*	Write trailer of output in CallbackRecorder and FileRecorder;
	*	Close output file in FileRecorder;
	*/
	virtual void WriteTrailer(AVFormatContext *&outputFmtCtx) abstract;
};