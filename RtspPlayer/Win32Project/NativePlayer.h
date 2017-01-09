#pragma once
#include "stdafx.h"

#ifdef NATIVEPLAYER_EXPORTS
#define NATIVEPLAYER_API __declspec(dllexport) 
#else
#define NATIVEPLAYER_API __declspec(dllimport) 
#endif


enum VendorType : WORD
{
	VT_UNKN = 0,
	VT_DAHUA = 1,
	VT_HIK_VISION = 2,
	VT_SUNNEL = 3,
	VT_XM = 4,
	VT_RTSP = 1000
};

enum OpenStreamMode : DWORD
{
	OSM_REALTIME = 0,
	OSM_FILE = 1,
	OSM_NOT_USED = 2
};

enum class BitrateType : INT
{
	BT_UNKNOWN = 0,
	BT_CBR = 1,
	BT_VBR = 2
};

enum class CodecType : INT
{
	CT_UNKNOWN = 0,
	CT_MJPEG = 1,
	CT_H263 = 2,
	CT_H264 = 3,
	CT_H265 = 4
};


typedef struct
{
	DWORD dwFileLengthMilliseconds;
	DWORD dwWidth;
	DWORD dwHeight;
	DWORD dwBitrate;
	INT nFps;
	BitrateType nBitrateType;
	CodecType nCodecType;

}STREAM_INFO, *PSTREAM_INFO;

#ifdef __cplusplus
extern "C"
{
#endif

	//Тип функции для обатного вызова при поступлении обработанного кадра от декодера
	typedef void (CALLBACK *FDecodeCallback)(BYTE* pOutBuf, DWORD dwBufSize, DWORD dwStride, DWORD dwWidth, DWORD dwHeight, DWORD dwTimeStampMilliseconds);

	//Тип функии для обратного вызова при окончании инициализации
	typedef void (CALLBACK *FEndInitCallback)(PSTREAM_INFO vsi);

	//Тип функции для обратного вызова при достижении конца файла
	typedef void (CALLBACK *FFileEndCallback)();
	
	//Получить указатель на плеер файла
	NATIVEPLAYER_API PVOID WINAPI GetPlayer(PCHAR pchFileName, VendorType wVendorType, FDecodeCallback fDecodeCallback, FFileEndCallback fFileEndCallback, HWND hMainWindow = NULL);

	//Получить указатель на плеер потока
	NATIVEPLAYER_API PVOID WINAPI GetLivePlayer(VendorType wVendorType, FDecodeCallback fDecodeCallback, FEndInitCallback fEndInitCallback, PCHAR pchFileName, DWORD openStreamMode, HWND hMainWindow = NULL);

	//Освободить ресурсы, занимаемые плеером
	NATIVEPLAYER_API void WINAPI ReleasePlayer(PVOID pPlayer);
	
	// Задает режим вывода изображения (originalSapectRatio == true - сохраняется оригинальное соотношение сторон)
	NATIVEPLAYER_API BOOL WINAPI SetStretchMode(PVOID pPlayer, BOOL originalSapectRatio);

	//Получить информацию о потоке
	NATIVEPLAYER_API BOOL WINAPI GetStreamInfo(PVOID pPlayer, PSTREAM_INFO pStreamInfo);

	//Начать воспроизведение файла
	NATIVEPLAYER_API BOOL WINAPI Play(PVOID pPlayer);

	//Постановка воспроизведения на паузу
	NATIVEPLAYER_API BOOL WINAPI Pause(PVOID pPlayer);

	//Остановка воспроизведения
	NATIVEPLAYER_API BOOL WINAPI Stop(PVOID pPlayer);

	//Включение/выключение звука
	NATIVEPLAYER_API BOOL WINAPI SwitchSound(PVOID pPlayer, BOOL bIsSoundSwitchedOn);

	//Получить уровень звука
	NATIVEPLAYER_API BOOL WINAPI GetVolume(PVOID pPlayer, BYTE *pbVolumeLevel);

	//Задать уровень звука
	NATIVEPLAYER_API BOOL WINAPI SetVolume(PVOID pPlayer, BYTE bVolumeLevel);

	//Задать позицию воспроизведения в миллисекундах относительно начала записи
	NATIVEPLAYER_API BOOL WINAPI SetPlaybackPosition(PVOID pPlayer, DWORD dwMilliseconds);

	//Покадровое воспроизведение: перейти на следующий кадр
	NATIVEPLAYER_API BOOL WINAPI MoveToNextFrame(PVOID pPlayer);

	//Покадровое воспроизведение: перейти на предыдущий кадр
	NATIVEPLAYER_API BOOL WINAPI MoveToPreviousFrame(PVOID pPlayer);

	//Увеличить скорость воспроизведения в 2 раза
	NATIVEPLAYER_API BOOL WINAPI IncreasePlaybackSpeed(PVOID pPlayer);

	//Замедлить скорость воспроизведения в 2 раза
	NATIVEPLAYER_API BOOL WINAPI DecreasePlaybackSpeed(PVOID pPlayer);

	NATIVEPLAYER_API BOOL WINAPI InputData(PVOID pPlayer, BYTE* pBuf, DWORD dwSize);

	// пауза для Hik
	NATIVEPLAYER_API BOOL WINAPI Refresh(PVOID pPlayer);

	NATIVEPLAYER_API BOOL WINAPI SaveSnapshoot(PVOID pPlayer, CHAR* path, CHAR* name);

	NATIVEPLAYER_API DWORD WINAPI GetPlaybackPosition(PVOID pPlayer);

	//Поиск смещения в файле, которое соответствует воспроизводимому времени
	NATIVEPLAYER_API BOOL WINAPI SeekPositionByTime(PVOID pPlayer, DWORD dwMilliseconds, DWORD *pdwBytesOffset);

	// Возвращает размер буфера сырых данных
	NATIVEPLAYER_API DWORD WINAPI GetSourceBufferMaxSize(PVOID pPlayer);

	// Возвращает объем свободного пространства в буфере сырых данных
	NATIVEPLAYER_API DWORD WINAPI GetSourceBufferRemainSize(PVOID pPlayer);

	// Очищает буфер сырых данных
	NATIVEPLAYER_API BOOL WINAPI ResetSourceBuffer(PVOID pPlayer);

	//Инициализация режима - отображение потока из файла
	NATIVEPLAYER_API BOOL WINAPI InitializationFileMode(PVOID pPlayer);	

#ifdef __cplusplus
}
#endif