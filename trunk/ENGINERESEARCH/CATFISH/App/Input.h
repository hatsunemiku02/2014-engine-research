//
//  Input.h
//  Catfish
//
//  Created by zhaohang on 14-4-15.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__Input__
#define __Catfish__Input__
#include <list>
namespace App
{
    enum TouchState
    {
        Down,
        Pressed,
        Up,
    };
    struct ScreenTouch
    {
        int TouchX;
        int TouchY;
        TouchState State;
    };
    
    class Input
    {
    public:
        static Input& GetInstance()
        {
            static Input instance;
            return instance;
        }
        ~Input()
        {
            
        }
        
        void Clear()
        {
            m_arrScreenTouch.clear();
        }
        void AddInput(const ScreenTouch& touch)
        {
            m_arrScreenTouch.push_back(touch);
            ConverToMiddle();
        }
        
        const std::list<ScreenTouch>& GetTouches() const
        {
            
            return m_arrScreenTouch;
        }
        
    protected:
        void ConverToMiddle();
        
        Input()
        {
            
        }
        std::list<ScreenTouch> m_arrScreenTouch;
    };
}
#endif /* defined(__Catfish__Input__) */
