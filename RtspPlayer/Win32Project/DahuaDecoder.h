#pragma once
#include "BasePlayer.h"

using namespace std;

class CDahuaDecoder : public CBasePlayer
{

private:
	CRITICAL_SECTION  m_CritSect;
	int m_nPortOpened;
	int m_nStreamOpened;
	int m_nPlayStarted;
	bool isInitSend;
	volatile bool m_bIsInit;
	bool m_bIsPaused;
	//����� �������� ����� ������ - ����� ��� ����
	WORD m_wOpenStreamMode;
	
	static void CALLBACK DisplayCBFun(LONG nPort,char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nStamp,LONG nType, void* pReserved);
	void OnDecodeCallback(BYTE* pRgbBuf,DWORD dwRgbBufSize,DWORD dwStride,DWORD width, DWORD height);
	 
	void Release();
public:

	
	//dhplay.dll
	LONG m_lPort; //���� �������������

	CDahuaDecoder(FDecodeCallback decodeCallback, FEndInitCallback endIntCallback, WORD wOpenStreamMode, HWND hMainWindow = NULL);

	virtual void SendInit(LONG nPort, LONG nWidth, LONG nHeight);

	BOOL SaveSnapshot(std::string path, std::string name) override;

	BOOL Init() override;

	BOOL Play() override;

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

	DWORD CDahuaDecoder::GetPlaybackPosition();

	// ���������� ������ ������ ����� ������
	DWORD GetSourceBufferMaxSize() override;

	// ���������� ����� ���������� ������������ � ������ ����� ������
	DWORD GetSourceBufferRemainSize() override;

	BOOL WINAPI ResetSourceBuffer() override;

	//������������� ������ - ����������� ������ �� �����
	BOOL InitializationFileMode() override;

	~CDahuaDecoder(void);
};

