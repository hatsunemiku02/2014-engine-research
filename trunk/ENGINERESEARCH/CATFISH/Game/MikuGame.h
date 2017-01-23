//
//  MikuGame.h
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__MikuGame__
#define __Catfish__MikuGame__
#include "GameApp.h"
#include "GameState.h"
namespace MikuGame
{

    struct ShowButton;
    class MikuGameApp:public App::GameApp
    {
    public:
        MikuGameApp();
        ~MikuGameApp();
        
        virtual void Init();//INIT AS AN CLICKTOSTART AND LOAD 
        virtual void Update();
        void SwitchState(App::GameState* pState);

    protected:
        
        
        static void StartGame(ShowButton*);
        static void ToSelector();
        static void ToScoreBoard();
        
    };
}

#endif /* defined(__Catfish__MikuGame__) */
