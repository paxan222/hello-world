using System;
using System.Diagnostics;
using System.IO;
using System.Windows;
using System.Windows.Interop;
using RVI.NativePlayerWrap;

namespace FFmpegPlayer
{
	/// <summary>
	/// Interaction logic for TempWindow.xaml
	/// </summary>
	public partial class VideoWindow : Window
	{
		private IntPtr _playerIntPtr;

		public VideoWindow()
		{
			InitializeComponent();
		}

		public void Show(string path)
		{
			Show();
			var wih = new WindowInteropHelper(this);
			IntPtr hwnd = wih.Handle;
			_playerIntPtr = NativePlayer.GetRtspPlayer(path, null, null, null, 10000, hwnd);
			if (_playerIntPtr != IntPtr.Zero)
			{
				//ShowFfmpeg(path);
				NativePlayer.Play(_playerIntPtr);
			}
			else
			{
				Close();
			}
		}

		private void ShowFfmpeg(string path)
		{
			var pathffplay = String.Format("{0}\\{1}", Directory.GetCurrentDirectory(), "ffplay.exe");
			var args = String.Format("-i \"{0}\" -rtsp_transport tcp -x 1280 -y 720", path);
			var psi = new ProcessStartInfo(pathffplay, args);
			Process.Start(psi);
			
		}
		public void CloseChild()
		{
			if (_playerIntPtr != IntPtr.Zero)
				NativePlayer.ReleasePlayer(_playerIntPtr);
			Close();
		}

		private void SwitchSound_OnClick(object sender, RoutedEventArgs e)
		{
			if (ReferenceEquals(SwitchSound.Content, "Mute"))
			{
				SwitchSound.Content = "Unmute";
				NativePlayer.SwitchSound(_playerIntPtr, false);
			}
			else
			{
				SwitchSound.Content = "Mute";
				NativePlayer.SwitchSound(_playerIntPtr, true);
			}
		}
		
		private void VideoWindow_OnClosed(object sender, EventArgs e)
		{
			CloseChild();
		}
	}
}
