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
	public partial class TempWindow : Window
	{
		public TempWindow()
		{
			InitializeComponent();
		}

		public void Show(string path)
		{
			Show();
			var wih = new WindowInteropHelper(this);
			IntPtr hwnd = wih.Handle;
			IntPtr playerIntPtr = NativePlayer.GetRtspPlayer(path, null, null, null, 10000, hwnd);
			NativePlayer.Play(playerIntPtr);

		}
	}
}
