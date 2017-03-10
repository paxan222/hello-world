namespace RVI.RtspRecorderWrap
{
	public enum ErrorCode
	{
		/// <summary>
		/// Неизвестно
		/// </summary>
		UnknownError = -1,
		/// <summary>
		/// Разрыв связи
		/// </summary>
		Disconnect,
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
		/// Callback получения данных не задан
		/// </summary>
		RecievedCallbackIsNull,
		/// <summary>
		/// Ошибка задания записи выходного файла через callback
		/// </summary>
		AllocCallbackError,
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