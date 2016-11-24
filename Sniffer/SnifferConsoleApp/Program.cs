using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Net.Sockets;
using Sniffer;

namespace SnifferConsoleApp
{
	class Program
	{
		private static SocketListner _listner;
		private static StreamWriter _swWriter;
		private static string _ip;

		static void Main(string[] args)
		{
			if (args.Length == 0)
			{
				Console.WriteLine("There is now args. Sniffer start for localhost address.");
				var getHostName = Dns.GetHostName();
				var getHostEntry = Dns.GetHostEntry(getHostName);
				var addressList = getHostEntry.AddressList;
				var hostIpAddress = addressList.Where(x => x.AddressFamily.Equals(AddressFamily.InterNetwork));
				var firstOrDefault = hostIpAddress.FirstOrDefault();
				if (firstOrDefault != null) _ip = firstOrDefault.ToString();
			}
			else
			{
				_ip = args[0];
			}
			_listner = new SocketListner(Directory.GetCurrentDirectory());
			_listner.OnNewPackage += Writeline;
			var filename = string.Format("recordTraffic_{0}_{1}.txt", DateTime.Now.ToString("HH-mm-ss"), _ip);
			_swWriter = new StreamWriter(filename);
			_listner.Start();
				
			Console.WriteLine("Press any key to exit");
			Console.ReadLine();
			_listner.Stop();
			_swWriter.Close();
		}

		private static void Writeline()
		{
			if (_listner.SourceIpAddress.ToString() == _ip)
			{
				_swWriter.WriteLine("{0}\t{1}:{2}\t{3}:{4}\t{5}\t{6}\t{7}",
					DateTime.Now.ToString("hh:mm:ss.fffff"),
					_listner.SourceIpAddress,
					_listner.SourcePort,
					_listner.DestinationIpAddress,
					_listner.DestinationPort,
					_listner.DataLength,
					_listner.Isn,
					_listner.An);
			}
		}

	}
}
