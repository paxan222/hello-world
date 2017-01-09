// NativePlayer.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"

#include "DahuaPlayer.h"
#include "HikPlayer.h"
#include "SunellPlayer.h"
#include "FFmpegPlayer.h"

/// live 
#include "DahuaDecoder.h"
#include "HikDecoder.h"
#include "SunellDecoder.h"
#include "RtspDecoder.h"
#include "XmDecoder.h"
#include "XmPlayer.h"

#ifdef _DEBUG
using namespace std;
#endif

//Получить указатель на плеер
NATIVEPLAYER_API PVOID WINAPI GetPlayer(PCHAR pchFileName, VendorType wVendorType, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND hMainWindow)
{
	CBasePlayer *pPlayer;

	switch (wVendorType)
	{
	case VT_DAHUA:
		pPlayer = new CDahuaPlayer(pchFileName, fDecodeCallback, fFileEndCallback, hMainWindow);
		break;
	case VT_UNKN:
	{
		pPlayer = new CFFmpegPlayer(pchFileName, fDecodeCallback, fFileEndCallback, nullptr, hMainWindow);
		break;
	}
	case VT_HIK_VISION:
		pPlayer = new CHikPlayer(pchFileName, fDecodeCallback, fFileEndCallback, hMainWindow);
		break;
	case VT_SUNNEL:
		pPlayer = new CSunellPlayer(pchFileName, fDecodeCallback, fFileEndCallback, hMainWindow);
		break;
	case VT_XM:
		pPlayer = new CXmPlayer(pchFileName, fDecodeCallback, fFileEndCallback, hMainWindow);
		break;
	default:
		return nullptr;
	}

	if (pPlayer->Init() == FALSE)
	{
		delete pPlayer;
		return nullptr;
	}

	return pPlayer;
}

//Получить указатель на плеер
NATIVEPLAYER_API PVOID WINAPI GetLivePlayer(VendorType wVendorType, FDecodeCallback fDecodeCallback, FEndInitCallback fEndInitCallback, PCHAR rtspPath, DWORD openStreamMode, HWND hMainWindow)
{
	CBasePlayer *pPlayer;

	switch (wVendorType)
	{
	case VT_DAHUA:
		//cout << "VT_DAHUA" << endl;
		pPlayer = new CDahuaDecoder(fDecodeCallback, fEndInitCallback, openStreamMode, hMainWindow);
		break;
	case VT_UNKN:
	{
		return nullptr;
	}
	case VT_HIK_VISION:
		//cout << "VT_HIK_VISION" << endl;
		pPlayer = new CHikDecoder(fDecodeCallback, fEndInitCallback, openStreamMode, hMainWindow);
		break;
	case VT_SUNNEL:
		//cout << "VT_SUNNEL" << endl;
		pPlayer = new CSunellDecoder(fDecodeCallback, fEndInitCallback, hMainWindow);
		break;

	case VT_RTSP:
		//cout << "VT_RTSP" << endl;
		pPlayer = new CRtspDecoder(rtspPath, fDecodeCallback, fEndInitCallback);
		break;

	case VT_XM:
		pPlayer = new XmDecoder(fDecodeCallback, fEndInitCallback, openStreamMode, hMainWindow);
		break;
	default:
		return nullptr;
	}

	if (pPlayer->Init() == FALSE)
	{
		delete pPlayer;
		return nullptr;
	}
	return pPlayer;
}

//Выгрузить плеер
NATIVEPLAYER_API void WINAPI ReleasePlayer(PVOID pPlayer)
{
	if (pPlayer == nullptr) return;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	pBasePlayer->Stop();
	delete pBasePlayer;
}

//Режим вывода изображения
NATIVEPLAYER_API BOOL WINAPI SetStretchMode(PVOID pPlayer, BOOL originalAspectRatio)
{
	if (pPlayer == nullptr) return FALSE;
	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->SetStretchMode(originalAspectRatio);
}

//Получить инфо потока
NATIVEPLAYER_API BOOL WINAPI GetStreamInfo(PVOID pPlayer, PSTREAM_INFO pStreamInfo)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->GetStreamInfo(pStreamInfo);
}

NATIVEPLAYER_API BOOL WINAPI Play(PVOID pPlayer)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->Play();
}

NATIVEPLAYER_API BOOL WINAPI Pause(PVOID pPlayer)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->Pause();
}

NATIVEPLAYER_API BOOL WINAPI Stop(PVOID pPlayer)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->Stop();
}

