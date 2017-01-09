#include "stdafx.h"
#include "XmPlayer.h"

#include "H264Play.h"
#pragma comment (lib, "H264Play.lib")

#ifdef _DEBUG
#include <iostream>
using namespace std;
#endif

void CXmPlayer::DecodeCallback(LONG nPort, LPCSTR pBuf, LONG nSize, FRAME_INFO* pFrameInfo, LONG nPlayedFrames)
{
	
}


void CXmPlayer::FileEndCallback(LONG playHandle, LONG nUser)
{
	CXmPlayer *pPlayer = (CXmPlayer*)nUser;

	if (pPlayer->m_fFileEndCallback != NULL)
	{
		pPlayer->m_fFileEndCallback();
	}
}

CXmPlayer::CXmPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND wndHandle) : CBasePlayer(pchFileName, fDecodeCallback, fFileEndCallback, NULL, wndHandle)
{
	m_lHeight = 0;
	m_lWidth = 0;
	m_bIsPortSet = FALSE;
	m_lPort = 0;
	m_bIsFileOpened = FALSE;
	m_bIsPlaying = FALSE;
	m_bIsPlayingInReverseOrder = FALSE;
	m_dwFileLengthMilliseconds = 0;
	m_bIsPaused = FALSE;
	m_dwPrevMilliseconds = 0;
	m_isSounOn = FALSE;
}

CXmPlayer::~CXmPlayer()
{
	PerformCleanup(false);
}

BOOL CXmPlayer::Init()
{
	if (H264_PLAY_GetPort(&m_lPort) == FALSE)
	{
		m_bIsPortSet = FALSE;
		PerformCleanup(true);
		return FALSE;
	}

	m_bIsPortSet = TRUE;

	if (m_fFileEndCallback != NULL)
	{
		if (H264_PLAY_SetFileEndCallBack(m_lPort, FileEndCallback, (LONG)this) == FALSE)
		{
			PerformCleanup(true);
			return FALSE;
		}
	}

	if (m_fDecodeCallback != NULL)
	{
		if (H264_PLAY_SetDecCallBack(m_lPort, DecodeCallback) == FALSE)
		{
			PerformCleanup(true);
			return FALSE;
		}
	}

	if (H264_PLAY_PlaySound(m_lPort) == TRUE)
	{
		m_isSounOn = TRUE;
	}

	if (H264_PLAY_OpenFile(m_lPort, const_cast<char*>(m_strFileName.c_str())) == FALSE)
	{
		PerformCleanup(true);
		return FALSE;
	}

	return TRUE;
}

BOOL CXmPlayer::Play()
{
	if (m_bIsPlaying == FALSE)
	{
		if (H264_PLAY_Play(m_lPort, m_hMainWindow) == FALSE)
		{
			m_bIsPlaying = FALSE;
			return FALSE;
		}
		m_bIsPlaying = TRUE;
		m_bIsPaused = FALSE;
		return TRUE;
	}

	if (m_bIsPaused == TRUE)
	{
		if (H264_PLAY_Pause(m_lPort, FALSE) == FALSE)
		{
			return FALSE;
		}
		m_bIsPaused = FALSE;
		return TRUE;
	}
	
	return FALSE;
}

BOOL CXmPlayer::Pause()
{
	if (m_bIsPaused == FALSE)
	{
		if (H264_PLAY_Pause(m_lPort, TRUE) == FALSE)
		{
			return FALSE;
		}
		m_bIsPaused = TRUE;
		return TRUE;
	}

	return FALSE;
}

BOOL CXmPlayer::Stop()
{
	if (H264_PLAY_Stop(m_lPort) == TRUE)
	{
		m_lPort = NULL;
		return TRUE;
	}

	return FALSE;
}

