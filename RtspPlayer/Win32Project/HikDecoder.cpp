#include "stdafx.h"
#include "HikDecoder.h"
#include <PlayM4.h>
#include <iostream>
#include <fstream>
#include <ctime>

#pragma comment (lib, "PlayCtrl.lib")

#define NET_DVR_SYSHEAD					1	//System header
#define NET_DVR_STREAMDATA				2	//stream data
#define NET_DVR_AUDIOSTREAMDATA			3	//Audio Stream data
#define NET_DVR_STD_VIDEODATA			4	//Standard video stream data
#define NET_DVR_STD_AUDIODATA			5	//Standard audio stream data
#define NET_DVR_SDP						6   //SDP data(valid for rtsp protocol) 
#define NET_DVR_CHANGE_FORWARD			10  //stream change from reverse to forward  
#define NET_DVR_CHANGE_REVERSE			11  //stream change from forward to reverse
#define NET_DVR_PRIVATE_DATA			112 //Private data

#define SOUND_VOLUME_TRANSFORMATION_COEFF 257 // 257 = 0xFFFF / 0xFF

using namespace std;

CHikDecoder* CHikDecoder::pHikDecoder = NULL;

void CALLBACK CHikDecoder::DisplayCBFun(long nPort, char * pBuf, long nSize, long nWidth, long nHeight, long nStamp, long nType, long nReserved)
{
	if (nType != T_YV12) return;

	CHikDecoder *pDecoder = pHikDecoder;

	BYTE *YBuf, *UBuf, *VBuf;
	YBuf = (byte*)pBuf;
	VBuf = (byte*)pBuf + nWidth * nHeight;
	UBuf = (byte*)pBuf + nWidth * nHeight * 5 / 4;

	pDecoder->SendInit(nPort, nWidth, nHeight);

	pDecoder->Convert_YUV_To_RGB24(YBuf, UBuf, VBuf, nWidth, nHeight, nStamp);
}

BOOL CHikDecoder::SaveSnapshot(std::string path, std::string name)
{
	string fullPath = path + "\\" + name + ".jpg";
	LONG lWidth = 0, lHeight = 0;
	BOOL bPictureSizeResult = PlayM4_GetPictureSize(m_nPort, &lWidth, &lHeight);
	int nLen = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + lWidth * lHeight * 4;
	char *pByte = new char[nLen];
	ZeroMemory(pByte,nLen);
	DWORD pRealSize;  // The actual size

	if (!PlayM4_GetJPEG(m_nPort, (unsigned char*)pByte, nLen, &pRealSize))
	{
		return FALSE;
	}
	
	ofstream file(fullPath, ios::out | ios::binary);
	file.write(pByte, pRealSize);
	file.close();
	return TRUE;
}

void CHikDecoder::SendInit(LONG nPort, LONG nWidth, LONG nHeight)
{
	if (!m_bIsInitSend)
	{
		GetStreamInfo(&m_StreamInfo);
		m_StreamInfo.dwWidth = nWidth;
		m_StreamInfo.dwHeight = nHeight;

		if (m_endInitCallback != nullptr)
		{
			m_endInitCallback(&m_StreamInfo);
		}
		m_bIsInitSend = true;
	}
}

BOOL CHikDecoder::GetStreamInfo(PSTREAM_INFO pStreamInfo)
{
	m_StreamInfo.nBitrateType = BitrateType::BT_UNKNOWN;
	m_StreamInfo.nCodecType = CodecType::CT_UNKNOWN;
	pStreamInfo->nFps = PlayM4_GetCurrentFrameRate(m_nPort);
	LONG lWidth = 0, lHeight = 0;
	BOOL bPictureSizeResult = PlayM4_GetPictureSize(m_nPort, &lWidth, &lHeight);
	
	if (bPictureSizeResult)
	{
		pStreamInfo->dwWidth = lWidth;
		pStreamInfo->dwHeight = lHeight;
	}

	pStreamInfo->dwBitrate = static_cast<DWORD>(GetCurrentBitrate());

	return TRUE;
}

CHikDecoder::CHikDecoder(FDecodeCallback decodeCallback, FEndInitCallback endIntCallback, DWORD openStreamMode, HWND wndHandle) : CBasePlayer("", decodeCallback, NULL, endIntCallback, wndHandle)
{
	m_openStreamMode = openStreamMode;
	av_register_all();
	avcodec_register_all();
	InitializeCriticalSection(&m_CritSect);
	m_nPort = 0;
	m_nPortOpened = 0;
	m_nStreamOpened = 0;
	m_nPlayStarted = 0;
	m_bIsInitSend = false;
	m_bIsInit = false;
	m_bIsPaused = false;
	m_lLastTime = 0;
	m_lInBytes = 0;
}

BOOL CHikDecoder::Play()
{
	EnterCriticalSection(&m_CritSect);

	pHikDecoder = this;

	if (!m_bIsInit)
	{
		Init();
	}

	if (m_bIsInit == true)
	{
		if (m_bIsPaused)
		{
			PlayBackResume();
			m_bIsPaused = false;
		}
		else
		{
			m_nPlayStarted = PlayM4_Play(m_nPort, m_hMainWindow);
			if (m_nPlayStarted == FALSE)
			{
				PerformCleanUp();
			}
		}
	}

	LeaveCriticalSection(&m_CritSect);
	return (m_nPlayStarted == TRUE) ? TRUE : FALSE;
}

BOOL CHikDecoder::Pause() // пауза для воспроизведения собственного архива устройства
{
	m_bIsPaused = true;
	return PlayBackPause();
}

