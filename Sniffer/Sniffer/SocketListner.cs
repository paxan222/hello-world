using System;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using Sniffer.Protocols;

namespace Sniffer
{
	/// <summary>
	/// Общий класс сниффера
	/// </summary>
	public class SocketListner
	{
		#region Переменные

		/// <summary>
		/// Сокет
		/// </summary>
		private Socket _socket;

		/// <summary>
		/// Массив с сообщением
		/// </summary>
		private static byte[] _data = new byte[4096];

		/// <summary>
		/// Ip адрес хоста
		/// </summary>
		private IPAddress _hostIpAddress;

		/// <summary>
		/// Сетевой адрес
		/// </summary>
		private EndPoint _endPoint;

		/// <summary>
		/// Входные данные, необходимые для операции задания низкоуровневых операционных режимов
		/// </summary>
		private readonly byte[] _optionInValue = new byte[4] { 1, 0, 0, 0 };

		/// <summary>
		/// Выходные данные, возвращенные операцией задания низкоуровневых операционных режимов
		/// </summary>
		private readonly byte[] _optionOutValue = new byte[4] { 1, 0, 0, 0 };

		/// <summary>
		/// Флаг проверки приемки пакетов
		/// </summary>
		private bool _continueCapturing;

		/// <summary>
		/// Исключение
		/// </summary>
		private Exception _socketListnerException;

		#region Ip данные

		private ProtocolType _version;
		private int _headerLength;
		private ushort _totalLength;
		private ushort _identifier;
		private int _ttl;
		private ProtocolType _protocol;
		private IPAddress _sourceIpAddress;
		private IPAddress _destinationIpAddress;
		private byte[] _dataIp;
		private ushort _dataLength;

		#endregion

		#region Tcp данные

		private ushort _sourcePort;
		private ushort _destinationPort;
		private uint _isn;
		private uint _an;
		private int _windowSize;
		private byte[] _dataTcp;

		#endregion

		private string _logsFolderPath;
		#endregion

		#region Конструктор

		/// <summary>
		/// Конструктор класса
		/// </summary>
		public SocketListner(string logsFolderPath)
		{
			_logsFolderPath = logsFolderPath;
			try
			{
				_socket = new Socket(AddressFamily.InterNetwork, SocketType.Raw, ProtocolType.IP);
				var getHostName = Dns.GetHostName();
				var getHostEntry = Dns.GetHostEntry(getHostName);
				var addressList = getHostEntry.AddressList;
				var hostIpAddress = addressList.Where(x => x.AddressFamily.Equals(AddressFamily.InterNetwork));
				_hostIpAddress = hostIpAddress.FirstOrDefault();
				if (_hostIpAddress != null) _endPoint = new IPEndPoint(_hostIpAddress, 0);
			}
			catch (Exception exception)
			{
				_socketListnerException = exception;
				OnException();
			}
		}

		#endregion

		#region Приватные методы

		//public static ManualResetEvent AllDone = new ManualResetEvent(false);
		public int MessageNumber = 0;
		private StreamWriter _swWriter;
		/// <summary>
		/// Прием сообщений
		/// </summary>
		/// <param name="ar"></param>
		private void OnReceive(IAsyncResult ar)
		{
			if (!_continueCapturing) return;
			try
			{
				//AllDone.Reset();
				var nReceived = _socket.EndReceive(ar);
				IpParser(_data, nReceived);
				_swWriter.WriteLine("{0}\t{1}:{2}\t{3}:{4}\t{5}\t{6}\t{7}", DateTime.Now.ToString("hh:mm:ss.fffff"), _sourceIpAddress, _sourcePort, _destinationIpAddress, _destinationPort, _dataLength, _isn, _an );
				MessageNumber++;
				OnNewPackage();
				_data = new byte[4096];
				_socket.BeginReceive(_data, 0, _data.Length, SocketFlags.None, OnReceive, null);
				//AllDone.WaitOne();
			}
			catch (Exception exception)
			{
				_socketListnerException = exception;
				OnException();
			}
		}

		/// <summary>
		/// Парсер IP пакета
		/// </summary>
		/// <param name="bytesBuffer">сообщение</param>
		/// <param name="nReceive">длина принятого сообщения</param>
		private void IpParser(byte[] bytesBuffer, int nReceive)
		{
			var ip = new Ip(bytesBuffer, nReceive);

			ip.OnException += IpException;
			_socketListnerException = ip.IpException;

			_version = ip.IpVersion;
			_headerLength = ip.HeaderLength;
			_totalLength = ip.TotalLength;
			_identifier = ip.Identifier;
			_ttl = ip.TTL;
			_protocol = ip.DataProtocol;
			_sourceIpAddress = ip.SourceIpAddress;
			_destinationIpAddress = ip.DestinationIpAddress;
			_dataIp = ip.Data;
			_dataLength = ip.DataLength;

			switch (_protocol)
			{
				case ProtocolType.Tcp:
					TcpParser();
					break;
				case ProtocolType.Udp:
					if (ip.DataLength > 8)
					{
						UdpParser();
					}
					break;
			}
		}

