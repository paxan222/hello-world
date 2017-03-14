using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
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
				NativePlayer.Play(_playerIntPtr);
			else
			{
				Close();
			}
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
	}
}
