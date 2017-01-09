#include "stdafx.h"
#include "HikPlayer.h"
#include <fstream>
#ifdef _DEBUG
#include <iostream>
using namespace std;
#endif

#include <PlayM4.h>

#pragma comment (lib, "PlayCtrl.lib")

#define SOUND_VOLUME_TRANSFORMATION_COEFF 257 // 257 = 0xFFFF / 0xFF
#define SLEEP_INTERVAL_BEFORE_CHANGING_PLAY_POSITION 100

void CALLBACK DisplayCBFun(DISPLAY_INFO *pstDisplayInfo)
{
	CHikPlayer *pPlayer = (CHikPlayer*)pstDisplayInfo->nUser;

	if (pPlayer == NULL) return;
	pPlayer->Convert_YUV_To_RGB24(
		(BYTE*)pstDisplayInfo->pBuf,
		(BYTE*)pstDisplayInfo->pBuf + pstDisplayInfo->nWidth * pstDisplayInfo->nHeight * 5 / 4,
		(BYTE*)pstDisplayInfo->pBuf + pstDisplayInfo->nWidth * pstDisplayInfo->nHeight,
		pstDisplayInfo->nWidth, pstDisplayInfo->nHeight, pstDisplayInfo->nStamp);
}

void CALLBACK CHikPlayer::FileEndCallback(long nPort, void *pUser)
{
	CHikPlayer *pPlayer = (CHikPlayer*)pUser;

	if (pPlayer->m_fFileEndCallback != NULL)
	{
		pPlayer->m_fFileEndCallback();
	}
}

void CALLBACK FileRefDoneCallback(DWORD nPort, DWORD nUser)
{
	CHikPlayer *pPlayer = (CHikPlayer*)nUser;

	if (pPlayer == NULL) return;
#ifdef _DEBUG
	cout << "Fileindex Created" << endl;
#endif
}

BOOL CHikPlayer::SaveSnapshot(std::string path, std::string name)
{
	string fullPath = path + "\\" + name + ".jpg";
	LONG lWidth = 0, lHeight = 0;
	BOOL bPictureSizeResult = PlayM4_GetPictureSize(m_nPort, &lWidth, &lHeight);
	int nLen = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + lWidth * lHeight * 4;
	char *pByte = new char[nLen];
	ZeroMemory(pByte, nLen);
	DWORD pRealSize;  // The actual size

	if (!PlayM4_GetJPEG(m_nPort, (unsigned char*)pByte, nLen, &pRealSize))
	{
		return FALSE;
	}
	else
	{
		ofstream file(fullPath, ios::out | ios::binary);
		file.write(pByte, pRealSize);
		file.close();
		return TRUE;
	}

	// Clear memory
	delete[]pByte;
	pByte = NULL;
}

CHikPlayer::CHikPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND wndHandle) : CBasePlayer(pchFileName, fDecodeCallback, fFileEndCallback, nullptr, wndHandle)
{
	m_nPort = -1;
	m_nIsPortOpened = FALSE;
	m_nIsFileOpened = FALSE;
	m_dwFileLengthMilliseconds = 0;
	m_bIsPlaying = false;
	m_bIsPaused = false;
}


CHikPlayer::~CHikPlayer()
{
	PerformCleanup(false);
}

BOOL CHikPlayer::Init()
{
	m_nIsPortOpened = PlayM4_GetPort(&m_nPort);

	if (m_nIsPortOpened == FALSE)
	{
		PerformCleanup(true);
		return FALSE;
	}

	if (m_fFileEndCallback != NULL)
	{
		if (PlayM4_SetFileEndCallback(m_nPort, FileEndCallback, this) == FALSE)
		{
			PerformCleanup(true);
			return FALSE;
		}
	}

	if (!PlayM4_SetFileRefCallBack(m_nPort, FileRefDoneCallback, (DWORD)this))
	{
		PerformCleanup(true);
		return FALSE;
	}

	m_nIsFileOpened = PlayM4_OpenFile(m_nPort, (LPSTR)m_strFileName.c_str());
	if (m_nIsFileOpened == FALSE)
	{
		PerformCleanup(true);
		return FALSE;
	}

	/*if (PlayM4_SetDisplayCallBackEx(m_nPort, DisplayCBFun, (LONG)this) == FALSE)
	{
	PerformCleanup(true);
	return FALSE;
	}*/

	//Необходимая пауза между Open и Play иначе в callback функции не обновляется время
	Sleep(SLEEP_INTERVAL_AFTER_FILE_OPENING);

	return TRUE;
}

void CHikPlayer::PerformCleanup(bool bWasError)
{
	DWORD dwLastErrorCode = 0;

	if (bWasError && m_nIsPortOpened)
	{
		dwLastErrorCode = PlayM4_GetLastError(m_nPort);
#ifdef _DEBUG
		cout << "Hik error code: " << dwLastErrorCode << endl;
#endif
	}

	if (m_nIsFileOpened)
	{
		PlayM4_CloseFile(m_nPort);
		m_nIsFileOpened = FALSE;
	}

	if (m_nIsPortOpened)
	{
		PlayM4_FreePort(m_nPort);
		m_nIsPortOpened = FALSE;
	}
}

