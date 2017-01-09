#include "stdafx.h"
#include "SunellDecoder.h"
#include <NvdcPlayerDll.h>

#pragma comment(lib, "NvdcPlayerDll.lib")

#define SOUND_VOLUME_TRANSFORMATION_COEFF 100 / 255

long CALLBACK DecodeCallBack(long p_hHandle, const char * pBuf, long  nSize, FRAME_INFO * pFrameInfo, void* pUserData)
{

	CSunellDecoder *pDecoder = (CSunellDecoder*)pUserData;
	if (pDecoder == NULL) return 0;

	pDecoder->m_dwFpsCounter++;

	pDecoder->SendInit(-1, pFrameInfo->nWidth, pFrameInfo->nHeight);

	pDecoder->Convert_YUV_To_RGB24(
		(BYTE*)pBuf,
		(BYTE*)pBuf + pFrameInfo->nWidth * pFrameInfo->nHeight,
		(BYTE*)pBuf + pFrameInfo->nWidth * pFrameInfo->nHeight * 5 / 4,
		pFrameInfo->nWidth, pFrameInfo->nHeight, pFrameInfo->nStamp / 10);
	return 0;
}

void CSunellDecoder::SendInit(LONG nPort, LONG nWidth, LONG nHeight)
{
	if (!m_bIsInitSend)
	{
		GetStreamInfo(&m_StreamInfo);
		m_StreamInfo.dwWidth = nWidth;
		m_StreamInfo.dwHeight = nHeight;

		if (m_endInitCallback != NULL)
		{
			m_endInitCallback(&m_StreamInfo);
		}
		m_bIsInitSend = true;
	}
}

BOOL CSunellDecoder::GetStreamInfo(PSTREAM_INFO pStreamInfo)
{
		pStreamInfo->nFps = -1;

	pStreamInfo->dwBitrate = static_cast<DWORD>(GetCurrentBitrate());

	LONG lWidth = 0, lHeight = 0;
	BOOL bPictureSizeResult = (Player_GetPictureSize(m_nPort, &lWidth, &lHeight) == 0) ? TRUE : FALSE;
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

	return TRUE;
}

CSunellDecoder::CSunellDecoder(FDecodeCallback decodeCallback, FEndInitCallback endInitCallback, HWND wndHandle) :CBasePlayer(NULL, decodeCallback, NULL, endInitCallback, wndHandle)
{
	InitializeCriticalSection(&m_CritSect);
	av_register_all();
	avcodec_register_all();

	m_bIsInit = false;
	m_bPause = false;
	m_nIsPlayerInitialized = FALSE;
	m_nIsPortInitialized = FALSE;
	m_nPlayStarted = FALSE;
	m_bIsInitSend = false;
	m_dwFpsCounter = 0;
	m_cLastFpsCalcTime = 0;
}

BOOL CSunellDecoder::SaveSnapshot(std::string path, std::string name)
{
	string fullPath = path + "\\" + name + ".jpg";
	return Player_Snapshot(m_nPort, fullPath.c_str());
}

BOOL CSunellDecoder::Play()
{
	EnterCriticalSection(&m_CritSect);

	if (!m_bIsInit)
	{
		Init();
	}

	if (m_bIsInit)
	{
		m_nPlayStarted = (Player_Play(m_nPort, (long)m_hMainWindow) == 0) ? TRUE : FALSE;
		if (!m_nPlayStarted)
		{
			PerformCleanUp();
		}
	}

	m_bPause = false;
	LeaveCriticalSection(&m_CritSect);
	return (m_nPlayStarted == TRUE) ? TRUE : FALSE;
}


BOOL CSunellDecoder::SetStretchMode(BOOL originalAspectRatio)
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

BOOL CSunellDecoder::Stop()
{
	EnterCriticalSection(&m_CritSect);

	if (m_nPlayStarted == TRUE)
	{
		BOOL res = (Player_Stop(m_nPort) == 0) ? TRUE : FALSE;
		if (res == TRUE)
		{
			m_nPlayStarted = FALSE;
			PerformCleanUp();
		}
	}

	LeaveCriticalSection(&m_CritSect);
	return (m_nPlayStarted == FALSE) ? TRUE : FALSE;
}

BOOL CSunellDecoder::Pause()
{
	BOOL bRes = Player_Pause(m_nPort, TRUE) == 0 ? TRUE : FALSE;
	if (bRes)
	{
		m_bPause = true;
	}
	return bRes;
}

BOOL CSunellDecoder::SwitchSound(BOOL bIsSoundSwitchedOn)
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

