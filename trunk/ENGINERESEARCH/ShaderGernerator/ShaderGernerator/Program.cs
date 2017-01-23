using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ShaderGernerator
{
    class Program
    {
        string shader = null;
        static void Main(string[] args)
        {
            if (args.Length<1)
            {
                System.Console.WriteLine("noInput");
                return;
            }
            string infile = args[0];


        }
    }
}
