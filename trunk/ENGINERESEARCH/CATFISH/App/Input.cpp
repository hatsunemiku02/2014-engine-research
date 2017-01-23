//
//  Input.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-15.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "Input.h"
#include "GlesDevice.h"
#include "cavans.h"
namespace App
{
    void Input::ConverToMiddle()
    {
        Math::vector2<int> _screenSize = GraphicCore::GlesDevice::GetInstance().GetScreenSize();
        Math::vector2<int> _cavansSize = Sprite::Cavans::GetInstance().GetCavansSize();
        
        std::list<ScreenTouch>::iterator itr = m_arrScreenTouch.begin();
        for(;itr!= m_arrScreenTouch.end();itr++)
        {
            itr->TouchX = itr->TouchX- (_screenSize.m_x/2);
            itr->TouchY = (_screenSize.m_y-itr->TouchY)- (_screenSize.m_y/2);
            
            itr->TouchX = (float)itr->TouchX* ((float)_cavansSize.m_x/(float)_screenSize.m_x)*2.0;
            itr->TouchY = (float)itr->TouchY* ((float)_cavansSize.m_y/(float)_screenSize.m_y)*2.0;
        }

    }

}