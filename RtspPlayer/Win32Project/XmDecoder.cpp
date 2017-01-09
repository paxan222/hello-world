#include "stdafx.h"
#include "XmDecoder.h"


void XmDecoder::OnDecodeCallback(BYTE* pRgbBuf, DWORD dwRgbBufSize, DWORD dwStride, DWORD width, DWORD height, DWORD dwTimeStampMilliseconds)
{
}

DWORD XmDecoder::GetSourceBufferMaxSize()
{
	return 0;
}

DWORD XmDecoder::GetSourceBufferRemainSize()
{
	return 0;
}

BOOL XmDecoder::ResetSourceBuffer()
{
	return 0;
}

BOOL XmDecoder::InitializationFileMode()
{
	return 0;
}

void XmDecoder::Release()
{
	if (m_nStreamOpened)
	{
		H264_PLAY_Stop(m_lPort);
	}

	if (m_nStreamOpened)
	{
		H264_PLAY_CloseStream(m_lPort); // закрыть поток
		m_nStreamOpened = FALSE;
	}

	if (m_nPortOpened)
	{
		H264_PLAY_FreePort(m_lPort); // освободить порт проигрывателя
		m_nPortOpened = FALSE;
	}

	m_bIsInit = false;
	m_lPort = -1;
}

BOOL XmDecoder::Init()
{
	InitializeCriticalSection(&m_CritSect);

	m_nPortOpened = H264_PLAY_GetPort(&m_lPort); // открыть порт проигрывания
	if (m_nPortOpened == FALSE)
	{
		Release();
		m_bIsInit = false;
		return FALSE;
	}

	int ret = H264_PLAY_SetStreamOpenMode(m_lPort, m_wOpenStreamMode);
	if (ret == FALSE)
	{
		Release();
		m_bIsInit = false;
		return FALSE;
	}

	m_nStreamOpened = H264_PLAY_OpenStream(m_lPort, nullptr, 0, SOURCE_BUF_MAX); // открыть поток
	if (m_nStreamOpened == FALSE)
	{
		Release();
		m_bIsInit = false;
		return FALSE;
	}

	m_bIsInit = true;
	return TRUE;
}

BOOL XmDecoder::Play()
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
			H264_PLAY_Pause(m_lPort, FALSE);
			m_bIsPaused = false;
		}
		else
		{

			m_nPlayStarted = H264_PLAY_Play(m_lPort, m_hMainWindow);
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

BOOL XmDecoder::Stop()
{
	return 0;
}

BOOL XmDecoder::GetStreamInfo(PSTREAM_INFO pStreamInfo)
{
	long fps = H264_PLAY_GetPlayFPS(m_lPort);
	long width, height = 0;
	BOOL res = H264_PLAY_GetPictureSize(m_lPort, &width, &height);
	if (res == TRUE)
	{
		pStreamInfo->dwHeight = height;
		pStreamInfo->dwWidth = width;
	}
	else
	{
		pStreamInfo->dwHeight = 0;
		pStreamInfo->dwWidth = 0;
	}

	pStreamInfo->dwBitrate = static_cast<DWORD>(GetCurrentBitrate());

	pStreamInfo->nBitrateType = BitrateType::BT_UNKNOWN;
	pStreamInfo->nCodecType = CodecType::CT_UNKNOWN;
	return 0;
}

BOOL XmDecoder::InputData(BYTE* pBuf, DWORD dwSize)
{
	if (m_bIsInit)
	{
		return H264_PLAY_InputData(m_lPort, pBuf, dwSize);
	}

	return FALSE;
}

XmDecoder::XmDecoder(FDecodeCallback decodeCallback, FEndInitCallback endIntCallback, WORD wOpenStreamMode, HWND hMainWindow) : CBasePlayer(NULL, decodeCallback, NULL, endIntCallback, hMainWindow)
{
	m_wOpenStreamMode = wOpenStreamMode;
	m_lPort = -1;
	m_nPortOpened = false;
	m_nStreamOpened = false;
	m_nPlayStarted = false;
	m_bIsInit = false;
	m_bIsPaused = false;
	isInitSend = false;
}

XmDecoder::~XmDecoder()
{
	DeleteCriticalSection(&m_CritSect);
	Release();
}
