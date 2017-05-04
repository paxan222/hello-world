using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using RtspExportWrap;
using RVI.RtspRecorderWrap;

namespace FFmpegPlayer
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		private string _path;
		private IntPtr _hwnd;
		private IntPtr _playerIntPtr;
		private List<Window> _windowList = new List<Window>();
		private RtspRecorder.RecieveDataCallback _recieveDataCallback;
		private RtspRecorder.ErrorCallback _errorCallback;
		private int _count = 1;
		private string _rtspPath;
		private bool _isHeaderCall = false;
		public MainWindow()
		{
			InitializeComponent();
		}

		private void PlayStreamButton_OnClick(object sender, RoutedEventArgs e)
		{
			_path = PathTextBox.Text;
			StartPlayingVideo();
		}

		private void StartPlayingVideo()
		{
			var childWindow = new VideoWindow();
			_windowList.Add(childWindow);
			childWindow.Width = 640;
			childWindow.Height = 480;
			childWindow.Show(_path);
			
		}
		private void MainWindow_OnClosed(object sender, EventArgs e)
		{
			foreach (var window in _windowList.Cast<VideoWindow>())
			{
				window.CloseChild();
			}
		}

		private void OpenImageButton_OnClick(object sender, RoutedEventArgs e)
		{
			_path = PathImageTextBox.Text;
			var time = Int32.Parse(TimestampImageTextBox.Text);
			var childWindow = new ImageWindow();
			_windowList.Add(childWindow);
			childWindow.Show(_path, time);
		}

		private void StartCutButton_OnClick(object sender, RoutedEventArgs e)
		{
			var startCutTime = Int32.Parse(StartTimeTextBox.Text);
			var endCutTime = Int32.Parse(EndTimeTextBox.Text);
			_playerIntPtr = RtspExport.Cut(PathCutFileTextBox.Text, PathCutResultTextBox.Text, startCutTime, endCutTime, null, null, null);
		}

		private void StartConcatenateButton_OnClick(object sender, RoutedEventArgs e)
		{
			_playerIntPtr = RtspExport.Concatenate(PathConcatenateFirtstFileTextBox.Text, PathConcatenateSecondFileTextBox.Text, PathConcatenateResultTextBox.Text, null, null, null);
		}

		private void RecordStreamButton_OnClick(object sender, RoutedEventArgs e)
		{
			_rtspPath = PathRecordTextBox.Text;
			_recieveDataCallback += RecieveDataCallback;
			_errorCallback += ErrorCallback;
			RtspRecorder.StartCallbackRecord(_rtspPath, 0, _recieveDataCallback, null, _errorCallback);
			//RtspRecorder.StartFileRecord(_rtspPath, "D:\\TestVideo\\Record\\test.mkv", 15000, _errorCallback);
		}

		private FileStream fsStream;
		private BinaryWriter writer;
		private int _fileSize = 0;
		private void RecieveDataCallback(IntPtr buf, int bufSize, bool isHeaderData)
		{
			var bytes = new byte[bufSize];
			Marshal.Copy(buf, bytes, 0, bufSize);
			var dir = string.Format("{0}\\RecordFiles", Directory.GetCurrentDirectory());

			if (!Directory.Exists(dir))
				Directory.CreateDirectory(dir);
			if (isHeaderData)
			{
				if (writer != null)
				{
					writer.Close();
					if (fsStream != null)
						fsStream.Close();
				}
				_path = string.Format("{0}\\recordFile{1}.mkv", dir, _count);
				fsStream = new FileStream(_path, FileMode.Append);
				writer = new BinaryWriter(fsStream, Encoding.UTF8);
				_count++;
				_isHeaderCall = false;
			}
			if (_path != string.Empty)
			{
				writer.Write(bytes);
			}
			_fileSize += bufSize;
			if (_fileSize > 10000000 && !_isHeaderCall)
			{
				RtspRecorder.WriteHeader(_rtspPath);
				_isHeaderCall = true;
				_fileSize = 0;
			}
		}
		private void ErrorCallback(ErrorCode errorCode)
		{
			Console.WriteLine("ErrorCode:{0}", errorCode);
		}

		private void StopRecordStreamButton_OnClick(object sender, RoutedEventArgs e)
		{
			RtspRecorder.Stop(_rtspPath);
			if (writer != null)
			{
				writer.Close();
				if (fsStream != null)
					fsStream.Close();
			}
		}
	}
}
