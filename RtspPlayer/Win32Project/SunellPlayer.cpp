#include "stdafx.h"
#include "SunellPlayer.h"

#include <NvdcPlayerDll.h>

#pragma comment(lib, "NvdcPlayerDll.lib")

#define SOUND_VOLUME_TRANSFORMATION_COEFF 100 / 255
#define SLEEP_INTERVAL_BEFORE_CHANGING_PLAY_POSITION 100

#ifdef _DEBUG
#include <iostream>
using namespace std;
#endif

long CALLBACK FDecodeCallBack(long p_hHandle, const char * pBuf, long nSize, FRAME_INFO * pFrameInfo, void* pUserData)
{
	CSunellPlayer *pPlayer = (CSunellPlayer*)pUserData;

	if (pPlayer == NULL) return 0;
	pPlayer->m_lWidth = pFrameInfo->nWidth;
	pPlayer->m_lHeight = pFrameInfo->nHeight;
	pPlayer->Convert_YUV_To_RGB24(
		(BYTE*)pBuf,
		(BYTE*)pBuf + pFrameInfo->nWidth * pFrameInfo->nHeight,
		(BYTE*)pBuf + pFrameInfo->nWidth * pFrameInfo->nHeight * 5 / 4,
		pFrameInfo->nWidth, pFrameInfo->nHeight, pPlayer->GetAdjustedPlaybackPosition());

	return 0;
}

BOOL CSunellPlayer::SaveSnapshot(std::string path, std::string name)
{
	string fullPath = path + "\\" + name + ".jpg";
	return Player_Snapshot(m_nPort, fullPath.c_str());
}

BOOL CSunellPlayer::SetStretchMode(BOOL originalAspectRatio)
{
	if (Player_SetStretchMode(m_nPort, !originalAspectRatio) > 0)
	{
		return FALSE;
	}
	// костыль - перерисовывает окно после смены режима, для обновления всего окна, 
	//т.к. остаются артефакты в случае если был включен режим отображения оргинального размера после растягивания
	InvalidateRgn(m_hMainWindow, NULL, TRUE);
	return TRUE;
}

long CALLBACK FTimeStampCallBack(long p_hHandle, const char * pBuf, long  nSize, FRAME_INFO * pFrameInfo, void* pUserData)
{
	CSunellPlayer *pPlayer = (CSunellPlayer*)pUserData;
	pPlayer->SetFirstTimeStamp(pPlayer->GetPlaybackPosition());
	return 0;
}

void CALLBACK CSunellPlayer::FileEndCallback(long p_hHandle, void *pUserData)
{
	CSunellPlayer *pPlayer = (CSunellPlayer*)pUserData;

	if (pPlayer->m_fFileEndCallback != NULL)
	{
		pPlayer->m_fFileEndCallback();
	}
}

CSunellPlayer::CSunellPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND wndHandle) : CBasePlayer(pchFileName, fDecodeCallback, fFileEndCallback,nullptr, wndHandle)
{
	m_nPort = 0;
	m_bIsFileOpened = false;
	m_bIsPlaying = false;
	m_dwFileLengthMilliseconds = 0;
	m_bIsPaused = false;
	m_hWnd = NULL;

	m_dwTimeStampMillisecondsShift = 0;
	m_nWaitHandle = NULL;
}


CSunellPlayer::~CSunellPlayer()
{
	PerformCleanup(false);

	m_dwTimeStampMillisecondsShift = 0;

	/*if (m_hWnd != NULL)
	{
	DestroyWnd(m_hWnd);
	m_hWnd = NULL;
	}*/
}

DWORD CSunellPlayer::CorrectFrameTimeStamp(DWORD dwTimeStampMilliseconds)
{
	return dwTimeStampMilliseconds - m_dwTimeStampMillisecondsShift;
}

void CSunellPlayer::SetFirstTimeStamp()
{
	CSunellPlayer *pPlayer = new CSunellPlayer(*this);

	m_dwTimeStampMillisecondsShift = pPlayer->GetFirstTimeStamp();

	delete pPlayer;
}

