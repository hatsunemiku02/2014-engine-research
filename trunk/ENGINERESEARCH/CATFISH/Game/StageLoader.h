//
//  StageLoader.h
//  Catfish
//
//  Created by zhaohang on 14-4-17.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__StageLoader__
#define __Catfish__StageLoader__
#include <string>
namespace  MikuGame
{
    class MikuRhythmStage;
    class Rhythm;
    class BackGround;
    class StageLoader
    {
    public:
        ~StageLoader();
        static StageLoader& GetInstance()
        {
            static StageLoader instance;
            return instance;
        }
        MikuRhythmStage* CreateStage(const char* path);
    protected:
        
        Rhythm* CreateRhythm(std::string& instr);
        BackGround* CreateBG(std::string& instr);
        StageLoader();

    };
}
#endif /* defined(__Catfish__StageLoader__) */
