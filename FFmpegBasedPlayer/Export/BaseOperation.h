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
#include <atlimage.h>
#include <fstream>

#undef main

extern "C" {
#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libavformat\avio.h>
#include <libswscale\swscale.h>
}
#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avutil.lib")
#pragma comment (lib, "swscale.lib")

#include "RtspExport.h"

#define CONVERT_TIME_TO_MS 1000 //convertion from seconds to miliseconds

struct GdiplusInit {
	GdiplusInit() {
		Gdiplus::GdiplusStartupInput inp;
		GdiplusStartup(&token_, &inp, NULL);
	}
	~GdiplusInit() {
		Gdiplus::GdiplusShutdown(token_);
	}
private:
	ULONG_PTR token_;
};

class CBaseOperation
{
	static HRESULT GetGdiplusEncoderClsid(__in LPCWSTR pwszFormat, __out GUID *pGUID);
	static int saveToJpeg(AVFrame *pFrame, int width, int height, char *buffer, int bufferSize);
	static int saveToJpeg(FGetImageCallback fGetImageCallback, AVFrame* pFrame, int width, int height);
public:
	//Constructor
	CBaseOperation();
	//Destructor
	virtual ~CBaseOperation();
	//Return mediaFileDuration
	static int GetFileDuration(PCHAR filename);
	//Return buffer with image by timestamp
	static int GetFrame(PCHAR inputFilename, char *buffer, int bufferSize, int width, int height, int64_t timestamp);
	static int GetFrameCollection(FGetImageCallback fgetImageCollectionCallback, PCHAR inputFilename, int width, int height, int64_t startTimestamp, int step = NULL, int count = NULL);
	//static int saveToJpeg(AVFrame* pFrame, int width, int height, IStream* istream);
	//Cancel task
	BOOL CancelTask();
protected:
	std::string m_firstInputFilename;
	std::string m_secondInputFilename;
	std::string m_outputFilename;
	/*----------Input data--------------------------------------------*/
	//Input format context
	AVFormatContext	*m_inputFmtCtx{ nullptr };
	/*InputStreams*/
	//Input video stream
	AVStream *m_inputVideoStream{ nullptr };
	//Input audio stream
	AVStream *m_inputAudioStream{ nullptr };
	/*----------Output data-------------------------------------------*/
	//Output format context
	AVFormatContext *m_outputFmtCtx{ nullptr };
	//Output video stream index
	int	m_outputVideoStreamIndex{ -1 };
	//Output audio stream index
	int	m_outputAudioStreamIndex{ -1 };
	/*----------Cancel------------------------------------------------*/
	//Cancel operation flag
	bool m_cancel{ false };
	/*----------Error-Code--------------------------------------------*/
	//Error code for Error callback
	ErrorCode m_errorCode{ ErrorCode::UnknownError };


	//Open input file
	BOOL OpenInputFile(AVFormatContext *&fmtCtx, PCHAR filename);
	//Guess output format
	BOOL GuessOutputFormat(AVFormatContext *outputFmtCtx, PCHAR outputFilename);
	//Open output file
	BOOL OpenOutputFile(PCHAR outputFilename);
	//Create output stream from input stream
	//Return stream index
	int CreateStream(AVCodecID codecId, AVStream *inputStream);
	//Create output streams
	virtual void CreateOutputStreams(AVFormatContext *outputFmtCtx) abstract;
	//Recalculate timestamps of the packet using timebase of input and output streams and offset if it necessary
	void RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset = NULL);
};