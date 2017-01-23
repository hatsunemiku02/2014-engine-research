//
//  ControllPanel.cpp
//  Catfish
//
//  Created by zhaohang on 14-6-19.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "ControllPanel.h"
#include "Sprite2D.h"
#include "Math.h"
#include "Input.h"
#include "RhythmGame.h"
#include "EngineShell.h"
#include "Selector.h"
#include <list>


namespace  MikuGame
{
    void Button::Update(double delta)
    {
        if(pButton==NULL||pCallBack==NULL||!bEnable)
        {
            return;
        }
        std::list<App::ScreenTouch> touches = App::Input::GetInstance().GetTouches();
		if(touches.size()!=1)
		{
			return ;
		}
		else
		{
			std::list<App::ScreenTouch>::iterator begin = touches.begin();
			Math::vector2<int> pos(begin->TouchX,begin->TouchY);
            
			if(Math::IsInRect<int>(pos,128,pButton->GetPosition()))
			{
                pCallBack(this);
            }
        }
				
    }

    ControllPanel::ControllPanel()
    {
        
    }
    
    ControllPanel::~ControllPanel()
    {
        
    }

    
    void ControllPanel::onPauseCallBack(Button* btn)
    {
        App::GameState* pState =  App::EngineShell::GetInstance().GetGame()->GetGameState();
        RhythmGame* pGame = (RhythmGame*)pState;
        pGame->Pause();
        pGame->GetControllPanel()->ShowBack(0.0);
        pGame->GetGameStage()->Pause();
    }
    
    void ControllPanel::onContinueCallBack(Button* btn)
    {
        App::GameState* pState =  App::EngineShell::GetInstance().GetGame()->GetGameState();
        RhythmGame* pGame = (RhythmGame*)pState;
        pGame->Continue();
        pGame->GetControllPanel()->HideBack(0.0);
        pGame->GetGameStage()->Continue();
    }
    
    void ControllPanel::onExitCallBack(Button* btn)
    {
         App::EngineShell::GetInstance().GetGame()->SwitchState( &MikuGame::Selector::GetInstance());
    }

    void ControllPanel::Init()
    {
        m_btnPause.pButton = Sprite::Sprite2D::CreateSprite2D("/Media/controllpanel/pause.png",Math::vector2<int> (1000,800),Math::vector2<float>(1.0f,1.0f) , 0.0f, 35);
        m_btnPause.pCallBack = onPauseCallBack;
        m_btnContinue.pButton = Sprite::Sprite2D::CreateSprite2D("/Media/controllpanel/btnc.png",Math::vector2<int> (0,100),Math::vector2<float>(1.0f,1.0f) , 0.0f, 35);
        m_btnContinue.pCallBack = onContinueCallBack;
        m_btnExit.pButton = Sprite::Sprite2D::CreateSprite2D("/Media/controllpanel/btne.png",Math::vector2<int> (0,-100),Math::vector2<float>(1.0f,1.0f) , 0.0f, 35);
        m_btnExit.pCallBack = onExitCallBack;
        pBackGround =Sprite::Sprite2D::CreateSprite2D("/Media/controllpanel/controllback.png",Math::vector2<int> (0,0),Math::vector2<float>(1.0f,1.0f) , 0.0f, 30);

        m_arrBtn.push_back(&m_btnPause);
    }
    
    void ControllPanel::Update(double delta)
    {
        for(int i = 0;i<m_arrBtn.size();i++)
        {
            m_arrBtn[i]->Update(delta);
        }
    }
    
    void ControllPanel::Start()
    {
        m_btnPause.pButton->Show();
    }
    
    void ControllPanel::Stop()
    {
        m_arrBtn.clear();

        pBackGround->Hide();
        m_btnContinue.pButton->Hide();
        m_btnExit.pButton->Hide();
        m_btnPause.pButton->Hide();
    }
    
    void ControllPanel::ShowBack(double delta)
    {
        m_btnPause.bEnable = false;
        m_arrBtn.push_back(&m_btnExit);
        m_arrBtn.push_back(&m_btnContinue);
        pBackGround->Show();
        m_btnExit.pButton->Show();
        m_btnContinue.pButton->Show();
    }
    
    void ControllPanel::HideBack(double delta)
    {
        m_arrBtn.clear();
        m_arrBtn.push_back(&m_btnPause);
        pBackGround->Hide();
        m_btnExit.pButton->Hide();
        m_btnContinue.pButton->Hide();
        m_btnPause.bEnable = true;

    }
    
    


}