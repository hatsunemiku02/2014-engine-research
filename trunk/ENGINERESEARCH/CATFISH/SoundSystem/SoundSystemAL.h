//
//  SoundSystemAL.h
//  Catfish
//
//  Created by zh on 14-3-21.
//  Copyright (c) 2014年 zh. All rights reserved.
//








#ifndef Catfish_SoundSystemAL_h
#define Catfish_SoundSystemAL_h
#include <string>
#include <vector>
#include "SoundDllCommon.h"
typedef struct ALCdevice_struct ALCdevice;
typedef struct ALCcontext_struct ALCcontext;
namespace  SoundSys
{
    class Sound;
class SOUND_API SoundSystemAL
{
public:
    static SoundSystemAL& GetInstance()
    {
        static SoundSystemAL instance;
        return instance;
    }
    ~SoundSystemAL();
    bool InitSoundSystem();
    bool DestorySoundSystem();
    Sound* CreateSound(const std::string& path);
    bool DestorySound(const std::string& path);
    void UpDate();
    
    
    unsigned int  GetEnumValue(const char* cenum);
    void AddSound(Sound* ps)
    {
        m_vecSound.push_back(ps);
    }
protected:
    SoundSystemAL();
    
    ALCdevice*   m_pALDevice;
    
    ALCcontext*  m_pALContext;
    
    std::vector<Sound*> m_vecSound;
};
}

#endif
