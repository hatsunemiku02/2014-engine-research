//
//  SoundRes.h
//  Catfish
//
//  Created by zh on 14-3-23.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_SoundRes_h
#define Catfish_SoundRes_h
#include "Res.h"
namespace SoundSys
{
    class Sound;
}


namespace Resource {
    class RES_API SoundRes:public Res
    {
    public:
        SoundRes();
        ~SoundRes();
        
        SoundSys::Sound* GetSound()
        {
            return m_pSound;
        }
    protected:
        virtual bool Load(const std::string& path);
        
        SoundSys::Sound* m_pSound;
        friend class ResMgr;
    };
}


#endif
