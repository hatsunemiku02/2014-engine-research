//
//  ClickToStart.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "ClickToStart.h"
#include "cavans.h"
#include "Lable.h"
#include "Sprite2D.h"
#include "Texture.h"
#include "ImageRes.h"
#include "Input.h"
#include "../Math/cmlmath.h"
#include "MikuRhythmStage.h"

namespace MikuGame
{
    ClickStart::ClickStart()
    :m_pClicked(false)
    ,m_CallBack(NULL)
    {
        m_State = App::CLICKTOSTART;
    }
    
    ClickStart::~ClickStart()
    {
        
    }

    void ClickStart::SetPicAndLable(const std::wstring& tip,const std::string& pic)
    {
        m_pLable = Sprite::Lable::CreateLable(tip, 256, 32,Math::vector2<int>(0,-100), Math::vector2<float>(2.0f,2.0f), 0.0f, 5);
        
        m_pClickPic = Sprite::Sprite2D::CreateSprite2D(pic, Math::vector2<int>(0,0), Math::vector2<float>(1.0f,1.0f), 00.0f, 1);
    }
    
    void ClickStart::Show()
    {
       
        int width = m_pClickPic->GetTextureRes()->GetTexture()->GetWidth();
        int height = m_pClickPic->GetTextureRes()->GetTexture()->GetHeight();
        
        Math::vector2<int> _cavansSize = Sprite::Cavans::GetInstance().GetCavansSize();
        
        Math::vector2<float> _scale;
        _scale.m_x = (float)_cavansSize.m_x/(float)width;
        _scale.m_y = (float)_cavansSize.m_y/(float)height;
        m_pClickPic->SetScale(_scale);
        m_pClickPic->Show();
        m_pLable->Show();
    }
    
    void ClickStart::Init()
    {
        
    }
    
    void ClickStart::Update(double delta)
    {
        if(m_pClicked)
        {
            return;
        }
        std::list<App::ScreenTouch> touches = App::Input::GetInstance().GetTouches();
        if(touches.size()!=0)
        {
            m_pClicked = true;
            if(m_CallBack)
            {
                m_CallBack();
            }
        }
    }
    
    void ClickStart::Release()
    {
        m_pClickPic->Hide();
        m_pLable->Hide();
    }
}