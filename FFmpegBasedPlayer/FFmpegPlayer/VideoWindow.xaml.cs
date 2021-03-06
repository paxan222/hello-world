﻿using System;
using System.Diagnostics;
using System.IO;
using System.Threading;
using System.Windows;
using System.Windows.Interop;
using PlayerSdlWrap;
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
		bool playerSdl = true;

		public void Show(string path)
		{
			Show();
			var wih = new WindowInteropHelper(this);
			IntPtr hwnd = wih.Handle;
			if (!playerSdl)
			{
				_playerIntPtr = PlayerSdl.StartPlayer(path, hwnd);
				PlayerSdl.Play(_playerIntPtr);
			}
			else
			{
				_playerIntPtr = PlayerSdl.OpenSdl(path, hwnd);
				PlayerSdl.PlaySdl(_playerIntPtr);
				
			}

			
			//_playerIntPtr = PlayerSdl.StartPlayer(path, hwnd);
			//_playerIntPtr = NativePlayer.GetRtspPlayer(path, null, null, null, 10000, hwnd);
			//NativePlayer.SwitchSound(_playerIntPtr, true);
			//if (_playerIntPtr != IntPtr.Zero)
			//{
			//	//ShowFfmpeg(path);
			//	//NativePlayer.Play(_playerIntPtr);
			//}
			//else
			//{
			//	Close();
			//}
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
				if (!playerSdl)
				{
					 PlayerSdl.StopPlayer(_playerIntPtr);
				}
				else
				{
					PlayerSdl.StopSdl(_playerIntPtr);

				}
			Close();
		}
		
		private void VideoWindow_OnClosed(object sender, EventArgs e)
		{
			CloseChild();
		}
	}
}
