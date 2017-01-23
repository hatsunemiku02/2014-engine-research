using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ShaderGernerator;

namespace ShaderGernerator
{
    public class ParamHeader
    {
        public Dictionary<string, string> m_AttSemeticToUsername;
        public Dictionary<string, string> m_UniSemeticToUsername;
        ParamHeader()
        {


        }
        ~ParamHeader()
        {

        }

        void InitSemeticDic()
        {
            m_AttSemeticToUsername.Add("POS", "");
            m_AttSemeticToUsername.Add("COLOR", "");
            m_AttSemeticToUsername.Add("NORMAL", "");
            m_AttSemeticToUsername.Add("TANGENT", "");
            m_AttSemeticToUsername.Add("BINORMAL", "");

            m_AttSemeticToUsername.Add("TEX0", "");
            m_AttSemeticToUsername.Add("TEX1", "");
            m_AttSemeticToUsername.Add("TEX2", "");
            m_AttSemeticToUsername.Add("TEX3", "");
            m_AttSemeticToUsername.Add("TEX4", "");
            m_AttSemeticToUsername.Add("TEX5", "");
            m_AttSemeticToUsername.Add("TEX6", "");
            m_AttSemeticToUsername.Add("TEX7", "");
            m_AttSemeticToUsername.Add("TEX8", "");

            m_UniSemeticToUsername.Add("WVPMAT", "");
            m_UniSemeticToUsername.Add("WORLDMAT", "");
            m_UniSemeticToUsername.Add("VIEWMAT", "");
            m_UniSemeticToUsername.Add("PROJMAT", "");
            m_UniSemeticToUsername.Add("VIEWPROJMAT", "");
            m_UniSemeticToUsername.Add("VIEWDIRV3", "");

//             m_SemeticToUsername.Add("POINTLIGHTPOS0V4", "");
//             m_SemeticToUsername.Add("POINTLIGHTPOS1V4", "");
//             m_SemeticToUsername.Add("POINTLIGHTPOS2V4", "");
//             m_SemeticToUsername.Add("POINTLIGHTPOS3V4", "");
// 
//             m_SemeticToUsername.Add("POINTLIGHTCOLOR0V4", "");
//             m_SemeticToUsername.Add("POINTLIGHTCOLOR1V4", "");
//             m_SemeticToUsername.Add("POINTLIGHTCOLOR2V4", "");
//             m_SemeticToUsername.Add("POINTLIGHTCOLOR3V4", "");

        }

        void FillSemeticDic(string paramHeader)
        {

            string[] headerlines = StrUtil.SplitByLine(paramHeader);
            foreach (string line in headerlines)
            {
                string[] pair = line.Split(new char[]{':'});

                if (m_UniSemeticToUsername.ContainsKey(pair[1]))
                {
                    m_UniSemeticToUsername[pair[1]] = pair[0];
                }
                else if (m_AttSemeticToUsername.ContainsKey(pair[1]))
                {
                    m_AttSemeticToUsername[pair[1]] = pair[0];
                }
                else
                {
                    //unknow semetic
                }
            }    
        }
    }
}
