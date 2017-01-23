//
//  SoundAL.cpp
//  Catfish
//
//  Created by zh on 14-3-21.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "SoundAL.h"
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include "SoundDecoderAL.h"
namespace SoundSys
{
    static const int numberOfBuffers = 4;
    SoundAL::SoundAL()
    :m_bIsplaying(false)
    {
        
    }
    SoundAL::~SoundAL()
    {
        
    }
    
    void SoundAL::GenAL()
    {
        alGenSources(1, &m_Source);
        alSourcei(m_Source,AL_LOOPING,AL_FALSE);
        alSourcef(m_Source,AL_SOURCE_TYPE,AL_STREAMING);
        
        alGenBuffers(numberOfBuffers, m_Buffer);
        unsigned long byteswritten = 0;

        for(int i=0;i<4;i++)
        {
            m_pDecoder->Decode(m_pBufferData, m_BufferSize, byteswritten);
            alBufferData(m_Buffer[i], m_Format, m_pBufferData, byteswritten, m_Frenquency);
            alSourceQueueBuffers(m_Source, 1, &m_Buffer[i]);
        }
     
    }
    
    void SoundAL::Play()
    {
        //alSourceRewind(m_Source);
        alSourcePlay(m_Source);
        _bufferProcessed = 0;
        m_bIsplaying = true;
    }
    
    void SoundAL::Pause()
    {
        m_bIsplaying = false;
        alSourcePause(m_Source);
    }
    
    void SoundAL::Countinue()
    {
        m_bIsplaying = true;
        alSourcePlay(m_Source);
    }
    
    void SoundAL::Stop()
    {
        m_bIsplaying = false;
        alSourceStop(m_Source);
        
        m_pDecoder->Stop();
    }
    
    void SoundAL::UpDate()
    {
        if(m_bIsplaying==false)
        {
            return;
        }
        int bufferalreayprocessed = 0;
        alGetSourcei(m_Source, AL_BUFFERS_PROCESSED,&bufferalreayprocessed);
        _bufferProcessed+=bufferalreayprocessed;
        while (bufferalreayprocessed) {
            ALuint __buffer = 0;
            unsigned long byteswritten = 0;
            alSourceUnqueueBuffers(m_Source, 1, &__buffer);
            
            m_pDecoder->Decode(m_pBufferData, m_BufferSize, byteswritten);
            if(byteswritten)
            {
                alBufferData(__buffer, m_Format, m_pBufferData, byteswritten, m_Frenquency);
                alSourceQueueBuffers(m_Source, 1, &__buffer);
                bufferalreayprocessed--;
            }
        }
        ALint value;
        alGetSourcei(m_Source, AL_SOURCE_STATE, &value);
        if(value!=AL_PLAYING)
        {
            int bufferleft;
            alGetSourcei(m_Source,AL_BUFFERS_QUEUED,&bufferleft);
            if(bufferleft)
            {
                alSourcePlay(m_Source);
            }
        }
    }

}