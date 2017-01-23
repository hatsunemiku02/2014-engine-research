//
//  SoundSystemAL.cpp
//  Catfish
//
//  Created by zh on 14-3-21.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "SoundSystemAL.h"
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include "FileReader.h"
#include "SoundDecoderAL.h"
#include "SoundAL.h"
#include "Sound.h"
namespace  SoundSys
{
    SoundSystemAL::~SoundSystemAL()
    {
        
    }

    SoundSystemAL::SoundSystemAL()
        :m_pALDevice(NULL)
        ,m_pALContext(NULL)
    {
        
    }
    void SoundSystemAL::UpDate()
    {
        for(int i = 0;i<m_vecSound.size();i++)
        {
            m_vecSound[i]->UpDate();
        }
    }

    bool SoundSystemAL::InitSoundSystem()
    {
        SoundDecoderAL::InitDecoder();
        m_pALDevice = alcOpenDevice(NULL);
        if(m_pALDevice)
        {
            m_pALContext = alcCreateContext(m_pALDevice, NULL);
            alcMakeContextCurrent(m_pALContext);
        }
        else
        {
            return false;
        }
        return true;
    }
    
    bool SoundSystemAL::DestorySoundSystem()
    {
        return false;
    }
    
    unsigned int  SoundSystemAL::GetEnumValue(const char* cenum)
    {
        return alGetEnumValue(cenum);
    }
    
    Sound* SoundSystemAL::CreateSound(const std::string& path)
    {
        SoundAL* pSound = new SoundAL();
        
        SoundDecoderAL* pDecoder = new SoundDecoderAL();
        IO::FileReader* reader = new IO::FileReader();
		reader->OpenFile(path.c_str());
		
        
        pDecoder->SetFile(reader);
		      
        long rate = 0;
        int channels = 0;
        int encoding = 0;
        pDecoder->GetInfo(rate, channels, encoding);
        
        ALuint format;
        unsigned long bsize;
        unsigned long frequency;
        if(channels==2)
        {
            format = alGetEnumValue("AL_FORMAT_STEREO16");
            bsize = rate;
            bsize -= (bsize%4);
            frequency = rate;
            pSound->SetFormat(format);
            pSound->SetSingleBufferSize(bsize);
            pSound->SetFrenquency(frequency);
            pSound->PrepareBufferData();
            pSound->SetDecoder(pDecoder);
            pSound->GenAL();
            m_vecSound.push_back((Sound*)pSound);
                     
        }
        else
        {
            return NULL;
        }
        
        return (Sound*)pSound;
    }
    
    bool SoundSystemAL::DestorySound(const std::string& path)
    {
        return false;
    }
}