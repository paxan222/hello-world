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

//#include "RtspExport.h"

#define CONVERT_TIME_TO_MS 1000 //convertion from seconds to miliseconds

class CExport{

	int							m_startCutTime{ 0 }, m_endCutTime{ 0 };
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

	enum class Procedure :INT{
		Unknown,
		Cut,
		Merge
	};
	Procedure					m_procedure{ Procedure::Unknown }; // Procedure

	/*std::string ErrorMessage(ErrorCode errCode){
		switch (errCode)
		{
			case ErrorCode::EC_UNKNOWN:
				return "Unknown error.";
			case ErrorCode::EC_OPENINPUT:
				return "Error occurred while trying to open an input file.";
			case ErrorCode::EC_BOUNDARYERROR:
				return "Start cutting time or end cutting time is out of range.";
			case ErrorCode::EC_GUESSOUTPUTFORMAT:
				return "Error occurred while trying guessing output format.";
			case ErrorCode::EC_OPENOUTPUT:
				return "Error occurred while trying to open an output file";
				break;
			default:
				return "Unknown error.";
		}
	}*/

public:
	CExport(){}

	~CExport(){
		/*Constructor params*/
		m_inputFilename = "";
		m_inputFilename2 = "";
		m_outputFilename = "";
		m_startCutTime = NULL;
		m_endCutTime = NULL;
		/**/
		if (m_outputFmtCtx)
			avformat_free_context(m_outputFmtCtx);
		m_videoStreamIndex = -1;
		m_audioStreamIndex = -1;
		m_videoStreamIndex2 = -1;
		m_audioStreamIndex2 = -1;
		if (m_outputFmt)
			av_free(m_outputFmt);

		m_cancel = false;
		m_outputFileDuration = NULL;
		m_currentPts = NULL;
		m_procedure = Procedure::Unknown;
	}

	BOOL Cut(PCHAR inputFilename, PCHAR outputFilename, //Cut procedure
		int startCutTime, int endCutTime/*,
		FProgressCallback fProgressCallback = nullptr,
		FEndOfOperationCallback fEofCallback = nullptr,
		FErrorCallback fErrorCallback = nullptr*/);
	BOOL Merge(PCHAR inputFilename, PCHAR inputFilename2, PCHAR outputFilename/*, // Merge procedure
		FProgressCallback fProgressCallback = nullptr,
		FEndOfOperationCallback fEofCallback = nullptr,
		FErrorCallback fErrorCallback = nullptr*/);
	BOOL CancelProcedure(); // Cancel procedure


private:
	BOOL Init(); //init input and output files
	BOOL OpenFile(AVFormatContext **inputFmtCtx, std::string inputFileName);
	void CreateStreams(); // Find and Create streams for output
	BOOL CheckRequirements(); //Check boundary conditions
	void RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset = NULL); //Recalculate pts, dts and duration
	void Cutting(); // cutting
	void Merging();	// merging
	int RecalculatedDuration(); // Get duration of outputFile
	void CleanUp();
};