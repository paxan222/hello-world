using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Net.Sockets;
using Sniffer;

namespace SnifferConsoleApp
{
	class Program
	{
		private static string SourceIpAddress;
		private static string SourcePort;
		private static string DestinationIpAddress;
		private static string DestinationPort;
		private static ProtocolType Protocol;


		static void Main(string[] args)
		{
			SocketListner listner = new SocketListner();
			listner.OnNewPackage += Writeline;

			listner.Start();
			while(!listner.Message)
			{
				
			}
			while (listner.Message)
			{
				SourceIpAddress = listner.SourceIpAddress.ToString();
				SourcePort = listner.SourcePort.ToString();
				DestinationIpAddress = listner.DestinationIpAddress.ToString();
				DestinationPort = listner.DestinationPort.ToString();
				Protocol = listner.Protocol;
			}
			Console.ReadLine();
			listner.Stop();
		}

		private static void Writeline()
		{
			if ((SourceIpAddress == "192.168.11.66") && (Protocol == ProtocolType.Udp))
			{
				Console.WriteLine("Time:{0}\t{1}\t{2}:{3}\t{4}:{5}", DateTime.Now.ToString("hh:mm:ss.ffff"), Protocol,
						SourceIpAddress, SourcePort, DestinationIpAddress, DestinationPort);
			}
		}

	}
}
