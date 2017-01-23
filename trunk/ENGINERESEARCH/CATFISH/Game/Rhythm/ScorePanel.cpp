//
//  ScorePanel.cpp
//  Catfish
//
//  Created by zhaohang on 14-6-17.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "ScorePanel.h"
#include "Sprite2D.h"

namespace  MikuGame
{
    ScorePanel::ScorePanel()
    :m_pBackGround(0)
    ,m_pScoreBar(0)
    ,m_pStatueBar(0)
    ,m_pAddedScore(0)
    {
        
    }
    
    ScorePanel::~ScorePanel()
    {
        if(m_pBackGround)
        {
            delete m_pBackGround;
        }
        
        if(m_pScoreBar)
        {
            delete m_pScoreBar;
        }
        
        if(m_pStatueBar)
        {
            delete m_pStatueBar;
        }
        
        if(m_pAddedScore)
        {
            delete m_pAddedScore;
        }
        
        std::list<ShowScore*>::iterator itr =m_arrShowScore.begin();
		for(;itr!=m_arrShowScore.end();itr++)
		{
			ShowScore* pSC=(*itr);
			delete pSC;
        }
        m_arrShowScore.clear();
    }
    
    void ScorePanel::Init()
    {
        
        m_pStatueBar = Sprite::Sprite2D::CreateSprite2D("/Media/scorepanel/statu/sad.png",Math::vector2<int> (-1000,-750),Math::vector2<float>(1.0f,1.0f) , 0.0f, 8);
    }
    
    void ScorePanel::Start()
    {
        m_Statue = 50;
        m_Score = 0;
        m_Combo = 0;
        
        m_pStatueBar->Show();

    }

    
    void ScorePanel::AddScore(Score s,Math::vector2<int> pos)
    {
        if(s!=Bad)
		{
			m_Combo++;
		}
		else
		{
			m_Combo = 0;
		}
        UpdateTotleScore(s);
        UpdateStatue(s);
        CreateShowScore( s,pos,Math::vector2<float>(1.0f,1.0f),0.5);
    }
    
    void ScorePanel::Update(double deltaTime)
    {
        UpdateShowScore();
    }

    void ScorePanel::Stop()
    {
        m_pStatueBar->Hide();
        
        std::list<ShowScore*>::iterator itr =m_arrShowScore.begin();
		for(;itr!=m_arrShowScore.end();itr++)
		{
			ShowScore* pSC=(*itr);
			pSC->Hide();//HACK
        }
    }
    
    void ScorePanel::UpdateTotleScore(Score s)
    {
        m_Score += ScoreToTotleScore(s);
    }
    
    void ScorePanel::UpdateStatue(Score s)
    {
        m_Statue += ScoreToStatue(s);
        if (m_Statue<0)
        {
            m_Statue = 0;
        }
        if(m_Statue>100)
        {
            m_Statue = 100;
        }
        if(m_Statue>70)
        {
            m_pStatueBar->SetTexture("/Media/scorepanel/statu/happy.png");
        }
        else if(m_Statue>30)
        {
            m_pStatueBar->SetTexture("/Media/scorepanel/statu/normal.png");
        }
        else
        {
            m_pStatueBar->SetTexture("/Media/scorepanel/statu/sad.png");
        }

    }

    int ScorePanel::ScoreToTotleScore(Score s)
    {
        switch (s)
        {
            case Cool:
                return 100*m_Combo;
            case Base:
                return 100*m_Combo;
            case Sad:
                return 20;
            case Bad:
                return 0;
            default:
                return 0;
        }
    }
    
    int ScorePanel::ScoreToStatue(Score s)
    {
        switch (s)
        {
            case Cool:
                return 15;
            case Base:
                return 10;
            case Sad:
                return -10;
            case Bad:
                return -20;
            default:
                return 0;
        }
    }
    
    ShowScore* ScorePanel::CreateShowScore(Score goal,const Math::vector2<int>& pos ,const Math::vector2<float>& scale,double lastTime)
    {
        
		ShowScore* _pScore = ShowScore::CreateShowScore(goal,m_Combo,pos,scale,lastTime);
		if(_pScore)
		{
			_pScore->Show();
            m_arrShowScore.push_back((ShowScore*)_pScore);
		}
		return _pScore;
    }
    
    
    void ScorePanel::UpdateShowScore()
	{
		std::list<ShowScore*>::iterator itr =m_arrShowScore.begin();
		for(;itr!=m_arrShowScore.end();)
		{
			ShowScore* pSC=(*itr);
			pSC->Update(0.0);//HACK
			std::list<ShowScore*>::iterator cacheitr = itr;
			itr++;
            
			if(pSC->GetLiveTime()>=pSC->GetLastTime())
			{
				pSC->Hide();
                
				m_arrShowScore.erase(cacheitr);
				delete pSC;
			}
		}
	}

}