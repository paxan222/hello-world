using System;
using System.Collections;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;
using System.Web.Caching;
using System.Windows;
using System.Windows.Forms;
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
            dialog.SelectedPath = FileProperties.Path;
            if (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                FileProperties.Path = dialog.SelectedPath;
                TextBlock.Text = FileProperties.Path;
            }
        }
        
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            string[] dirStrings = Directory.GetFiles(FileProperties.Path, FileProperties.Extension, SearchOption.AllDirectories);
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

        private void ComboBox_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            switch (ComboBox.SelectedIndex)
            {   
                case 0:
                    FileProperties.Extension = "*.cs";
                    break;
                case 1:
                    FileProperties.Extension = "*.xaml";
                    break;
            }
        }

        private void Button_Click2(object sender, RoutedEventArgs e)
        {
            Process.Start(@FileProperties.RootPath);
        }
    }

    public class FileProperties
    {
        public static string Path = "D:\\repo\\Trank\\Projects\\";
        public static string RootPath = "D:\\repo\\LocalizedTrank\\";
        public static string Extension = "*.cs";
        public static string FileName = string.Empty;
        public enum PathEnum
        {
            Path
        }
    }
    public class Parse
    {
        private Hashtable _myHashtable;

        private readonly char[] _russianAlphabeth = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ".ToCharArray();
        private readonly char[] _englishAlphabeth = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".ToCharArray();

        private string ReadFromFile(StreamReader streamReader)
        {
            string tmp = string.Empty;
            while (!streamReader.EndOfStream)
            {
                string line = streamReader.ReadLine();
                if ((line != null) && (line.IndexOfAny(_russianAlphabeth) >=0))
                    tmp += line + Environment.NewLine;
            }
            return tmp;
        }

        private string CutString(string input)
        {
            string output = string.Empty;
            int startRussian = 0;
            int stopRussian = 0;
            int startString = 0;
            int stopString = 0;
            if (!input.StartsWith("<!--"))
            {
                startRussian = input.IndexOfAny(_russianAlphabeth);
                startString = input.LastIndexOf('"', startRussian) + 1;

                stopRussian = input.LastIndexOfAny(_russianAlphabeth);
                stopString = input.IndexOf('"', stopRussian);
                if (stopString > startString)
                {
                    output = input.Substring(startString, stopString - startString);
                }
                else
                {
                    output = input;
                }
            }
            return output;
        }
        public void Writer(string path, string dirString, System.Windows.Controls.TextBox textBox)
        {
            var streamReader = new StreamReader(dirString);
            CheckExcel();
            string tmp = ReadFromFile(streamReader);
            if (tmp != string.Empty)
            {
                var streamWriter = new StreamWriter(path + ".txt", true);
                streamWriter.WriteLine(Path.GetFullPath(dirString) + "\t" + tmp);
                streamWriter.Close();
                ExportToExcel(path, dirString, tmp);
                textBox.Text += dirString + Environment.NewLine;
            }
            streamReader.Close();
            KillExcel();
        }

        private void ExportToExcel(string path, string dirString, string tmp)
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
            if (tmp.Contains("\n"))
            {
                string[] subStrings = tmp.Split('\n');
                foreach (var substring in subStrings)
                {
                    string s = Regex.Replace(substring, @"\t", "");
                    if (s != string.Empty)
                    {
                        if (!s.StartsWith("//") && (!s.StartsWith("#"))&&
                            (!s.StartsWith("Logger.")))
                        {
                            workSheet.Cells[row, "A"] = Path.GetFullPath(dirString);
                            workSheet.Cells[row, "B"] = Path.GetFileNameWithoutExtension(dirString);
                            workSheet.Cells[row, "C"] = s;
                            if(FileProperties.Extension=="*.xaml")
                                workSheet.Cells[row, "D"] = CutString(s);
                            row++;
                        }
                    }
                }
            }
            workSheet.Columns.AutoFit();
            ExcelApp.ActiveWorkbook.SaveAs(path + ".xlsx", Excel.XlFileFormat.xlOpenXMLWorkbook,
                System.Reflection.Missing.Value, System.Reflection.Missing.Value, System.Reflection.Missing.Value,
                System.Reflection.Missing.Value, Excel.XlSaveAsAccessMode.xlShared, System.Reflection.Missing.Value,
                System.Reflection.Missing.Value, System.Reflection.Missing.Value, System.Reflection.Missing.Value,
                System.Reflection.Missing.Value);
            ExcelApp.ActiveWorkbook.Close(false);
            ExcelApp.Quit();
            Marshal.ReleaseComObject(workSheet);
            Marshal.ReleaseComObject(ExcelApp);
        }

        private void CheckExcel()
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

        private void KillExcel()
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
