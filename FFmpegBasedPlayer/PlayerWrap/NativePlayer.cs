using System;
using System.Runtime.InteropServices;

namespace RVI.NativePlayerWrap
{
    public static class NativePlayer
    {
        /// <summary>
        /// Указатель на функцию обратного вызова (формат пикселенй RGB 24)
        /// </summary>
        /// <param name="dataIntPtr">Данные изображения</param>
        /// <param name="dataSize">Размер в байтах</param>
        /// <param name="stide">гор. размер изображения в байтах</param>
        /// <param name="width">гор. размер изображения </param>
        /// <param name="height">верт. размер изображения в бйтах</param>
        public delegate void DecodeCallback(IntPtr dataIntPtr, UInt32 dataSize, UInt32 stide, UInt32 width, UInt32 height, UInt32 msTimeStamp);

        /// <summary>
        /// Указатель на функцию обратного вызова окончания файла
        /// </summary>
        public delegate void MediaEndedCallback();

        /// <summary>
        /// Указатель на функцию обратного вызова завершения инииализации
        /// </summary>
        public delegate void EndInitCallback(StreamInfo streamInfo);

	    public delegate void ErrorCallback(string errorInfo);
		
        private const String NATIVE_PLAYER_DLL_NAME = @"\Dll\Player.dll";

        //Получить указатель на плеер, null в случае ошибки
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern IntPtr GetPlayer(String pchFileName, UInt16 wVendorType, DecodeCallback fDecodeCallback, MediaEndedCallback fMediaEndedCallback, IntPtr windowHandle);

        //Получить указатель на плеер, null в случае ошибки
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern IntPtr GetLivePlayer(UInt16 wVendorType, DecodeCallback fDecodeCallback, EndInitCallback fEndInitCallback, String rtspPath, uint mode, IntPtr windowHandle);

        //Получить указатель на плеер, null в случае ошибки
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern IntPtr GetRtspPlayer(string rtspUri, DecodeCallback fDecodeCallback, MediaEndedCallback fMediaEndedCallback, ErrorCallback fErrorCallback, int timeout, IntPtr windowHandle);

        //Получить информацию о потоке
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool GetStreamInfo(IntPtr pPlayer, [In, Out] StreamInfo streamInfo);

        //Освободить ресурсы, занимаемые плеером
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern void ReleasePlayer(IntPtr pPlayer);

        //Начать воспроизведение файла
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool Play(IntPtr pPlayer);

        //Постановка воспроизведения на паузу
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool Pause(IntPtr pPlayer);

        //Остановка воспроизведения
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool Stop(IntPtr pPlayer);

        //Включение/выключение звука
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool SwitchSound(IntPtr pPlayer, bool bIsSoundSwitchedOn);

        //Получить уровень звука
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool GetVolume(IntPtr pPlayer, out Byte pbVolumeLevel);

        //Задать уровень звука
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool SetVolume(IntPtr pPlayer, Byte bVolumeLevel);

        //Задать позицию воспроизведения в миллисекундах относительно начала записи
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool SetPlaybackPosition(IntPtr pPlayer, UInt32 dwMilliseconds);

        //Покадровое воспроизведение: перейти на следующий кадр
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool MoveToNextFrame(IntPtr pPlayer);

        //Еще не реализовано! Покадровое воспроизведение: перейти на предыдущий кадр
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool MoveToPreviousFrame(IntPtr pPlayer);

        //Увеличить скорость воспроизведения в 2 раза
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool IncreasePlaybackSpeed(IntPtr pPlayer);

        //Замедлить скорость воспроизведения в 2 раза
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool DecreasePlaybackSpeed(IntPtr pPlayer);

        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool InputData(IntPtr pPlayer, byte[] pBuf, UInt32 dwSize);

        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool Refresh(IntPtr pPlayer); // костыль для плеера архива Hik (для корректной работы паузы )

        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool SaveSnapshoot(IntPtr pPlayer, [MarshalAs(UnmanagedType.LPStr)]String directoryPath, [MarshalAs(UnmanagedType.LPStr)]String fileName); // 

        /// <summary>
        /// Возвращает текущую позицию воспроизведения в файле
        /// </summary>
        /// <param name="pPlayer"></param>
        /// <returns></returns>
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern UInt32 GetPlaybackPosition(IntPtr pPlayer);

        /// <summary>
        /// Задает режим вывода изображения (originalAspectRatio = true - изображение выводится с оригинальным соотношением сторон)
        /// </summary>
        /// <param name="pPlayer"></param>
        /// <param name="originalAspectRatio"></param>
        /// <returns></returns>
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool SetStretchMode(IntPtr pPlayer, bool originalAspectRatio);

        /// <summary>
        /// Поиск смещения в файле, которое соответствует воспроизводимому времени
        /// </summary>
        /// <param name="pPlayer">экземпляр плеера</param>
        /// <param name="milliseconds">смещение в миллисекундах от начала файла</param>
        /// <param name="bytesOffset">смещение в байтах от начала файла</param>
        /// <returns>true при успехе, false - при ошибке</returns>
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool SeekPositionByTime(IntPtr pPlayer, UInt32 milliseconds, ref UInt32 bytesOffset);

        /// <summary>
        /// Возвращает размер буфера сырых данных
        /// </summary>
        /// <param name="pPlayer"></param>
        /// <returns></returns>
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern UInt32 GetSourceBufferMaxSize(IntPtr pPlayer);

        /// <summary>
        /// Возвращает объем свободного пространства в буфере сырых данных
        /// </summary>
        /// <param name="pPlayer"></param>
        /// <returns></returns>
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern UInt32 GetSourceBufferRemainSize(IntPtr pPlayer);

        /// <summary>
        /// Очищает буфер сырых данных
        /// </summary>
        /// <param name="pPlayer"></param>
        /// <returns></returns>
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool ResetSourceBuffer(IntPtr pPlayer);

        /// <summary>
        /// Инициализация параметров для работы с файлом.
        /// Нужен для санела, т.к. устанавливает режим чтения файла
        /// </summary>
        /// <returns></returns>
        [DllImport(NATIVE_PLAYER_DLL_NAME)]
        public static extern bool InitializationFileMode(IntPtr pPlayer);
    }
}
