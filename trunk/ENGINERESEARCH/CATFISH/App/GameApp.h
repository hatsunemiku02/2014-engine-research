//
//  GameApp.h
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_GameApp_h
#define Catfish_GameApp_h
#include "SubTitle.h"
#include "MikuRhythmStage.h"
#include "Rhythm.h"
#include "SubTitleLoader.h"
#include "SubTitle.h"
#include "ClickToStart.h"

namespace App
{

    class GameState;
    class GameApp
    {
    public:
        GameApp();
        ~GameApp();
        virtual void Init();
        virtual void Update();
        
        GameState* GetGameState()
        {
            return m_pCurrentGame;
        }
        virtual void SwitchState(GameState* pState);
    protected:
     
        GameState* m_pCurrentGame;

        
        MikuGame::MikuRhythmStage* m_pGameStage;
        MikuGame::SubTitleManager* m_pSubTitleManager;

    };
}
#endif
