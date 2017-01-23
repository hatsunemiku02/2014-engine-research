using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ShaderGernerator;

namespace ShaderGernerator
{
    public class GlesCode
    {
        ParamHeader m_Header;
        string m_OriContent;
        public GlesCode(ParamHeader header,string inStr)
        {
            m_Header = header;
            m_OriContent = inStr;
        }

        ~GlesCode()
        {

        }
       
        public void ReplaceUniformName()
        {

        }

        public void OrderAttribute()
        {

        }
    }
}
