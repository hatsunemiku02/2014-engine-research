//
//  Rhythm.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "Rhythm.h"
#include "Sprite2D.h"
#include "Lable.h"
#include "Input.h"
#include "Timer.h"
#include "GameApp.h"
#include "EngineShell.h"
#include <stdio.h>
#include <stdlib.h>

namespace  MikuGame{
	ShowScore::ShowScore()
		:m_pScoreSprite(NULL)
		,m_pScoreLable(NULL)
	{

	}

	ShowScore::~ShowScore()
	{
		if(m_pScoreLable)
		{
			delete m_pScoreLable;
            m_pScoreLable = NULL;
		}
		if(m_pScoreSprite)
		{
			delete m_pScoreSprite;
            m_pScoreSprite = NULL;
		}

	}

	void ShowScore::Show()
	{
		if(m_pScoreLable)
		{
			m_pScoreLable->Show();
		}
		if(m_pScoreSprite)
		{
			m_pScoreSprite->Show();
		}

	}
	void ShowScore::Hide()
	{
		if(m_pScoreLable)
		{
			m_pScoreLable->Hide();
		}
		if(m_pScoreSprite)
		{
			m_pScoreSprite->Hide();
		}

	}

	ShowScore* ShowScore::CreateShowScore(Score goal,int combo,const Math::vector2<int>& pos ,const Math::vector2<float>& scale,double lastTime)
	{

		std::string picPath;
		switch (goal)
		{
		case None:
			return NULL;
		case Cool:
			picPath = "/Media/miku.png";
			break;

		default:
			picPath = "/Media/miku.png";
			break;
		}
		ShowScore* score = new ShowScore();
		score->m_LastTime = lastTime;
		score->m_LiveTime = 0.0;
		if(combo>2)
		{
			std::wstring content = L"Combo:";
			wchar_t count[10];
			swprintf(count,10, L"%d", combo);
			content = content+count;
			score->m_pScoreLable = Sprite::Lable::CreateLable(content, 128, 32, pos, scale, 0, 6);
		}
		else
		{
			score->m_pScoreSprite = Sprite::Sprite2D::CreateSprite2D(picPath, pos, scale, 0.0f, 6);

		}

		return score;
	}

	void ShowScore::Update(double deltaTime)
	{
		m_LiveTime+=App::Timer::GetInstance().GetDeltaTime();
	}
    
 
    
	const int rythmsize = 128;

	Rhythm* Rhythm::CreateRhythm(const std::string& clickPath,const std::string& tipPath,const Math::vector2<int>& pos,const Math::vector2<float>& scale,double before,double explode,double last)
	{
		Rhythm* ret = new Rhythm();
		ret->m_pClick = Sprite::Sprite2D::CreateSprite2D(clickPath, pos, scale, 0.0f, 5);
		ret->m_pTip = Sprite::Sprite2D::CreateSprite2D(tipPath, pos, scale, 0.0f, 10);
		ret->m_Position = pos;
		ret->m_Scale = scale;
		ret->m_ExplodeTime = explode;
		ret->m_BeforeTime = before;
		ret->m_LastTime = last;

		return ret;
	}

	Score Rhythm::BeClicked(double time)
	{
		if(!m_Show)
		{
			return None;
		}
		std::list<App::ScreenTouch> touches = App::Input::GetInstance().GetTouches();
		if(touches.size()!=1)
		{
			return None;
		}
		else
		{
			std::list<App::ScreenTouch>::iterator begin = touches.begin();
			Math::vector2<int> pos(begin->TouchX,begin->TouchY);

			if(Math::IsInRect<int>(pos,rythmsize,m_Position))
			{
				
				m_Score  =this->TimeToScore(time);
                SetPlayed();
				
				return m_Score;
			}
			return None;
		}
	}

	Score Rhythm::TimeToScore(double time)
	{ 
		double lastTime = time - (m_ExplodeTime-m_BeforeTime);
		if(lastTime<-m_LastTime||time>m_ExplodeTime+m_LastTime)
		{
			return None;
		}
		else
		{
			double per = lastTime / m_BeforeTime;
			if(per>1.1f)
			{
				return Sad;
			}
			if(per>0.9f)
			{
				return Cool;
			}
			else if(per>0.7)
			{
				return Base;
			}
			else if(per>0.5)
			{
				return Sad;
			}
			else if(per>0.2)
			{
				return Bad;
			}

			else
			{
				return None;
			}
		}
	}

	void Rhythm::SetPlayed()
	{
		if(m_Show)
		{
			m_Played = true;
			m_pClick->Hide();
			m_pTip->Hide();
			m_Show = false;
            
            if(m_RhythmCallBack)
            {
                m_RhythmCallBack(this);
            }
		}
	}
    
    void Rhythm::Stop()
    {
        m_pClick->Hide();
        m_pTip->Hide();
    }

	void Rhythm::Update(double deltaTime)
	{
		if(m_Played)
		{
			return;
		}

		if(!m_Show&&!m_Played)
		{
			if(deltaTime>(m_ExplodeTime+m_LastTime-m_BeforeTime)&&deltaTime<m_ExplodeTime+m_LastTime)
			{
				m_pClick->Show();
				m_pTip->Show();
				m_Show = true;   
			}
			return;
		}

		if(m_Show&&!m_Played)
		{
			float timelast = deltaTime -(m_ExplodeTime-m_BeforeTime);
			float perscale = 2.0f- timelast/m_BeforeTime;
			m_pTip->SetScale(m_Scale*perscale);
			BeClicked(deltaTime);
			if(deltaTime>m_ExplodeTime+m_LastTime)
			{
                m_Score = Bad;
				SetPlayed();
			}
		}
	}

}