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
using System.Windows.Navigation;
using System.Windows.Shapes;
using RVI.NativePlayerWrap;

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

		private void OpenButton_OnClick(object sender, RoutedEventArgs e)
		{
			_path = PathTextBox.Text;
			var childWindow = new VideoWindow();
			_windowList.Add(childWindow);
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
	}
}