DWORD CSunellPlayer::GetFirstTimeStamp()
{
	if (Player_Initial((long)m_hWnd) != 0)
	{
		return FALSE;
	}

	if (Player_OpenFile(&m_nPort, m_strFileName.c_str()) != 0)
	{
		PerformCleanup(true);
		return FALSE;
	}
	m_bIsFileOpened = true;

	if (Player_SetDecodeCallBack(m_nPort, FTimeStampCallBack, this) != 0)
	{
		PerformCleanup(true);
		return FALSE;
	}

	//Необходимая пауза между Open и Play иначе в callback функции не обновляется время
	//Sleep(SLEEP_INTERVAL_AFTER_FILE_OPENING);

	m_nWaitHandle = CreateEvent(NULL, FALSE, FALSE, NULL);
	Play();
	WaitForSingleObject(m_nWaitHandle, 1000);
	CloseHandle(m_nWaitHandle);
	m_nWaitHandle = NULL;
	Stop();

	return m_dwTimeStampMillisecondsShift;
}

void CSunellPlayer::SetFirstTimeStamp(DWORD dwMilliseconds)
{
	m_dwTimeStampMillisecondsShift = dwMilliseconds;
	SetEvent(m_nWaitHandle);
}

BOOL CSunellPlayer::Init()
{
	//	if (m_hWnd == NULL)
	//	{
	//		m_hWnd = CreateWnd(TEXT("dwaw"));
	//	}

	if (Player_Initial((long)m_hWnd) != 0)
	{
		return FALSE;
	}

	if (Player_OpenFile(&m_nPort, m_strFileName.c_str()) != 0)
	{
		PerformCleanup(true);
		return FALSE;
	}
	m_bIsFileOpened = true;

	if (m_fFileEndCallback != NULL)
	{
		if (Player_SetFileEndCallback(m_nPort, FileEndCallback, this) != 0)
		{
			PerformCleanup(true);
			return FALSE;
		}
	}

	SetFirstTimeStamp();
#ifdef _DEBUG
	//cout << "m_dwTimeStampMillisecondsShift = " << m_dwTimeStampMillisecondsShift << endl;
#endif

	/*if (Player_SetDecodeCallBack(m_nPort, FDecodeCallBack, this) != 0)
	{
		PerformCleanup(true);
		return FALSE;
	}
*/
	//Необходимая пауза между Open и Play иначе в callback функции не обновляется время
	Sleep(SLEEP_INTERVAL_AFTER_FILE_OPENING);

	return TRUE;
}

void CSunellPlayer::PerformCleanup(bool bWasError)
{
	if (m_bIsFileOpened)
	{
		Player_CloseFile(m_nPort);
		m_bIsFileOpened = false;
	}

	Player_Free();
}

