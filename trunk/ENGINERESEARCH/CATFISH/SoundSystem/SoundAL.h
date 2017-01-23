//
//  Header.h
//  Catfish
//
//  Created by zh on 14-3-21.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_SoundAL_h
#define Catfish_SoundAL_h
#include "SoundDllCommon.h"
namespace SoundSys
{
    typedef unsigned int  ALuint;
    class SoundDecoderAL;
class SOUND_API SoundAL
{
public:
    SoundAL();
    ~SoundAL();
    
    void Play();
    void Pause();
    void Countinue();
    void Stop();
    void UpDate();
    
    SoundDecoderAL* GetDecoder()
    {
        return m_pDecoder;
    }
    void SetDecoder(SoundDecoderAL* de)
    {
        m_pDecoder = de;
    }
    
    void SetFormat(ALuint f)
    {
        m_Format = f;
    }
    
    void SetSingleBufferSize(unsigned long size)
    {
        m_BufferSize = size;
    }
    
    void SetFrenquency( unsigned long f)
    {
        m_Frenquency = f;
    }
    
    void PrepareBufferData()
    {
        m_pBufferData = new char[m_BufferSize];
    }
    
    void DestoryBufferData()
    {
        delete [] m_pBufferData;
    }
    void* GetBufferData()
    {
        return m_pBufferData;
    }
    void GenAL();
protected:
    
    SoundDecoderAL* m_pDecoder;
    ALuint m_Source;
    ALuint m_Buffer[4];
    
    
    ALuint m_Format;
    unsigned long m_BufferSize;
    unsigned long m_Frenquency;
    
    void* m_pBufferData;
    
    friend class SoundSystemAL;
    
    int  _bufferProcessed;
    bool m_bIsplaying;
};

}
#endif
