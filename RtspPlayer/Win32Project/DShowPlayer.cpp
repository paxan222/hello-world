#include "stdafx.h"
#include "DShowPlayer.h"
#include <string>

CDShowPlayer::CDShowPlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback) :CBasePlayer(pchFileName, fDecodeCallback, fFileEndCallback, NULL)
{

}

CDShowPlayer::~CDShowPlayer()
{
	delete m_pPlayer;
}

//выполнить инициализацию плеера
BOOL CDShowPlayer::Init()
{
	BOOL hr;
	HWND hwnd = CreateWnd(L"dshow_wnd");
	m_pPlayer = new DShowPlayer(hwnd);
	if (m_pPlayer == NULL)
	{
		return FALSE;
	}

	auto ansi_str = m_strFileName;
	const int size_of_ansi_str = 255;
	wchar_t ansi_wcstr[size_of_ansi_str];
	MultiByteToWideChar(CP_ACP, 0, ansi_str.c_str(), -1, ansi_wcstr, size_of_ansi_str);
	std::wstring ansi_wstr = std::wstring(ansi_wcstr);

	hr = m_pPlayer->OpenFile(ansi_wstr.c_str());
}
//Начать процесс проигрывания
BOOL CDShowPlayer::Play()
{ 
	m_pPlayer->Play(); 
	return TRUE;
}
//Остановить процесс воспроизведения
BOOL CDShowPlayer::Stop()
{
	m_pPlayer->Stop();
	return TRUE;
}
//Поставить воспроизведение на паузу
BOOL CDShowPlayer::Pause()
{
	m_pPlayer->Pause();
	return TRUE;
}
//Включение/выключение звука
BOOL CDShowPlayer::SwitchSound(BOOL bIsSoundSwitchedOn){ return FALSE; }
//Получить уровень громкости
BOOL CDShowPlayer::GetVolume(BYTE *pbVolumeLevel){ return FALSE; }
//Задать уровень громкости
BOOL CDShowPlayer::SetVolume(BYTE bVolumeLevel){ return FALSE; }
//Получить информацию о файле
BOOL CDShowPlayer::GetStreamInfo(PSTREAM_INFO pStreamInfo){ return FALSE; }
//Задать позицию воспроизведения в файле
BOOL CDShowPlayer::SetPlaybackPosition(DWORD dwMilliseconds){ return FALSE; }
//Переместиться на следующий кадр
BOOL CDShowPlayer::MoveToNextFrame(){ return FALSE; }
//Переместиться на предыдущий следующий кадр
BOOL CDShowPlayer::MoveToPreviousFrame(){ return FALSE; }