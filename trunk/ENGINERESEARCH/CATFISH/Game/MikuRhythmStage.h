//
//  MikuRhythm.h
//  Catfish
//
//  Created by zhaohang on 14-4-14.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__MikuRhythm__
#define __Catfish__MikuRhythm__
#include <vector>
#include <list>
#include "Rhythm.h"


namespace SoundSys
{
    class Sound;
}
namespace  MikuGame{

    typedef void(*OnRhythmGameEndCallBack)();
    
    class Rhythm;
    class BackGround;
    class ShowScore;
    class MikuRhythmStage
    {
    public:
        MikuRhythmStage()
        :m_bStarted(false)
        ,m_pMusic(NULL)
        ,m_pBackGround(NULL)
        {
            
        }
        ~MikuRhythmStage()
        {
                     
            if(m_pBackGround)
            {
                delete m_pBackGround;
                m_pBackGround = NULL;
            }
            
            for(int i=m_arrRhythm.size()-1;i>=0;i--)
            {
                delete m_arrRhythm[i];
            }
            m_arrRhythm.clear();
            
        }
        
        void AddRhythm( Rhythm* r)
        {
            r->SetCallBack(RhythmCallBack);
            m_arrRhythm.push_back((Rhythm*)r);
        } 
        
        void SetMusic(const char* path);
 
        void SetBackGround(const BackGround* pbg)
        {
            m_pBackGround = (BackGround*)pbg;
        }
        
        void Start();
        
        void Pause();
        
        void Continue();
        
        void Stop();
        
        void Update(double delta);
        
        double GetCurrentTime()
        {
            return m_CurrentTime;
        }
    protected:
        
        static void RhythmCallBack(Rhythm* rhy);
        
        SoundSys::Sound* m_pMusic;
        BackGround* m_pBackGround;
        std::vector<Rhythm*>  m_arrRhythm;
        std::list<ShowScore*> m_arrShowScore;

        double m_CurrentTime;
        bool m_bStarted;
    };
}

#endif /* defined(__Catfish__MikuRhythm__) */
