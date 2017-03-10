#pragma once


/*
 error comes from the vlc headers trying to use macros in stdint.h that are only defined for C and not C++. 
 You can add a #define that should be able to fix this. From your C++ code:
*/
extern "C"
{
#ifndef __STDC_CONSTANT_MACROS
#  define __STDC_CONSTANT_MACROS
#endif
}

#include "BasePlayer.h"

class CRtspDecoder : public CBasePlayer
{
private:
	char* m_rtspPath;
	CRITICAL_SECTION  m_CritSect;
	bool m_bPause;
	AVFormatContext* format_context;
	SwsContext* img_convert_context;
	AVCodecContext* codec_context;
	AVCodec* codec;
	unsigned char *mExtradataBuffer;
	unsigned int mExtardataBufferSize;

	volatile bool m_bIsInit;
	int m_nPlayStarted;
	int video_stream_idx;	// ������ ����������� � ����������
	int audio_stream_idx;	// ������ ����������� � ����������
	int w,h;
	int w16; // ������ ��������� ����������� ����������� �� 16 ����
	bool m_bIsInitSend;

	HANDLE hDecodeThread;
	HANDLE hInitThread;

	void Cleanup(); // ����������� �������

public:
	CRtspDecoder(const char* rtspPath,FDecodeCallback decodeCallback,FEndInitCallback endInitCallback);

	void SendInitCompleted();

	void Decode();

	BOOL Open();

	virtual BOOL Play();

	BOOL SaveSnapshot(std::string path, std::string name) override;

	//��������� ��������������� �� �����
	virtual BOOL Pause(){ return Stop(); }

	virtual BOOL Stop();

	virtual BOOL SwitchSound(BOOL bIsSoundSwitchedOn){ return TRUE; }
	//�������� ������� ���������
	virtual BOOL GetVolume(BYTE *pbVolumeLevel){ return TRUE; }
	//������ ������� ���������
	virtual BOOL SetVolume(BYTE bVolumeLevel){ return TRUE; }

	//�������� ���������� � �����
	virtual BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo){ return TRUE; }

	//������ ������� ��������������� � �����
	virtual BOOL SetPlaybackPosition(DWORD dwMilliseconds){ return TRUE; }
	//������������� �� ��������� ����
	virtual BOOL MoveToNextFrame(){ return TRUE; }
	//������������� �� ���������� ��������� ����
	virtual BOOL MoveToPreviousFrame(){ return TRUE; }

	BOOL IncreasePlaybackSpeed() override;
	BOOL DecreasePlaybackSpeed() override;

	virtual BOOL InputData(BYTE* pBuf, DWORD dwSize);

	// �� ������������
	virtual DWORD GetSourceBufferMaxSize() override { return 0; }
	// �� ������������
	virtual DWORD GetSourceBufferRemainSize() override { return 0; }
	// �� ������������
	virtual BOOL WINAPI ResetSourceBuffer() override { return FALSE; }
	//������������� ������ - ����������� ������ �� �����
	virtual BOOL InitializationFileMode() override { return TRUE; }

	~CRtspDecoder(void);
};

