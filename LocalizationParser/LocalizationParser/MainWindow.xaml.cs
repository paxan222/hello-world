using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;

namespace LocalizationParser
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //OpenFileDialog openFileDialog = new OpenFileDialog();
            //openFileDialog.InitialDirectory = FileProperties.Path;
            //if (openFileDialog.ShowDialog() == true)
            //{
            //    FileProperties.Path = openFileDialog.InitialDirectory;
            //    FileProperties.FileName = openFileDialog.FileName;
            //    TextBlock.Text = FileProperties.FileName;
            //}
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            dialog.RootFolder = Environment.SpecialFolder.MyComputer;
            if (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                FileProperties.Path = dialog.SelectedPath;
                TextBlock.Text = FileProperties.Path;
            }
        }
        
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            string[] dirStrings = Directory.GetFiles(FileProperties.Path,"*.cs", SearchOption.AllDirectories);
            TextBox.Text = string.Empty;
            Parse parse = new Parse();
            StreamWriter streamWriter = new StreamWriter("D:\\someRussianText.txt");
            foreach (var dirString in dirStrings)
            {
                streamWriter.WriteLine(System.IO.Path.GetFileName(dirString) + "\t" + parse.Output(new StreamReader(dirString)));
                //TextBox.Text += dirString + Environment.NewLine + Environment.NewLine;
                //TextBox.Text += parse.Output(new StreamReader(dirString));
            }
            streamWriter.Close();
        }
    }

    public class FileProperties
    {
        public static string Path = "D:\\repo\\Rubezh\\Projects\\FireAdministrator\\Modules\\AutomationModule\\Steps";
        public static string FileName = string.Empty;
    }

    public class Parse
    {
        public string Output(StreamReader streamReader)
        {
            string tmp = "";
            while (!streamReader.EndOfStream)
            {
                string tmp2 = streamReader.ReadLine();
                string line = tmp2.ToLower();
                if (line != null && (line.Contains("а") ||
                                     line.Contains("б") ||
                                     line.Contains("в") ||
                                     line.Contains("г") ||
                                     line.Contains("д") ||
                                     line.Contains("е") ||
                                     line.Contains("ё") ||
                                     line.Contains("ж") ||
                                     line.Contains("з") ||
                                     line.Contains("и") ||
                                     line.Contains("й") ||
                                     line.Contains("к") ||
                                     line.Contains("л") ||
                                     line.Contains("м") ||
                                     line.Contains("н") ||
                                     line.Contains("о") ||
                                     line.Contains("п") ||
                                     line.Contains("р") ||
                                     line.Contains("с") ||
                                     line.Contains("т") ||
                                     line.Contains("у") ||
                                     line.Contains("ф") ||
                                     line.Contains("х") ||
                                     line.Contains("ц") ||
                                     line.Contains("ч") ||
                                     line.Contains("ш") ||
                                     line.Contains("щ") ||
                                     line.Contains("ь") ||
                                     line.Contains("ы") ||
                                     line.Contains("ъ") ||
                                     line.Contains("э") ||
                                     line.Contains("ю") ||
                                     line.Contains("я")))
                {
                    tmp += tmp2 + Environment.NewLine;
                }
            }
            streamReader.Close();
            return tmp;
        }
    }
}
