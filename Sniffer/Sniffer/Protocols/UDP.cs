using System;
using System.IO;

namespace Sniffer.Protocols
{
	/// <summary>
	/// Класс, описывающий структуру UDP пакета
	/// </summary>
	class UDP
	{
		#region Переменные

		/// <summary>
		/// Порт источника
		/// </summary>
		private ushort _sourcePort;

		/// <summary>
		/// Порт назначения
		/// </summary>
		private ushort _destinationPort;

		/// <summary>
		/// Длина датаграммы 
		/// </summary>
		private ushort _length;

		/// <summary>
		/// Контрольная сумма
		/// </summary>
		private ushort _checksum;

		/// <summary>
		/// Данные
		/// </summary>
		private byte[] _data = new byte[4096];

		#endregion
		
		#region Конструктор

		/// <summary>
		/// Конструктор класса
		/// </summary>
		/// <param name="bytesBuffer">сообщение</param>
		/// <param name="nReceive">длина сообщения</param>
		public UDP(byte[] bytesBuffer, int nReceive)
		{
			var memoryStream = new MemoryStream(bytesBuffer, 0, nReceive);
			var binaryReader = new BinaryReader(memoryStream);

			_sourcePort = binaryReader.ReadUInt16();
			_destinationPort = binaryReader.ReadUInt16();
			_length = binaryReader.ReadUInt16();
			_checksum = binaryReader.ReadUInt16();

			_data = new byte[4096];

			Array.Copy(bytesBuffer, 8, _data, 0, nReceive - 8);
		}

		#endregion

		#region Методы

		/// <summary>
		/// Порт источника
		/// </summary>
		public int SourcePort
		{
			get
			{
				return _sourcePort;
			}
		}

		/// <summary>
		/// Порт назначения
		/// </summary>
		public int DestinationPort
		{
			get
			{
				return _destinationPort;
			}
		}

		/// <summary>
		/// Длина датаграммы 
		/// </summary>
		public int Length
		{
			get
			{
				return _length;
			}
		}

		/// <summary>
		/// Контрольная сумма
		/// </summary>
		public int checksum
		{
			get
			{
				return _checksum;
			}
		}

		/// <summary>
		/// Данные
		/// </summary>
		public byte[] Data
		{
			get
			{
				return _data;
			}
		}

		#endregion

	}
}
