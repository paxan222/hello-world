#pragma once
#include <windows.h>
#include "BasePlayer.h"
#include "playback.h"

class CDShowPlayer : CBasePlayer
{
public:
	CDShowPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback);
	~CDShowPlayer();
	BOOL SetDecodedFrameSize(DWORD dwWidth, DWORD dwHeight);

	//выполнить инициализацию плеера
	virtual BOOL Init();
	//Начать процесс проигрывания
	virtual BOOL Play();
	//Остановить процесс воспроизведения
	virtual BOOL Stop();
	//Поставить воспроизведение на паузу
	virtual BOOL Pause();

	//Включение/выключение звука
	virtual BOOL SwitchSound(BOOL bIsSoundSwitchedOn);
	//Получить уровень громкости
	virtual BOOL GetVolume(BYTE *pbVolumeLevel);
	//Задать уровень громкости
	virtual BOOL SetVolume(BYTE bVolumeLevel);

	//Получить информацию о файле
	virtual BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo);

	//Задать позицию воспроизведения в файле
	virtual BOOL SetPlaybackPosition(DWORD dwMilliseconds);
	//Переместиться на следующий кадр
	virtual BOOL MoveToNextFrame();
	//Переместиться на предыдущий следующий кадр
	virtual BOOL MoveToPreviousFrame();

private:
	DShowPlayer *m_pPlayer;
};
