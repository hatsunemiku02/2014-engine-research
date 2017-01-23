//
//  BackGround.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-22.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "BackGround.h"
#include "Sprite2D.h"
namespace  MikuGame
{
	BackGround::BackGround()
	{

	}

	BackGround::~BackGround()
	{
        for(int i = 0;i<m_arrBGs.size();i++)
		{
			
            delete m_arrBGs[i].pSprite;			
		}
        m_arrBGs.clear();
	}

	void BackGround::AddBG(const BgPic& bg)
	{
		BgPic _bgpic = bg;
		_bgpic.pSprite = Sprite::Sprite2D::CreateSprite2D(_bgpic.PicPath,_bgpic.Position,_bgpic.Scale,0,2);
		m_arrBGs.push_back(_bgpic);
	}
    
    void BackGround::Stop()
    {
        for(int i = 0;i<m_arrBGs.size();i++)
		{
			m_arrBGs[i].pSprite->Hide();
		}
    }

	void BackGround::Update(double currentTime)
	{
		for(int i = 0;i<m_arrBGs.size();i++)
		{
			if(currentTime>m_arrBGs[i].StartTime&&currentTime<m_arrBGs[i].EndTime)
			{
				m_arrBGs[i].pSprite->Show();
			}
			else
			{
				m_arrBGs[i].pSprite->Hide();
			}
		}
	}

}