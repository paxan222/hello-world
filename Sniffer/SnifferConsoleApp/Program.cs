using System;
using System.IO;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Net.Sockets;
using Sniffer;

namespace SnifferConsoleApp
{
	class Program
	{
		private static SocketListner _listner;
		private static StreamWriter _swWriter;
		private static string _ip;
		private static string _folder;

		[DllImport("Kernel32")]
		private static extern bool SetConsoleCtrlHandler(EventHandler handler, bool add);

		private delegate bool EventHandler(CtrlType sig);
		static EventHandler _handler;

		enum CtrlType
		{
			CTRL_C_EVENT = 0,
			CTRL_BREAK_EVENT = 1,
			CTRL_CLOSE_EVENT = 2,
			CTRL_LOGOFF_EVENT = 5,
			CTRL_SHUTDOWN_EVENT = 6
		}

		private static bool Handler(CtrlType sig)
		{
			switch (sig)
			{
				case CtrlType.CTRL_C_EVENT:
					OnExit();
					return true;
				case CtrlType.CTRL_LOGOFF_EVENT:
					OnExit();
					return true;
				case CtrlType.CTRL_SHUTDOWN_EVENT:
					OnExit();
					return true;
				case CtrlType.CTRL_CLOSE_EVENT:
					OnExit();
					return true;
				default:
					return false;
			}
		}

		static void Main(string[] args)
		{
			_handler += Handler;
			SetConsoleCtrlHandler(_handler, true);
			foreach (var s in args)
			{
				if (s.StartsWith("-"))
				{
					var tmp = s.Split('=');
					switch (tmp[0])
					{
						case"-ip":
							_ip = tmp[1];
							break;
						case"-folder":
							_folder = tmp[1];
							break;
						default:
							_ip = string.Empty;
							_folder = string.Empty;
							break;
					}
				}
			}
			_listner = new SocketListner(_folder);
			_listner.OnNewPackage += Writeline;
			var filename = string.Format("recordTraffic_{0}_{1}.txt", DateTime.Now.ToString("HH-mm-ss"), _ip);
			_swWriter = new StreamWriter(Path.Combine(_folder,filename));
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

		private static void OnExit()
		{
			_listner.Stop();
			_swWriter.Close();
		}

	}
}
