//
//  GameApp.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "GameApp.h"
#include "GlesDevice.h"
#include "ResMgr.h"
#include "SoundSystem.h"
#include "Font.h"
#include "cavans.h"
#include "Timer.h"
#include "SimplePipeline.h"
#include "Input.h"
#include "StageLoader.h"
#include "Selector.h"
#include "Sprite2D.h"
#include "Lable.h"
#include "GameState.h"

namespace App
{

    GameApp::GameApp()
    {
        
    }
    GameApp::~GameApp()
    {
        
    }
    
    void GameApp::SwitchState(GameState* pState)
    {
        
    }
    
    void GameApp::Init()
    {
        /*
        MikuGame::ClickStart::GetInstance().SetPicAndLable(std::wstring(L"点击屏幕开始"),std::string("/Media/picglow.jpg"));
        MikuGame::ClickStart::GetInstance().Show();
        
        m_pGameStage =  MikuGame::StageLoader::GetInstance().CreateStage("/Media/fuck.txt");
        m_pSubTitleManager = MikuGame::SubTitleLoader::GetInstance().CreateSubTitleManager("/Media/st.txt");
        
        
        MikuGame::ShowButton button;
        button.pButton = Sprite::Sprite2D::CreateSprite2D("/Media/miku.png", Math::vector2<int>(-400,0), Math::vector2<float>(1.0f,1.0f), 0, 4);
        button.pShower = Sprite::Sprite2D::CreateSprite2D("/Media/TTB.png", Math::vector2<int>(400,0), Math::vector2<float>(1.0f,1.0f), 0, 4);
        button.pSketch = Sprite::Lable::CreateLable(L"GLOW", 128, 32, Math::vector2<int>(400,0), Math::vector2<float>(1.0f,1.0f), 0, 5);

        
        MikuGame::ShowButton button2;
        button2.pButton = Sprite::Sprite2D::CreateSprite2D("/Media/miku.png", Math::vector2<int>(-400,0), Math::vector2<float>(1.0f,1.0f), 0, 4);
        button2.pShower = Sprite::Sprite2D::CreateSprite2D("/Media/miku.png", Math::vector2<int>(400,0), Math::vector2<float>(1.0f,1.0f), 0, 4);
        button2.pSketch = Sprite::Lable::CreateLable(L"GLOW2", 128, 32, Math::vector2<int>(400,0), Math::vector2<float>(1.0f,1.0f), 0, 5);

        
        MikuGame::Selector::GetInstance().AddShowButton(button);
        MikuGame::Selector::GetInstance().AddShowButton(button2);

        MikuGame::Selector::GetInstance().SetBackGround(std::string("/Media/picglow.jpg"));
         */
        
    }
    
    void GameApp::Update()
    {
        /*
        MikuGame::ClickStart::GetInstance().Update(0.0f);
        
        if( MikuGame::ClickStart::GetInstance().GetClicked())
        {
            MikuGame::Selector::GetInstance().Start();
            MikuGame::Selector::GetInstance().Update(0.0f);
        }
        
        if(MikuGame::Selector::GetInstance().GetStarted()!=0)
        {
            m_pGameStage->Update(0);
            m_pSubTitleManager->UpDate(m_pGameStage->GetCurrentTime());
        }
        */
    }


}