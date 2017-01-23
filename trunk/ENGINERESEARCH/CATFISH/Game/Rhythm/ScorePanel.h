//
//  ScorePanel.h
//  Catfish
//
//  Created by zhaohang on 14-6-17.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__ScorePanel__
#define __Catfish__ScorePanel__

#include <list>
#include "vector2.h"
#include "Rhythm.h"
//enum Score
//{
//    None = 0,
//    Cool, 15
//    Base, 10
//    Sad,  0
//    bad,  -10
//};
// statue 0 - 100
//enum Score
//{
//    None = 0,
//    Cool, 15
//    Base, 10
//    Sad,  0
//    bad,  -10
//};
//
//

namespace Sprite
{
    class Sprite2D;
    class Lable;
}

namespace  MikuGame
{
    class ShowScore;
    class ScorePanel
    {
        
    public:
        ScorePanel();
        ~ScorePanel();
        
        void Init();
        
        void Start();
        void AddScore(Score s,Math::vector2<int> pos);
        void Update(double deltaTime);
        void Stop();
    protected:
        
        
        Sprite::Sprite2D* m_pBackGround;
        Sprite::Sprite2D* m_pScoreBar;
        Sprite::Sprite2D* m_pStatueBar;
        Sprite::Lable*    m_pAddedScore;
        std::list<ShowScore*> m_arrShowScore;
        
        int m_Statue;
        int m_Score;
        int m_Combo;
        
    protected:
        void UpdateShowScore();
        ShowScore* CreateShowScore(Score goal,const Math::vector2<int>& pos ,const Math::vector2<float>& scale,double lastTime);
        
        void UpdateTotleScore(Score s);
        void UpdateStatue(Score s);
        
        int ScoreToTotleScore(Score s);
        int ScoreToStatue(Score s);

    };
}

#endif /* defined(__Catfish__ScorePanel__) */
