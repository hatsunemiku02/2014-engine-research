//
//  ClickToStart.h
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_ClickToStart_h
#define Catfish_ClickToStart_h
#include <string>
#include "GameState.h"
namespace Sprite
{
	class Sprite2D;
    class Lable;
}
namespace MikuGame {
    class MikuRhythmStage;
    typedef void(*OnClickStartCallBack)()  ;

    class ClickStart:public App::GameState
    {
    public:
        static ClickStart& GetInstance()
        {
            static ClickStart instance;
            return instance;
        }
        ~ClickStart();
        
        void SetPicAndLable(const std::wstring& tip,const std::string& pic);
        void Show();
        
        virtual void Init();
        virtual void Update(double delta);
        virtual void Release();
        
        bool GetClicked()
        {
            return m_pClicked;
        }
         void SetCallBack(OnClickStartCallBack call)
        {
            m_CallBack = call;
        }
    protected:
        ClickStart();
        
        Sprite::Sprite2D* m_pClickPic;
        Sprite::Lable* m_pLable;
        OnClickStartCallBack m_CallBack;
        bool m_pClicked;
    };
}

#endif
