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
}
#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avutil.lib")

#define CONVERT_TIME_TO_MS 1000 //convertion from seconds to miliseconds

class CBaseOperation
{
public:
	//Constructor
	CBaseOperation();
	//Destructor
	~CBaseOperation();
	//Return mediaFileDuration
	int GetFileDuration(PCHAR filename);
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

	//Open input file
	BOOL OpenInputFile(AVFormatContext **fmtCtx, PCHAR filename);
	//Open output file
	virtual BOOL OpenOutputFile(PCHAR outputFilename);
	//Create output streams
	virtual void CreateOutputStream();
	//Recalculate timestamps of the packet using timebase of input and output streams and offset if it necessary
	void RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset = NULL);
};