//
//  PressRhythm.h
//  Catfish
//
//  Created by zhaohang on 14-4-17.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__PressRhythm__
#define __Catfish__PressRhythm__
#include "Rhythm.h"
namespace  MikuGame{
    
    class PressRhythm:public Rhythm
    {
    public:
        PressRhythm();
        ~PressRhythm();
        
        static Rhythm* CreatePressRhythm(const std::string& clickPath,const std::string& tipPath,const Math::vector2<int>& pos ,const Math::vector2<float>& scale,double before,double explode,double sexplode);
        
    protected:
        double m_SecondExplodeTime;
    };
}


#endif /* defined(__Catfish__PressRhythm__) */
