#pragma once


/*
 error comes from the vlc headers trying to use macros in stdint.h that are only defined for C and not C++. 
 You can add a #define that should be able to fix this. From your C++ code:
*/
extern "C"
{
#ifndef __STDC_CONSTANT_MACROS
#  define __STDC_CONSTANT_MACROS
#endif
}

#include "BasePlayer.h"

class CRtspDecoder : public CBasePlayer
{
private:
	char* m_rtspPath;
	CRITICAL_SECTION  m_CritSect;
	bool m_bPause;
	AVFormatContext* format_context;
	SwsContext* img_convert_context;
	AVCodecContext* codec_context;
	AVCodec* codec;
	unsigned char *mExtradataBuffer;
	unsigned int mExtardataBufferSize;

	volatile bool m_bIsInit;
	int m_nPlayStarted;
	int video_stream_idx;	// индекс видеопотока в контейнере
	int audio_stream_idx;	// индекс аудиопотока в контейнере
	int w,h;
	int w16; // ширина выходного изображения выравненная на 16 байт
	bool m_bIsInitSend;

	HANDLE hDecodeThread;
	HANDLE hInitThread;

	void Cleanup(); // освобождает ресурсы

public:
	CRtspDecoder(const char* rtspPath,FDecodeCallback decodeCallback,FEndInitCallback endInitCallback);

	void SendInitCompleted();

	void Decode();

	BOOL Open();

	virtual BOOL Play();

	BOOL SaveSnapshot(std::string path, std::string name) override;

	//Поставить воспроизведение на паузу
	virtual BOOL Pause(){ return Stop(); }

	virtual BOOL Stop();

	virtual BOOL SwitchSound(BOOL bIsSoundSwitchedOn){ return TRUE; }
	//Получить уровень громкости
	virtual BOOL GetVolume(BYTE *pbVolumeLevel){ return TRUE; }
	//Задать уровень громкости
	virtual BOOL SetVolume(BYTE bVolumeLevel){ return TRUE; }

	//Получить информацию о файле
	virtual BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo){ return TRUE; }

	//Задать позицию воспроизведения в файле
	virtual BOOL SetPlaybackPosition(DWORD dwMilliseconds){ return TRUE; }
	//Переместиться на следующий кадр
	virtual BOOL MoveToNextFrame(){ return TRUE; }
	//Переместиться на предыдущий следующий кадр
	virtual BOOL MoveToPreviousFrame(){ return TRUE; }

	BOOL IncreasePlaybackSpeed() override;
	BOOL DecreasePlaybackSpeed() override;

	virtual BOOL InputData(BYTE* pBuf, DWORD dwSize);

	// не используется
	virtual DWORD GetSourceBufferMaxSize() override { return 0; }
	// не используется
	virtual DWORD GetSourceBufferRemainSize() override { return 0; }
	// не используется
	virtual BOOL WINAPI ResetSourceBuffer() override { return FALSE; }
	//Инициализация режима - отображение потока из файла
	virtual BOOL InitializationFileMode() override { return TRUE; }

	~CRtspDecoder(void);
};

