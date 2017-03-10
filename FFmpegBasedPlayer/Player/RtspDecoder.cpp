#include "stdafx.h"
#include "RtspDecoder.h"
#include <iostream>

unsigned long _stdcall RunInitThread(void * param)
{
	CRtspDecoder *decoder = (CRtspDecoder*)param;
	decoder->Open();
	return TRUE;
}

unsigned long _stdcall RtspRunDecodeThread(void * param)
{
	CRtspDecoder *decoder = (CRtspDecoder*)param;
	decoder->Decode();
	return TRUE;
}

BOOL CRtspDecoder::SaveSnapshot(std::string path, std::string name)
{
	return FALSE;
}

CRtspDecoder::CRtspDecoder(const char* rtspPath,FDecodeCallback decodeCallback,FEndInitCallback endInitCallback): CBasePlayer(NULL,decodeCallback,NULL,endInitCallback)
{
	av_register_all();
	avcodec_register_all();
	avformat_network_init();
	m_rtspPath = (char*)malloc(strlen(rtspPath));
	memcpy(m_rtspPath,rtspPath,strlen(rtspPath));
	InitializeCriticalSection(&m_CritSect);
	m_bPause = true;
	format_context = NULL;
	img_convert_context = NULL;
	codec_context = NULL;
	codec = NULL;
	m_nPlayStarted = FALSE;
	m_bIsInit = false;
	m_bIsInitSend = false;
	w = h = 0;
}

void CRtspDecoder::Cleanup()
{
	 avformat_close_input(&format_context);
}

//TODO Добавить освобождение ресурсов (e.g. avformat_close_input(&format_context);)
BOOL CRtspDecoder::Open()
{
	if (m_bIsInit)
	{
		return TRUE;
	}

	int err = avformat_open_input(&format_context, m_rtspPath, NULL, NULL);
	if (err < 0) 
	{
		cout << "ffmpeg: Unable to open input file" << endl;
		m_nPlayStarted = FALSE;
		m_bIsInit = false;
		return FALSE;
	}

	/*if(avformat_find_stream_info(format_context,NULL) < 0){
		return FALSE;
    }*/

	av_dump_format(format_context, 0, m_rtspPath, 0);

	for (int idx = 0; idx < format_context->nb_streams; ++idx)
	{
		if (format_context->streams[idx]->codec->codec_type == AVMEDIA_TYPE_VIDEO) 
		{
			video_stream_idx = idx;
		}
	}
	if (video_stream_idx <0)
	{
		cout << "ffmpeg: Unable to find video stream" << endl;
		m_nPlayStarted = FALSE;
		m_bIsInit = false;
		return FALSE;
	}

	codec_context = format_context->streams[video_stream_idx]->codec;
	codec = avcodec_find_decoder(codec_context->codec_id);
	//avcodec_get_context_defaults3(codec_context, codec);

	err = avcodec_open2(codec_context, codec, NULL);
	if (err < 0) {
		cout << "ffmpeg: Unable to open codec\n" << endl;
		m_nPlayStarted = FALSE;
		m_bIsInit = false;
		return FALSE;
	}

	if (codec_context->codec_id == AV_CODEC_ID_H264)
	{
		codec_context->flags2 |= CODEC_FLAG2_CHUNKS; // if set this flag, image become much better, but we will get frames losing
		// if we didnt set this flag, we will get corrupted frames after decoding
	}
	//_asm int 3

	/*uint8_t startCode[] = {0x00, 0x00, 0x01};
	mExtardataBufferSize = format_context->streams[video_stream_idx]->codec->extradata_size + sizeof(startCode);
	if ( format_context->streams[video_stream_idx]->codec->extradata_size > 0)
	{
		mExtradataBuffer =  new unsigned char[mExtardataBufferSize + sizeof(startCode) +  FF_INPUT_BUFFER_PADDING_SIZE];
		memcpy(mExtradataBuffer,startCode,sizeof(startCode));
		memcpy(mExtradataBuffer+sizeof(startCode),format_context->streams[video_stream_idx]->codec->extradata,mExtardataBufferSize);
		codec_context->extradata = mExtradataBuffer;
		codec_context->extradata_size = mExtardataBufferSize;

	}*/
	m_nPlayStarted = TRUE;
	m_bIsInit = true;

	hDecodeThread = CreateThread( NULL, 0, &RtspRunDecodeThread, this, 0, NULL);

	return TRUE;
}

