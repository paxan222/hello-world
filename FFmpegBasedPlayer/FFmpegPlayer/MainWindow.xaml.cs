using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Windows;
using RtspExportWrap;

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

		public MainWindow()
		{
			InitializeComponent();
		}

		private void PlayStreamButton_OnClick(object sender, RoutedEventArgs e)
		{
			_path = PathTextBox.Text;
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
			var childWindow = new ImageWindow();
			_windowList.Add(childWindow);
			childWindow.Show(_path);
		}

		private void StartCutButton_OnClick(object sender, RoutedEventArgs e)
		{
			var startCutTime = Int32.Parse(StartTimeTextBox.Text);
			var endCutTime = Int32.Parse(EndTimeTextBox.Text);
			_playerIntPtr = RtspExport.Cut(PathCutFileTextBox.Text, PathCutResultTextBox.Text, startCutTime, endCutTime, null, null, null);
		}

		private void StartConcatenateButton_OnClick(object sender, RoutedEventArgs e)
		{
			_playerIntPtr = RtspExport.Concatenate(PathConcatenateFirtstFileTextBox.Text,PathConcatenateSecondFileTextBox.Text, PathConcatenateResultTextBox.Text, null, null, null);
		}
	}
}
