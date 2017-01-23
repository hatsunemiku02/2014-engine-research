//
//  ControllPanel.h
//  Catfish
//
//  Created by zhaohang on 14-6-19.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__ControllPanel__
#define __Catfish__ControllPanel__

#include <vector>

namespace Sprite
{
    class Sprite2D;
    class Lable;
}



namespace  MikuGame
{
    
    class RhythmGame;
    
    struct Button;
    typedef void(*ButtonClickCallBack)(Button*)  ;

    struct Button
    {
        Button()
        :pButton(0)
        ,pCallBack(0)
        ,bEnable(true)
        {
            
        }
        void Update(double delta);
        
        bool bEnable;
        Sprite::Sprite2D* pButton;
        ButtonClickCallBack pCallBack;
    };
    
    class ControllPanel
    {
    public:
        ControllPanel();
        ~ControllPanel();
        
        void Init();
        
        void Start();
        void Update(double delta);
        void Stop();
    protected:
        
        void ShowBack(double delta);
        void HideBack(double delta);
        
        
        static void onPauseCallBack(Button* btn);
        static void onContinueCallBack(Button* btn);
        static void onExitCallBack(Button* btn);

    protected:
        
        Sprite::Sprite2D* pBackGround;
        Button m_btnContinue;
        Button m_btnExit;
        Button m_btnPause;
        
        std::vector<Button*> m_arrBtn;
        
        friend class RhythmGame;
    };
}

#endif /* defined(__Catfish__ControllPanel__) */
