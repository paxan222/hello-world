using System;
using System.IO;
using System.Net;

namespace Sniffer.Protocols
{
	/// <summary>
	/// Класс, описывающий структуру IP пакета
	/// </summary>
	class IP
	{
		#region Переменные

		/// <summary>
		/// 4 бита - версия
		/// </summary>
		private byte _version;

		/// <summary>
		/// 4 бита - размер заголовка
		/// </summary>
		private byte _headerLength;

		#region TOS

		/// <summary>
		/// 8 бит - тип обслуживания
		/// </summary>
		private byte _tos;

		/// <summary>
		/// 3 бита - приоритет
		/// </summary>
		private byte _precedence;

		/// <summary>
		/// 1 бит - задержка(0-нормальная, 1-низкая задержка)
		/// </summary>
		private byte _delay;

		/// <summary>
		/// 1 бит - пропускная способоность(0-низкая, 1 - высокая пропускная способность)
		/// </summary>
		private byte _throughtput;

		/// <summary>
		/// 1 бит - надежность(0 - нормальная, 1 - высокая)
		/// </summary>
		private byte _reliability;

		/// <summary>
		/// 2 бита - явное сообщение о задержке
		/// </summary>
		private byte _ecn;

		#endregion
		
		/// <summary>
		/// 16 бит - размер пакета(полный)
		/// </summary>
		private ushort _totalLength;

		/// <summary>
		/// 16 бит - идентификатор
		/// </summary>
		private ushort _identifier;

		#region Фрагментирование

		/// <summary>
		/// 3 бита - флаг
		/// 13 бит - смещение фрагмента
		/// </summary>
		private ushort _flagsAndFragmentOffset;

		/// <summary>
		/// 3 бита - флаг
		/// </summary>
		public byte _flags;

		/// <summary>
		/// 13 бит - смещение фрагмента
		/// </summary>
		public ushort _fragmentOffset;

		#endregion
		
		/// <summary>
		/// 8 бит - время жизни
		/// </summary>
		private byte _ttl;

		/// <summary>
		/// 8 бит - протокол
		/// </summary>
		private byte _protocol;

		/// <summary>
		/// 16 бит - контрольная сумма заголовка
		/// </summary>
		private ushort _headerChecksum;

		/// <summary>
		/// 32 бита - дрес источника
		/// </summary>
		private uint _sourceIpAddress;

		/// <summary>
		/// 32 бита - адрес получателя
		/// </summary>
		private uint _destinationIpAddress;

		/// <summary>
		/// Опции
		/// </summary>
		private uint _options;

		/// <summary>
		/// Опции и данные
		/// </summary>
		private readonly byte[] _data;

		#endregion

		#region Конструктор

		/// <summary>
		/// Конструктор класса
		/// </summary>
		/// <param name="bytesBuffer">сообщение</param>
		/// <param name="nReceive">длина сообщения</param>
		public IP(byte[] bytesBuffer, int nReceive)
		{
			var memoryStream = new MemoryStream(bytesBuffer, 0, nReceive);
			var binaryReader = new BinaryReader(memoryStream);
			var tmpVersionAndHeaderLength = binaryReader.ReadByte();

			_version = tmpVersionAndHeaderLength;
			_version >>= 4;
			
			_headerLength = tmpVersionAndHeaderLength;
			_headerLength <<= 4; // сдвигаем влево 4 раза
			_headerLength >>= 4; // сдвигаем вправо 4 раза
			_headerLength *= 4; // получаем размер заголовка в байтах

			_tos = binaryReader.ReadByte();
			_precedence = _tos;
			_precedence >>= 5;

			_delay = _tos;
			_delay <<= 3;
			_delay >>= 7;

			_throughtput = _tos;
			_throughtput <<= 4;
			_throughtput >>= 7;

			_reliability = _tos;
			_reliability <<= 5;
			_reliability >>= 7;

			_ecn = _tos;
			_ecn <<= 6;
			_ecn >>= 6;
			_totalLength=(ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());

			_identifier = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());

			_flagsAndFragmentOffset = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());
			_fragmentOffset = _flagsAndFragmentOffset;
			_fragmentOffset <<= 3;
			_fragmentOffset >>= 3;

			_flags = (byte)(_flagsAndFragmentOffset>>13);

			_ttl = binaryReader.ReadByte();
			_protocol = binaryReader.ReadByte();
			_headerChecksum = (ushort)IPAddress.NetworkToHostOrder(binaryReader.ReadInt16());
			_sourceIpAddress = binaryReader.ReadUInt32();
			_destinationIpAddress = binaryReader.ReadUInt32();

