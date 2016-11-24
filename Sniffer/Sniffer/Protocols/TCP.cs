using System;
using System.IO;
using System.Net;

namespace Sniffer.Protocols
{
	/// <summary>
	/// Класс, описывающий структуру TCP пакета
	/// </summary>
	class Tcp
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
		/// Порядковый номер
		/// </summary>
		private uint _sequenceNumber;

		/// <summary>
		/// Номер подтверждения
		/// </summary>
		private uint _acknowladgementNumber;

		/// <summary>
		/// Длина заголовка(смещение данных)
		/// </summary>
		private byte _dataOffset;

		/// <summary>
		/// Зарезервировано
		/// </summary>
		private byte _reserved;

		#region Флаги
		
		/// <summary>
		/// Защита ECN-маскировки 
		/// </summary>
		private byte _ns;

		/// <summary>
		/// Окно перегрузки уменьшено
		/// </summary>
		private byte _cwr;

		/// <summary>
		/// Эхо ECN
		/// </summary>
		private byte _ece;

		/// <summary>
		/// Указатель важности
		/// </summary>
		private byte _urg;

		/// <summary>
		/// Номер подтверждения
		/// </summary>
		private byte _ack;

		/// <summary>
		/// Инструктирует получателя протолкнуть данные, накопившиеся в приёмном буфере
		/// 
		/// </summary>
		private byte _psh;

		/// <summary>
		/// Сброс соединения, сброс буфера
		/// </summary>
		private byte _rst;

		/// <summary>
		/// Синхронизация номеров последовательности
		/// </summary>
		private byte _syn;

		/// <summary>
		/// Флаг завершения соединения
		/// </summary>
		private byte _fin;

		#endregion

		/// <summary>
		/// Размер окна
		/// </summary>
		private ushort _windowSize;

		/// <summary>
		/// Контрольная сумма
		/// </summary>
		private ushort _checkSum;

		/// <summary>
		/// Указатель важности
		/// </summary>
		private ushort _urgentPointer;

		/// <summary>
		/// Опции
		/// </summary>
		private uint _options;

		/// <summary>
		/// Данные
		/// </summary>
		private readonly byte[] _data = new byte[4096];

		/// <summary>
		/// Исключение
		/// </summary>
		private Exception _tcpException;

		#endregion
		
		#region Конструктор

