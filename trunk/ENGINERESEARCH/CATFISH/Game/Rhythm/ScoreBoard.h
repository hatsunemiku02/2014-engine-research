//
//  ScoreBoard.h
//  Catfish
//
//  Created by zhaohang on 14-4-17.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__ScoreBoard__
#define __Catfish__ScoreBoard__
#include "GameState.h"

namespace Sprite
{
    class Sprite2D;
    class Lable;
}

namespace  MikuGame
{
    class ScoreBoard:public App::GameState
    {
    public:
        ScoreBoard();
        ~ScoreBoard();
        
        
        void SetPropities(int coolCount,int baseCount,int sadCount,int badCount,int totalScore);
        virtual void Init();
        virtual void Update(double delta);
        virtual void Release();
        
    protected:
        
        void Show();
        void Hide();
        
        Sprite::Sprite2D* m_pBackGround;
        Sprite::Sprite2D* m_pScoreBar;
        Sprite::Sprite2D* m_pStatueBar;
        Sprite::Lable*    m_pAddedScore;
        
        int m_CoolCount;
        int m_BaseCount;
        int m_SadCount;
        int m_BadCount;
        int m_TotalCount;
    };
}

#endif /* defined(__Catfish__ScoreBoard__) */
