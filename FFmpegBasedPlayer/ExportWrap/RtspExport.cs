using System;
using System.Dynamic;
using System.IO;
using System.Runtime.InteropServices;

namespace RVI.RtspExportWrap
{
	public class RtspExport
	{
		/// <summary>
		/// Сигнатура функции обратного вызова прогресса
		/// </summary>
		/// <param name="duration">общая длительность результирующего файла в мс</param>
		/// <param name="currentDuration">текущая длительность результирующего файла в мс</param>
		public delegate void ProgressCallback(int duration, int currentDuration);

		/// <summary>
		/// Сигнатура функции обратного вызова окончания операции
		/// </summary>
		public delegate void OperationCompleteCallback();

		/// <summary>
		/// Сигнатура функции обратного вызова ошибки
		/// <param name="errorCode">код ошибки </param>
		/// <see cref="ErrorCode"/>
		/// </summary>
		public delegate void ErrorCallback(ErrorCode errorCode);

		/// <summary>
		/// Путь к библиотеке с модулем записи
		/// </summary>
		private const string RTSP_EXPORT_DLL_NAME = @"\Dll\RVI.RtspExport.dll";

		/// <summary>
		/// Операция обрезки видео
		/// </summary>
		/// <param name="inputFilename">имя файла для обрезки</param>
		/// <param name="outputFilename">имя выходного файла</param>
		/// <param name="startCutTime">время начала обрезки</param>
		/// <param name="endCutTime">время окончания обрезки</param>
		/// <param name="fProgressCallback">вызывается для оповещения об изменении прогресса операции</param>
		/// <param name="fEofCallback">вызывается при окончании операции</param>
		/// <param name="fErrorCallback">вызывается при возникновении ошибки</param>
		/// <returns>Идентификатор операции</returns>
		[DllImport(RTSP_EXPORT_DLL_NAME)]
		public static extern IntPtr Cut(string inputFilename, string outputFilename, int startCutTime, int endCutTime,
			ProgressCallback fProgressCallback, OperationCompleteCallback fEofCallback, ErrorCallback fErrorCallback);

		/// <summary>
		/// Операция склейки видео
		/// </summary>
		/// <param name="firstInputFilename">путь первого файла</param>
		/// <param name="secondInputFilename">путь второго файла</param>
		/// <param name="outputFilename">путь выходного файла</param>
		/// <param name="fProgressCallback">вызывается для оповещения об изменении прогресса операции</param>
		/// <param name="fEofCallback">вызывается при окончании операции</param>
		/// <param name="fErrorCallback">вызывается при возникновении ошибки</param>
		/// <returns>Идентификатор операции</returns>
		[DllImport(RTSP_EXPORT_DLL_NAME)]
		public static extern IntPtr Concatenate(string firstInputFilename, string secondInputFilename, string outputFilename,
			ProgressCallback fProgressCallback, OperationCompleteCallback fEofCallback, ErrorCallback fErrorCallback);

		/// <summary>
		/// Функция получения длины файла
		/// </summary>
		/// <param name="filename">имя файла</param>
		/// <returns>возвращает длину файла или 0, если ошибка</returns>
		[DllImport(RTSP_EXPORT_DLL_NAME)]
		public static extern int GetMediaFileDuration(string filename);

		/// <summary>
		/// Функция получения фрейма в ppm формате по времени
		/// </summary>
		/// <param name="filePath">путь до источника с файлом</param>
		/// <param name="buffer">буфер для фрейма</param>
		/// <param name="bufferSize">размер буфера для фрейма</param>
		/// <param name="width">ширина фрейма</param>
		/// <param name="height">высота фрейма</param>
		/// <param name="timestamp">время кадра</param>
		///  <returns>
		/// Возвращает фрейм в buffer или код ошибки:
		/// 0-успешно
		/// 1-время меньше нуля или больше длительности файла
		/// 2-невозможно открыть источник
		/// 3-нет видео потока
		/// 4-невозможно найти кодек
		/// 5-невозможно декодировать фрейм
		/// 6-невозможно найти encoderid
		/// 7-невозможно сохранить фрейм
		/// 8-невозможно заполнить буфер(размер буфера меньше размера массива с фреймом)
		/// </returns>
		[DllImport(RTSP_EXPORT_DLL_NAME)]
		private static extern int GetFrame(string filePath, IntPtr buffer, int bufferSize, int width, int height, Int64 timestamp);

		/// <summary>
		/// Отмена операции
		/// </summary>
		/// <param name="operationId">Идентификатор операции, полученный от Cut или Concatenate</param>
		/// <returns></returns>
		[DllImport(RTSP_EXPORT_DLL_NAME)]
		public static extern bool Cancel(IntPtr operationId);

		/// <summary>
		/// Записывает буфер с изображением в IStream
		/// </summary>
		/// <param name="path">путь к файлу</param>
		/// <param name="width">ширина изображения</param>
		/// <param name="height">высота изображения</param>
		/// <param name="timestamp">временная метка</param>
		/// <param name="stream"></param>
		public void GetFrame(string path, int width, int height, Int64 timestamp, Stream stream)
		{
			if (!stream.CanWrite)
			{
				throw new Exception("Ошибка получения потока");
			}
			if (string.IsNullOrEmpty(path))
			{
				return;
			}
			int defaultBufferSize = 1024;
			bool isFinding = false;
			int writtenSize = 0;
			while (!isFinding)
			{
				Byte[] buffer = new byte[defaultBufferSize];
				IntPtr pBuffer = Marshal.AllocHGlobal(buffer.Length);
				int res = RtspExport.GetFrame(path, pBuffer, buffer.Length, width, height, timestamp);
				Marshal.Copy(pBuffer, buffer,0, buffer.Length);
				Marshal.FreeHGlobal(pBuffer);

				if (res < 0)
				{
					defaultBufferSize = res*(-1);
					continue;
				}
				switch (res)
				{
					case 0:
						break;
					case 1:
						throw new ArgumentOutOfRangeException();
					case 2:
						throw new Exception(string.Format("Невозможно открыть источник: {0}", path));
					case 3:
						throw new Exception("Невозможно получить изображение");
					default:
						writtenSize = res; // ошибка Размер буффера меньше необходимого

						var bw = new BinaryWriter(stream);
						bw.Write(buffer);
						bw.Close();
						//stream.Write(buffer,0, writtenSize);
						isFinding = true;
						break;
						//throw new Exception(string.Format("Размер буффера меньше необходимого: {0}", task));
				}
			}


		}
	}
}
