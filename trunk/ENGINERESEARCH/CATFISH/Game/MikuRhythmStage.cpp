//
//  MikuRhythm.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "MikuRhythmStage.h"
#include "EngineShell.h"

#include "Timer.h"
#include "Sound.h"
#include "SoundRes.h"
#include "ResMgr.h"
#include "BackGround.h"
#include "Sprite2D.h"
#include "RhythmGame.h"
#include "ScorePanel.h"

namespace  MikuGame
{
	void MikuRhythmStage::Start()
	{
		if(!m_bStarted)
		{
			m_CurrentTime = 0;
			m_pMusic->Play();
			m_bStarted = true;

		}
	}

	void MikuRhythmStage::SetMusic(const char* path)
	{
		m_pMusic = Resource::ResMgr::GetInstance().GetRes<Resource::SoundRes>(path)->GetSound();
	}
    
    void MikuRhythmStage::RhythmCallBack(Rhythm* rhy)
    {
        App::GameState* pState =  App::EngineShell::GetInstance().GetGame()->GetGameState();
        RhythmGame* pGame = (RhythmGame*)pState;
        pGame->GetScorePanel()->AddScore(rhy->m_Score,rhy->m_pClick->GetPosition());
    }
    
    void MikuRhythmStage::Pause()
    {
        m_pMusic->Pause();
    }
    
    void MikuRhythmStage::Continue()
    {
        m_pMusic->Countinue();
    }

    void MikuRhythmStage::Stop()
    {
        m_pMusic->Stop();
        m_pBackGround->Stop();
        for(int i=0;i<m_arrRhythm.size();i++)
		{
			m_arrRhythm[i]->Stop();
		}
    }
    
	void MikuRhythmStage::Update(double delta)
	{
		m_CurrentTime+=delta;

		for(int i=0;i<m_arrRhythm.size();i++)
		{
			m_arrRhythm[i]->Update(m_CurrentTime);
		}
        m_pBackGround->Update(m_CurrentTime);
	}

}
