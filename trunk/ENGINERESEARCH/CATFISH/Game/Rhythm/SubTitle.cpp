//
//  SubTitle.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-17.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "SubTitle.h"
#include "Font.h"
#include "Lable.h"
namespace  MikuGame
{
	SubTitleManager::SubTitleManager()
		:m_LastSubTitleIndex(0)
		,m_pLable(NULL)
        ,m_CurrentTime(0.0f)
	{
		//Hack
		m_Position.m_x = 0;
		m_Position.m_y = -800;
		m_Scale.m_x = 2.0f;
		m_Scale.m_y = 2.0f;
		m_Size.m_x = 256;
		m_Size.m_y = 64;
	}
	SubTitleManager::~SubTitleManager()
	{
        if(m_pLable)
        {
            m_pLable->Hide();
            delete m_pLable;
        }
        
	}
	void SubTitleManager::SetLable(const std::wstring& content)
	{
		if(m_pLable==NULL)
		{
			m_pLable = Sprite::Lable::CreateLable(content, m_Size.m_x , m_Size.m_y,m_Position, m_Scale, 0.0f, 20);
			m_pLable->Show();
		}
		else
		{
			m_pLable->ChangeContent(content);
		}
	}
	void SubTitleManager::AddSubTitle(const std::wstring& content ,double times,double timee  )
	{
		SubTitle title;
		title.Content = content;
		title.StartTime = times;
		title.EndTime = timee;
		m_arrSubTitles.push_back(title);
	}
    
    void SubTitleManager::Start()
    {
        m_CurrentTime = 0.0;
    }


	void SubTitleManager::Update(double delta)
	{
        m_CurrentTime+=delta;
		if(m_LastSubTitleIndex>=m_arrSubTitles.size())
		{
			return;
		}

		if(m_arrSubTitles[m_LastSubTitleIndex].StartTime<=m_CurrentTime)
		{
			SetLable(m_arrSubTitles[m_LastSubTitleIndex].Content);
			m_LastSubTitleIndex++;
		}

		// SetLable(m_arrSubTitles[m_LastSubTitleIndex].Content);
	}
    void SubTitleManager::Stop()
    {
        m_pLable->Hide();
    }
}