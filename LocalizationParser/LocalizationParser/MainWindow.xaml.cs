using System;
using System.Collections;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Media.TextFormatting;
using Excel=Microsoft.Office.Interop.Excel;

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
            TextBlock.Text = Directory.GetParent(FileProperties.Path).FullName;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new FolderBrowserDialog();
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
            var parse = new Parse();
            var directoryInfo = new DirectoryInfo(FileProperties.RootPath);
            if (directoryInfo.Exists)
            {
                foreach (FileInfo file in directoryInfo.GetFiles())
                {
                    file.Delete();
                }
            }
            foreach (var dirString in dirStrings)
            {
                string path = FileProperties.RootPath + Directory.GetParent(dirString).Name;
                parse.Writer(path,dirString,TextBox);
            }
        }
    }

    public class FileProperties
    {
        public static string Path = "D:\\repo\\Trank\\Projects\\FireAdministrator\\Modules\\StrazhModule\\";
        public static string RootPath = "D:\\repo\\LocalizedTrank\\";
        public static string FileName = string.Empty;
    }

    public class Parse
    {
        Hashtable _myHashtable;
        public string Output(StreamReader streamReader)
        {
            string tmp = string.Empty;
            while (!streamReader.EndOfStream)
            {
                string tmp2 = streamReader.ReadLine();
                if (tmp2 != null)
                {
                    string line = tmp2.ToLower();
                    if ((line.Contains("а") ||
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
            }
            return tmp;
        }
        public void Writer(string path, string dirString, System.Windows.Controls.TextBox textBox)
        {
            var streamReader = new StreamReader(dirString);
            CheckExcel();
            string tmp = Output(streamReader);
            if (tmp != string.Empty)
            {
                var streamWriter = new StreamWriter(path + ".txt", true);
                streamWriter.WriteLine(Path.GetFullPath(dirString) + "\t" + tmp);
                streamWriter.Close();
                ExportToExcel(path,dirString,tmp);
                textBox.Text += dirString + Environment.NewLine;
            }
            streamReader.Close();
            KillExcel();
        }
        public void ExportToExcel(string path, string dirString, string tmp)
        {
            var ExcelApp = new Excel.Application();

                try
                {
                    ExcelApp.Workbooks.Open(path + ".xlsx");
                }
                catch (COMException)
                {
                    ExcelApp.Workbooks.Add();
                }
                Excel._Worksheet workSheet = ExcelApp.ActiveSheet;
                int row = ExcelApp.Sheets[1].Cells.SpecialCells(Excel.XlCellType.xlCellTypeLastCell).Row;
                row++;
                workSheet.Cells[row, "A"] = Path.GetFullPath(dirString);
                if (tmp.Contains("\n"))
                {
                    string[] subStrings = tmp.Split('\n');
                    foreach (var substring in subStrings)
                    {
                        string s = Regex.Replace(substring,@"\t", "");
                        if (!s.StartsWith("//"))
                        {
                            workSheet.Cells[row, "B"] = s;
                            row++;
                        }
                    }
                }
                workSheet.Columns.AutoFit();
                ExcelApp.ActiveWorkbook.SaveAs(path + ".xlsx", Excel.XlFileFormat.xlOpenXMLWorkbook, System.Reflection.Missing.Value, System.Reflection.Missing.Value, System.Reflection.Missing.Value, System.Reflection.Missing.Value,
                    Excel.XlSaveAsAccessMode.xlShared, System.Reflection.Missing.Value, System.Reflection.Missing.Value, System.Reflection.Missing.Value, System.Reflection.Missing.Value, System.Reflection.Missing.Value);
                ExcelApp.ActiveWorkbook.Close(false);
                ExcelApp.Quit();
                Marshal.ReleaseComObject(workSheet);
                Marshal.ReleaseComObject(ExcelApp);
        }
        public void CheckExcel()
        {
            Process[] AllProcesses = Process.GetProcessesByName("excel");
            _myHashtable = new Hashtable();
            int iCount = 0;

            foreach (Process ExcelProcess in AllProcesses)
            {
                _myHashtable.Add(ExcelProcess.Id, iCount);
                iCount = iCount + 1;
            } 
        }
        public void KillExcel()
        {
            Process[] AllProcesses = Process.GetProcessesByName("excel");

            // check to kill the right process
            foreach (Process ExcelProcess in AllProcesses)
            {
                if (_myHashtable.ContainsKey(ExcelProcess.Id) == false)
                    ExcelProcess.Kill();
            }

            AllProcesses = null;
        }
    }
}
