//
//  RhythmGame.h
//  Catfish
//
//  Created by zhaohang on 14-6-11.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__RhythmGame__
#define __Catfish__RhythmGame__
#include "Rhythm/SubTitle.h"
#include "MikuRhythmStage.h"
#include "GameState.h"
namespace  MikuGame
{
    class ScorePanel;
    class ControllPanel;
    struct Button;
    class RhythmGame:public App::GameState
    {
    public:
        RhythmGame()
        :m_bPaused(false)
        {
            m_State = App::GAME;
        }
        ~RhythmGame()
        {
            
        }
        void CreateGame(const std::string& title,const std::string& game);
        void ReleaseGame();
        MikuRhythmStage* GetGameStage()
        {
            return m_pGameStage;
        }
        
        ScorePanel* GetScorePanel()
        {
            return m_pScorePanel;
        }
        
        ControllPanel* GetControllPanel()
        {
            return m_pControllPanel;
        }

        
        virtual void Init();
        virtual void Update(double delta);
        virtual void Release();
        
        void Pause()
        {
            m_bPaused = true;
        }
        
        void Continue()
        {
            m_bPaused = false;
        }
      
    protected:
        SubTitleManager* m_pSubTitle;
        MikuRhythmStage* m_pGameStage;
        ScorePanel*      m_pScorePanel;
        ControllPanel*   m_pControllPanel;
        
        bool m_bPaused;
    };
}

#endif /* defined(__Catfish__RhythmGame__) */
