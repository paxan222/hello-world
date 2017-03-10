using System;
using System.Runtime.InteropServices;

namespace RVI.RtspRecorderWrap
{
	public static class RtspRecorder
	{
		/// <summary>
		/// Указатель на функцию обратного вызова разрыва соединения
		/// Возвращает код ошибки
		/// </summary>
		public delegate void ErrorCallback(ErrorCode errorCode);
		
		/// <summary>
		/// Функция для получения данных rtsp потока
		/// </summary>
		/// <param name="buf">Буфер с данными(Byte* )</param>
		/// <param name="bufSize">размер буфера</param>
		/// <param name="isHeaderData">
		/// Флаг присутствия заголовка в буфере (Устанавливается после вызова WriteHeader). 
		/// Заголовок должен быть записан в начале файла.
		/// </param>
		/// 
		public delegate void RecieveDataCallback(IntPtr buf, int bufSize, bool isHeaderData);

		/// <summary>
		/// Функция для получения заголовка rtsp потока
		/// </summary>
		/// <param name="buf">Буфер с заголовком(Byte* )</param>
		/// <param name="bufSize">размер буфера</param>
		public delegate void RecieveHeaderCallback(IntPtr buf, int bufSize);

		/// <summary>
		/// Путь к библиотеке с модулем записи
		/// </summary>
		private const string RTSP_RECORDER_DLL_NAME = @"\Dll\RVI.RtspRecorder.dll";

		/// <summary>
		/// Старт получения данных по rtsp
		/// </summary>
		/// <param name="rtspPath">ртсп ссылка</param>
		/// <param name="outputFilename">выходной файл</param>
		/// <param name="timeout">таймаут подключения в мс, если таймаут меньше или равен 0, то работаем без него</param>
		/// <param name="fErrorCallback">вызывается при ошибке</param>
		/// <returns>Идентификатор сессии или IntPtr.Zero если ошибка</returns>
		[DllImport(RTSP_RECORDER_DLL_NAME)]
		public static extern IntPtr StartFileRecord(string rtspPath, string outputFilename, int timeout,
			ErrorCallback fErrorCallback);

		/// <summary>
		/// Старт получения данных по rtsp
		/// </summary>
		/// <param name="rtspPath">ртсп ссылка</param>
		/// <param name="timeout">таймаут подключения в мс, если таймаут меньше или равен 0, то работаем без него</param>
		/// <param name="fReceiveDataCallback">Вызывается при получении данных rtsp потока</param>
		/// <param name="fRecieveHeaderCallback">Вызывается при получении заголовка</param>
		/// <param name="fErrorCallback">вызывается при ошибке</param>
		/// <returns></returns>
		[DllImport(RTSP_RECORDER_DLL_NAME)]
		public static extern bool StartCallbackRecord(string rtspPath, int timeout, RecieveDataCallback fReceiveDataCallback, RecieveHeaderCallback fRecieveHeaderCallback,ErrorCallback fErrorCallback);

		/// <summary>
        /// Завершить получение данных rtsp потока
        /// Освобождает ресурсы занимаемые сессией.
		/// </summary>
		/// <param name="rtspPath">Идентификатор сессии от GetCallbackRecorder или GetFileRecorder</param>
		/// <returns></returns>
		[DllImport(RTSP_RECORDER_DLL_NAME)]
		public static extern void Stop(string rtspPath);

		/// <summary>
		/// Добавляет в поток вывода заголовок mkv файла. После вызова метода в RecieveDataCallback, переменная
		/// isHeaderData принимает значение true. Эти данные должны быть записаны в начало файла.
		/// Заголовок будет добавлен в выходной поток, только перед следующим опорным кадром.
		/// </summary>
		/// <param name="rtspPath">Идентификатор сессии от GetCallbackRecorder или GetFileRecorder</param>
		/// <returns></returns>
		[DllImport(RTSP_RECORDER_DLL_NAME)]
		public static extern bool WriteHeader(string rtspPath);

		/// <summary>
		/// Создает в поток вывода заголовок mkv файла.
		/// </summary>
		/// <param name="rtspPath">Идентификатор сессии от GetCallbackRecorder или GetFileRecorder</param>
		/// <returns>Возвращает буфер с заголовком в RecieveHeaderCallback</returns>
		[DllImport(RTSP_RECORDER_DLL_NAME)]
		public static extern bool GetHeader(string rtspPath);
	}
}
