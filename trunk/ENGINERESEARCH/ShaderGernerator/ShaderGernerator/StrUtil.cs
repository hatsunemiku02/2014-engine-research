using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ShaderGernerator
{
    public static class StrUtil
    {

        public static string[] SplitByLine(string instr)
        {
           // List<string> ret = null;

            string lineseper = GetLineSerperator(instr);
            if (lineseper=="")
            {
                Exception ex = new Exception();
              //  ex.Data = "unknown line seperator!\n";
            }
            return instr.Split(lineseper.ToCharArray()); 
        }

        private static string GetLineSerperator(string instr)
        {

             int index = instr.IndexOf("\n\r");
            if(index!=-1)
            {
                return "\n\r";
            }
            index = instr.IndexOf("\r\n");
            if(index!=-1)
            {
                return "\r\n";
            }
            index = instr.IndexOf("\n");
            if(index!=-1)
            {
                return "\n";
            }
            index = instr.IndexOf("\r");
            if(index!=-1)
            {
                return  "\r";
            }
            return "";
        }
    }
}
