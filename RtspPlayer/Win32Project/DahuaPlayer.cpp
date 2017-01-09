#include "stdafx.h"
#include "DahuaPlayer.h"

#include <dhplay.h>
#include <string>

#ifdef _DEBUG
#include <iostream>
using namespace std;
#endif

#pragma comment(lib, "dhplay.lib")

#define SOUND_VOLUME_TRANSFORMATION_COEFF 257 // 257 = 0xFFFF / 0xFF
#define SLEEP_INTERVAL_BEFORE_CHANGING_PLAY_POSITION 100
#define FORWARD_PLAY_DIRECTION 0
#define BACKWARD_PLAY_DIRECTION 1
#define FILE_INDEX_CREATION_TIMEOUT 5000

void CALLBACK CDahuaPlayer::DisplayCBFun(LONG nPort, char * pBuf, LONG nSize, LONG nWidth, LONG nHeight, LONG nStamp, LONG nType, void* pReserved)
{
	CDahuaPlayer *pPlayer = (CDahuaPlayer*)pReserved;

	pPlayer->m_lWidth = nWidth;
	pPlayer->m_lHeight = nHeight;


	pPlayer->Convert_YUV_To_RGB24(
		(BYTE*)pBuf,
		(BYTE*)pBuf + nWidth * nHeight,
		(BYTE*)pBuf + nWidth * nHeight * 5 / 4,
		nWidth, nHeight, pPlayer->GetPlaybackPosition());

}

BOOL CDahuaPlayer::SaveSnapshot(std::string path, std::string name)
{
	string fullPath = path + "\\" + name + ".jpg";
	return PLAY_CatchPic(m_lPort, (char*)fullPath.c_str());
}


void CALLBACK CDahuaPlayer::FileEndCBFun(DWORD dwPort, void *pUser)
{
	CDahuaPlayer *pPlayer = (CDahuaPlayer*)pUser;

	if (pPlayer->m_fFileEndCallback != NULL)
	{
		pPlayer->m_fFileEndCallback();
	}
}

CDahuaPlayer::CDahuaPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND hMainWindow) : CBasePlayer(pchFileName, fDecodeCallback, fFileEndCallback, NULL, hMainWindow)
{
	m_lHeight = 0;
	m_lWidth = 0;
	m_bIsPortSet = false;
	m_lPort = 0;
	m_bIsFileOpened = false;
	m_bIsPlaying = false;
	m_bIsPlayingInReverseOrder = false;
	m_hWnd = NULL;
	m_dwFileLengthMilliseconds = 0;
	m_bIsPaused = false;
	m_dwPrevMilliseconds = 0;
}

CDahuaPlayer::~CDahuaPlayer(void)
{
	PerformCleanup(false);

	/*if (m_hWnd != NULL)
	{
	DestroyWnd(m_hWnd);
	m_hWnd = NULL;
	}*/
}

BOOL CDahuaPlayer::Init()
{
	if (PLAY_GetFreePort(&m_lPort) == FALSE)
	{
		PerformCleanup(true);
		return FALSE;
	}
	m_bIsPortSet = true;

	if (PLAY_OpenFile(m_lPort, (LPSTR)m_strFileName.c_str()) == FALSE)
	{
		PerformCleanup(true);
		return FALSE;
	}
	m_bIsFileOpened = true;

	if (m_fFileEndCallback != NULL)
	{
		if (PLAY_SetFileEndCallBack(m_lPort, FileEndCBFun, this) == FALSE)
		{
			PerformCleanup(true);
			return FALSE;
		}
	}

	// нет необходимости получать данные 
	/*if (PLAY_SetDisplayCallBack(m_lPort, DisplayCBFun, this) == FALSE)
	{
	PerformCleanup(true);
	return FALSE;
	}*/

	//Ќеобходима€ пауза между Open и Play иначе в callback функции не обновл€етс€ врем€
	Sleep(SLEEP_INTERVAL_AFTER_FILE_OPENING);

	return TRUE;
}

void CDahuaPlayer::PerformCleanup(bool bWasError)
{
	DWORD dwLastErrorCode = 0;

	if (bWasError && m_bIsPortSet)
	{
		dwLastErrorCode = PLAY_GetLastError(m_lPort);
#ifdef _DEBUG
		cout << "Dahua error code: " << dwLastErrorCode << endl;
#endif
	}

	if (m_bIsFileOpened)
	{
		PLAY_CloseFile(m_lPort);
		m_bIsFileOpened = false;
	}

	if (m_bIsPortSet)
	{
		PLAY_ReleasePort(m_lPort);
		m_lPort = 0;
		m_bIsPortSet = false;
	}
}

BOOL CDahuaPlayer::Play()
{
	if (m_bIsPlaying)
	{
		if (m_bIsPaused)
		{
			BOOL bResumeRes = PLAY_Pause(m_lPort, FALSE);
			if (bResumeRes)
			{
				m_bIsPaused = false;
			}
			return bResumeRes;
		}
		return TRUE;
	}
	else
	{
		/*if (m_hWnd == NULL)
		{
		m_hWnd = CreateWnd(std::wstring(L"dwaw" + std::to_wstring(m_lPort)).c_str());
		}*/

		if (m_bIsPlayingInReverseOrder)
		{
			PLAY_SetPlayDirection(m_lPort, FORWARD_PLAY_DIRECTION);
		}
		
		BOOL res = PLAY_Play(m_lPort, m_hMainWindow);
		if (res == TRUE)
		{
			m_bIsPlaying = true;
		}
		return res;
	}
}

BOOL CDahuaPlayer::Stop()
{
	m_bIsPaused = false;
	m_bIsPlaying = false;
	return PLAY_Stop(m_lPort);
}

