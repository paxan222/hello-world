#pragma once
#include "NativePlayer.h"

using namespace std;

#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avutil.lib")
#pragma comment (lib, "swscale.lib")
#pragma comment (lib, "avfilter.lib")

extern "C"
{
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS

#endif
#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libswscale\swscale.h>
#include <libavutil\avutil.h>
#include <libavutil\time.h>
#include <libavfilter\avfilter.h>
}


#define SLEEP_INTERVAL_AFTER_FILE_OPENING 100
 

//Базовый класс плеера, который поддерживает основной функционал
class CBasePlayer
{
private:
	byte b;
	DWORD m_dwFrameCount;
	//Внутренний счетчик текущего шага управления воспроизведением
	//Диапазон изменяемых значений: [-4, 4], значение по умолчанию - 0
	LONG m_nInternalPlaybackSpeed;
	//void SaveBMP(BYTE* pDataBuf, DWORD dwDataBufSize, long nWidth, long nHeight, char *pFileName);
	ULONG_PTR gdiplusToken;


protected:

	bool m_saveSnapShoot;
	
	wstring m_SnapshootPath;
	wstring m_SnapshootName;

	clock_t  m_lLastTime;
	int64_t m_lInBytes;
	double m_prev_bitrate;
	//Хэндл окна для отрисовки
	HWND m_hMainWindow;
	//Размер выходного изображения, в который надо конвертировать исходное
	DWORD m_dwDecodedWidth, m_dwDecodedHeight;
	//указатель на строку с открываемым файлом
	std::string m_strFileName;
	STREAM_INFO m_StreamInfo;
	
	HRESULT GetGdiplusEncoderClsid(__in LPCWSTR pwszFormat, __out GUID *pGUID);
	//Callback функция, которая будет вызываться при успешном получении RGB24 кадра
	FDecodeCallback m_fDecodeCallback;
	//Callback функция, которая будет запускаться при достижении конца файла
	FFileEndCallback m_fFileEndCallback;
	//Callback функция, которая будет вызываться при окончании инииализации
	FEndInitCallback m_endInitCallback;
	//Функция, зажигающая callback функцию при успешном получении RGB24 кадра
	virtual void OnDecodeCallback(BYTE* pRgbBuf, DWORD dwRgbBufSize, DWORD dwStride, DWORD width, DWORD height, DWORD dwTimeStampMilliseconds);
	virtual void SendInit(LONG nPort, LONG nWidth, LONG nHeight);
	//Функция, которая создает виндовое окно для реализации затыков косяков SDK сторонних вендоров
	HWND CreateWnd(LPCWSTR szAppName);
	static BOOL DestroyWnd(HWND hWnd);
	//Фунция для корректировки временной метки кадра - переопределяется только у тех производителей, где это необходимо, например, у Санелла
	virtual DWORD CorrectFrameTimeStamp(DWORD dwTimeStampMilliseconds);

	//Попробовать ускорить воспроизведение и получить значение коэффициента воспроизведения
	BOOL GetIncrementedPlaybackSpeedValue(float *pfPlaySpeed);
	//Попробовать замедлить воспроизведение и получить значение коэффициента воспроизведения
	BOOL GetDecrementedPlaybackSpeedValue(float *pfPlaySpeed);
	// инициализирует directx для масштабирования изображения и вывода на экран
	bool dirExists(const wstring dirName_in);

	double GetCurrentBitrate();

public:

	//Конвертация YUV изображения в GRB24
	void Convert_YUV_To_RGB24(BYTE *YBuf, BYTE *UBuf, BYTE *VBuf, LONG nWidth, LONG nHeight, DWORD dwTimeStampMilliseconds);

	virtual BOOL SaveSnapshot(std::string path, std::string name) = 0;

	CBasePlayer(PCHAR pchFileName, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback,FEndInitCallback endIntCallback, HWND hMainWindow = NULL);

	virtual ~CBasePlayer(void);
	
	// Задает режим вывода изображения (originalSapectRatio == true - сохраняется оригинальное соотношение сторон)
	virtual BOOL SetStretchMode(BOOL originalSapectRatio);

	//выполнить инициализацию плеера
	virtual BOOL Init() = 0;
	//Начать процесс проигрывания
	virtual BOOL Play() = 0;
	//Остановить процесс воспроизведения
	virtual BOOL Stop() = 0;
	//Поставить воспроизведение на паузу
	virtual BOOL Pause() = 0;

	//Включение/выключение звука
	virtual BOOL SwitchSound(BOOL bIsSoundSwitchedOn) = 0;
	//Получить уровень громкости
	virtual BOOL GetVolume(BYTE *pbVolumeLevel) = 0;
	//Задать уровень громкости
	virtual BOOL SetVolume(BYTE bVolumeLevel) = 0;

	//Получить информацию о файле
	virtual BOOL GetStreamInfo(PSTREAM_INFO pStreamInfo) = 0;

	//Задать позицию воспроизведения в файле
	virtual BOOL SetPlaybackPosition(DWORD dwMilliseconds);
	//Получить текущую позицию воспроизведения в файле
	virtual DWORD GetPlaybackPosition();
	//Получить текущую позицию воспроизведения в файле с учётом корректировки для исправления косяков в SDK
	virtual DWORD GetAdjustedPlaybackPosition();
	//Переместиться на следующий кадр
	virtual BOOL MoveToNextFrame() = 0;
	//Переместиться на предыдущий следующий кадр
	virtual BOOL MoveToPreviousFrame() = 0;

	//Увеличить скорость воспроизведения в 2 раза
	virtual BOOL IncreasePlaybackSpeed() = 0;
	//Замедлить скорость воспроизведения в 2 раза
	virtual BOOL DecreasePlaybackSpeed() = 0;

	// добавить данные в очередь декодирования
	virtual BOOL InputData(BYTE* pBuf, DWORD dwSize) = 0;

	//Обновить нативный плеер с целью очистки буфера, например, при переходе на другую отметку времени
	virtual BOOL Refresh();

	//Поиск смещения в файле, которое соответствует воспроизводимому времени
	virtual BOOL SeekPositionByTime(DWORD dwMilliseconds, DWORD *pdwBytesOffset);

	// Возвращает размер буфера сырых данных
	virtual DWORD GetSourceBufferMaxSize() = 0;

	// Возвращает объем свободного пространства в буфере сырых данных
	virtual DWORD GetSourceBufferRemainSize() = 0;

	virtual BOOL WINAPI ResetSourceBuffer() = 0;

	//Инициализация режима - отображение потока из файла
	virtual BOOL InitializationFileMode() = 0;
};

//Функция окна windows, которая необходима для корректной работы функции CreateWnd()
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
