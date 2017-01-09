#pragma once
#include "BasePlayer.h"
#include <H264Play.h>

#define MIN_VOLUME_VALUE 0
#define MAX_VOLUME_VALUE 500
#define GET_VOLUME_TRANSFORM_COEFF (256.0f / (MAX_VOLUME_VALUE - MIN_VOLUME_VALUE))
#define SET_VOLUME_TRANSFORM_COEFF (((float)(MAX_VOLUME_VALUE - MIN_VOLUME_VALUE)) / 256)

class CXmPlayer :
	public CBasePlayer
{
protected:
	void OnDecodeCallback(BYTE* pRgbBuf, DWORD dwRgbBufSize, DWORD dwStride, DWORD width, DWORD height, DWORD dwTimeStampMilliseconds) override
	{
	}

	void SendInit(LONG nPort, LONG nWidth, LONG nHeight) override
	{
	}

	DWORD CorrectFrameTimeStamp(DWORD dwTimeStampMilliseconds) override
	{
		return 0;
	}

public:
	BOOL SetStretchMode(BOOL originalSapectRatio) override
	{
		return 0;
	}

	DWORD GetAdjustedPlaybackPosition() override
	{
		return 0;
	}

	BOOL Refresh() override
	{
		return 0;
	}

	BOOL SeekPositionByTime(DWORD dwMilliseconds, DWORD* pdwBytesOffset) override
	{
		return 0;
	}

	DWORD GetSourceBufferMaxSize() override
	{
		return 0;
	}

	DWORD GetSourceBufferRemainSize() override
	{
		return 0;
	}

	BOOL __stdcall ResetSourceBuffer() override
	{
		return 0;
	}

	BOOL InitializationFileMode() override
	{
		return 0;
	}

private:
	bool m_bIsPortSet, m_bIsFileOpened, m_bIsPlaying, m_bIsPaused, m_bIsPlayingInReverseOrder;
	LONG m_lPort;
	DWORD m_dwFileLengthMilliseconds;
	DWORD m_dwPrevMilliseconds;
	void PerformCleanup(bool bWasError);
	LONG m_lWidth;
	LONG m_lHeight;
	BOOL m_isSounOn;

	static void CALLBACK DecodeCallback(LONG nPort, LPCSTR pBuf, LONG nSize, FRAME_INFO * pFrameInfo, LONG nPlayedFrames);
	static void CALLBACK FileEndCallback(LONG playHandle, LONG nUser);

public:
	CXmPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND wndHandle = NULL);
	~CXmPlayer(void);

	BOOL Init() override;
	BOOL Play() override;
	BOOL Stop() override;
	BOOL Pause() override;

	BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo) override;
	BOOL InputData(BYTE* pBuf, DWORD dwSize) override
	{ return FALSE; };

	BOOL SaveSnapshot(std::string path, std::string name) override;

	BOOL SwitchSound(BOOL bIsSoundSwitchedOn) override;
	BOOL GetVolume(BYTE* pbVolumeLevel) override;
	BOOL SetVolume(BYTE bVolumeLevel) override;

	BOOL SetPlaybackPosition(DWORD dwMilliseconds) override;
	DWORD GetPlaybackPosition() override;
	BOOL MoveToNextFrame() override;
	BOOL MoveToPreviousFrame() override;

	BOOL IncreasePlaybackSpeed() override;
	BOOL DecreasePlaybackSpeed() override;
};
