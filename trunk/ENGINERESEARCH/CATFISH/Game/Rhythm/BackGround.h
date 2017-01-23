//
//  BackGround.h
//  Catfish
//
//  Created by zhaohang on 14-4-22.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__BackGround__
#define __Catfish__BackGround__
#include <vector>
#include <string>
#include "../../Math/cmlmath.h"
namespace Sprite
{
	class Sprite2D;
}

namespace  MikuGame
{
    struct BgPic
    {
        double StartTime;
        double EndTime;
        Math::vector2<int> Position;
        Math::vector2<float> Scale;
        std::string PicPath;
        Sprite::Sprite2D* pSprite;
    };
    class BackGround
    {
    public:
        BackGround();
        ~BackGround();
        
        void AddBG(const BgPic& bg);
        
        void Update(double currentTime);
        
        void Stop();
        
    protected:
        std::vector<BgPic> m_arrBGs;
        
    };
    
    
    
}

#endif /* defined(__Catfish__BackGround__) */
