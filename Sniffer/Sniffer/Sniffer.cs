using System;
using System.Net;
using System.Net.Sockets;
using Sniffer.Protocols;

namespace Sniffer
{
	/// <summary>
	/// Общий класс сниффера
	/// </summary>
    public class Sniffer
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
	    private static IPAddress _sourceIpAddress;

	    /// <summary>
	    /// Порт источника
	    /// </summary>
	    private static int _sourcePort;

	    /// <summary>
	    /// Ip адрес назначения
	    /// </summary>
	    private static IPAddress _desinationIpAddress;

	    /// <summary>
	    /// Порт назначения
	    /// </summary>
	    private static int _destinationPort;

	    #endregion

	    #region Конструктор

	    public Sniffer()
	    {
		    _socket = new Socket(AddressFamily.InterNetwork, SocketType.Raw, ProtocolType.IP);
		    _hostIpAddress = Dns.Resolve(Dns.GetHostName()).AddressList[0];
		    _endPoint = new IPEndPoint(_hostIpAddress, 0);
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
				_data = new byte[4096];
				_socket.BeginReceive(_data, 0, _data.Length, SocketFlags.None,
					OnReceive, null);
			}
			catch (Exception exception)
			{
				Console.WriteLine(exception);
			}
		}

		/// <summary>
		/// Парсер IP пакета
		/// </summary>
		/// <param name="bytesBuffer">сообщение</param>
		/// <param name="nReceive">длина принятого сообщения</param>
		private static void IpParser(byte[] bytesBuffer, int nReceive)
		{
			var ip = new IP(bytesBuffer, nReceive);
			_sourceIpAddress = ip.SourceIpAddress;
			_desinationIpAddress = ip.DestinationIpAddress;
			switch (ip.DataProtocol)
			{
				case IP.Protocol.TCP:
					TcpParser(ip);
					break;
				case IP.Protocol.UDP:
					UdpParser(ip);
					break;
			}
		}

		/// <summary>
		/// Парсер TCP пакета
		/// </summary>
		/// <param name="ip">ip пакет</param>
		private static void TcpParser(IP ip)
		{
			var bytesBuffer = ip.Data;
			var nReceive = ip.DataLength;
			var tcp = new TCP(bytesBuffer, nReceive);

			_sourcePort = tcp.SourcePort;
			_destinationPort = tcp.DestinationPort;
		}

		/// <summary>
		/// Парсер UDP пакета
		/// </summary>
		/// <param name="ip">ip пакет</param>
		private static void UdpParser(IP ip)
		{
			var bytesBuffer = ip.Data;
			var nReceive = ip.DataLength;
			var udp = new UDP(bytesBuffer, nReceive);

			_sourcePort = udp.SourcePort;
			_destinationPort = udp.DestinationPort;
		}

	    #endregion

	    #region Методы

		/// <summary>
		/// Старт сокета
		/// </summary>
		public void Start()
		{
			_socket.Bind(_endPoint);
			_socket.IOControl(IOControlCode.ReceiveAll, optionInValue, optionOutValue);
			_socket.BeginReceive(_data, 0, _data.Length, SocketFlags.None, OnReceive, null);
		}

		/// <summary>
		/// Стоп сокета
		/// </summary>
		public void Stop()
		{
			if (_socket != null)
				_socket.Close();
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

	    #endregion
	}
}
