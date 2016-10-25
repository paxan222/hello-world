using System;
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
	    private byte[] _data = new byte[4096];

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
	    private readonly byte[] optionInValue = new byte[4] {1, 0, 0, 0};

	    /// <summary>
	    /// Выходные данные, возвращенные операцией задания низкоуровневых операционных режимов
	    /// </summary>
	    private readonly byte[] optionOutValue = new byte[4] {1, 0, 0, 0};

	    /// <summary>
	    /// Ip адрес источника
	    /// </summary>
	    private IPAddress _sourceIpAddress;

	    /// <summary>
	    /// Порт источника
	    /// </summary>
	    private int _sourcePort;

	    /// <summary>
	    /// Ip адрес назначения
	    /// </summary>
	    private IPAddress _desinationIpAddress;

	    /// <summary>
	    /// Порт назначения
	    /// </summary>
	    private int _destinationPort;

		/// <summary>
		/// Протокол
		/// </summary>
		private ProtocolType _protocol;

		/// <summary>
		/// Логгер
		/// </summary>
		private Logger _logger;

		/// <summary>
		/// Флаг проверки приемки пакетов
		/// </summary>
		private bool _continueCapturing;

		/// <summary>
		/// Флаг приема первого сообщения
		/// </summary>
		private bool _firstMessage;
	    #endregion

	    #region Конструктор

		/// <summary>
		/// Конструктор класса
		/// </summary>
	    public SocketListner()
	    {
		    _socket = new Socket(AddressFamily.InterNetwork, SocketType.Raw, ProtocolType.IP);
		    var getHostName = Dns.GetHostName();
		    var getHostEntry = Dns.GetHostEntry(getHostName);
		    var addressList = getHostEntry.AddressList;
		    var hostIpAddress = addressList.Where(x => x.AddressFamily.Equals(AddressFamily.InterNetwork));
		    _hostIpAddress = hostIpAddress.FirstOrDefault();
		    _endPoint = new IPEndPoint(_hostIpAddress, 0);
			_logger = new Logger(@"log.txt",false);
	    }

	    #endregion

	    #region Приватные методы
		
		/// <summary>
		/// Прием сообщений
		/// </summary>
		/// <param name="ar"></param>
		private void OnReceive(IAsyncResult ar)
		{
			try
			{
				var nReceived = _socket.EndReceive(ar);
				IpParser(_data, nReceived);
				if (_continueCapturing)
				{
					_logger.Add("Time:{0}\t{1}\t{2}:{3}\t{4}:{5}", DateTime.Now.ToString("hh:mm:ss.ffff"), Protocol,
						SourceIpAddress, SourcePort, DestinationIpAddress, DestinationPort); 
					_firstMessage = true;
					OnNewPackage();
					_data = new byte[4096]; 
					_socket.BeginReceive(_data, 0, _data.Length, SocketFlags.None, OnReceive, null);
					
				}
			}
			catch (Exception exception)
			{
				_logger.Add("Time:{0}\t{1}",DateTime.Now.ToString("hh:mm:ss.ffff"),exception);
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
			_sourceIpAddress = ip.SourceIpAddress;
			_desinationIpAddress = ip.DestinationIpAddress;
			_protocol = ip.DataProtocol;
			switch (_protocol)
			{
				case ProtocolType.Tcp:
					TcpParser(ip);
					break;
				case ProtocolType.Udp:
					if (ip.DataLength > 8)
					{
						UdpParser(ip);
					}
					break;
			}
		}

		/// <summary>
		/// Парсер TCP пакета
		/// </summary>
		/// <param name="ip">ip пакет</param>
		private void TcpParser(Ip ip)
		{
			var bytesBuffer = ip.Data;
			var nReceive = ip.DataLength;
			var tcp = new Tcp(bytesBuffer, nReceive);

			_sourcePort = tcp.SourcePort;
			_destinationPort = tcp.DestinationPort;
		}

		/// <summary>
		/// Парсер UDP пакета
		/// </summary>
		/// <param name="ip">ip пакет</param>
		private void UdpParser(Ip ip)
		{
			var bytesBuffer = ip.Data;
			var nReceive = (int) ip.DataLength;
			var udp = new UDP(bytesBuffer, nReceive);
			_sourcePort = udp.SourcePort;
			_destinationPort = udp.DestinationPort;			
		}

	    #endregion

	    #region Методы

		/// <summary>
		/// Делегат
		/// </summary>
		public delegate void ReceivedPackage();
		/// <summary>
		/// Событие на получение нового пакета
		/// </summary>
		public event ReceivedPackage OnNewPackage;

		/// <summary>
		/// Флаг получения первого сообщения
		/// </summary>
		public bool Message
		{
			get
			{
				return _firstMessage;
			}
		}

		/// <summary>
		/// Старт сокета
		/// </summary>
		public void Start()
		{
			if (!_continueCapturing)
			{
				_continueCapturing = true;
				_socket.Bind(_endPoint);
				_socket.IOControl(IOControlCode.ReceiveAll, optionInValue, optionOutValue);
				_socket.BeginReceive(_data, 0, _data.Length, SocketFlags.None, OnReceive, null);
			}
			else
			{
				_continueCapturing = false;
				_socket.Close();
			}
		}

		/// <summary>
		/// Стоп сокета
		/// </summary>
		public void Stop()
		{
			if (_continueCapturing)
			{
				_socket.Close();
				_logger.Stop();
			}
		}

		/// <summary>
		/// Ip адрес источника
		/// </summary>
		public IPAddress SourceIpAddress
		{
			get
			{
				return _sourceIpAddress;
			}
		}

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
		/// Ip адрес назначения
		/// </summary>
		public IPAddress DestinationIpAddress
		{
			get
			{
				return _desinationIpAddress;
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
		/// Протокол
		/// </summary>
		public ProtocolType Protocol
		{
			get
			{
				return _protocol;
			}
		}
	    #endregion
	}
}
