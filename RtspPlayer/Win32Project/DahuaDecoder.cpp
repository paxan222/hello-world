#include "stdafx.h"
#include "DahuaDecoder.h"
#include <dhplay.h>

#pragma comment (lib, "dhplay.lib")

#define COMPOSITE_STREAM_TYPE 3
#define SOUND_VOLUME_TRANSFORMATION_COEFF 257 // 257 = 0xFFFF / 0xFF

void CALLBACK CDahuaDecoder::DisplayCBFun(LONG nPort, char * pBuf, LONG nSize, LONG nWidth, LONG nHeight, LONG nStamp, LONG nType, void* pReserved)
{
	CDahuaDecoder * pDecoder = (CDahuaDecoder*)(pReserved);
	if (pDecoder == NULL)
	{
		return;
	}

	BYTE *YBuf, *UBuf, *VBuf;
	YBuf = (byte*)pBuf;
	UBuf = (byte*)pBuf + nWidth * nHeight;
	VBuf = (byte*)pBuf + nWidth * nHeight * 5 / 4;

	pDecoder->SendInit(nPort, nWidth, nHeight);

	pDecoder->Convert_YUV_To_RGB24(YBuf, UBuf, VBuf, nWidth, nHeight, nStamp);
}

BOOL CDahuaDecoder::SaveSnapshot(std::string path, std::string name)
{
	string fullPath = path + "\\" + name + ".jpg";
	return PLAY_CatchPic(m_lPort, (char*)fullPath.c_str());
}


void CDahuaDecoder::SendInit(LONG nPort, LONG nWidth, LONG nHeight)
{
	if (!isInitSend)
	{
		GetStreamInfo(&m_StreamInfo);
		m_StreamInfo.dwWidth = nWidth;
		m_StreamInfo.dwHeight = nHeight;

		if (m_endInitCallback != NULL)
		{
			m_endInitCallback(&m_StreamInfo);
		}

		isInitSend = true; // ??? задание параметров произойдет один раз - убрать проверку для постоянного обновляения информации
	}
}

CDahuaDecoder::CDahuaDecoder(FDecodeCallback decodeCallback, FEndInitCallback endIntCallback, WORD wOpenStreamMode, HWND hMainWindow) :CBasePlayer(NULL, decodeCallback, NULL, endIntCallback, hMainWindow)
{
	InitializeCriticalSection(&m_CritSect);
	av_register_all();
	avcodec_register_all();

	m_nPortOpened = false;
	m_nStreamOpened = false;
	m_nPlayStarted = false;
	m_bIsInit = false;
	m_bIsPaused = false;
	isInitSend = false;
	m_lPort = 0;
	m_wOpenStreamMode = wOpenStreamMode;
}


BOOL CDahuaDecoder::GetStreamInfo(PSTREAM_INFO pStreamInfo)
{
	MEDIA_INFO mediaInfo;
	int retSize;
	if (PLAY_QueryInfo(m_lPort, PLAY_CMD_GetMediaInfo, (char*)&mediaInfo, sizeof(MEDIA_INFO), &retSize))
	{
		LONG lWidth = 0, lHeight = 0;
		PLAY_GetPictureSize(m_lPort, &lWidth, &lHeight);
		pStreamInfo->dwWidth = lWidth;
		pStreamInfo->dwHeight = lHeight;

		pStreamInfo->nFps = mediaInfo.lFrameRate;

		pStreamInfo->dwBitrate = static_cast<DWORD>(GetCurrentBitrate());
		
		pStreamInfo->nBitrateType = BitrateType::BT_UNKNOWN;
		pStreamInfo->nCodecType = CodecType::CT_UNKNOWN;
	}
	//cout << pStreamInfo->nFps << " | " << pStreamInfo->dwBitrate << endl;
	return TRUE;
}

BOOL CDahuaDecoder::Init()
{
	m_nPortOpened = PLAY_GetFreePort(&m_lPort); // открыть порт проигрывания
	if (m_nPortOpened == FALSE)
	{
		Release();
		m_bIsInit = false;
		return FALSE;
	}

	int ret = PLAY_SetStreamOpenMode(m_lPort, m_wOpenStreamMode == 0 ? STREAME_REALTIME : STREAME_FILE); // задать режим открытия потока
	if (ret == FALSE)
	{
		Release();
		m_bIsInit = false;
		return FALSE;
	}
	m_nStreamOpened = PLAY_OpenStream(m_lPort, NULL, 0, 1024 * 200000); // открыть поток
	if (m_nStreamOpened == FALSE)
	{
		Release();
		m_bIsInit = false;
		return FALSE;
	}
	//ret = PLAY_SetDisplayCallBack(m_lPort, DisplayCBFun, this); // задать функцию обратного вызова для получения кадров
	//if (ret == FALSE)
	//{
	//	Release();
	//	m_bIsInit = false;
	//	return FALSE;
	//}

	ret = PLAY_SetDecCBStream(m_lPort, COMPOSITE_STREAM_TYPE); // задать тип получаемых данных
	if (ret == FALSE)
	{
		Release();
		m_bIsInit = false;
		return FALSE;
	}
	m_bIsInit = true;
	return TRUE;
}

