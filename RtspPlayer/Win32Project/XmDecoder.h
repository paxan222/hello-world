#pragma once

#include "BasePlayer.h"
#include "H264Play.h"
#pragma comment (lib, "H264Play.lib")
//#define SOURCE_BUF_MAX	1024 * 110000 // 110 mb
#define SOURCE_BUF_50MB	1024*1024*50
#define STREAM_REALTIME 0
#define STREAM_FILE 0
#define MIN_VOLUME_VALUE 0
#define MAX_VOLUME_VALUE 500
#define GET_VOLUME_TRANSFORM_COEFF (256.0f / (MAX_VOLUME_VALUE - MIN_VOLUME_VALUE))
#define SET_VOLUME_TRANSFORM_COEFF (((float)(MAX_VOLUME_VALUE - MIN_VOLUME_VALUE)) / 256)
class XmDecoder : public CBasePlayer
{
protected:
	void OnDecodeCallback(BYTE* pRgbBuf, DWORD dwRgbBufSize, DWORD dwStride, DWORD width, DWORD height, DWORD dwTimeStampMilliseconds) override;
public:
	DWORD GetSourceBufferMaxSize() override;
	DWORD GetSourceBufferRemainSize() override;
	BOOL __stdcall ResetSourceBuffer() override;
	BOOL InitializationFileMode() override;
private:
	CRITICAL_SECTION  m_CritSect;
	int m_nPortOpened;
	int m_nStreamOpened;
	int m_nPlayStarted;
	bool isInitSend;
	volatile bool m_bIsInit;
	bool m_bIsPaused;
	WORD m_wOpenStreamMode;
	LONG m_lPort; //порт проигрывателя

protected:
	void SendInit(LONG nPort, LONG nWidth, LONG nHeight) override
	{
	}

	void Release();

	DWORD CorrectFrameTimeStamp(DWORD dwTimeStampMilliseconds) override
	{
		return 0;
	}

public:
	BOOL SaveSnapshot(std::string path, std::string name) override
	{
		string fullPath = path + "\\" + name + ".bmp";
		const int JPEG_FILE_TYPE = 1;
		return H264_PLAY_CatchPic(m_lPort, fullPath.c_str());
	};
	BOOL SetStretchMode(BOOL originalAspectRatio) override
	{
		return 0;
	};

	BOOL Init() override;
	BOOL Play() override;
	BOOL Stop() override;

	BOOL Pause() override
	{
		if (H264_PLAY_Pause(m_lPort, !m_bIsPaused))
		{
			m_bIsPaused = !m_bIsPaused;
			return TRUE;
		}
		return FALSE;
	}

	BOOL SwitchSound(BOOL bIsSoundSwitchedOn) override
	{
		if (bIsSoundSwitchedOn == TRUE)
		{
			return H264_PLAY_PlaySound(m_lPort);
		}
		else
		{
			return H264_PLAY_StopSound();
		}
	};

	BOOL GetVolume(BYTE* pbVolumeLevel) override
	{
		WORD wVolume = H264_PLAY_GetVolume(m_lPort);
		*pbVolumeLevel = wVolume * GET_VOLUME_TRANSFORM_COEFF;
		return 0;
	}

	BOOL SetVolume(BYTE bVolumeLevel) override
	{
		WORD volume = bVolumeLevel * SET_VOLUME_TRANSFORM_COEFF;
		if (volume > MAX_VOLUME_VALUE)
		{
			volume = MAX_VOLUME_VALUE;
		}
		return H264_PLAY_SetVolume(m_lPort, bVolumeLevel);
	}

	BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo) override;

	BOOL SetPlaybackPosition(DWORD dwMilliseconds) override
	{
		return 0;
	};
	DWORD GetPlaybackPosition() override
	{
		return 0;
	};
	DWORD GetAdjustedPlaybackPosition() override
	{
		return 0;
	};
	BOOL MoveToNextFrame() override
	{
		return 0;
	};
	BOOL MoveToPreviousFrame() override
	{
		return 0;
	};
	BOOL IncreasePlaybackSpeed() override
	{
		return H264_PLAY_Fast(m_lPort);
	};
	BOOL DecreasePlaybackSpeed() override
	{
		return H264_PLAY_Slow(m_lPort);
	};
	BOOL InputData(BYTE* pBuf, DWORD dwSize) override;
	BOOL Refresh() override
	{
		return 0;
	};
	BOOL SeekPositionByTime(DWORD dwMilliseconds, DWORD* pdwBytesOffset) override
	{
		return 0;
	};
	XmDecoder(FDecodeCallback decodeCallback, FEndInitCallback endIntCallback, WORD wOpenStreamMode, HWND hMainWindow = NULL);
	~XmDecoder();
};

