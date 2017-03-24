using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace PlayerSdlWrap
{
    public class PlayerSdl
    {
		private const string PlayerSdlDllName = @"\Dll\PlayerSdl.dll";
		[DllImport(PlayerSdlDllName)]
		public static extern IntPtr StartPlayer(string filename, IntPtr hwndPtr);
		[DllImport(PlayerSdlDllName)]
		public static extern bool StopPlayer(IntPtr hwndPtr);
    }
}
