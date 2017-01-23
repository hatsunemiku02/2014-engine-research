//
//  StrUtil.h
//  Catfish
//
//  Created by zhaohang on 14-4-18.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__StrUtil__
#define __Catfish__StrUtil__
#include <string>
namespace MikuGame {
    void GetFirstStr(std::string& instr,std::string& outStr);
    void ToNextLine(std::string& instr);
    int GetIndexToNextLine(const std::string& instr);
    
    void GetFirstStr(std::wstring& instr,std::wstring& outStr);
    void ToNextLine(std::wstring& instr);
    int GetIndexToNextLine(const std::wstring& instr);
    
    int UTF8ToWide(const char* src, unsigned short* dst);
}

#endif /* defined(__Catfish__StrUtil__) */
