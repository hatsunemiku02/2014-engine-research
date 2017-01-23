//
//  EngineShell.h
//  Catfish
//
//  Created by zhaohang on 14-4-15.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__EngineShell__
#define __Catfish__EngineShell__
#include "MikuRhythmStage.h"
#include "Rhythm.h"
#include "SubTitleLoader.h"
#include "SubTitle.h"
#include "GameApp.h"
namespace App
{
    
    class EngineShell
    {
    public:
        static EngineShell& GetInstance()
        {
            static EngineShell instance;
            return instance;
        }
        ~EngineShell()
        {
            
        }
        void InitEngine(int width ,int height,int cwidth ,int cheight,const char* basedir);
        
        void UpdateEngine();
        
        GameApp* GetGame()
        {
            return m_pGame;
        }
    protected:
        EngineShell()
        {
            
        }
        
        GameApp* m_pGame;
    };
}

#endif /* defined(__Catfish__EngineShell__) */
