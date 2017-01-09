#pragma once
#include "Baseplayer.h"

class CDahuaPlayer :
	public CBasePlayer
{
private:
	bool m_bIsPortSet, m_bIsFileOpened, m_bIsPlaying, m_bIsPaused, m_bIsPlayingInReverseOrder;
	LONG m_lPort;
	//окно, необходимое для корректной работы плеера Dahua
	HWND m_hWnd;
	DWORD m_dwFileLengthMilliseconds;
	DWORD m_dwPrevMilliseconds;
	void PerformCleanup(bool bWasError);
	LONG m_lWidth;
	LONG m_lHeight;

	//Хэндл AutoResetEvent
	HANDLE m_nWaitHandle;

	static void CALLBACK DisplayCBFun(LONG nPort, char * pBuf, LONG nSize, LONG nWidth, LONG nHeight, LONG nStamp, LONG nType, void* pReserved);
	static void CALLBACK FileEndCBFun(DWORD dwPort, void *pUser);

public:
	CDahuaPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND hMainWindow = NULL);
	~CDahuaPlayer(void);

	BOOL Init() override;
	BOOL Play() override;
	BOOL Stop() override;
	BOOL Pause() override;

	BOOL SaveSnapshot(std::string path, std::string name) override;

	BOOL SwitchSound(BOOL bIsSoundSwitchedOn) override;
	BOOL GetVolume(BYTE *pbVolumeLevel) override;
	BOOL SetVolume(BYTE bVolumeLevel) override;

	BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo) override;

	BOOL SetPlaybackPosition(DWORD dwMilliseconds) override;
	DWORD GetPlaybackPosition() override;
	BOOL MoveToNextFrame() override;
	BOOL MoveToPreviousFrame() override;

	BOOL IncreasePlaybackSpeed() override;
	BOOL DecreasePlaybackSpeed() override;

	BOOL InputData(BYTE* pBuf, DWORD dwSize){ return FALSE; }

	BOOL SeekPositionByTime(DWORD dwMilliseconds, DWORD* pdwBytesOffset) override;

	virtual DWORD GetSourceBufferMaxSize() override;

	// Возвращает объем свободного пространства в буфере сырых данных
	virtual DWORD GetSourceBufferRemainSize() override;

	virtual BOOL WINAPI ResetSourceBuffer() override;

	//Инициализация режима - отображение потока из файла
	virtual BOOL InitializationFileMode() override;
};