			//if (_headerLength > 20)
			//{
			//	var position = (int)memoryStream.Position;
			//	var tmpOptions = binaryReader.ReadBytes(_headerLength - position);
			//}
			_data = new byte[4096];
			Array.Copy(bytesBuffer,_headerLength, _data, 0, _totalLength-_headerLength);
		}

		#endregion

		#region Перечисления

		public enum Version
		{
			IPv4,
			IPv6
		}

		public enum Delay
		{
			Normal = 0,
			Low = 1
		}

		public enum Throughput
		{
			Low = 0,
			High = 1
		}

		public enum Reliability
		{
			Normal = 0,
			High = 1
		}

		public enum ECN
		{
			Non_ECT,
			ECT0,
			ECT1,
			CE
		}

		public enum Protocol
		{
			TCP,
			UDP,
			Unknown
		}

		#endregion

		#region Методы

		/// <summary>
		/// Версия
		/// </summary>
		public Version IpVersion
		{
			get
			{
				switch (_version)
				{
					case 4:
						return Version.IPv4;
					case 6:
						return Version.IPv6;
					default:
						throw new ArgumentOutOfRangeException();
				}
			}
		}

		/// <summary>
		/// Размер заголовка
		/// </summary>
		public int HeaderLength
		{
			get
			{
				return _headerLength;
			}
		}

		/// <summary>
		/// Тип обслуживания
		/// </summary>
		public byte Tos
		{
			get
			{
				return _tos;
			}
		}

		/// <summary>
		/// Приоритет
		/// </summary>
		public byte Precedence
		{
			get
			{
				return _precedence;
			}
		}

		/// <summary>
		/// Задержка
		/// </summary>
		public Delay TOSDelay
		{
			get
			{
				switch (_delay)
				{
					case 0:
						return Delay.Normal;
					case 1:
						return Delay.Low;
					default:
						throw new ArgumentOutOfRangeException();
				}
			}
		}

		/// <summary>
		/// Пропускная способность
		/// </summary>
		public Throughput TOSThroughput
		{
			get
			{
				switch (_throughtput)
				{
					case 0:
						return Throughput.Low;
					case 1:
						return Throughput.High;
					default:
						throw new ArgumentOutOfRangeException();
				}
			}
		}

		/// <summary>
		/// Надежность
		/// </summary>
		public Reliability TOSReliability
		{
			get
			{
				switch (_reliability)
				{
					case 0:
						return Reliability.Normal;
					case 1:
						return Reliability.High;
					default:
						throw new ArgumentOutOfRangeException();
				}
			}
		}

		/// <summary>
		/// Явное Уведомление о Перегруженности
		/// </summary>
		public ECN TOSEcn
		{
			get
			{
				switch (_ecn)
				{
					case 0:
						return ECN.Non_ECT;
					case 1:
						return ECN.ECT1;
					case 2:
						return ECN.ECT0;
					case 3:
						return ECN.CE;
					default:
						throw new ArgumentOutOfRangeException();
				}
			}
		}
		
		/// <summary>
		/// Размер пакета
		/// </summary>
		public ushort TotalLength
		{
			get
			{
				return _totalLength;
			}
		}

		/// <summary>
		/// Идентификатор
		/// </summary>
		public ushort Identifier
		{
			get
			{
				return _identifier;
			}
		}

		/// <summary>
		/// Флаги
		/// </summary>
		public byte Flags
		{
			get
			{
				return _flags;
			}
		}

		/// <summary>
		/// Смещение фрагмента
		/// </summary>
		public int FragmentOffset
		{
			get
			{
				return _fragmentOffset;
			}
		}

		/// <summary>
		/// Время жизни
		/// </summary>
		public byte TTL
		{
			get
			{
				return _ttl;
			}
		}

		/// <summary>
		/// Протокол
		/// </summary>
		public Protocol DataProtocol
		{
			get
			{
				switch (_protocol)
				{
					case 6:
						return Protocol.TCP;
					case 17:
						return Protocol.UDP;
					default:
						return Protocol.Unknown;
				}
			}
		}

		/// <summary>
		/// Контрольная сумма заголовка
		/// </summary>
		public ushort HeaderChecksum
		{
			get
			{
				return _headerChecksum;
			}
		}

		/// <summary>
		/// Ip адрес источника
		/// </summary>
		public IPAddress SourceIpAddress
		{
			get
			{
				return new IPAddress(_sourceIpAddress);
			}
		}

		/// <summary>
		/// Ip адрес назначения
		/// </summary>
		public IPAddress DestinationIpAddress
		{
			get
			{
				return new IPAddress(_destinationIpAddress);
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
		/// Длина сообщения
		/// </summary>
		public ushort DataLength
		{
			get
			{
				return (ushort) (_totalLength - _headerLength);
			}
		}
		#endregion
	}
}
