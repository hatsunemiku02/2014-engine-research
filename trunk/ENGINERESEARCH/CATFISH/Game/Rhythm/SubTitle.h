//
//  SubTitle.h
//  Catfish
//
//  Created by zhaohang on 14-4-17.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__SubTitle__
#define __Catfish__SubTitle__
#include <string>
#include <vector>
#include "../../Math/cmlmath.h"
namespace Sprite
{
    class Lable;
}


namespace  MikuGame
{
    struct SubTitle
    {
        double StartTime;
        double EndTime;
        std::wstring Content;
    };
    
    class SubTitleManager
    {
    public:
        SubTitleManager();
        ~SubTitleManager();
        
        void AddSubTitle(const std::wstring& content ,double times,double timee  );
        void AddSubTitle(const SubTitle& st)
        {
            m_arrSubTitles.push_back(st);
        }
        void Start();
        void Update(double delta);
        void Stop();
    protected:
        void SetLable(const std::wstring& content);
        std::vector<SubTitle> m_arrSubTitles;
        int m_LastSubTitleIndex;
        Sprite::Lable* m_pLable;
        Math::vector2<int> m_Position;
        Math::vector2<int> m_Size;
        Math::vector2<float> m_Scale;
        double m_CurrentTime;
    };
    
    
}

#endif /* defined(__Catfish__SubTitle__) */