BOOL CDahuaPlayer::Pause()
{
	if (m_bIsPaused || !m_bIsPlaying) return FALSE;
	BOOL bRes = PLAY_Pause(m_lPort, TRUE);
	if (bRes)
	{
		m_bIsPaused = true;
	}
	return bRes;
}

BOOL CDahuaPlayer::SwitchSound(BOOL bIsSoundSwitchedOn)
{
	if (bIsSoundSwitchedOn == TRUE)
	{
		return PLAY_PlaySound(m_lPort);
	}
	else
	{
		return PLAY_StopSound();
	}
}

BOOL CDahuaPlayer::GetVolume(BYTE *pbVolumeLevel)
{
	WORD wVolume = PLAY_GetVolume(m_lPort);
	*pbVolumeLevel = (BYTE)(wVolume / SOUND_VOLUME_TRANSFORMATION_COEFF);

	return TRUE;
}

BOOL CDahuaPlayer::SetVolume(BYTE bVolumeLevel)
{
	return PLAY_SetVolume(m_lPort, bVolumeLevel * SOUND_VOLUME_TRANSFORMATION_COEFF);
}

BOOL CDahuaPlayer::GetStreamInfo(PSTREAM_INFO pStreamInfo)
{
	if (m_dwFileLengthMilliseconds == 0)
	{
		DWORD dwFileTime = PLAY_GetFileTime(m_lPort);
		DWORD dwSleepCount = 0; //количество попыток получени€ размера видео файла
		DWORD dwSleepTime = 10; //интервал времени между попытками получени€ размера видео файла
		DWORD dwMaxSleepTime = 1000; //максимальное врем€, которое можно потратить на попытки
		while ((dwFileTime == 0) && (dwSleepTime * dwSleepCount < dwMaxSleepTime))
		{
			Sleep(dwSleepTime);
			dwFileTime = PLAY_GetFileTime(m_lPort);
			dwSleepCount++;
		}
		m_dwFileLengthMilliseconds = 1000 * dwFileTime;
	}

	pStreamInfo->dwFileLengthMilliseconds = m_dwFileLengthMilliseconds;

	LONG lWidth = 0, lHeight = 0;
	BOOL resPictureSize = PLAY_GetPictureSize(m_lPort, &lWidth, &lHeight);
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

	double dRealBitRate = 0;
	BOOL resBitRate = PLAY_GetRealFrameBitRate(m_lPort, &dRealBitRate);
	if (resBitRate == TRUE)
	{
		pStreamInfo->dwBitrate = (DWORD)dRealBitRate;
	}
	else
	{
		pStreamInfo->dwBitrate = 0;
	}

	return TRUE;
}

BOOL CDahuaPlayer::SetPlaybackPosition(DWORD dwMilliseconds)
{
	DWORD dwTimePosition = 0;
	if (dwMilliseconds != 0)
	{
		dwTimePosition = dwMilliseconds + SLEEP_INTERVAL_BEFORE_CHANGING_PLAY_POSITION;
	}
	Sleep(SLEEP_INTERVAL_BEFORE_CHANGING_PLAY_POSITION);
	return PLAY_SetPlayedTimeEx(m_lPort, dwTimePosition);
}

DWORD CDahuaPlayer::GetPlaybackPosition()
{
	return PLAY_GetPlayedTimeEx(m_lPort);
}

BOOL CDahuaPlayer::MoveToNextFrame()
{
	BOOL res = PLAY_OneByOne(m_lPort);
	if (res == TRUE)
	{
		m_bIsPlaying = false;
		m_bIsPaused = false;
		m_bIsPlayingInReverseOrder = false;
	}
	return res;
}

BOOL CDahuaPlayer::MoveToPreviousFrame()
{
	BOOL res = PLAY_OneByOneBack(m_lPort);
	if (res == TRUE)
	{
		m_bIsPlaying = false;
		m_bIsPaused = false;
		m_bIsPlayingInReverseOrder = true;
	}
	return res;
}

BOOL CDahuaPlayer::IncreasePlaybackSpeed()
{
	float fPlaySpeed = 1;
	if (GetIncrementedPlaybackSpeedValue(&fPlaySpeed))
	{
		return PLAY_SetPlaySpeed(m_lPort, fPlaySpeed);
	}

	return FALSE;
}

BOOL CDahuaPlayer::DecreasePlaybackSpeed()
{
	float fPlaySpeed = 1;
	if (GetDecrementedPlaybackSpeedValue(&fPlaySpeed))
	{
		return PLAY_SetPlaySpeed(m_lPort, fPlaySpeed);
	}

	return FALSE;
}

BOOL CDahuaPlayer::SeekPositionByTime(DWORD dwMilliseconds, DWORD* pdwBytesOffset)
{
	WaitForSingleObject(m_nWaitHandle, FILE_INDEX_CREATION_TIMEOUT);
	FRAME_POS struFramePos = {};
	BOOL res = PLAY_GetKeyFramePos(m_lPort, dwMilliseconds, BY_FRAMETIME, &struFramePos);
	*pdwBytesOffset = struFramePos.nFilePos;

	return res;
}

// не используетс€
DWORD CDahuaPlayer::GetSourceBufferMaxSize()
{
	return 0;
}

// не используетс€
DWORD CDahuaPlayer::GetSourceBufferRemainSize()
{
	return 0;
}
// не используетс€
BOOL CDahuaPlayer::ResetSourceBuffer()
{
	return FALSE;
}

//»нициализаци€ режима - отображение потока из файла
BOOL CDahuaPlayer::InitializationFileMode()
{
	return TRUE;
}