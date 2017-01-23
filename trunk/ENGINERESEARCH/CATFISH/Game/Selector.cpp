//
//  Selector.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "Selector.h"
#include "Input.h"
#include "Sprite2D.h"
#include "Lable.h"
#include "ImageRes.h"
#include "Texture.h"
#include "cavans.h"
#include <math.h>

namespace  MikuGame
{
    static const int menustep = 150;
    Selector::Selector()
    :m_ShowIndex(0)
    ,m_pBackGround(NULL)
    ,m_bStart(false)
    ,m_bGameStarted(false)
    {
        m_State = App::SELECTOR;
    }
    
    Selector::~Selector()
    {
        if(m_pBackGround)
        {
            delete m_pBackGround;
            m_pBackGround = NULL;
        }
    }
    
    void Selector::SetBackGround(const std::string& path)
    {
        m_pBackGround= Sprite::Sprite2D::CreateSprite2D(path, Math::vector2<int>(0,0), Math::vector2<float>(1.0f,1.0f), 0.0f, 1);
        
        int width = m_pBackGround->GetTextureRes()->GetTexture()->GetWidth();
        int height = m_pBackGround->GetTextureRes()->GetTexture()->GetHeight();
        
        Math::vector2<int> _cavansSize = Sprite::Cavans::GetInstance().GetCavansSize();
        
        Math::vector2<float> _scale;
        _scale.m_x = (float)_cavansSize.m_x/(float)width;
        _scale.m_y = (float)_cavansSize.m_y/(float)height;
        m_pBackGround->SetScale(_scale);

    }
    
    void Selector::Start()
    {
        if(!m_bStart)
        {
            m_bStart = true;
            
            m_pBackGround->Show();
            
            m_arrMenu[m_ShowIndex].pShower->Show();
            m_arrMenu[m_ShowIndex].pSketch->Show();
            for(int i=0;i<m_arrMenu.size();i++)
            {
                m_arrMenu[i].pButton->Show();
            }
        }
        
    }
    
    void Selector::Init()
    {
        Start();
    }
    
    void Selector::Update(double delta)
    {
        if(!m_bStart)
        {
            return;
        }
        std::list<App::ScreenTouch> touches = App::Input::GetInstance().GetTouches();
        
        std::list<App::ScreenTouch>::iterator itr = touches.begin();
        std::list<App::ScreenTouch>::iterator downitr = touches.end();
        std::list<App::ScreenTouch>::iterator upitr = touches.end();
        
        int size = m_arrMenu[m_ShowIndex].pShower->GetTextureRes()->GetTexture()->GetWidth();
        Math::vector2<int> center = m_arrMenu[m_ShowIndex].pShower->GetPosition();
        
        int _countd = 0;
        int _countu = 0;
        for(;itr!=touches.end();itr++)
        {
            if((*itr).State==App::Down)
            {
                _countd++;
                downitr = itr;
            }
        }
        itr = touches.begin();
        for(;itr!=touches.end();itr++)
        {
            if((*itr).State==App::Up)
            {
                _countu++;
                upitr = itr;
            }
        }
        
        if(_countu!=1 && _countd!=1)
        {
            return;
        }
      
        if(downitr!=touches.end()&&Math::IsInRect<int>(Math::vector2<int>((*downitr).TouchX,(*downitr).TouchY), size, center))
        {
            //StartGame(1);
            m_arrMenu[m_ShowIndex].OnShowButtonPressed();
        }
        else if(downitr!=touches.end())
        {
            m_StartDragPos.m_x =(*downitr).TouchX;
            m_StartDragPos.m_y =(*downitr).TouchY;
        }
        else if(upitr!=touches.end())
        {
            int xoffest = m_StartDragPos.m_x-(*upitr).TouchX;
            int yoffest = m_StartDragPos.m_y-(*upitr).TouchY;
            if(fabs((float)xoffest)>fabs((float)yoffest))
            {
                return;
            }
            if(yoffest<-50)
            {
                MoveUp();
            }
            else if(yoffest>50)
            {
                MoveDown();
            }
        }
        return;
    }

    void Selector::Release()
    {
        Hide();
    }
    
    void Selector::Hide()
    {
        if(m_bStart)
        {
            m_arrMenu[m_ShowIndex].pShower->Hide();
            m_arrMenu[m_ShowIndex].pSketch->Hide();
            for(int i=0;i<m_arrMenu.size();i++)
            {
                m_arrMenu[i].pButton->Hide();
            }

            m_pBackGround->Hide();
            m_bStart = false;
        }
    }
    
    void Selector::AddShowButton(const ShowButton& button)
    {
         Math::vector2<int> _pos=button.pButton->GetPosition();
        _pos.m_y = m_arrMenu.size()*menustep;
        button.pButton->SetPosition(_pos);
        m_arrMenu.push_back(button);
    }
    
    
    void Selector::MoveUp()
    {
        std::list<App::ScreenTouch> touches = App::Input::GetInstance().GetTouches();
        
        if(m_ShowIndex==0)
        {
            return;
        }
        Math::vector2<int> _lastpos = m_arrMenu[m_ShowIndex-1].pButton->GetPosition();
        int _movedis = 0 - _lastpos.m_y;
        m_arrMenu[m_ShowIndex].pShower->Hide();
        m_arrMenu[m_ShowIndex].pSketch->Hide();
        m_ShowIndex-=1;
        m_arrMenu[m_ShowIndex].pShower->Show();
        m_arrMenu[m_ShowIndex].pSketch->Show();

        for(int i=0;i<m_arrMenu.size();i++)
        {
            Math::vector2<int> pos =  m_arrMenu[i].pButton->GetPosition();
            pos.m_y+=_movedis;
            m_arrMenu[i].pButton->SetPosition(pos);
        }
    }
    
    void Selector::MoveDown()
    {
        if(m_ShowIndex==(m_arrMenu.size()-1))
        {
            return;
        }
        Math::vector2<int> _nextpos = m_arrMenu[m_ShowIndex+1].pButton->GetPosition();
        int _movedis = 0 - _nextpos.m_y;
        m_arrMenu[m_ShowIndex].pShower->Hide();
        m_arrMenu[m_ShowIndex].pSketch->Hide();
        m_ShowIndex+=1;
        m_arrMenu[m_ShowIndex].pShower->Show();
        m_arrMenu[m_ShowIndex].pSketch->Show();
        
        
        for(int i=0;i<m_arrMenu.size();i++)
        {
            Math::vector2<int> pos =  m_arrMenu[i].pButton->GetPosition();
            pos.m_y+=_movedis;
            m_arrMenu[i].pButton->SetPosition(pos);
        }

    }
}