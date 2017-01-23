//
//  Timer.cpp
//  Catfish
//
//  Created by zhaohang on 14-4-15.
//  Copyright (c) 2014年 zh. All rights reserved.
//
#include <sys/time.h>
#include "Timer.h"
namespace App
{
    void Timer::Update()
    {
        m_LastFrame = m_CurrentFrame;
        struct timeval _time;
        gettimeofday(&_time, NULL);
        m_CurrentFrame = (double)_time.tv_sec+(double)_time.tv_usec/1000000.00000;
    }
    
    double Timer::GetDeltaTime()
    {
        if(m_LastFrame==0.0)
        {
            return 0.0;
        }
        else
        {
            return m_CurrentFrame-m_LastFrame;
        }
    }
}