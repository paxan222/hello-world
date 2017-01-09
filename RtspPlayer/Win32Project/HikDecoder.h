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
	//���������� �������������� ������ ��� ������� ����������� ������ ��� �������������
	BOOL InternalInit(BYTE* pBuf, DWORD dwSize);

public:

	CHikDecoder(FDecodeCallback decodeCallback, FEndInitCallback endIntCallback, DWORD openStreamMode,HWND wndHandle);
	
	BOOL SaveSnapshot(std::string path, std::string name) override;

	//��������� ������������� ������
	BOOL Init() override;
	BOOL Play() override;
	void SendInit(LONG nPort, LONG nWidth, LONG nHeight) override;
	//��������� ��������������� �� �����
	BOOL Pause() override;

	BOOL Stop() override;

	BOOL SwitchSound(BOOL bIsSoundSwitchedOn) override;
	//�������� ������� ���������
	BOOL GetVolume(BYTE *pbVolumeLevel) override;
	//������ ������� ���������
	BOOL SetVolume(BYTE bVolumeLevel) override;

	//�������� ���������� � �����
	BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo) override;

	//������������� �� ��������� ����
	BOOL MoveToNextFrame() override;
	//������������� �� ���������� ��������� ����
	BOOL MoveToPreviousFrame() override;

	BOOL IncreasePlaybackSpeed() override;
	BOOL DecreasePlaybackSpeed() override;

	BOOL InputData(BYTE* pBuf, DWORD dwSize) override;

	BOOL Refresh() override;

	DWORD CHikDecoder::GetPlaybackPosition();

	// ���������� ������ ������ ����� ������
	DWORD GetSourceBufferMaxSize() override;

	// ���������� ����� ���������� ������������ � ������ ����� ������
	DWORD GetSourceBufferRemainSize() override;

	BOOL WINAPI ResetSourceBuffer() override;

	//������������� ������ - ����������� ������ �� �����
	BOOL InitializationFileMode() override;

	~CHikDecoder(void);
};

