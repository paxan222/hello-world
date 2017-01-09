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

	//��������� ������������� ������
	virtual BOOL Init();
	//������ ������� ������������
	virtual BOOL Play();
	//���������� ������� ���������������
	virtual BOOL Stop();
	//��������� ��������������� �� �����
	virtual BOOL Pause();

	//���������/���������� �����
	virtual BOOL SwitchSound(BOOL bIsSoundSwitchedOn);
	//�������� ������� ���������
	virtual BOOL GetVolume(BYTE *pbVolumeLevel);
	//������ ������� ���������
	virtual BOOL SetVolume(BYTE bVolumeLevel);

	//�������� ���������� � �����
	virtual BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo);

	//������ ������� ��������������� � �����
	virtual BOOL SetPlaybackPosition(DWORD dwMilliseconds);
	//������������� �� ��������� ����
	virtual BOOL MoveToNextFrame();
	//������������� �� ���������� ��������� ����
	virtual BOOL MoveToPreviousFrame();

private:
	DShowPlayer *m_pPlayer;
};
