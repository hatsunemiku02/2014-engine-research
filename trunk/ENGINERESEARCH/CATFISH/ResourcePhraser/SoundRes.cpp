//
//  SoundRes.cpp
//  Catfish
//
//  Created by zh on 14-3-23.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "SoundRes.h"
#include "Sound.h"
#include "SoundDecoderAL.h"
#include "SoundSystem.h"
#include "FileReader.h"
namespace Resource
{
    SoundRes::SoundRes()
    {
        
    }
    SoundRes::~SoundRes()
    {
        
    }
    bool SoundRes::Load(const std::string& path)
    {
        
        SoundSys::SoundAL* pSound = new SoundSys::SoundAL();
        m_pSound = (SoundSys::Sound*)pSound;
        SoundSys::SoundDecoderAL* pDecoder = new SoundSys::SoundDecoderAL();
        IO::FileReader* reader = new IO::FileReader();
		reader->OpenFile(path.c_str());
        
        pDecoder->SetFile(reader);
        
        long rate = 0;
        int channels = 0;
        int encoding = 0;
        pDecoder->GetInfo(rate, channels, encoding);
        
        unsigned int format;
        unsigned long bsize;
        unsigned long frequency;
        if(channels==2)
        {
            format = SoundSys::SoundSystem::GetInstance().GetEnumValue("AL_FORMAT_STEREO16");
            bsize = rate;
            bsize -= (bsize%4);
            frequency = rate;
            pSound->SetFormat(format);
            pSound->SetSingleBufferSize(bsize);
            pSound->SetFrenquency(frequency);
            pSound->PrepareBufferData();
            pSound->SetDecoder(pDecoder);
            pSound->GenAL();
                      
            SoundSys::SoundSystem::GetInstance().AddSound((SoundSys::Sound*)pSound);
            
        }
        else
        {
            return false;
        }
        
        return true;
        
    }
    


}