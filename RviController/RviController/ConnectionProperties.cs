namespace RviController
{
	/// <summary>
	/// Класс, хранящий в себе настройки подключения
	/// </summary>
	public class ConnectionProperties
	{
		public string Host { get; set; }
		public string Port { get; set; }
		public string IpAddress { get; set; }
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="host">хост</param>
		/// <param name="port">порт</param>
		/// <param name="ipaddress">адрес</param>
		public ConnectionProperties(string host, string port, string ipaddress)
		{
			Host = host;
			Port = port;
			IpAddress = ipaddress;
		}
	}
}