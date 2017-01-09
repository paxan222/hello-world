#pragma once
#include "BasePlayer.h"

class CSunellDecoder :	public CBasePlayer
{
#define SOURCE_BUF_MAX	1024 * 100000 // 110 mb

private:
	CRITICAL_SECTION  m_CritSect;
	bool m_bPause;
	BOOL m_nIsPlayerInitialized, m_nIsPortInitialized;
	LONG m_nPort;
	bool m_bIsInitSend;
	volatile bool m_bIsInit;
	int m_nPlayStarted;
	void PerformCleanUp();
	/**
	/!\ Пользователь не должен вызывать этот метод, метод используется самим классом */
	

public:
	clock_t  m_cLastFpsCalcTime;
	DWORD m_dwFpsCounter;

	CSunellDecoder(FDecodeCallback decodeCallback, FEndInitCallback endInitCallback, HWND wndHandle);

	void OnDecodeCallback(BYTE* pRgbBuf, DWORD dwRgbBufSize, DWORD dwStride, DWORD width, DWORD height);

	BOOL Init() override;

	void SendInit(LONG nPort, LONG nWidth, LONG nHeight) override;

	BOOL SaveSnapshot(std::string path, std::string name) override;

	BOOL SetStretchMode(BOOL originalAspectRatio) override;

	BOOL Play() override;

	//Поставить воспроизведение на паузу
	BOOL Pause() override;

	BOOL Stop() override;

	BOOL SwitchSound(BOOL bIsSoundSwitchedOn) override;
	//Получить уровень громкости
	BOOL GetVolume(BYTE *pbVolumeLevel) override;
	//Задать уровень громкости
	BOOL SetVolume(BYTE bVolumeLevel) override;

	//Получить информацию о файле
	BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo) override;

	//Переместиться на следующий кадр
	BOOL MoveToNextFrame() override;
	//Переместиться на предыдущий следующий кадр
	BOOL MoveToPreviousFrame() override;

	BOOL IncreasePlaybackSpeed() override;
	BOOL DecreasePlaybackSpeed() override;

	BOOL InputData(BYTE* pBuf, DWORD dwSize) override;

	DWORD CSunellDecoder::GetPlaybackPosition();

	// Возвращает размер буфера сырых данных
	DWORD GetSourceBufferMaxSize() override;

	// Возвращает объем свободного пространства в буфере сырых данных
	DWORD GetSourceBufferRemainSize() override;

	BOOL WINAPI ResetSourceBuffer() override;

	//Инициализация режима - отображение потока из файла
	BOOL InitializationFileMode() override;

	~CSunellDecoder(void);
};