BOOL CHikDecoder::PlayBackPause()
{
	return PlayM4_Pause(m_nPort, TRUE) ? TRUE : FALSE;
}

BOOL CHikDecoder::PlayBackResume()
{
	return PlayM4_Pause(m_nPort, FALSE) ? TRUE : FALSE;
}

BOOL CHikDecoder::Init()
{
	//Заглушка, т.к. необходимо получить из InputData необходимые сведения для инициализации
	return TRUE;
}

BOOL CHikDecoder::InternalInit(BYTE* pBuf, DWORD dwSize)
{
	m_nPortOpened = PlayM4_GetPort(&m_nPort);

	if (m_nPortOpened == FALSE)
	{
		PerformCleanUp();
		m_bIsInit = false;
		return FALSE;
	}
	if (PlayM4_SetStreamOpenMode(m_nPort, m_openStreamMode == 0 ? STREAME_REALTIME : STREAME_FILE) == FALSE)
	{
		PerformCleanUp();
		m_bIsInit = false;
		return FALSE;
	}
	m_nStreamOpened = PlayM4_OpenStream(m_nPort, pBuf, dwSize, SOURCE_BUF_MAX);
	if (m_nStreamOpened == FALSE)
	{
		PerformCleanUp();
		m_bIsInit = false;
		return FALSE;
	}
	
	m_bIsInit = true;
	return TRUE;
}

BOOL CHikDecoder::Stop()
{
	EnterCriticalSection(&m_CritSect);

	if (m_nPlayStarted == TRUE)
	{
		BOOL res = PlayM4_Stop(m_nPort);
		if (res == TRUE)
		{
			m_nPlayStarted = FALSE;
			PerformCleanUp();
		}
	}

	LeaveCriticalSection(&m_CritSect);
	return (m_nPlayStarted == FALSE) ? TRUE : FALSE;
}

void CHikDecoder::PerformCleanUp()
{
	if (m_nPlayStarted)
	{
		PlayM4_SetDisplayCallBack(m_nPort, NULL);
		m_nPlayStarted = FALSE;
	}

	if (m_nStreamOpened)
	{
		PlayM4_CloseStream(m_nPort);
		m_nStreamOpened = FALSE;
	}

	if (m_nPortOpened)
	{
		PlayM4_FreePort(m_nPort);
		m_nPortOpened = FALSE;
	}

	m_bIsInit = false;
	m_nPort = 0;
}

BOOL CHikDecoder::SwitchSound(BOOL bIsSoundSwitchedOn)
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

BOOL CHikDecoder::MoveToNextFrame()
{
	BOOL res = PlayM4_OneByOne(m_nPort);
	return res;
}

BOOL CHikDecoder::MoveToPreviousFrame()
{
	BOOL res = PlayM4_OneByOneBack(m_nPort);
	return res;
}

BOOL CHikDecoder::IncreasePlaybackSpeed()
{
	BOOL res = PlayM4_Fast(m_nPort);
	return res;
}

BOOL CHikDecoder::DecreasePlaybackSpeed()
{
	BOOL res = PlayM4_Slow(m_nPort);
	return res;
}

BOOL CHikDecoder::GetVolume(BYTE *pbVolumeLevel)
{
	*pbVolumeLevel = (BYTE)(PlayM4_GetVolume(m_nPort) / SOUND_VOLUME_TRANSFORMATION_COEFF);

	return TRUE;
}

BOOL CHikDecoder::SetVolume(BYTE bVolumeLevel)
{
	return PlayM4_SetVolume(m_nPort, bVolumeLevel * SOUND_VOLUME_TRANSFORMATION_COEFF);
}

BOOL CHikDecoder::InputData(BYTE* pBuf, DWORD dwSize)
{
	if (!m_bIsInit)
	{
		InternalInit(pBuf, dwSize);
		Play();
		return TRUE;
	}

	if ((dwSize > 0) && (m_nStreamOpened != FALSE))
	{
		m_lInBytes += dwSize;
		if (PlayM4_InputData(m_nPort, pBuf, dwSize))
		{
			return TRUE;
		}
	}
	//return FALSE;
}

BOOL CHikDecoder::Refresh()
{
	BOOL dwRes = PlayM4_ResetSourceBuffer(m_nPort);
	if (m_bIsPaused)
	{
		PlayBackResume();
		m_bIsPaused = false;
	}
	return dwRes;
}

DWORD CHikDecoder::GetPlaybackPosition()
{
	return PlayM4_GetPlayedTimeEx(m_nPort); //Данная функция с ошибкой определяет первый таймштамп - 4294967295
}

// Возвращает размер буфера сырых данных
DWORD CHikDecoder::GetSourceBufferMaxSize()
{
	return PlayM4_GetBufferValue(m_nPort, BUF_VIDEO_SRC);
}

// Возвращает объем свободного пространства в буфере сырых данных
DWORD CHikDecoder::GetSourceBufferRemainSize()
{

	return PlayM4_GetSourceBufferRemain(m_nPort);
}

BOOL CHikDecoder::ResetSourceBuffer()
{
	return PlayM4_ResetBuffer(m_nPort, BUF_VIDEO_SRC);
}

//Инициализация режима - отображение потока из файла
BOOL CHikDecoder::InitializationFileMode()
{
	return TRUE;
}

CHikDecoder::~CHikDecoder(void)
{
	DeleteCriticalSection(&m_CritSect);
	PerformCleanUp();
}