BOOL CSunellPlayer::Play()
{
	if (m_bIsPlaying)
	{
		if (m_bIsPaused)
		{
			BOOL bResumeRes = Player_Pause(m_nPort, FALSE) == 0 ? TRUE : FALSE;
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
		//		if (m_hWnd == NULL)
		//		{
		//			m_hWnd = CreateWnd(TEXT("dwaw"));
		//		}

		BOOL res = Player_Play(m_nPort, (long)m_hMainWindow) == 0 ? TRUE : FALSE;
		if (res)
		{
			m_bIsPlaying = true;
		}
		return res;
	}
}

BOOL CSunellPlayer::Stop()
{
	m_bIsPaused = false;
	m_bIsPlaying = false;
	return (Player_Stop(m_nPort) == 0) ? TRUE : FALSE;
}

BOOL CSunellPlayer::Pause()
{
	if (m_bIsPaused || !m_bIsPlaying) return FALSE;
	BOOL bRes = Player_Pause(m_nPort, TRUE) == 0 ? TRUE : FALSE;
	if (bRes)
	{
		m_bIsPaused = true;
	}
	return bRes;
}

BOOL CSunellPlayer::SwitchSound(BOOL bIsSoundSwitchedOn)
{
	if (bIsSoundSwitchedOn)
	{
		return (Player_PlaySound(m_nPort) == 0) ? TRUE : FALSE;
	}
	else
	{
		return (Player_StopSound(m_nPort) == 0) ? TRUE : FALSE;
	}
}

BOOL CSunellPlayer::GetVolume(BYTE *pbVolumeLevel)
{
	long lVolumeLevel = 0;
	BOOL res = Player_GetVolume(m_nPort, &lVolumeLevel) == 0 ? TRUE : FALSE;

	if (res)
	{
		*pbVolumeLevel = (BYTE)(lVolumeLevel / SOUND_VOLUME_TRANSFORMATION_COEFF);
	}

	return res;
}

BOOL CSunellPlayer::SetVolume(BYTE bVolumeLevel)
{
	return (Player_SetVolume(m_nPort, (long)(bVolumeLevel * SOUND_VOLUME_TRANSFORMATION_COEFF)) == 0) ? TRUE : FALSE;
}

BOOL CSunellPlayer::GetStreamInfo(PSTREAM_INFO pStreamInfo)
{
	BOOL bFileLengtBOOL = FALSE;
	if (m_dwFileLengthMilliseconds == 0)
	{
		float fTimeLength = 0;
		bFileLengtBOOL = (Player_GetFileTimeV2(m_nPort, &fTimeLength) == 0) ? TRUE : FALSE;
		if (bFileLengtBOOL)
		{
			m_dwFileLengthMilliseconds = (DWORD)(fTimeLength * 1000);
		}
	}
	else
	{
		bFileLengtBOOL = TRUE;
	}

	if (bFileLengtBOOL)
	{
		pStreamInfo->dwFileLengthMilliseconds = m_dwFileLengthMilliseconds;
	}

	LONG lWidth = 0, lHeight = 0;
	BOOL bPictureSizeResult = (Player_GetPictureSize(m_nPort, &lWidth, &lHeight) == 0) ? TRUE : FALSE;
	if (bPictureSizeResult)
	{
		pStreamInfo->dwWidth = lWidth;
		pStreamInfo->dwHeight = lHeight;
	}
	else
	{
		pStreamInfo->dwWidth = m_lWidth;
		pStreamInfo->dwHeight = m_lHeight;
	}

	return bFileLengtBOOL || bPictureSizeResult;
}

BOOL CSunellPlayer::SetPlaybackPosition(DWORD dwMilliseconds)
{
	float fPosition = (float)(dwMilliseconds + m_dwTimeStampMillisecondsShift + (dwMilliseconds != 0 ? SLEEP_INTERVAL_BEFORE_CHANGING_PLAY_POSITION : 0)) / 1000;
	Sleep(SLEEP_INTERVAL_BEFORE_CHANGING_PLAY_POSITION);
#ifdef _DEBUG
	//cout << "SetPlaybackPosition(" << dwMilliseconds << " => " << fPosition << ")" << endl;
#endif
	return (Player_SetPlayTimeV2(m_nPort, fPosition) == 0) ? TRUE : TRUE;
}

DWORD CSunellPlayer::GetPlaybackPosition()
{
	float playedTime = 0;
	long errCode = Player_GetPlayTimeV2(m_nPort, &playedTime);
	if (errCode == 0)
	{
#ifdef _DEBUG
		//cout << "RawTS = " << (DWORD)(playedTime * 1000) << endl;
#endif
		return (DWORD)(playedTime * 1000);
	}
	else
	{
		return 0;
	}
}

DWORD CSunellPlayer::GetAdjustedPlaybackPosition()
{
	return GetPlaybackPosition() - m_dwTimeStampMillisecondsShift;
}

BOOL CSunellPlayer::MoveToNextFrame()
{
	BOOL res = (Player_OneByOne(m_nPort) == 0) ? TRUE : FALSE;
	if (res)
	{
		m_bIsPlaying = false;
		m_bIsPaused = false;
	}
	return res;
}

BOOL CSunellPlayer::MoveToPreviousFrame()
{
	BOOL res = (Player_OneByOneBack(m_nPort) == 0) ? TRUE : FALSE;
	if (res)
	{
		m_bIsPlaying = false;
		m_bIsPaused = false;
	}
	return res;
}

BOOL CSunellPlayer::IncreasePlaybackSpeed()
{
	float fPlaySpeed = 1;
	if (GetIncrementedPlaybackSpeedValue(&fPlaySpeed))
	{
		return Player_SetSpeed(m_nPort, fPlaySpeed) == 0 ? TRUE : FALSE;
	}

	return FALSE;
}

BOOL CSunellPlayer::DecreasePlaybackSpeed()
{
	float fPlaySpeed = 1;
	if (GetDecrementedPlaybackSpeedValue(&fPlaySpeed))
	{
		return Player_SetSpeed(m_nPort, fPlaySpeed) == 0 ? TRUE : FALSE;
	}

	return FALSE;
}

// не используется
DWORD CSunellPlayer::GetSourceBufferMaxSize()
{
	return 0;
}

// не используется
DWORD CSunellPlayer::GetSourceBufferRemainSize()
{
	return 0;
}

// не используется
BOOL CSunellPlayer::ResetSourceBuffer()
{
	return FALSE;
}

//Инициализация режима - отображение потока из файла
BOOL CSunellPlayer::InitializationFileMode()
{
	return TRUE;
}