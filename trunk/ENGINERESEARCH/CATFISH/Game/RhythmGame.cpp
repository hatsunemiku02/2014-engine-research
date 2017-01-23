//
//  RhythmGame.cpp
//  Catfish
//
//  Created by zhaohang on 14-6-11.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "RhythmGame.h"
#include "StageLoader.h"
#include "SubTitleLoader.h"
#include "ScorePanel.h"
#include "ControllPanel.h"

namespace  MikuGame
{
    void RhythmGame::CreateGame(const std::string& title,const std::string& game)
    {
        m_pGameStage =  MikuGame::StageLoader::GetInstance().CreateStage(title.c_str());
        m_pSubTitle = MikuGame::SubTitleLoader::GetInstance().CreateSubTitleManager(game.c_str());
        
        m_pScorePanel = new ScorePanel();
        m_pScorePanel->Init();
        
        m_pControllPanel = new ControllPanel();
        m_pControllPanel->Init();
    }
    
    void RhythmGame::ReleaseGame()
    {
        m_pGameStage->Stop();
        m_pSubTitle->Stop();
        m_pScorePanel->Stop();
        m_pControllPanel->Stop();
        delete m_pGameStage;
        delete m_pSubTitle;
        delete m_pScorePanel;
        delete m_pControllPanel;
    }
    
    void RhythmGame::Init()
    {
        m_pGameStage->Start();
        m_pSubTitle->Start();
        m_pScorePanel->Start();
        m_pControllPanel->Start();
    }
    
    void RhythmGame::Update(double delta)
    {
        m_pControllPanel->Update(delta);
        if(m_bPaused)
        {
            return;
        }
        m_pGameStage->Update(delta);
        m_pSubTitle->Update(delta);
        m_pScorePanel->Update(delta);
       
    }
    
    void RhythmGame::Release()
    {
        ReleaseGame();
    }
    
}
