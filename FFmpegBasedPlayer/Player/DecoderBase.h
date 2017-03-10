#pragma once

#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avutil.lib")
#pragma comment (lib, "swscale.lib")
#pragma comment (lib, "avfilter.lib")

extern "C"
{
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS

#endif

#ifndef INT64_C
#define INT64_C(c) (c ## LL)
#define UINT64_C(c) (c ## ULL)
#endif

#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libswscale\swscale.h>
#include <libavutil\avutil.h>
#include <libavutil\time.h>
#include <libavfilter\avfilter.h>
}

struct VideoStreamInfo
{
	int frame_width;
	int frame_height;
	int fps;
	int bitrate;
	int bitratetype; // ��� �������� 
	char codec_name[32];
};


#define CALLBACK   __stdcall
// ��������� �� ������� ��������� ������, ������� ����� ������� ����� ������������� �����
// pOutBuf - ������ � ��������������� ������� � ������� RGB24
typedef void (CALLBACK *FDecodeCallback)(BYTE* pOutBuf, DWORD dwBufSize, DWORD dwStride, DWORD width, DWORD height);
typedef void (CALLBACK *FEndInitCallback)(VideoStreamInfo vsi);



class CDecoderBase
{

protected:
	FDecodeCallback m_decodeCallback; // 
	FEndInitCallback m_endInitCallback;
	VideoStreamInfo m_vsi;

public:
	DWORD m_dwDecodedWidth;
	DWORD m_dwDecodedHeight;
	/**
		@param decodeCallback ���������� ����� ������������� ���������� �����
		@param initCompletedCallback ���������� ����� ���������� ������������� */
	CDecoderBase(FDecodeCallback decodeCallback, FEndInitCallback endInitCallback);

	// ���������������� �������
	virtual BOOL Start(int outWidth, int outHeight) = 0;

	virtual BOOL SetDecodedFrameSize(DWORD outWidth, DWORD outHeight);

	virtual BOOL Stop() = 0;

	// �������� ������ � ������� �������������
	virtual BOOL InputData(BYTE* pBuf, DWORD dwSize) = 0;

	virtual ~CDecoderBase(void);
};

