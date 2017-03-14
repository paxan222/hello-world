using System;
using System.IO;
using System.Windows;
using System.Windows.Interop;
using System.Windows.Media.Imaging;
using RtspExportWrap;

namespace FFmpegPlayer
{
	/// <summary>
	/// Interaction logic for ImageWindow.xaml
	/// </summary>
	public partial class ImageWindow : Window
	{
		public ImageWindow()
		{
			InitializeComponent();
		}

		public void Show(string path)
		{
			var width = 640;
			var height = 480;
			var rtspExport = new RtspExport();
			using (var byteStream = new MemoryStream())
			{
				rtspExport.GetFrame("D:\\TestVideo\\1", width, height, 3000, byteStream);
				var image = new BitmapImage();
				byteStream.Position = 0;
				image.BeginInit();
				image.CreateOptions = BitmapCreateOptions.PreservePixelFormat;
				image.CacheOption = BitmapCacheOption.OnLoad;
				image.UriSource = null;
				image.StreamSource = byteStream;
				image.EndInit();
				image.Freeze();
				Image.Source = image;
			}
			Show();
		}
	}
}
