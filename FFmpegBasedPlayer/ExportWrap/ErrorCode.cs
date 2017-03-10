namespace RVI.RtspExportWrap
{
	/// <summary>
	/// Код ошибки
	/// </summary>
	public enum ErrorCode
	{
		/// <summary>
		/// Неизвестно
		/// </summary>
		UnknownError = -1,
		/// <summary>
		/// Ошибка при открытии входного файла
		/// </summary>
		OpenInputFileError,
		/// <summary>
		/// Ошибка при открытии выходного файла
		/// </summary>
		OpenOutputFileError,
		/// <summary>
		/// Пустое имя файла
		/// </summary>
		EmptyFilename,
		/// <summary>
		/// Параметры времени обрезки находятся вне диапазона
		/// </summary>
		ArgumentOutOfRange,
		/// <summary>
		/// Формат выходного файла не найден в списке форматов
		/// </summary>
		OutputFormatNotMatchFormat,
		/// <summary>
		/// Видео поток не существует
		/// </summary>
		VideoStreamNotExist
	}
}