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

//��������� ������������� ������
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
//������ ������� ������������
BOOL CDShowPlayer::Play()
{ 
	m_pPlayer->Play(); 
	return TRUE;
}
//���������� ������� ���������������
BOOL CDShowPlayer::Stop()
{
	m_pPlayer->Stop();
	return TRUE;
}
//��������� ��������������� �� �����
BOOL CDShowPlayer::Pause()
{
	m_pPlayer->Pause();
	return TRUE;
}
//���������/���������� �����
BOOL CDShowPlayer::SwitchSound(BOOL bIsSoundSwitchedOn){ return FALSE; }
//�������� ������� ���������
BOOL CDShowPlayer::GetVolume(BYTE *pbVolumeLevel){ return FALSE; }
//������ ������� ���������
BOOL CDShowPlayer::SetVolume(BYTE bVolumeLevel){ return FALSE; }
//�������� ���������� � �����
BOOL CDShowPlayer::GetStreamInfo(PSTREAM_INFO pStreamInfo){ return FALSE; }
//������ ������� ��������������� � �����
BOOL CDShowPlayer::SetPlaybackPosition(DWORD dwMilliseconds){ return FALSE; }
//������������� �� ��������� ����
BOOL CDShowPlayer::MoveToNextFrame(){ return FALSE; }
//������������� �� ���������� ��������� ����
BOOL CDShowPlayer::MoveToPreviousFrame(){ return FALSE; }