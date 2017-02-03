#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

extern "C"
{
#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libavformat\avio.h>
}

static int timePrev = 0;
static int interruptTimeout = 0;
static bool interruptFlag = false;

class CRtspRecorder{

	std::string					m_inputFilename, m_inputFilename2;
	int							m_connectionTimeout = 0;
	std::string					m_outputFilename;
	AVDictionary				*m_dictionary{ NULL };
	AVFormatContext				*m_inputFmtCtx{ NULL }, *m_inputFmtCtx2{ NULL }, *m_outputFmtCtx{ NULL };
	int							m_videoStreamIndex = -1, m_audioStreamIndex = -1;
	AVPacket					m_packet;
	AVOutputFormat				*m_outputFmt{ NULL };
	AVStream					*m_inputVideoStream{ NULL }, *m_inputAudioStream{ NULL }, *m_outputVideoStream{ NULL }, *m_outputAudioStream{ NULL };
	bool						m_stop{ false };

	AVCodecContext *m_videoCodec = nullptr;
	AVCodecContext *m_audioCodec = nullptr;

public:
	CRtspRecorder(PCHAR inputFilename, PCHAR inputFilename2, int connectionTimeout, PCHAR outputFilename){

		m_inputFilename = inputFilename;
		m_inputFilename2 = inputFilename2;
		m_connectionTimeout = connectionTimeout;
		m_outputFilename = outputFilename;
	}

	~CRtspRecorder(){
		avformat_close_input(&m_inputFmtCtx);
		m_inputFilename = "";
		m_connectionTimeout = 0;
		m_outputFilename = "";
		av_dict_free(&m_dictionary);
		avformat_free_context(m_inputFmtCtx);
		avformat_free_context(m_outputFmtCtx);
		m_videoStreamIndex = -1;
		m_audioStreamIndex = -1;
		av_free(m_outputFmt);
		av_free(m_inputVideoStream);
		av_free(m_inputAudioStream);
		av_free(m_outputVideoStream);
		av_free(m_outputAudioStream);
		m_stop = false;
		avcodec_close(m_videoCodec);
		avcodec_close(m_audioCodec);
	}

	BOOL Open(); //Open stream/file
	BOOL StartRecord(); // start record thread
	BOOL Cut();
	BOOL Merge();
	BOOL StopRecord(); // stop record thread

private:
	BOOL Init(); //init input and output files
	static int Interrupt_cb(void *ctx); // interrupt timeout callback
	static int WritePacket_cb(void* opaque, uint8_t *buf, int buf_size);
	void RecalculateTimeStamps(AVPacket packet, AVRational inputTimeBase, AVRational outputTimeBase);
};