void CRtspDecoder::SendInitCompleted()
{
	m_StreamInfo.dwWidth = codec_context->width;
	m_StreamInfo.dwHeight = codec_context->height;
	m_StreamInfo.nCodecType = CodecType::CT_UNKNOWN;
	m_StreamInfo.dwBitrate = 0;
	m_StreamInfo.nFps = 20;
	m_StreamInfo.nBitrateType = BitrateType::BT_UNKNOWN;

	m_endInitCallback(&m_StreamInfo);
	m_bIsInitSend = true;
}

void CRtspDecoder::Decode()
{

	//std::cout << "Start playing .... " << std::endl;
	AVPacket packet;

	while (av_read_frame(format_context,&packet)>=0)
	{

		if (!m_bPause)
		{
			//std::cout << "playing .... " << std::endl;
			if (packet.stream_index == video_stream_idx)
			{
				while (packet.size > 0)
				{
					int frame_finished;

					AVFrame* frame = av_frame_alloc();
					auto len = avcodec_decode_video2(codec_context,frame,&frame_finished,&packet);

					if (frame_finished)
					{
						if (!m_bIsInitSend)
						{
							//_asm int 3
							SendInitCompleted();
						}

						w = m_dwDecodedWidth; 
						h = m_dwDecodedHeight;

						/*w = codec_context->width;
						h = codec_context->height;*/

						if (w < 1 || h < 1)
						{
							w = frame->width;
							h =  frame->height;
						}
						AVPixelFormat SrcPixFormat;
						switch ((AVPixelFormat)codec_context->pix_fmt) 
						{
						case AV_PIX_FMT_YUVJ420P:
							SrcPixFormat = AV_PIX_FMT_YUV420P;
							break;
						case AV_PIX_FMT_YUVJ422P:
							SrcPixFormat = AV_PIX_FMT_YUV422P;
							break;
						case AV_PIX_FMT_YUVJ444P:
							SrcPixFormat = AV_PIX_FMT_YUV444P;
							break;
						case AV_PIX_FMT_YUVJ440P:
							SrcPixFormat = AV_PIX_FMT_YUV440P;
						default:
							SrcPixFormat = (AVPixelFormat)frame->format;
							break;
						}

						w16 = w + (16 - w%16);

						img_convert_context = sws_getContext(frame->width, frame->height,SrcPixFormat, w, h, AV_PIX_FMT_RGB24, SWS_FAST_BILINEAR, NULL, NULL, NULL);
						if(img_convert_context != NULL)
						{
							AVPicture outpic;
							avpicture_alloc(&outpic,AV_PIX_FMT_RGB24,w16,h);

							sws_scale(img_convert_context, frame->data, frame->linesize,0, codec_context->height, &outpic.data[0], &outpic.linesize[0]);

							//std::cout << "send pic ..." << std::endl;
							m_fDecodeCallback(outpic.data[0],outpic.linesize[0]*h,outpic.linesize[0],w16,h,0);
							sws_freeContext(img_convert_context);
							avpicture_free(&outpic);
						}
					}
					av_frame_free(&frame);

					packet.size -= len;
					packet.data += len;
				}
			}
		}//END if (!m_bPause) 
		else
		{
			Sleep(10);
		}
		av_free_packet(&packet);
	}//END while(av_read_frame)


}

// инициализировать декодер
BOOL CRtspDecoder::Play()
{

	EnterCriticalSection(&m_CritSect);

	if (!m_bIsInit)
	{
		Open();
		//hInitThread = CreateThread( NULL, 0, &RtspRunInitThread, this, 0, NULL);
	}
	m_bPause = false;
	LeaveCriticalSection(&m_CritSect);
	return TRUE;
}

BOOL CRtspDecoder::Stop()
{
	EnterCriticalSection(&m_CritSect);
	m_bPause = true;
	LeaveCriticalSection(&m_CritSect);
	return TRUE;
}

BOOL CRtspDecoder::InputData(BYTE* pBuf,DWORD dwSize)
{
	return TRUE;
}

BOOL CRtspDecoder::IncreasePlaybackSpeed()
{
	return FALSE;
}

BOOL CRtspDecoder::DecreasePlaybackSpeed()
{
	return FALSE;
}

CRtspDecoder::~CRtspDecoder(void)
{
	DeleteCriticalSection(&m_CritSect);
	free(m_rtspPath);
}