BOOL CHikPlayer::Play()
{
	if (m_bIsPlaying)
	{
		if (m_bIsPaused)
		{
			BOOL bResumeRes = PlayM4_Pause(m_nPort, FALSE);
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
		BOOL res = PlayM4_Play(m_nPort, m_hMainWindow);
		if (res)
		{
			m_bIsPlaying = true;
		}
		return res;
	}
}

BOOL CHikPlayer::Stop()
{
	m_bIsPaused = false;
	m_bIsPlaying = false;
	return PlayM4_Stop(m_nPort);
}

BOOL CHikPlayer::Pause()
{
	if (m_bIsPaused || !m_bIsPlaying) return FALSE;
	BOOL bRes = PlayM4_Pause(m_nPort, TRUE);
	if (bRes)
	{
		m_bIsPaused = true;
	}
	return bRes;
}

BOOL CHikPlayer::SwitchSound(BOOL bIsSoundSwitchedOn)
{
	if (bIsSoundSwitchedOn)
	{
		return PlayM4_PlaySound(m_nPort);
	}
	else
	{
		return PlayM4_StopSound();
	}
}

BOOL CHikPlayer::GetVolume(BYTE *pbVolumeLevel)
{
	*pbVolumeLevel = (BYTE)(PlayM4_GetVolume(m_nPort) / SOUND_VOLUME_TRANSFORMATION_COEFF);

	return TRUE;
}

BOOL CHikPlayer::SetVolume(BYTE bVolumeLevel)
{
	return PlayM4_SetVolume(m_nPort, bVolumeLevel * SOUND_VOLUME_TRANSFORMATION_COEFF);
}

BOOL CHikPlayer::GetStreamInfo(PSTREAM_INFO pStreamInfo)
{
	BOOL bFileLengtBOOL = FALSE;
	if (m_dwFileLengthMilliseconds == 0)
	{
		DWORD dwFileLengthSeconds = PlayM4_GetFileTime(m_nPort);
		if (dwFileLengthSeconds != 0xFFFFFFFF)
		{
			m_dwFileLengthMilliseconds = 1000 * dwFileLengthSeconds;
			bFileLengtBOOL = TRUE;
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
	BOOL bPictureSizeResult = PlayM4_GetPictureSize(m_nPort, &lWidth, &lHeight);
	if (bPictureSizeResult)
	{
		pStreamInfo->dwWidth = lWidth;
		pStreamInfo->dwHeight = lHeight;
	}
	else
	{
		pStreamInfo->dwWidth = 0;
		pStreamInfo->dwHeight = 0;
	}

	return bFileLengtBOOL || bPictureSizeResult;
}

BOOL CHikPlayer::SetPlaybackPosition(DWORD dwMilliseconds)
{
	BOOL dwRes = FALSE;
	DWORD dwTimePosition = 0;

	Pause();

	if (dwMilliseconds != 0)
	{
		dwTimePosition = dwMilliseconds + SLEEP_INTERVAL_BEFORE_CHANGING_PLAY_POSITION;
	}
	Sleep(SLEEP_INTERVAL_BEFORE_CHANGING_PLAY_POSITION);

#ifdef _DEBUG
	//cout << "this = " << this << "\tSetPlaybackPosition(" << dwTimePosition << ")" << endl;
#endif
	
	if (PlayM4_SetPlayedTimeEx(m_nPort, dwTimePosition))
	{
		dwRes = TRUE;
		//Play();
	}
	else
	{
		auto errCode =  PlayM4_GetLastError(m_nPort);
#ifdef _DEBUG

		cout << " Error PlayM4_SetPlayedTimeEx : error code = " << errCode << endl;
#endif
	}
	Play();
	return dwRes; 
}

DWORD CHikPlayer::GetPlaybackPosition()
{
	return PlayM4_GetPlayedTimeEx(m_nPort); //Данная функция с ошибкой определяет первый таймштамп - 4294967295
}

BOOL CHikPlayer::MoveToNextFrame()
{
	BOOL res = PlayM4_OneByOne(m_nPort);
	if (res)
	{
		m_bIsPlaying = false;
		m_bIsPaused = false;
	}
	return res;
}

BOOL CHikPlayer::MoveToPreviousFrame()
{
	BOOL res = PlayM4_OneByOneBack(m_nPort);
	if (res)
	{
		m_bIsPlaying = false;
		m_bIsPaused = false;
	}
	return res;
}

BOOL CHikPlayer::IncreasePlaybackSpeed()
{
	BOOL res = PlayM4_Fast(m_nPort);
	return res;
}

BOOL CHikPlayer::DecreasePlaybackSpeed()
{
	BOOL res = PlayM4_Slow(m_nPort);
	return res;
}

// не используется
DWORD CHikPlayer::GetSourceBufferMaxSize()
{
	return 0;
}

// не используется
DWORD CHikPlayer::GetSourceBufferRemainSize()
{
	return 0;
}
// не используется
BOOL CHikPlayer::ResetSourceBuffer()
{
	return FALSE;
}

//Инициализация режима - отображение потока из файла
BOOL CHikPlayer::InitializationFileMode()
{
	return TRUE;
}