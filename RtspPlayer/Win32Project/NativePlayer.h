#pragma once
#include "stdafx.h"

#ifdef NATIVEPLAYER_EXPORTS
#define NATIVEPLAYER_API __declspec(dllexport) 
#else
#define NATIVEPLAYER_API __declspec(dllimport) 
#endif


enum VendorType : WORD
{
	VT_UNKN = 0,
	VT_DAHUA = 1,
	VT_HIK_VISION = 2,
	VT_SUNNEL = 3,
	VT_XM = 4,
	VT_RTSP = 1000
};

enum OpenStreamMode : DWORD
{
	OSM_REALTIME = 0,
	OSM_FILE = 1,
	OSM_NOT_USED = 2
};

enum class BitrateType : INT
{
	BT_UNKNOWN = 0,
	BT_CBR = 1,
	BT_VBR = 2
};

enum class CodecType : INT
{
	CT_UNKNOWN = 0,
	CT_MJPEG = 1,
	CT_H263 = 2,
	CT_H264 = 3,
	CT_H265 = 4
};


typedef struct
{
	DWORD dwFileLengthMilliseconds;
	DWORD dwWidth;
	DWORD dwHeight;
	DWORD dwBitrate;
	INT nFps;
	BitrateType nBitrateType;
	CodecType nCodecType;

}STREAM_INFO, *PSTREAM_INFO;

#ifdef __cplusplus
extern "C"
{
#endif

	//��� ������� ��� �������� ������ ��� ����������� ������������� ����� �� ��������
	typedef void (CALLBACK *FDecodeCallback)(BYTE* pOutBuf, DWORD dwBufSize, DWORD dwStride, DWORD dwWidth, DWORD dwHeight, DWORD dwTimeStampMilliseconds);

	//��� ������ ��� ��������� ������ ��� ��������� �������������
	typedef void (CALLBACK *FEndInitCallback)(PSTREAM_INFO vsi);

	//��� ������� ��� ��������� ������ ��� ���������� ����� �����
	typedef void (CALLBACK *FFileEndCallback)();
	
	//�������� ��������� �� ����� �����
	NATIVEPLAYER_API PVOID WINAPI GetPlayer(PCHAR pchFileName, VendorType wVendorType, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND hMainWindow = NULL);

	//�������� ��������� �� ����� ������
	NATIVEPLAYER_API PVOID WINAPI GetLivePlayer(VendorType wVendorType, FDecodeCallback fDecodeCallback, FEndInitCallback fEndInitCallback, PCHAR pchFileName, DWORD openStreamMode, HWND hMainWindow = NULL);

	//���������� �������, ���������� �������
	NATIVEPLAYER_API void WINAPI ReleasePlayer(PVOID pPlayer);
	
	// ������ ����� ������ ����������� (originalSapectRatio == true - ����������� ������������ ����������� ������)
	NATIVEPLAYER_API BOOL WINAPI SetStretchMode(PVOID pPlayer, BOOL originalSapectRatio);

	//�������� ���������� � ������
	NATIVEPLAYER_API BOOL WINAPI GetStreamInfo(PVOID pPlayer, PSTREAM_INFO pStreamInfo);

	//������ ��������������� �����
	NATIVEPLAYER_API BOOL WINAPI Play(PVOID pPlayer);

	//���������� ��������������� �� �����
	NATIVEPLAYER_API BOOL WINAPI Pause(PVOID pPlayer);

	//��������� ���������������
	NATIVEPLAYER_API BOOL WINAPI Stop(PVOID pPlayer);

	//���������/���������� �����
	NATIVEPLAYER_API BOOL WINAPI SwitchSound(PVOID pPlayer, BOOL bIsSoundSwitchedOn);

	//�������� ������� �����
	NATIVEPLAYER_API BOOL WINAPI GetVolume(PVOID pPlayer, BYTE *pbVolumeLevel);

	//������ ������� �����
	NATIVEPLAYER_API BOOL WINAPI SetVolume(PVOID pPlayer, BYTE bVolumeLevel);

	//������ ������� ��������������� � ������������� ������������ ������ ������
	NATIVEPLAYER_API BOOL WINAPI SetPlaybackPosition(PVOID pPlayer, DWORD dwMilliseconds);

	//���������� ���������������: ������� �� ��������� ����
	NATIVEPLAYER_API BOOL WINAPI MoveToNextFrame(PVOID pPlayer);

	//���������� ���������������: ������� �� ���������� ����
	NATIVEPLAYER_API BOOL WINAPI MoveToPreviousFrame(PVOID pPlayer);

	//��������� �������� ��������������� � 2 ����
	NATIVEPLAYER_API BOOL WINAPI IncreasePlaybackSpeed(PVOID pPlayer);

	//��������� �������� ��������������� � 2 ����
	NATIVEPLAYER_API BOOL WINAPI DecreasePlaybackSpeed(PVOID pPlayer);

	NATIVEPLAYER_API BOOL WINAPI InputData(PVOID pPlayer, BYTE* pBuf, DWORD dwSize);

	// ����� ��� Hik
	NATIVEPLAYER_API BOOL WINAPI Refresh(PVOID pPlayer);

	NATIVEPLAYER_API BOOL WINAPI SaveSnapshoot(PVOID pPlayer, CHAR* path, CHAR* name);

	NATIVEPLAYER_API DWORD WINAPI GetPlaybackPosition(PVOID pPlayer);

	//����� �������� � �����, ������� ������������� ���������������� �������
	NATIVEPLAYER_API BOOL WINAPI SeekPositionByTime(PVOID pPlayer, DWORD dwMilliseconds, DWORD *pdwBytesOffset);

	// ���������� ������ ������ ����� ������
	NATIVEPLAYER_API DWORD WINAPI GetSourceBufferMaxSize(PVOID pPlayer);

	// ���������� ����� ���������� ������������ � ������ ����� ������
	NATIVEPLAYER_API DWORD WINAPI GetSourceBufferRemainSize(PVOID pPlayer);

	// ������� ����� ����� ������
	NATIVEPLAYER_API BOOL WINAPI ResetSourceBuffer(PVOID pPlayer);

	//������������� ������ - ����������� ������ �� �����
	NATIVEPLAYER_API BOOL WINAPI InitializationFileMode(PVOID pPlayer);	

#ifdef __cplusplus
}
#endif