NATIVEPLAYER_API BOOL WINAPI SwitchSound(PVOID pPlayer, BOOL bIsSoundSwitchedOn)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->SwitchSound(bIsSoundSwitchedOn);
}

NATIVEPLAYER_API BOOL WINAPI GetVolume(PVOID pPlayer, BYTE *pbVolumeLevel)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->GetVolume(pbVolumeLevel);
}

NATIVEPLAYER_API BOOL WINAPI SetVolume(PVOID pPlayer, BYTE bVolumeLevel)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->SetVolume(bVolumeLevel);
}

NATIVEPLAYER_API BOOL WINAPI SetPlaybackPosition(PVOID pPlayer, DWORD dwMilliseconds)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->SetPlaybackPosition(dwMilliseconds);
}

NATIVEPLAYER_API BOOL WINAPI MoveToNextFrame(PVOID pPlayer)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer = static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->MoveToNextFrame();
}

NATIVEPLAYER_API BOOL WINAPI MoveToPreviousFrame(PVOID pPlayer)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer =static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->MoveToPreviousFrame();
}

//Увеличить скорость воспроизведения в 2 раза
NATIVEPLAYER_API BOOL WINAPI IncreasePlaybackSpeed(PVOID pPlayer)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer =static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->IncreasePlaybackSpeed();
}

//Замедлить скорость воспроизведения в 2 раза
NATIVEPLAYER_API BOOL WINAPI DecreasePlaybackSpeed(PVOID pPlayer)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer =static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->DecreasePlaybackSpeed();
}

NATIVEPLAYER_API BOOL WINAPI InputData(PVOID pPlayer, BYTE* pBuf, DWORD dwSize)
{
	if (pPlayer == nullptr) return FALSE;
	CBasePlayer *pBasePlayer =static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->InputData(pBuf, dwSize);
}

// пауза для Hik
NATIVEPLAYER_API BOOL WINAPI Refresh(PVOID pPlayer)
{
	if (pPlayer == nullptr) return FALSE;

	CBasePlayer *pBasePlayer =static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->Refresh();
}

NATIVEPLAYER_API BOOL WINAPI SaveSnapshoot(PVOID pPlayer, LPSTR path, LPSTR name)
{
	if (pPlayer == nullptr) return FALSE;

	string path_wstr(path);
	string name_wstr(name);

	CBasePlayer *pBasePlayer =static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->SaveSnapshot(path_wstr.c_str(), name_wstr);
}

NATIVEPLAYER_API DWORD WINAPI GetPlaybackPosition(PVOID pPlayer)
{
	if (pPlayer == nullptr) return 0;
	CBasePlayer *pBasePlayer =static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->GetPlaybackPosition();
}

NATIVEPLAYER_API BOOL WINAPI SeekPositionByTime(PVOID pPlayer, DWORD dwMilliseconds, DWORD *pdwBytesOffset)
{
	if (pPlayer == nullptr) return 0;
	CBasePlayer *pBasePlayer =static_cast<CBasePlayer*>(pPlayer);
	return pBasePlayer->SeekPositionByTime(dwMilliseconds, pdwBytesOffset);
}

// Возвращает размер буферf сырых данных
NATIVEPLAYER_API DWORD WINAPI GetSourceBufferMaxSize(PVOID pPlayer)
{
	if (pPlayer == NULL) return 0;
	CBasePlayer *pBasePlayer = (CBasePlayer*)pPlayer;
	return pBasePlayer->GetSourceBufferMaxSize();
}

// Возвращает объем свободного пространства в буфере сырых данных
NATIVEPLAYER_API DWORD WINAPI GetSourceBufferRemainSize(PVOID pPlayer)
{
	if (pPlayer == NULL) return 0;
	CBasePlayer *pBasePlayer = (CBasePlayer*)pPlayer;
	return pBasePlayer->GetSourceBufferRemainSize();
}

NATIVEPLAYER_API BOOL WINAPI ResetSourceBuffer(PVOID pPlayer)
{
	if (pPlayer == NULL) return 0;
	CBasePlayer *pBasePlayer = (CBasePlayer*)pPlayer;
	return pBasePlayer->ResetSourceBuffer();
}

//Инициализация режима - отображение потока из файла
NATIVEPLAYER_API BOOL WINAPI InitializationFileMode(PVOID pPlayer)
{
	if (pPlayer == NULL) return 0;
	CBasePlayer *pBasePlayer = (CBasePlayer*)pPlayer;
	return pBasePlayer->InitializationFileMode();
}