void CDahuaDecoder::Release()
{
	if (m_nPlayStarted)
	{
		PLAY_SetDisplayCallBack(m_lPort, NULL, NULL);// отменить регистрацию на получение декодированных кадров
		m_nPlayStarted = FALSE;
	}

	if (m_nStreamOpened)
	{
		PLAY_CloseStream(m_lPort); // закрыть поток
		m_nStreamOpened = FALSE;
	}

	if (m_nPortOpened)
	{
		PLAY_ReleasePort(m_lPort); // освободить порт проигрывателя
		m_nPortOpened = FALSE;
	}

	m_bIsInit = false;
	m_lPort = 0;
}

BOOL CDahuaDecoder::Play()
{

	EnterCriticalSection(&m_CritSect);

	if (!m_bIsInit)
	{
		Init();
	}

	if (m_bIsInit == true)
	{
		if (m_bIsPaused)
		{
			PLAY_Pause(m_lPort, FALSE);
			m_bIsPaused = false;
		}
		else
		{
			
			m_nPlayStarted = PLAY_Play(m_lPort, m_hMainWindow);
			if (m_nPlayStarted == FALSE)
			{
				//cout << "Error while trying to start playing #" << endl;
				Release();
				m_bIsInit = false;
			}
		}
	}

	LeaveCriticalSection(&m_CritSect);
	return (m_nPlayStarted == TRUE) ? TRUE : FALSE;
}

BOOL CDahuaDecoder::Stop()
{
	EnterCriticalSection(&m_CritSect);

	if (m_nPlayStarted == TRUE)
	{
		BOOL res = PLAY_Stop(m_lPort);
		if (res == TRUE)
		{
			m_nPlayStarted = FALSE;
			Release();
		}
	}

	LeaveCriticalSection(&m_CritSect);
	return (m_nPlayStarted == FALSE) ? TRUE : FALSE;
}

BOOL CDahuaDecoder::Pause()
{
	m_bIsPaused = true;
	return PLAY_Pause(m_lPort, TRUE);
}

BOOL CDahuaDecoder::SwitchSound(BOOL bIsSoundSwitchedOn)
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

BOOL CDahuaDecoder::GetVolume(BYTE *pbVolumeLevel)
{
	WORD wVolume = PLAY_GetVolume(m_lPort);
	*pbVolumeLevel = static_cast<BYTE>((wVolume / SOUND_VOLUME_TRANSFORMATION_COEFF));

	return TRUE;
}

BOOL CDahuaDecoder::SetVolume(BYTE bVolumeLevel)
{
	return PLAY_SetVolume(m_lPort, bVolumeLevel * SOUND_VOLUME_TRANSFORMATION_COEFF);
}

BOOL CDahuaDecoder::MoveToNextFrame()
{
	BOOL res = PLAY_OneByOne(m_lPort);
	return res;
}

BOOL CDahuaDecoder::MoveToPreviousFrame()
{
	BOOL res = PLAY_OneByOneBack(m_lPort);
	return res;
}

BOOL CDahuaDecoder::IncreasePlaybackSpeed()
{
	float fPlaySpeed = 1;
	if (GetIncrementedPlaybackSpeedValue(&fPlaySpeed))
	{
		return PLAY_SetPlaySpeed(m_lPort, fPlaySpeed);
	}

	return FALSE;
}

BOOL CDahuaDecoder::DecreasePlaybackSpeed()
{
	float fPlaySpeed = 1;
	if (GetDecrementedPlaybackSpeedValue(&fPlaySpeed))
	{
		return PLAY_SetPlaySpeed(m_lPort, fPlaySpeed);
	}

	return FALSE;
}

/**
Добавляет данные для декодирования

@param pBuf указатель на буфер входных данных
@param dwSize размер буфера входных данных
@return TRUE если успешно, FALSE -буфер заполнен
*/
BOOL CDahuaDecoder::InputData(BYTE* pBuf, DWORD dwSize)
{
	if (m_nPlayStarted)
	{
		m_lInBytes += dwSize;
		if (PLAY_InputData(m_lPort, pBuf, dwSize))
		{
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}

BOOL CDahuaDecoder::Refresh()
{
	BOOL dwRes = PLAY_ResetSourceBuffer(m_lPort);
	if (m_bIsPaused)
	{
		PLAY_Pause(m_lPort, FALSE);
		m_bIsPaused = false;
	}
	return dwRes;
}

DWORD CDahuaDecoder::GetPlaybackPosition()
{
	return PLAY_GetPlayedTimeEx(m_lPort);
}

// Возвращает размер буфера сырых данных
DWORD CDahuaDecoder::GetSourceBufferMaxSize()
{
	return PLAY_GetBufferValue(m_lPort, BUF_VIDEO_SRC);
}

// Возвращает объем свободного пространства в буфере сырых данных
DWORD CDahuaDecoder::GetSourceBufferRemainSize()
{

	return PLAY_GetSourceBufferRemain(m_lPort);
}

BOOL CDahuaDecoder::ResetSourceBuffer()
{
	return PLAY_ResetSourceBuffer(m_lPort);
}

//Инициализация режима - отображение потока из файла
BOOL CDahuaDecoder::InitializationFileMode() 
{ 
	return TRUE; 
}

CDahuaDecoder::~CDahuaDecoder(void)
{
	DeleteCriticalSection(&m_CritSect);
	Release();
}