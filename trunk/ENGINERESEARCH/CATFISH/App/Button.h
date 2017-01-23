//
//  Button.h
//  Catfish
//
//  Created by zhaohang on 14-5-19.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__Button__
#define __Catfish__Button__

namespace Sprite
{
	class Sprite2D;
    class Lable;
}

namespace App
{
    class Button;
    typedef void(*ButtonClick)(Button* btn);
    
    class Button
    {
    public:
        Button()
        {
            
        }
        ~Button()
        {
            
        }
        
        void SetSprite(Sprite::Sprite2D* sprite)
        {
            m_pSprite2D = sprite;
        }
        
        void SetCallBack(ButtonClick call)
        {
            m_CallBack = call;
        }
    protected:
        Sprite::Sprite2D*   m_pSprite2D;
        ButtonClick m_CallBack;
        
    };
    
}

#endif /* defined(__Catfish__Button__) */
