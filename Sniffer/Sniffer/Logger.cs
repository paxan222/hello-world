using System.IO;

namespace Sniffer
{
	public class Logger
	{
		private readonly StreamWriter _streamWriter;

		public Logger(string filename, bool append)
		{
			_streamWriter = new StreamWriter(filename, append);
		}
		public void Add(string line)
		{
			_streamWriter.WriteLine(line);
		}
		public void Add(string format, params object[] arg)
		{
			var tmp = string.Format(format, arg);
			_streamWriter.WriteLine(tmp);
		}
		public void Stop()
		{
			_streamWriter.Close();
		}
	}
}
