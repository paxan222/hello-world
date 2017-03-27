using System;
using System.Configuration;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using RVI.RtspRecorderWrap;

namespace FFmpegPlayerConsole
{
	class Program
	{
		static string ReadSetting(string key)
		{
			try
			{
				var appSettings = ConfigurationManager.AppSettings;
				return appSettings[key] ?? "Not Found";
			}
			catch (ConfigurationErrorsException)
			{
				Console.WriteLine("Error reading app settings");
			}
			return "Not Found";
		}

		static void Main(string[] args)
		{
			var rtsp = ReadSetting("rtsp");
			if (rtsp != "Not Found")
			{
				StartRecord(rtsp);
				Console.WriteLine("Start Recording");
			}
			var message = string.Empty;
			while (message != "q")
			{
				Console.WriteLine("Type \"q\" and press \"Enter\" to exit");
				message = Console.ReadLine();
			}
			StopRecord(rtsp);
		}

		private static void StopRecord(string rtsp)
		{
			var rec = new Recorder();
			rec.StopRecord(rtsp);
		}

		static void StartRecord(string rtsp)
		{
			var rec = new Recorder();
			rec.StartRecord(rtsp);
		}

		class Recorder
		{
			private RtspRecorder.RecieveDataCallback _recieveDataCallback;
			private RtspRecorder.ErrorCallback _errorCallback;

			private string _rtspPath;

			public void StartRecord(string rtsp)
			{
				_rtspPath = rtsp;
				_recieveDataCallback += RecieveDataCallback;
				_errorCallback += ErrorCallback;
				RtspRecorder.StartCallbackRecord(_rtspPath, 10000, _recieveDataCallback, null, _errorCallback);
			}

			public void StopRecord(string rtsp)
			{
				RtspRecorder.Stop(rtsp);
			}
			private void ErrorCallback(ErrorCode errorcode)
			{
				Console.WriteLine("ErrorCode:{0}", errorcode);
			}

			private int _fileSize = 0;
			private bool _isHeaderCall;
			private BinaryWriter writer;
			private int _count = 0;
			private string _path;

			private void RecieveDataCallback(IntPtr buf, int bufsize, bool isheaderdata)
			{
				var bytes = new byte[bufsize];
				Marshal.Copy(buf, bytes, 0, bufsize);
				var dir = string.Format("{0}\\RecordFiles", Directory.GetCurrentDirectory());

				if (!Directory.Exists(dir))
					Directory.CreateDirectory(dir);

				if (isheaderdata)
				{
					if (writer != null)
					{
						writer.Close();
						writer = null;
					}
					_path = string.Format("{0}\\recordFile{1}.mkv", dir, _count);
					writer = new BinaryWriter(File.Open(_path, FileMode.Append));
					_count++;
				}
				if (_path != string.Empty)
				{
					writer.Write(bytes);
				}

				_fileSize += bufsize;
				if (_fileSize > 104857600)
				{
					RtspRecorder.WriteHeader(_rtspPath);
					_fileSize = 0;
				}

			}
		}
	}
}
