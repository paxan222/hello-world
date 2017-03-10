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

//#include "RtspExport.h"

#define CONVERT_TIME_TO_MS 1000 //convertion from seconds to miliseconds

class CBaseOperation
{
public:
	//Constructor
	CBaseOperation();
	//Destructor
	virtual ~CBaseOperation();
	//Return mediaFileDuration
	static int GetFileDuration(PCHAR filename);
	static int GetJpeg(PCHAR filename, char* strBuf, int stdBufSize, int width, int height, int64_t timestamp);
	//Cancel task
	BOOL CancelTask();
protected:
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
	//ErrorCode m_errorCode{ ErrorCode::UnknownError };


	//Open input file
	BOOL OpenInputFile(AVFormatContext *&fmtCtx, PCHAR filename);
	//Guess output format
	BOOL GuessOutputFormat(AVFormatContext *outputFmtCtx, PCHAR outputFilename);
	//Open output file
	BOOL OpenOutputFile(PCHAR outputFilename);
	//Create output stream from input stream
	//return stream index
	int CreateStream(AVCodecID codecId, AVStream *inputStream);
	//Create output streams
	virtual void CreateOutputStreams(AVFormatContext *outputFmtCtx) abstract;
	//Recalculate timestamps of the packet using timebase of input and output streams and offset if it necessary
	void RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset = NULL);

private:
	static void saveFrame(AVFrame *pFrame, PCHAR outputFilename, int width, int height);
	static HRESULT GetGdiplusEncoderClsid(__in LPCWSTR pwszFormat, __out GUID *pGUID);
	static int saveToJpeg(AVFrame* pFrame, int width, int height, char* buffer, int bufSize);
	static void saveFrameToBmp(AVFrame *pFrame, PCHAR outputFilename, int width, int height);
};