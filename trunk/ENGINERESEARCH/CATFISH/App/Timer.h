//
//  Timer.h
//  Catfish
//
//  Created by zhaohang on 14-4-15.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__Timer__
#define __Catfish__Timer__
namespace App
{
    
    class Timer
    {
    public:
        static Timer& GetInstance()
        {
            static Timer instance;
            return instance;
        }
        ~Timer()
        {
            
        }
        void Update();
        double GetDeltaTime();
    protected:
        Timer()
        :m_LastFrame(0.0)
        ,m_CurrentFrame(0.0)
        {
            
        }
        double m_LastFrame;
        double m_CurrentFrame;
    };
}



#endif /* defined(__Catfish__Timer__) */
