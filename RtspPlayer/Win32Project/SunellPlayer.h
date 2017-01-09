#pragma once
#include "BasePlayer.h"

class CSunellPlayer :
	public CBasePlayer
{
private:
	LONG m_nPort;
	bool m_bIsFileOpened, m_bIsPlaying, m_bIsPaused;
	DWORD m_dwFileLengthMilliseconds;
	HWND m_hWnd;
	//Хэндл AutoResetEvent
	HANDLE m_nWaitHandle;
	//Сдвиг в миллисекундах, если в первом кадре от плеера была ненулевая метка времени
	DWORD m_dwTimeStampMillisecondsShift;

	void PerformCleanup(bool bWasError);
	//Задать таймштамп первого кадра
	void SetFirstTimeStamp();
	//Получить таймштамп первого кадра
	DWORD GetFirstTimeStamp();
	
	//static long CALLBACK CSunellPlayer::FDecodeCallBack(long p_hHandle, const char * pBuf, long  nSize, FRAME_INFO * pFrameInfo, void* pUserData);
	static void CALLBACK CSunellPlayer::FileEndCallback(long p_hHandle, void *pUserData);

protected:
	DWORD CorrectFrameTimeStamp(DWORD dwTimeStampMilliseconds) override;

public:
	CSunellPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND wndHandle);
	~CSunellPlayer();
	LONG m_lWidth;
	LONG m_lHeight;
	BOOL Init() override;
	BOOL Play() override;
	BOOL Stop() override;
	BOOL Pause() override;

	BOOL SetStretchMode(BOOL originalAspectRatio) override;

	BOOL SaveSnapshot(std::string path, std::string name) override;
	BOOL SwitchSound(BOOL bIsSoundSwitchedOn) override;
	BOOL GetVolume(BYTE *pbVolumeLevel) override;
	BOOL SetVolume(BYTE bVolumeLevel) override;

	BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo) override;

	BOOL SetPlaybackPosition(DWORD dwMilliseconds) override;
	DWORD GetPlaybackPosition() override;
	DWORD GetAdjustedPlaybackPosition() override;
	BOOL MoveToNextFrame() override;
	BOOL MoveToPreviousFrame() override;

	BOOL IncreasePlaybackSpeed() override;
	BOOL DecreasePlaybackSpeed() override;

	BOOL InputData(BYTE* pBuf, DWORD dwSize){ return ERROR_CALL_NOT_IMPLEMENTED; }

	//Задать значение первого таймштампа
	void SetFirstTimeStamp(DWORD dwMilliseconds);

	virtual DWORD GetSourceBufferMaxSize() override;

	// Возвращает объем свободного пространства в буфере сырых данных
	virtual DWORD GetSourceBufferRemainSize() override;

	virtual BOOL WINAPI ResetSourceBuffer() override;

	//Инициализация режима - отображение потока из файла
	virtual BOOL InitializationFileMode() override;
};