BOOL CXmPlayer::GetStreamInfo(PSTREAM_INFO pStreamInfo)
{
	if (m_dwFileLengthMilliseconds == 0)
	{
		DWORD dwFileTime = H264_PLAY_GetFileTime(m_lPort);
		DWORD dwSleepCount = 0; //количество попыток получения размера видео файла
		DWORD dwSleepTime = 10; //интервал времени между попытками получения размера видео файла
		DWORD dwMaxSleepTime = 1000; //максимальное время, которое можно потратить на попытки
		while ((dwFileTime == 0) && (dwSleepTime * dwSleepCount < dwMaxSleepTime))
		{
			Sleep(dwSleepTime);
			dwFileTime = H264_PLAY_GetFileTime(m_lPort);
			dwSleepCount++;
		}
		m_dwFileLengthMilliseconds = 1000 * dwFileTime;
	}

	pStreamInfo->dwFileLengthMilliseconds = m_dwFileLengthMilliseconds;

	LONG lWidth = 0, lHeight = 0;
	BOOL resPictureSize = H264_PLAY_GetPictureSize(m_lPort, &lWidth, &lHeight);
	if (resPictureSize == TRUE)
	{
		pStreamInfo->dwWidth = lWidth;
		pStreamInfo->dwHeight = lHeight;
	}
	else
	{
		pStreamInfo->dwWidth = m_lWidth;
		pStreamInfo->dwHeight = m_lHeight;
	}

	pStreamInfo->dwBitrate = H264_PLAY_GetPlayFPS(m_lPort); 

	return TRUE;
}

BOOL CXmPlayer::DecreasePlaybackSpeed()
{
	return H264_PLAY_Slow(m_lPort);
}

BOOL CXmPlayer::IncreasePlaybackSpeed()
{
	return H264_PLAY_Fast(m_lPort);
}

DWORD CXmPlayer::GetPlaybackPosition()
{
	return H264_PLAY_GetPlayedTimeEx(m_lPort);
}

BOOL CXmPlayer::SetPlaybackPosition(DWORD dwMilliseconds)
{
	return H264_PLAY_SetPlayedTimeEx(m_lPort, dwMilliseconds);
}

BOOL CXmPlayer::MoveToNextFrame()
{
	return H264_PLAY_NextFrame(m_lPort);
}

BOOL CXmPlayer::MoveToPreviousFrame()
{
	return H264_PLAY_PrevFrame(m_lPort);
}

BOOL CXmPlayer::SaveSnapshot(std::string path, std::string name)
{
	string fullPath = path + "\\" + name + ".jpg";
	return H264_PLAY_CatchPic(m_lPort, (char*)fullPath.c_str());
}

BOOL CXmPlayer::GetVolume(BYTE* pbVolumeLevel)
{
	WORD wVolume = H264_PLAY_GetVolume(m_lPort);
	*pbVolumeLevel = wVolume * GET_VOLUME_TRANSFORM_COEFF;
	return TRUE;
}

BOOL CXmPlayer::SetVolume(BYTE bVolumeLevel)
{
	WORD volume = bVolumeLevel * SET_VOLUME_TRANSFORM_COEFF;
	if (volume > MAX_VOLUME_VALUE)
	{
		volume = MAX_VOLUME_VALUE;
	}
	return H264_PLAY_SetVolume(m_lPort, bVolumeLevel);
}

BOOL CXmPlayer::SwitchSound(BOOL bIsSoundSwitchedOn)
{
	if (bIsSoundSwitchedOn == TRUE && m_isSounOn == FALSE)
	{
		return H264_PLAY_PlaySound(m_lPort);
	}
	if (bIsSoundSwitchedOn == FALSE && m_isSounOn == TRUE)
	{
		return H264_PLAY_StopSound();
	}

	return TRUE;
}


void CXmPlayer::PerformCleanup(bool bWasError)
{
	DWORD dwLastErrorCode = 0;

	if (bWasError && m_bIsPortSet)
	{
		dwLastErrorCode = H264_PLAY_GetLastError(m_lPort);
#ifdef _DEBUG
		cout << "Dahua error code: " << dwLastErrorCode << endl;
#endif
	}

	if (m_bIsFileOpened)
	{
		H264_PLAY_CloseFile(m_lPort);
		m_bIsFileOpened = FALSE;
	}

	if (m_bIsPortSet)
	{
		H264_PLAY_FreePort(m_lPort);
		m_lPort = 0;
		m_bIsPortSet = FALSE;
	}
}