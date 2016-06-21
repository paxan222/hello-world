using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GenerateSomeText
{
    class Program
    {
        static void Main(string[] args)
        {
            var streamWriter = new StreamWriter(@"D:\test.txt");
            streamWriter.WriteLine("В режиме <Односторонний>, задействовав <дверь 1>, выполнить следующие сценарии:");
            streamWriter.WriteLine();
            streamWriter.WriteLine("Повторить 1 раз");
            streamWriter.WriteLine("{");
            for (int i = 1; i < 1000; i++)
            {
                streamWriter.WriteLine("Пройти по карте через дверь(1,"+i.ToString()+",500)");
            }
            streamWriter.WriteLine("}");
            streamWriter.Dispose();
        }
    }
}