		/// <summary>
		/// Парсер TCP пакета
		/// </summary>
		private void TcpParser()
		{
			var bytesBuffer = _dataIp;
			var nReceive = _dataLength;
			var tcp = new Tcp(bytesBuffer, nReceive);

			tcp.OnException += TcpException;
			_socketListnerException = tcp.TcpException;

			_sourcePort = tcp.SourcePort;
			_destinationPort = tcp.DestinationPort;
			_isn = tcp.InitialSequenceNumber;
			_an = tcp.AcknowladgementNumber;
			_windowSize = tcp.WindowSize;
			_dataTcp = tcp.Data;

		}

		/// <summary>
		/// Парсер UDP пакета
		/// </summary>
		private void UdpParser()
		{
			var bytesBuffer = _dataIp;
			var nReceive = (int)_dataLength;
			var udp = new UDP(bytesBuffer, nReceive);

			udp.OnException += UdpException;
			_socketListnerException = udp.UdpException;

			_sourcePort = udp.SourcePort;
			_destinationPort = udp.DestinationPort;
		}

		/// <summary>
		/// Обработчик исключения в Ip
		/// </summary>
		private void IpException()
		{
			OnException();
		}

		/// <summary>
		/// Обработчик исключения в Tcp
		/// </summary>
		private void TcpException()
		{
			OnException();
		}

		/// <summary>
		/// Обработчик исключения в Udp
		/// </summary>
		private void UdpException()
		{
			OnException();
		}

		#endregion

		#region События

		/// <summary>
		/// Делегат
		/// </summary>
		public delegate void SocketListnerEventHandler();
		/// <summary>
		/// Событие на получение нового пакета
		/// </summary>
		public event SocketListnerEventHandler OnNewPackage;

		/// <summary>
		/// Событие при исключении
		/// </summary>
		public event SocketListnerEventHandler OnException;

		#endregion

		#region Методы

		/// <summary>
		/// Старт сокета
		/// </summary>
		public void Start()
		{
			var filepath = Path.Combine(_logsFolderPath, string.Format("FullTraffic_{0}.txt", DateTime.Now.ToString("HH-mm-ss")));
			_swWriter = new StreamWriter(filepath, false);
			try
			{
				if (!_continueCapturing)
				{

					_continueCapturing = true;
					_socket.Bind(_endPoint);
					_socket.IOControl(IOControlCode.ReceiveAll, _optionInValue, _optionOutValue);
					_socket.BeginReceive(_data, 0, _data.Length, SocketFlags.None, OnReceive, null);

				}
				else
				{
					_continueCapturing = false;
					_socket.Shutdown(SocketShutdown.Both);

					if (_socket != null)
						_socket.Close();
				}
			}
			catch (Exception exception)
			{
				_socketListnerException = exception;
				OnException();
			}
		}

		/// <summary>
		/// Стоп сокета
		/// </summary>
		public void Stop()
		{
			if (_continueCapturing)
			{
				_continueCapturing = false;
				_socket.Shutdown(SocketShutdown.Both);
				if (_socket != null)
					_socket.Close();
			}
			_swWriter.Close();
		}

		/// <summary>
		/// Исключение
		/// </summary>
		public Exception SocketListnerException
		{
			get
			{
				return _socketListnerException;
			}
		}

		#region Ip данные

		public ProtocolType Version
		{
			get
			{
				return _version;
			}
		}
		public int HeaderLength
		{
			get
			{
				return _headerLength;
			}
		}
		public ushort TotalLength
		{
			get
			{
				return _totalLength;
			}
		}
		public ushort Identifier
		{
			get
			{
				return _identifier;
			}
		}
		public int Ttl
		{
			get
			{
				return _ttl;
			}
		}
		public ProtocolType Protocol
		{
			get
			{
				return _protocol;
			}
		}
		public IPAddress SourceIpAddress
		{
			get
			{
				return _sourceIpAddress;
			}
		}
		public IPAddress DestinationIpAddress
		{
			get
			{
				return _destinationIpAddress;
			}
		}
		public byte[] DataIp
		{
			get
			{
				return _dataIp;
			}
		}
		public ushort DataLength
		{
			get
			{
				return _dataLength;
			}
		}

		#endregion

		#region Tcp данные

		public ushort SourcePort
		{
			get
			{
				return _sourcePort;
			}
		}
		public ushort DestinationPort
		{
			get
			{
				return _destinationPort;
			}
		}
		public uint Isn
		{
			get
			{
				return _isn;
			}
		}
		public uint An
		{
			get
			{
				return _an;
			}
		}
		public int WindowSize
		{
			get
			{
				return _windowSize;
			}
		}
		public byte[] DataTcp
		{
			get
			{
				return _dataTcp;
			}
		}

		#endregion

		#endregion
	}
}
