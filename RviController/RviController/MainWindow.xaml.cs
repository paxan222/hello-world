using System;
using System.Diagnostics;
using System.IO;
using System.Windows;

namespace RviController
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		private void Button2_Click(object sender, RoutedEventArgs e)
		{
			var script = new Script();
			const string host = "192.168.8.66";
			const string port = "5555";
			const string ipaddress = "192.168.8.217";
			var connectionProperties = new ConnectionProperties(host, port, ipaddress);
			script.WriteSystemRebootRequestScriptFile(connectionProperties);

		}

		//private void run_cmd(string cmd, string args)
		//{
		//	ProcessStartInfo start = new ProcessStartInfo();
		//	start.FileName = "my/full/path/to/python.exe";
		//	start.Arguments = string.Format("{0} {1}", cmd, args);
		//	start.UseShellExecute = false;
		//	start.RedirectStandardOutput = true;
		//	using (Process process = Process.Start(start))
		//	{
		//		using (StreamReader reader = process.StandardOutput)
		//		{
		//			string result = reader.ReadToEnd();
		//			Console.Write(result);
		//		}
		//	}
		//}
	}

}
