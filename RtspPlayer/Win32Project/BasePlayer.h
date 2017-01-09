#pragma once
#include "NativePlayer.h"

using namespace std;

#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avutil.lib")
#pragma comment (lib, "swscale.lib")
#pragma comment (lib, "avfilter.lib")

extern "C"
{
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS

#endif
#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libswscale\swscale.h>
#include <libavutil\avutil.h>
#include <libavutil\time.h>
#include <libavfilter\avfilter.h>
}


#define SLEEP_INTERVAL_AFTER_FILE_OPENING 100
 

//������� ����� ������, ������� ������������ �������� ����������
class CBasePlayer
{
private:
	byte b;
	DWORD m_dwFrameCount;
	//���������� ������� �������� ���� ���������� ����������������
	//�������� ���������� ��������: [-4, 4], �������� �� ��������� - 0
	LONG m_nInternalPlaybackSpeed;
	//void SaveBMP(BYTE* pDataBuf, DWORD dwDataBufSize, long nWidth, long nHeight, char *pFileName);
	ULONG_PTR gdiplusToken;


protected:

	bool m_saveSnapShoot;
	
	wstring m_SnapshootPath;
	wstring m_SnapshootName;

	clock_t  m_lLastTime;
	int64_t m_lInBytes;
	double m_prev_bitrate;
	//����� ���� ��� ���������
	HWND m_hMainWindow;
	//������ ��������� �����������, � ������� ���� �������������� ��������
	DWORD m_dwDecodedWidth, m_dwDecodedHeight;
	//��������� �� ������ � ����������� ������
	std::string m_strFileName;
	STREAM_INFO m_StreamInfo;
	
	HRESULT GetGdiplusEncoderClsid(__in LPCWSTR pwszFormat, __out GUID *pGUID);
	//Callback �������, ������� ����� ���������� ��� �������� ��������� RGB24 �����
	FDecodeCallback m_fDecodeCallback;
	//Callback �������, ������� ����� ����������� ��� ���������� ����� �����
	FFileEndCallback m_fFileEndCallback;
	//Callback �������, ������� ����� ���������� ��� ��������� ������������
	FEndInitCallback m_endInitCallback;
	//�������, ���������� callback ������� ��� �������� ��������� RGB24 �����
	virtual void OnDecodeCallback(BYTE* pRgbBuf, DWORD dwRgbBufSize, DWORD dwStride, DWORD width, DWORD height, DWORD dwTimeStampMilliseconds);
	virtual void SendInit(LONG nPort, LONG nWidth, LONG nHeight);
	//�������, ������� ������� �������� ���� ��� ���������� ������� ������� SDK ��������� ��������
	HWND CreateWnd(LPCWSTR szAppName);
	static BOOL DestroyWnd(HWND hWnd);
	//������ ��� ������������� ��������� ����� ����� - ���������������� ������ � ��� ��������������, ��� ��� ����������, ��������, � �������
	virtual DWORD CorrectFrameTimeStamp(DWORD dwTimeStampMilliseconds);

	//����������� �������� ��������������� � �������� �������� ������������ ���������������
	BOOL GetIncrementedPlaybackSpeedValue(float *pfPlaySpeed);
	//����������� ��������� ��������������� � �������� �������� ������������ ���������������
	BOOL GetDecrementedPlaybackSpeedValue(float *pfPlaySpeed);
	// �������������� directx ��� ��������������� ����������� � ������ �� �����
	bool dirExists(const wstring dirName_in);

	double GetCurrentBitrate();

public:

	//����������� YUV ����������� � GRB24
	void Convert_YUV_To_RGB24(BYTE *YBuf, BYTE *UBuf, BYTE *VBuf, LONG nWidth, LONG nHeight, DWORD dwTimeStampMilliseconds);

	virtual BOOL SaveSnapshot(std::string path, std::string name) = 0;

	CBasePlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback,FEndInitCallback endIntCallback, HWND hMainWindow = NULL);

	virtual ~CBasePlayer(void);
	
	// ������ ����� ������ ����������� (originalSapectRatio == true - ����������� ������������ ����������� ������)
	virtual BOOL SetStretchMode(BOOL originalSapectRatio);

	//��������� ������������� ������
	virtual BOOL Init() = 0;
	//������ ������� ������������
	virtual BOOL Play() = 0;
	//���������� ������� ���������������
	virtual BOOL Stop() = 0;
	//��������� ��������������� �� �����
	virtual BOOL Pause() = 0;

	//���������/���������� �����
	virtual BOOL SwitchSound(BOOL bIsSoundSwitchedOn) = 0;
	//�������� ������� ���������
	virtual BOOL GetVolume(BYTE *pbVolumeLevel) = 0;
	//������ ������� ���������
	virtual BOOL SetVolume(BYTE bVolumeLevel) = 0;

	//�������� ���������� � �����
	virtual BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo) = 0;

	//������ ������� ��������������� � �����
	virtual BOOL SetPlaybackPosition(DWORD dwMilliseconds);
	//�������� ������� ������� ��������������� � �����
	virtual DWORD GetPlaybackPosition();
	//�������� ������� ������� ��������������� � ����� � ������ ������������� ��� ����������� ������� � SDK
	virtual DWORD GetAdjustedPlaybackPosition();
	//������������� �� ��������� ����
	virtual BOOL MoveToNextFrame() = 0;
	//������������� �� ���������� ��������� ����
	virtual BOOL MoveToPreviousFrame() = 0;

	//��������� �������� ��������������� � 2 ����
	virtual BOOL IncreasePlaybackSpeed() = 0;
	//��������� �������� ��������������� � 2 ����
	virtual BOOL DecreasePlaybackSpeed() = 0;

	// �������� ������ � ������� �������������
	virtual BOOL InputData(BYTE* pBuf, DWORD dwSize) = 0;

	//�������� �������� ����� � ����� ������� ������, ��������, ��� �������� �� ������ ������� �������
	virtual BOOL Refresh();

	//����� �������� � �����, ������� ������������� ���������������� �������
	virtual BOOL SeekPositionByTime(DWORD dwMilliseconds, DWORD *pdwBytesOffset);

	// ���������� ������ ������ ����� ������
	virtual DWORD GetSourceBufferMaxSize() = 0;

	// ���������� ����� ���������� ������������ � ������ ����� ������
	virtual DWORD GetSourceBufferRemainSize() = 0;

	virtual BOOL WINAPI ResetSourceBuffer() = 0;

	//������������� ������ - ����������� ������ �� �����
	virtual BOOL InitializationFileMode() = 0;
};

//������� ���� windows, ������� ���������� ��� ���������� ������ ������� CreateWnd()
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
