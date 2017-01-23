//
//  MikuGame.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "MikuGame.h"
#include "ClickToStart.h"
#include "Timer.h"
#include "Selector.h"
#include "Sprite2D.h"
#include "Lable.h"

#include "RhythmGame.h"
#include "EngineShell.h"


namespace MikuGame
{
    MikuGameApp::MikuGameApp()
    {
        
    }

    MikuGameApp::~MikuGameApp()
    {
        
    }
    
    void MikuGameApp::StartGame(ShowButton* pSB)
    {
        RhythmGame* pRg = new RhythmGame();
        pRg->CreateGame("/Media/fuck.txt","/Media/st.txt");
        
        App::EngineShell::GetInstance().GetGame()->SwitchState(pRg);
    }
    
    
    
    void MikuGameApp::ToSelector()
    {
        App::EngineShell::GetInstance().GetGame()->SwitchState( &MikuGame::Selector::GetInstance());
    }
    
    void MikuGameApp::SwitchState(App::GameState* pState)
    {
        if(m_pCurrentGame==pState)
        {
            return;
        }
        m_pCurrentGame->Release();
        pState->Init();
        App::State s = pState->GetState();
        m_pCurrentGame = pState;
        switch(s)
        {
            case App::CLICKTOSTART:
                break;
            case App::SELECTOR:
                break;
            case App::GAME:
                break;
            case App::SCOREBOARD:
                break;
        }
    }
    
    void MikuGameApp::Init()
    {
        //----------- init click to start ui--------------//
        m_pCurrentGame = &MikuGame::ClickStart::GetInstance();
        MikuGame::ClickStart::GetInstance().SetPicAndLable(std::wstring(L"点击屏幕开始"),std::string("/Media/picglow.jpg"));
        MikuGame::ClickStart::GetInstance().Show();
        MikuGame::ClickStart::GetInstance().SetCallBack(ToSelector);
        
        //----------- init selector ui ------------------//
        MikuGame::ShowButton button;
        button.pButton = Sprite::Sprite2D::CreateSprite2D("/Media/miku.png", Math::vector2<int>(-400,0), Math::vector2<float>(1.0f,1.0f), 0, 4);
        button.pShower = Sprite::Sprite2D::CreateSprite2D("/Media/TTB.png", Math::vector2<int>(400,0), Math::vector2<float>(1.0f,1.0f), 0, 4);
        button.pSketch = Sprite::Lable::CreateLable(L"GLOW", 128, 32, Math::vector2<int>(400,0), Math::vector2<float>(1.0f,1.0f), 0, 5);
        button.m_ShowButtonCallBack = StartGame;
        
        MikuGame::ShowButton button2;
        button2.pButton = Sprite::Sprite2D::CreateSprite2D("/Media/miku.png", Math::vector2<int>(-400,0), Math::vector2<float>(1.0f,1.0f), 0, 4);
        button2.pShower = Sprite::Sprite2D::CreateSprite2D("/Media/miku.png", Math::vector2<int>(400,0), Math::vector2<float>(1.0f,1.0f), 0, 4);
        button2.pSketch = Sprite::Lable::CreateLable(L"GLOW2", 128, 32, Math::vector2<int>(400,0), Math::vector2<float>(1.0f,1.0f), 0, 5);
        button2.m_ShowButtonCallBack = StartGame;
        
        MikuGame::Selector::GetInstance().AddShowButton(button);
        MikuGame::Selector::GetInstance().AddShowButton(button2);
        
        MikuGame::Selector::GetInstance().SetBackGround(std::string("/Media/picglow.jpg"));
        //--------- other ----------------------------//

    }
    
    void MikuGameApp::Update()
    {
        if(m_pCurrentGame!=NULL)
        {
            m_pCurrentGame->Update(App::Timer::GetInstance().GetDeltaTime());
        }
    }
    
    
    
    
}