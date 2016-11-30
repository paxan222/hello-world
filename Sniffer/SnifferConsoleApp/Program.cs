using System;
using System.IO;
using System.Runtime.InteropServices;
using Sniffer;

namespace SnifferConsoleApp
{
	class Program
	{
		private static SocketListner _listner;
		private static StreamWriter _inputTrafficWriter;
		private static StreamWriter _outputTrafficWriter;
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
			if (_ip != "")
			{
				var filename = string.Format("recordInputTraffic_{0}_{1}.txt", DateTime.Now.ToString("HH-mm-ss"), _ip);
				_inputTrafficWriter = new StreamWriter(Path.Combine(_folder, filename));
				filename = string.Format("recordOutputTraffic_{0}_{1}.txt", DateTime.Now.ToString("HH-mm-ss"), _ip);
				_outputTrafficWriter = new StreamWriter(Path.Combine(_folder, filename));
			}
			_listner.Start();
				
			Console.WriteLine("Press any key to exit");
			Console.ReadLine();
			OnExit();
		}

		private static void Writeline()
		{
			if (_listner.SourceIpAddress.ToString() == _ip)
			{
				_inputTrafficWriter.WriteLine("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}\t{7}\t{8}\t{9}\t{10}\t{11}\t{12}\t{13}",
					DateTime.Now.ToString("hh:mm:ss.fffff"),
					_listner.SourceIpAddress,
					_listner.SourcePort,
					_listner.DestinationIpAddress,
					_listner.DestinationPort,
					_listner.DataLength,
					_listner.Isn,
					_listner.An,
					_listner.Urg,
					_listner.Ack,
					_listner.Psh,
					_listner.Rst,
					_listner.Syn,
					_listner.Fin
					);
			}
			if (_listner.DestinationIpAddress.ToString() == _ip)
			{
				_outputTrafficWriter.WriteLine("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}\t{7}\t{8}\t{9}\t{10}\t{11}\t{12}\t{13}",
					DateTime.Now.ToString("hh:mm:ss.fffff"),
					_listner.SourceIpAddress,
					_listner.SourcePort,
					_listner.DestinationIpAddress,
					_listner.DestinationPort,
					_listner.DataLength,
					_listner.Isn,
					_listner.An,
					_listner.Urg,
					_listner.Ack,
					_listner.Psh,
					_listner.Rst,
					_listner.Syn,
					_listner.Fin
					);
			}
		}

		private static void Analyze()
		{
			//StreamReader
		}
		private static void OnExit()
		{
			_listner.Stop();
			if (_ip != "")
			{
				_inputTrafficWriter.Close();
				_outputTrafficWriter.Close();
			}
			Analyze();
		}

	}
}
