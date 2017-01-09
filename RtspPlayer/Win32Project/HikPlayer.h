#pragma once
#include "BasePlayer.h"

class CHikPlayer :
	public CBasePlayer
{
private:
	LONG m_nPort;
	BOOL m_nIsPortOpened, m_nIsFileOpened;
	DWORD m_dwFileLengthMilliseconds;
	bool m_bIsPlaying, m_bIsPaused;

	void PerformCleanup(bool bWasError);

	//static void CALLBACK DisplayCBFun(DISPLAY_INFO *pstDisplayInfo);
	static void CALLBACK FileEndCallback(long nPort, void *pUser);

public:
	CHikPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND wndHandle);
	~CHikPlayer();

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

	BOOL InputData(BYTE* pBuf, DWORD dwSize){ return ERROR_CALL_NOT_IMPLEMENTED; }

	virtual DWORD GetSourceBufferMaxSize() override;

	// Возвращает объем свободного пространства в буфере сырых данных
	virtual DWORD GetSourceBufferRemainSize() override;

	virtual BOOL WINAPI ResetSourceBuffer() override;

	//Инициализация режима - отображение потока из файла
	virtual BOOL InitializationFileMode() override;
};

