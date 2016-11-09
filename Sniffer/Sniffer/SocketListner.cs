using System;
using System.Globalization;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Security.Policy;
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
	    private ushort _sourcePort;

	    /// <summary>
	    /// Ip адрес назначения
	    /// </summary>
	    private IPAddress _desinationIpAddress;

	    /// <summary>
	    /// Порт назначения
	    /// </summary>
	    private ushort _destinationPort;

		/// <summary>
		/// Протокол
		/// </summary>
		private ProtocolType _protocol;

		/// <summary>
		/// Логгер
		/// </summary>
		private Logger _logger;
		private Logger _loggerIn;
		private Logger _loggerOut;

		/// <summary>
		/// Флаг проверки приемки пакетов
		/// </summary>
		private bool _continueCapturing;

		/// <summary>
		/// Флаг приема первого сообщения
		/// </summary>
		private bool _firstMessage;

		/// <summary>
		/// Время жизни пакета
		/// </summary>
		private int _ttl;
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
			//_logger = new Logger(@"log.txt",true);
			//_loggerIn = new Logger(@"logIn.txt", true);
			//_loggerOut = new Logger(@"logOut.txt", true);
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
					//_logger.Add(Protocol, SourceIpAddress, SourcePort, DestinationIpAddress, DestinationPort, Ttl);
					//_logger.Add("SYN:{0}\tSEQ:{1}\tACK:{2}\tACKNUM:{3}\tID:{4}\tFIN:{5}\tLEN:{6}", _synTcp, _seqNum, _ackTcp, _ackNum, _id, _finFlag, _length);
					_firstMessage = true;
					OnNewPackage();
					_data = new byte[4096]; 
					_socket.BeginReceive(_data, 0, _data.Length, SocketFlags.None, OnReceive, null);
					
				}
			}
			catch (Exception exception)
			{
				//_logger.Add("Time:{0}\t{1}",DateTime.Now.ToString("hh:mm:ss.ffff"),exception);
			}
		}

		private byte[] pseudoTcpHeader = new byte[4096];
		private string sourceip;
		private string destip;
		private string reserved;
		private string protocol;
		private string tcplength;
		private byte _finFlag;
		private ushort _id;

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
			
			_ttl = ip.TTL;
			_fragmentIp = ip.Flags;
			_fragmentOffset = ip.FragmentOffset;
			_length = ip.DataLength;

			_protocol = ip.DataProtocol;
			
			_id = ip.Identifier;

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

		private string PseudoHeaderTcpSum(byte[] bytesBuffer)
		{
			var source = bytesBuffer[12].ToString("X2") + bytesBuffer[13].ToString("X2");
			var sum = Convert.ToInt32(source, 16);
			source = bytesBuffer[14].ToString("X2") + bytesBuffer[15].ToString("X2");
			sum += Convert.ToInt32(source, 16);

			source = bytesBuffer[16].ToString("X2") + bytesBuffer[17].ToString("X2");
			sum += Convert.ToInt32(source, 16);
			source = bytesBuffer[18].ToString("X2") + bytesBuffer[19].ToString("X2");
			sum += Convert.ToInt32(source, 16);

			source = "00" + bytesBuffer[9].ToString("X2");
			sum += Convert.ToInt32(source, 16);

			sum += _length;
			sum += Convert.ToInt32(tcplength, 16);

			return sum.ToString("X2");
		}

		/// <summary>
		/// проверка ошибок в контрльной сумме пакета
		/// </summary>
		/// <param name="sumhex"></param>
		//private bool CheckSumIsCorrect(string sumhex)
		//{
		//	var charArr = sumhex.ToCharArray();
		//	var i = 0;
		//	var carryBits = string.Empty;
		//	var lastpart = string.Empty;
		//	//for (var i = 0; i < charArr.Length; i++)
		//	//{
				
		//	//}
		//	while (charArr[i] != 'F')
		//	{
		//		carryBits += charArr[i].ToString();

		//		i++;
		//	}
		//	while (i != charArr.Length)
		//	{
		//		lastpart += charArr[i].ToString();
		//		i++;
		//	}
		//	var sum = 0;
		//	try
		//	{
		//		/// не учел суммы типа F2FF0D
		//		if (carryBits == string.Empty)
		//		{
		//			Console.WriteLine("{0} from {1} to {2}", sumhex, _sourceIpAddress, _desinationIpAddress);
		//		}
		//		else
		//		{
		//			sum = Convert.ToInt32(carryBits, 16) + Convert.ToInt32(lastpart, 16);
		//		}
		//	}
		//	catch (Exception exception)
		//	{
		//	}
		//	if (sum == Math.Pow(16, lastpart.Length) - 1)					
		//	{
		//		return true;
		//	}
		//	return false;
		//}


		private byte _synTcp;
		private byte _ackTcp;
		private byte _fragmentIp;
		private int _fragmentOffset;
		private int _length;
		private uint _ackNum;
		private uint _seqNum;
		private int count;

		public string ServiceInfo()
		{
			return string.Format("SYN:{0}\tSEQ:{1}\tACK:{2}\tACKNUM:{3}\tID:{4}\tFIN:{5}\tLEN:{6}", _synTcp, _seqNum, _ackTcp, _ackNum, _id, _finFlag, _length);
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

			tcplength = tcp.CalculatedSum;
			_synTcp = tcp.SYN;
			_ackTcp = tcp.ACK;
			_seqNum = tcp.InitialSequenceNumber;
			_ackNum = tcp.AcknowladgementNumber;
			_sourcePort = tcp.SourcePort;
			_destinationPort = tcp.DestinationPort;
			_finFlag = tcp.FIN;
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
		public delegate void SocketListnerEventHandler();
		/// <summary>
		/// Событие на получение нового пакета
		/// </summary>
		public event SocketListnerEventHandler OnNewPackage;

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
				_loggerIn.Stop();
				_loggerOut.Stop();
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
		public ushort SourcePort
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
		public ushort DestinationPort
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

		/// <summary>
		/// Время жизни пакета
		/// </summary>
		public int Ttl
		{
			get
			{
				return _ttl;
			}
		}
	    #endregion
	}
}
