using System;
using System.IO;
using System.Net;
using System.Net.Sockets;

namespace Sniffer
{
	public class Logger
	{
		private readonly StreamWriter _streamWriter;

		public Logger(string filename, bool append)
		{
			_streamWriter = new StreamWriter(filename, append);
		}
		public void Add(string line)
		{
			_streamWriter.WriteLine(line);
		}
		public void Add(string format, params object[] arg)
		{
			var tmp = string.Format(format, arg);
			_streamWriter.WriteLine(tmp);
		}

		public void Add(ProtocolType protocol, IPAddress sourceIpAddress, int sourcePort, IPAddress destinationIpAddress,
			int destinationPort, int ttl)
		{
			_protocol = protocol;
			_sourceIpAddress = sourceIpAddress;
			_sourcePort = sourcePort;
			_destinationIpAddress = destinationIpAddress;
			_destinationPort = destinationPort;
			_ttl = ttl;
			WriteLine();
		}

		private ProtocolType _protocol;
		private IPAddress _sourceIpAddress;
		private int _sourcePort;
		private IPAddress _destinationIpAddress;
		private int _destinationPort;
		private int _ttl;
		private void WriteLine()
		{
			_streamWriter.WriteLine("Protocol: {0}", _protocol);
			_streamWriter.WriteLine("Source:\t{0}:{1}", _sourceIpAddress, _sourcePort);
			_streamWriter.WriteLine("Destination:\t{0}:{1}", _destinationIpAddress, _destinationPort);
			_streamWriter.WriteLine("Ttl: {0}", _ttl);
		}

		public void Stop()
		{
			_streamWriter.Close();
		}
	}
}
