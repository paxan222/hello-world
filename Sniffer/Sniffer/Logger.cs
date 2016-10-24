using System.IO;

namespace Sniffer
{
	class Logger
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
		public void Stop()
		{
			_streamWriter.Close();
		}
	}
}