BOOL CSunellDecoder::GetVolume(BYTE *pbVolumeLevel)
{
	long lVolumeLevel = 0;
	BOOL res = Player_GetVolume(m_nPort, &lVolumeLevel) == 0 ? TRUE : FALSE;

	if (res)
	{
		*pbVolumeLevel = (BYTE)(lVolumeLevel / SOUND_VOLUME_TRANSFORMATION_COEFF);
	}

	return res;
}

BOOL CSunellDecoder::SetVolume(BYTE bVolumeLevel)
{
	return (Player_SetVolume(m_nPort, (long)(bVolumeLevel * SOUND_VOLUME_TRANSFORMATION_COEFF)) == 0) ? TRUE : FALSE;
}

BOOL CSunellDecoder::MoveToNextFrame()
{
	BOOL res = (Player_OneByOne(m_nPort) == 0) ? TRUE : FALSE;
	return res;
}

BOOL CSunellDecoder::MoveToPreviousFrame()
{
	BOOL res = (Player_OneByOneBack(m_nPort) == 0) ? TRUE : FALSE;
	return res;
}

BOOL CSunellDecoder::IncreasePlaybackSpeed()
{
	float fPlaySpeed = 1;
	if (GetIncrementedPlaybackSpeedValue(&fPlaySpeed))
	{
		return Player_SetSpeed(m_nPort, fPlaySpeed) == 0 ? TRUE : FALSE;
	}

	return FALSE;
}

BOOL CSunellDecoder::DecreasePlaybackSpeed()
{
	float fPlaySpeed = 1;
	if (GetDecrementedPlaybackSpeedValue(&fPlaySpeed))
	{
		return Player_SetSpeed(m_nPort, fPlaySpeed) == 0 ? TRUE : FALSE;
	}

	return FALSE;
}

BOOL CSunellDecoder::InputData(BYTE* pBuf, DWORD dwSize)
{
	if ((dwSize > 0) && (m_nIsPortInitialized != FALSE))
	{
		m_lInBytes += dwSize;
		BOOL hRes = (Player_InputTSDataEx(m_nPort, pBuf, dwSize) == 0) ? TRUE : FALSE;

		//cout << "hRes = " << hRes << endl;

		return hRes;
	}
	return FALSE;
}

BOOL CSunellDecoder::Init()
{
	m_nIsPlayerInitialized = (Player_Initial(NULL) == 0) ? TRUE : FALSE;

	if (!m_nIsPlayerInitialized)
	{
		return FALSE;
	}

	m_nIsPortInitialized = (Player_OpenStream(&m_nPort) == 0) ? TRUE : FALSE;
	if (!m_nIsPlayerInitialized)
	{
		PerformCleanUp();
		m_bIsInit = false;
		return FALSE;
	}
	Player_SetPlayBufferSize(m_nPort, SOURCE_BUF_MAX);
	
	m_bIsInit = true;
	return TRUE;
}

void CSunellDecoder::PerformCleanUp()
{
	if (m_nIsPortInitialized)
	{
		Player_CloseStream(m_nPort);
		m_nPort = 0;
		m_nIsPortInitialized = FALSE;
	}

	if (m_nIsPlayerInitialized)
	{
		Player_Free();
		m_nIsPlayerInitialized = FALSE;
	}

	m_bIsInit = false;
}

DWORD CSunellDecoder::GetPlaybackPosition()
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

// Возвращает размер буфера сырых данных
DWORD CSunellDecoder::GetSourceBufferMaxSize()
{
	long bufSize = 0;
	if (Player_GetBufMaxSize(m_nPort, &bufSize))
	{
		return bufSize;
	}
	return 0;
}

// Возвращает объем свободного пространства в буфере сырых данных
DWORD CSunellDecoder::GetSourceBufferRemainSize()
{
	long remainSize = 0;
	if (Player_GetLeftDataSize(m_nPort, &remainSize) == SN_SUCCESS)
	{
		return remainSize;
	}
	return 0;
}

BOOL CSunellDecoder::ResetSourceBuffer()
{
	if (Player_Reset(m_nPort) == SN_SUCCESS);
	{
		return TRUE;
	}
	return FALSE;
}

//Инициализация режима - отображение потока из файла
BOOL CSunellDecoder::InitializationFileMode()
{
	Player_SetInputQueueMaxSize(m_nPort, 100000);
	Player_SetLivePlayFlag(m_nPort, false);
	Player_SetPlayBufferSize(m_nPort, 100000);
	Player_SetUseTimeStamp(m_nPort, true);
	return TRUE;
}

CSunellDecoder::~CSunellDecoder(void)
{
	DeleteCriticalSection(&m_CritSect);
	PerformCleanUp();
}