		/// <summary>
		/// Конструктор класса
		/// </summary>
		/// <param name="bytesBuffer">сообщение</param>
		/// <param name="nReceive">длина сообщения</param>
		public Tcp(byte[] bytesBuffer, int nReceive)
		{
			try
			{
				var memoryStream = new MemoryStream(bytesBuffer, 0, nReceive);
				var binaryReader = new BinaryReader(memoryStream);

				_sourcePort = (ushort)IPAddress.HostToNetworkOrder(binaryReader.ReadInt16());
				_destinationPort = (ushort)IPAddress.HostToNetworkOrder(binaryReader.ReadInt16());
				_sequenceNumber = (uint)IPAddress.HostToNetworkOrder(binaryReader.ReadInt32());
				_acknowladgementNumber = (uint)IPAddress.HostToNetworkOrder(binaryReader.ReadInt32());

				var tmpDataOffset = binaryReader.ReadByte();

				_dataOffset = tmpDataOffset;
				_dataOffset >>= 4;
				_dataOffset *= 4;

				_reserved = tmpDataOffset;
				_reserved <<= 4;
				_reserved >>= 5;

				_ns = tmpDataOffset;
				_ns <<= 7;
				_ns >>= 7;

				var tmpFlags = binaryReader.ReadByte();
				_cwr = tmpFlags;
				_cwr >>= 7;
			
				_ece = tmpFlags;
				_ece <<= 1;
				_ece >>= 7;

				_urg = tmpFlags;
				_urg <<= 2;
				_urg >>= 7;

				_ack = tmpFlags;
				_ack <<= 3;
				_ack >>= 7;

				_psh = tmpFlags;
				_psh <<= 4;
				_psh >>= 7;

				_rst = tmpFlags;
				_rst <<= 5;
				_rst >>= 7;

				_syn = tmpFlags;
				_syn <<= 6;
				_syn >>= 7;

				_fin = tmpFlags;
				_fin <<= 7;
				_fin >>= 7;

				_windowSize = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());
				_checkSum = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());
				_urgentPointer = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());

				//if (_dataOffset > 20)
				//{
				//	var position = (int)memoryStream.Position;
				//	var tmpOptions = binaryReader.ReadBytes(_dataOffset - position);
				//}
				_data = new byte[4096];
				Array.Copy(bytesBuffer, _dataOffset, _data, 0, nReceive - _dataOffset);
				_calculatedSum = CalculateChecksum(bytesBuffer, nReceive);
			}
			catch (Exception exception)
			{
				_tcpException = exception;
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

		#region Приватные методы
		
		/// <summary>
		/// Посчитанная сумма
		/// </summary>
		private string _calculatedSum;

		/// <summary>
		/// Расчет контрольной суммы
		/// </summary>
		/// <param name="bytesBuffer"></param>
		/// <param name="nReceive"></param>
		/// <returns></returns>
		private string CalculateChecksum(byte[] bytesBuffer, int nReceive)
		{
			var sum = 0;
			for (var i = 0; i < nReceive; i = i + 2)
			{
				var tmpString = bytesBuffer[i].ToString("X2") + bytesBuffer[i + 1].ToString("X2");
				sum += Convert.ToInt32(tmpString, 16);
			}
			return sum.ToString("X2");
		}

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
		/// Порядковый номер
		/// </summary>
		public uint InitialSequenceNumber
		{
			get
			{
				if (_syn == 1)
				{
					return _sequenceNumber + 1;
				}
				return _sequenceNumber;
			}
		}

		/// <summary>
		/// Номер подтверждения
		/// </summary>
		public uint AcknowladgementNumber
		{
			get
			{
				if (_ack == 1)
				{
					return _acknowladgementNumber;
				}
				return 0;
			}
		}

		/// <summary>
		/// Длина заголовка(смещение)
		/// </summary>
		public int DataOffset
		{
			get
			{
				return _dataOffset;
			}
		}

		/// <summary>
		/// Зарезервировано
		/// </summary>
		public byte Reserved
		{
			get
			{
				return _reserved;
			}
		}

		/// <summary>
		/// Защита ECN-маскировки
		/// </summary>
		public byte NS
		{
			get
			{
				return _ns;
			}
		}

		/// <summary>
		/// Окно перегрузки уменьшено
		/// </summary>
		public byte CWR
		{
			get
			{
				return _cwr;
			}
		}

		/// <summary>
		/// Эхо ECN
		/// </summary>
		public byte ECE
		{
			get
			{
				return _ece;
			}
		}

		/// <summary>
		/// Указатель важности
		/// </summary>
		public byte URG
		{
			get
			{
				return _urg;
			}
		}

		/// <summary>
		/// Номер подтверждения
		/// </summary>
		public byte ACK
		{
			get
			{
				return _ack;
			}
		}

		/// <summary>
		/// Инструктирует получателя протолкнуть данные, накопившиеся в приемном бункере
		/// </summary>
		public byte PSH
		{
			get
			{
				return _psh;
			}
		}

		/// <summary>
		/// Оборвать соединения, сбросить буфер
		/// </summary>
		public byte RST
		{
			get
			{
				return _rst;
			}
		}

		/// <summary>
		/// Синхронизация номеров последовательности
		/// </summary>
		public byte SYN
		{
			get
			{
				return _syn;
			}
		}

		/// <summary>
		/// Флаг завершения соединения
		/// </summary>
		public byte FIN
		{
			get
			{
				return _fin;
			}
		}

		/// <summary>
		/// Размер окна
		/// </summary>
		public int WindowSize
		{
			get
			{
				return _windowSize;
			}
		}

		/// <summary>
		/// Контрольная сумма
		/// </summary>
		public int Checksum
		{
			get
			{
				return _checkSum;
			}
		}

		/// <summary>
		/// Указатель важности
		/// </summary>
		public int UrgentPointer
		{
			get
			{
				if (_urg == 1)
				{
					return _urgentPointer;
				}
				return 0;
			}
		}

		/// <summary>
		/// Опции
		/// </summary>
		public uint Options
		{
			get
			{
				return _options;
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
		/// Посчитанная сумма
		/// </summary>
		public string CalculatedSum
		{
			get
			{
				return _calculatedSum;
			}
		}

		/// <summary>
		/// Исключение
		/// </summary>
		public Exception TcpException
		{
			get
			{
				return _tcpException;
			}
		}

		#endregion
	}
}
