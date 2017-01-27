#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

extern "C"
{
#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libavformat\avio.h>
#include <libswscale\swscale.h>
}

class CRtspRecorder{
	std::string m_filename;
	AVDictionary *m_dictionary{ NULL };
	AVFormatContext *m_inputFmtCtx, *m_outputFmtCtx{ NULL };
	int m_videoStreamIndex, m_audioStreamIndex;
	AVPacket m_packet;
	AVOutputFormat *m_outputFmt{ NULL };
	AVStream  *m_outputVideoStream{ NULL }, *m_outputAudioStream{ NULL };
	bool m_stop{ false };

	AVCodecContext *m_videoCodec = nullptr;
	AVCodecContext *m_audioCodec = nullptr;
public:
	CRtspRecorder(PCHAR filename){
		m_filename = filename;
	}
	~CRtspRecorder(){
		av_dict_free(&m_dictionary);
		avformat_free_context(m_inputFmtCtx);
		avformat_free_context(m_outputFmtCtx);
		
	}

	BOOL Open();
	BOOL StartReadAndWrite();
	BOOL StopReadAndWrite();


private:
	BOOL Init();
};