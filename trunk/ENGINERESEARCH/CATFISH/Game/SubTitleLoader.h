//
//  SubTitleLoader.h
//  Catfish
//
//  Created by zhaohang on 14-4-18.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_SubTitleLoader_h
#define Catfish_SubTitleLoader_h
#include <string>
#include "SubTitle.h"
namespace  MikuGame
{
    class SubTitleLoader
    {
    public:
        ~SubTitleLoader();
        static SubTitleLoader& GetInstance()
        {
            static SubTitleLoader instance;
            return instance;
        }
        SubTitleManager* CreateSubTitleManager(const char* path);
    protected:
        SubTitle CreateSubTitle(std::string& inStr);
        SubTitle CreateSubTitle(std::wifstream& stream);
        
        SubTitleLoader();
        
    };
}

#endif
