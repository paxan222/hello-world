#pragma once
#include "BasePlayer.h"

class CHikDecoder : public CBasePlayer
{
private:
	CRITICAL_SECTION  m_CritSect;
	static CHikDecoder * pHikDecoder;
	LONG m_nPort;
	BOOL m_nPortOpened;
	BOOL m_nStreamOpened;
	BOOL m_nPlayStarted;
	bool m_bIsInitSend;
	bool m_bIsPaused;
	
	
	
	volatile bool m_bIsInit;
	WORD m_openStreamMode;
	static void CALLBACK DisplayCBFun(long nPort, char * pBuf, long nSize, long nWidth, long nHeight, long nStamp, long nType, long nReserved);
	void OnDecodeCallback(BYTE* pRgbBuf, DWORD dwRgbBufSize, DWORD dwStride, DWORD width, DWORD height);

	void PerformCleanUp();

	BOOL PlayBackPause();

	BOOL PlayBackResume();
	//Внутренняя ининциализация плеера при приходе необходимых данных для инициализации
	BOOL InternalInit(BYTE* pBuf, DWORD dwSize);

public:

	CHikDecoder(FDecodeCallback decodeCallback, FEndInitCallback endIntCallback, DWORD openStreamMode,HWND wndHandle);
	
	BOOL SaveSnapshot(std::string path, std::string name) override;

	//выполнить инициализацию плеера
	BOOL Init() override;
	BOOL Play() override;
	void SendInit(LONG nPort, LONG nWidth, LONG nHeight) override;
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

	BOOL Refresh() override;

	DWORD CHikDecoder::GetPlaybackPosition();

	// Возвращает размер буфера сырых данных
	DWORD GetSourceBufferMaxSize() override;

	// Возвращает объем свободного пространства в буфере сырых данных
	DWORD GetSourceBufferRemainSize() override;

	BOOL WINAPI ResetSourceBuffer() override;

	//Инициализация режима - отображение потока из файла
	BOOL InitializationFileMode() override;

	~CHikDecoder(void);
};

