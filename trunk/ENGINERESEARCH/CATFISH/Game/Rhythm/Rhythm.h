//
//  Rhythm.h
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__Rhythm__
#define __Catfish__Rhythm__
#include "../../Math/cmlmath.h"
#include <string>
namespace Sprite
{
	class Sprite2D;
    class Lable;
}
namespace  MikuGame{
    enum Score
    {
        None = 0,
        Cool,
        Base,
        Sad,
        Bad,
    };
    class MikuRhythmStage;
    class ShowScore
    {
    public:
        ShowScore();
        ~ShowScore();
        
        static ShowScore* CreateShowScore(Score goal,int comble,const Math::vector2<int>& pos ,const Math::vector2<float>& scale,double lastTime);
        virtual void Update(double deltaTime);
        void Show();
        void Hide();
        Sprite::Sprite2D* GetSprite()
        {
            return m_pScoreSprite;
        }
        const double GetLastTime() const
        {
            return m_LastTime;
        }
        
        const double GetLiveTime() const
        {
            return m_LiveTime;
        }

    protected:
        double m_LastTime;
        double m_LiveTime;
        Sprite::Sprite2D* m_pScoreSprite;
        Sprite::Lable*    m_pScoreLable;
    };
    
    class Rhythm;
    typedef void(*RhythmCallBack)(Rhythm*);
    
    class Rhythm
    {
    public:
        Rhythm()
            :m_Show(false)
            ,m_Played(false)
            ,m_RhythmCallBack(NULL)
            ,m_pTip(0)
            ,m_pClick(0)
            ,m_Score(None)
        {
            
        }
        ~Rhythm()
        {
            if(m_pClick)
            {
                delete m_pClick;
            }
            if(m_pTip)
            {
                delete m_pTip;
            }
        }
        static Rhythm* CreateRhythm(const std::string& clickPath,const std::string& tipPath,const Math::vector2<int>& pos ,const Math::vector2<float>& scale,double before,double explode,double last);
        
        void SetCallBack(RhythmCallBack call)
        {
            m_RhythmCallBack = call;
        }
        
        virtual void Update(double currentTime);
        
        void Stop();
    protected:
        
        
        void SetPlayed();
        virtual Score BeClicked(double time);
        virtual Score TimeToScore(double time);
        
        
        RhythmCallBack m_RhythmCallBack;
        
        Sprite::Sprite2D* m_pClick;
        Sprite::Sprite2D* m_pTip;
        Math::vector2<int> m_Position;
        Math::vector2<float> m_Scale;

        double m_ExplodeTime;
        double m_BeforeTime;
        double m_LastTime;
        bool m_Show;
        bool m_Played;
        Score m_Score;
        
        friend class MikuRhythmStage;
     };
}

#endif /* defined(__Catfish__Rhythm__) */
