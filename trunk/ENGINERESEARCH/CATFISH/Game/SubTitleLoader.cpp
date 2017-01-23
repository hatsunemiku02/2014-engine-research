//
//  SubTitleLoader.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-18.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "SubTitleLoader.h"
#include "FileReader.h"
#include "ResMgr.h"
#include "StrUtil.h"
#include "SubTitle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <codecvt>
namespace  MikuGame
{
    SubTitleLoader::SubTitleLoader()
    {
        
    }
    
    SubTitleLoader::~SubTitleLoader()
    {
        
    }
    
    SubTitle SubTitleLoader::CreateSubTitle(std::string& inStr)
    {
        std::string value;
        SubTitle ret;
        GetFirstStr(inStr,value);
        ret.StartTime = atof((const char*)value.c_str());
        GetFirstStr(inStr,value);
        ret.EndTime = atof((const char*)value.c_str());
        GetFirstStr(inStr,value);
        wchar_t* chinese = (wchar_t*)value.c_str();
         std::wstring fileContentw((wchar_t*)value.c_str());
        ret.Content = chinese;
        
        return ret;
    }
    using namespace std;

    SubTitle SubTitleLoader::CreateSubTitle(std::wifstream& stream)
    {
        SubTitle ret;
        std::wstring value;
        stream>>value;
        swscanf(value.c_str(), L"%lf", &ret.StartTime);
        
        stream>>value;
        swscanf(value.c_str(), L"%lf", &ret.EndTime);
        stream>>value;
        ret.Content = value;
        return ret;
    }
    
    SubTitleManager* SubTitleLoader::CreateSubTitleManager(const char* path)
    {
        SubTitleManager* pRet = new SubTitleManager();
        
        IO::FileReader reader;
        
        std::string filepath = Resource::ResMgr::GetInstance().GetBaseDic()+path;
        
        std::wstring str1;
        std::wifstream wifs(filepath,std::wios::in);
        wifs.imbue(locale(wifs.getloc(), new codecvt_utf8<wchar_t, 0x10ffff, consume_header>()));
  		
        std::wstring value;
        
        wifs>>value;
        while (value==L"R")
        {
            value = L"";
            pRet->AddSubTitle(CreateSubTitle(wifs));
            wifs>>value;
        }
        
        wifs.close();

        return pRet;
    }
}