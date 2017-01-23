//
//  Selector.h
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__Selector__
#define __Catfish__Selector__
#include <vector>
#include <string>
#include "../Math/cmlmath.h"
#include "GameState.h"

namespace Sprite
{
    class Sprite2D;
    class Lable;
}

namespace  MikuGame{
    
    struct ShowButton;
    typedef void(*ShowButtonCallBack)(ShowButton*)  ;
    struct ShowButton
    {
    public:
        ShowButton()
        :pButton(0)
        ,pShower(0)
        ,pSketch(0)
        ,m_ID(0)
        ,m_ShowButtonCallBack(0)
        {
            
        }
        void OnShowButtonPressed()
        {
            if(m_ShowButtonCallBack)
            {
                m_ShowButtonCallBack(this);
            }
        }
        Sprite::Sprite2D* pButton;
        Sprite::Sprite2D* pShower;
        Sprite::Lable*    pSketch;
        int               m_ID;//ID
        ShowButtonCallBack m_ShowButtonCallBack;
        
    };
    
    class Selector:public App::GameState
    {
    public:
        static Selector& GetInstance()
        {
            static Selector instance;
            return instance;
        }
        ~Selector();
        
        virtual void Init();
        virtual void Update(double delta);
        virtual void Release();
        
        void Start();
        void Hide();
        void AddShowButton(const ShowButton& button);
        void SetBackGround(const std::string& path);
    protected:
        
        Selector();
 
        void MoveUp();
        void MoveDown();
        Sprite::Sprite2D* m_pBackGround;
       
        std::vector<ShowButton> m_arrMenu;
        int m_ShowIndex;
        bool m_bStart;
        bool m_bGameStarted;
        
        Math::vector2<int> m_StartDragPos;
    };
}


#endif /* defined(__Catfish__Selector__) */
