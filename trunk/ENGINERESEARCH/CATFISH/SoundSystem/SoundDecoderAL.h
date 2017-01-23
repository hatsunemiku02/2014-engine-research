//
//  SoundDecoderAL.h
//  Catfish
//
//  Created by zh on 14-3-22.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef Catfish_SoundDecoderAL_h
#define Catfish_SoundDecoderAL_h

#include <list>
#include "SoundDllCommon.h"


typedef struct mpg123_handle_struct mpg123_handle;

namespace IO
{
    class FileReader;
}

namespace  SoundSys
{
    class Sound;
    class SOUND_API SoundDecoderAL
    {
    public:
        SoundDecoderAL();
        ~SoundDecoderAL();
        static void InitDecoder();
        void SetFile(IO::FileReader* reader);
        
        void GetInfo(long& rate,int& channels,int& encodeing);
        
        void Decode(void* outBuffer,unsigned int size,unsigned long& byteswritten );

        void Stop();
        
        void OnSettedToPlayer(Sound* pSound);
        void OnReleasePlayer(Sound* pSound);
    protected:
        mpg123_handle* m_pMpgHandle;
        unsigned int m_Size;
        IO::FileReader* m_File;
        
        std::list<Sound*> m_RefedSound;
    };
}

#endif
