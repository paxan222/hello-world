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

class CExport{

	int							m_startCutTime{ 0 }, m_endCutTime{ 0 };
	int							m_timeBaseRatio{ 0 };
	std::string					m_inputFilename;
	std::string					m_inputFilename2;
	std::string					m_outputFilename;
	AVFormatContext				*m_inputFmtCtx{ nullptr }, *m_outputFmtCtx{ nullptr }, *m_inputFmtCtx2{ nullptr };
	int							m_videoStreamIndex{ -1 }, m_audioStreamIndex{ -1 };
	int							m_videoStreamIndex2{ -1 }, m_audioStreamIndex2{ -1 };
	AVPacket					m_packet;
	AVOutputFormat				*m_outputFmt{ nullptr };
	AVStream					*m_inputVideoStream{ nullptr }, *m_inputAudioStream{ nullptr }, *m_outputVideoStream{ nullptr }, *m_outputAudioStream{ nullptr };
	AVStream					*m_inputVideoStream2{ nullptr }, *m_inputAudioStream2{ nullptr };
	bool						m_cancel{ false };

	int							m_outputFileDuration{ 0 };	//Duration for progress callback
	int64_t						m_currentPts{ 0 };			//Pts of writed packet for progress callback
	//FEndOfOperationCallback		m_fEofCb{ nullptr };	//End of operation callback
	//FProgressCallback			m_fProgCb{ nullptr };	//Progress callback
	//FErrorCallback				m_fErrCb{ nullptr };	//Error callback

public:
	//Constructor for fileoutput
	//If outputFilename incorrect, than we get FALSE at guessing an outputFormat
	CExport(){
	}

	~CExport(){
		avformat_close_input(&m_inputFmtCtx);
		/*Constructor params*/
		m_inputFilename = "";
		m_outputFilename = "";
		/**/
		avformat_free_context(m_inputFmtCtx);
		avformat_free_context(m_outputFmtCtx);
		m_videoStreamIndex = -1;
		m_audioStreamIndex = -1;
		av_free(m_outputFmt);
		av_free(m_inputVideoStream);
		av_free(m_inputAudioStream);
		av_free(m_outputVideoStream);
		av_free(m_outputAudioStream);
		m_cancel = false;

		m_outputFileDuration = 0;
		m_currentPts = 0;
	}

	BOOL Cut(PCHAR inputFilename, PCHAR outputFilename, //Cut procedure
		int startCutTime, int endCutTime/*,
		FProgressCallback fProgressCallback = nullptr,
		FEndOfOperationCallback fEofCallback = nullptr,
		FErrorCallback fErrorCallback = nullptr*/);
	BOOL Merge(PCHAR inputFilename, PCHAR inputFilename2, PCHAR outputFilename //Merge procedure
		/*,								FProgressCallback fProgressCallback = nullptr,
										FEndOfOperationCallback fEofCallback = nullptr,
										FErrorCallback fErrorCallback = nullptr*/);
	BOOL CancelProcedure(); // stop record thread


private:
	BOOL Init(); //init input and output files
	void CreateStreams(); // Find and Create streams for output
	BOOL CheckRequirements(); //Check boundary conditions
	void RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset = NULL); //Recalculate pts, dts and duration
	void Cutting(); // cutting
	void Merging();
	int RecalculatedDuration(); // Get duration of outputFile
};