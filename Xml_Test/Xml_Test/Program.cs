using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;

namespace Xml_Test
{
    class Program
    {
        static void Main(string[] args)
        {

            var doc = XDocument.Load("StrazhAdmin.exe.config");
            var key = "DefaultCulture";
            //var root = doc.Root;
            //var element = root.Element("appSettings");
            //var keys = element.Descendants("add")
            //    .Select(x => new
            //    {
            //        key = x.Attribute("key").Value,
            //        value = x.Attribute("value").Value});
            //foreach (var def in keys)
            //{
            //    if(def.key == "DefaultCulture")
            //        Console.WriteLine("Key = {0} \t Value = {1}", def.key, def.value);
            //}

            var list = from appNode in doc.Descendants("appSettings").Elements()
                       where appNode.Attribute("key").Value == key
                       select appNode;
            var e = list.FirstOrDefault();
            if(e!=null) 
            {
                Console.WriteLine(e.Attribute("value").Value);
                e.Attribute("value").SetValue("en");
                doc.Save("StrazhAdmin.exe.config");
                Console.WriteLine(e.Attribute("value").Value);
            }

            Console.ReadLine();
        }
    }
}
