using System;
using System.IO;
using System.Net;

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

		/// <summary>
		/// Исключение
		/// </summary>
		private Exception _udpException;

		#endregion
		
		#region Конструктор

		/// <summary>
		/// Конструктор класса
		/// </summary>
		/// <param name="bytesBuffer">сообщение</param>
		/// <param name="nReceive">длина сообщения</param>
		public UDP(byte[] bytesBuffer, int nReceive)
		{
			try
			{
				var memoryStream = new MemoryStream(bytesBuffer, 0, nReceive);
				var binaryReader = new BinaryReader(memoryStream);

				_sourcePort = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());
				_destinationPort = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());
				_length = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());
				_checksum = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadUInt16());

				_data = new byte[4096];

				Array.Copy(bytesBuffer, 8, _data, 0, nReceive - 8);
			}
			catch (Exception exception)
			{
				_udpException = exception;
				OnException();
			}
		}

		#endregion

		#region События

		/// <summary>
		/// Событие при исключении
		/// </summary>
		public event SocketListner.SocketListnerEventHandler OnException;

		#endregion

		#region Методы

		/// <summary>
		/// Порт источника
		/// </summary>
		public ushort SourcePort
		{
			get
			{
				return _sourcePort;
			}
		}

		/// <summary>
		/// Порт назначения
		/// </summary>
		public ushort DestinationPort
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

		/// <summary>
		/// Исключение
		/// </summary>
		public Exception UdpException
		{
			get
			{
				return _udpException;
			}
		}

		#endregion

	}
}
