//
//  StrUtil.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-18.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "StrUtil.h"
#include <stdlib.h>

namespace MikuGame
{
    
    int GetIndexToNextLine(const std::string& instr)
    {
        int index = instr.find_first_of("\n\r");
        if(index!=-1)
        {
            return index;
        }
        index = instr.find_first_of("\r\n");
        if(index!=-1)
        {
            return index;
        }
        index = instr.find_first_of("\n");
        if(index!=-1)
        {
            return index;
        }
        index = instr.find_first_of("\r");
        if(index!=-1)
        {
            return index;
        }
        return -1;
    }
    
    void ToNextLine(std::string& instr)
    {
        int index = instr.find_first_of("\n\r");
        if(index!=-1)
        {
            instr = instr.substr(index+4,instr.length());
            return;
        }
        index = instr.find_first_of("\r\n");
        if(index!=-1)
        {
            instr = instr.substr(index+4,instr.length());
            return;
        }
        index = instr.find_first_of("\n");
        if(index!=-1)
        {
            instr = instr.substr(index+2,instr.length());
            return;
        }
        index = instr.find_first_of("\r");
        if(index!=-1)
        {
            instr = instr.substr(index+2,instr.length());
            return;
        }
    }
    
    void GetFirstStr(std::string& instr,std::string& outstr)
    {
        int index1 = instr.find_first_of(" ");
        
        
        int index = GetIndexToNextLine(instr);
        if(index1==-1&&index==1)
        {
            return;
        }
        if(index1==-1)
        {
            
        }
        else if(index==-1)
        {
            index = index1;
        }
        else if(index>index1)
        {
            index = index1;
        }
        
        
        outstr = instr.substr(0,index);
        instr = instr.substr(index+1,instr.length());
    }

    
    
    int GetIndexToNextLine(const std::wstring& instr)
    {
        int index = instr.find_first_of(L"\n\r");
        if(index!=-1)
        {
            return index;
        }
        index = instr.find_first_of(L"\r\n");
        if(index!=-1)
        {
            return index;
        }
        index = instr.find_first_of(L"\n");
        if(index!=-1)
        {
            return index;
        }
        index = instr.find_first_of(L"\r");
        if(index!=-1)
        {
            return index;
        }
        return -1;
    }
    
    void ToNextLine(std::wstring& instr)
    {
        int index = instr.find_first_of(L"\n\r");
        if(index!=-1)
        {
            instr = instr.substr(index+4,instr.length());
            return;
        }
        index = instr.find_first_of(L"\r\n");
        if(index!=-1)
        {
            instr = instr.substr(index+4,instr.length());
            return;
        }
        index = instr.find_first_of(L"\n");
        if(index!=-1)
        {
            instr = instr.substr(index+2,instr.length());
            return;
        }
        index = instr.find_first_of(L"\r");
        if(index!=-1)
        {
            instr = instr.substr(index+2,instr.length());
            return;
        }
    }
    
    void GetFirstStr(std::wstring& instr,std::wstring& outstr)
    {
        int index1 = instr.find_first_of(L" ");
        
        
        int index = GetIndexToNextLine(instr);
        if(index1==-1&&index==1)
        {
            return;
        }
        if(index1==-1)
        {
            
        }
        else if(index==-1)
        {
            index = index1;
        }
        else if(index>index1)
        {
            index = index1;
        }
        
        
        outstr = instr.substr(0,index);
        instr = instr.substr(index+1,instr.length());
    }
    
    int UTF8ToWide(const char* src, unsigned short* dst)
    {
        int numConv = mbstowcs( (wchar_t*)dst, src,  strlen(src) * 2);
        if (numConv > 0)
        {
            dst[numConv] = 0;
            return numConv;
        }
        else
        {
            
            return -1;
        }
    }
}
