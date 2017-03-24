using System;
using System.Windows.Interop;
using RVI.NativePlayerWrap;

namespace FFmpegPlayer
{
	/// <summary>
	/// Interaction logic for Player.xaml
	/// </summary>
	public partial class Player
	{
		private IntPtr _playerIntPtr;
		public Player()
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
	}
}
