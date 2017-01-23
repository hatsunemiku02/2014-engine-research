//
//  SoundDecoderAL.cpp
//  Catfish
//
//  Created by zh on 14-3-22.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "SoundDecoderAL.h"
#if __IOS__
#include "../../mpg123/ports/Xcode/mpg123.h"
#else
#include "../../mpg123/ports/MSVC++/mpg123.h"
#endif
#include <OpenAL/al.h>

#include "FileReader.h"

namespace  SoundSys
{
    
    ssize_t mp3fileread(void* handle,void* buf,size_t sz)
    {
        IO::FileReader* pReader = (IO::FileReader*)handle;
        
        return pReader->Read(sz, buf);
    }
    
    off_t mp3fileseek(void* handle,off_t offset,int whence)
    {
        IO::FileReader* pReader = (IO::FileReader*)handle;
        pReader->Seek((int)offset, whence);
        
        return pReader->GetPos();
    }
    
    void mp3cleanup(void* handle)
    {
        
    }

    
    
    SoundDecoderAL::SoundDecoderAL()
        :m_pMpgHandle(NULL)
        ,m_RefedSound()
    {
        
    }
    
    SoundDecoderAL::~SoundDecoderAL()
    {
        
    }
    
    void SoundDecoderAL::OnSettedToPlayer(Sound* pSound)
    {
        
    }
    
    void SoundDecoderAL::OnReleasePlayer(Sound* pSound)
    {
        
    }
    
    void SoundDecoderAL::InitDecoder()
    {
        if(MPG123_OK!= mpg123_init())
        {
              
        }
    
    }
    
    void SoundDecoderAL::SetFile(IO::FileReader* reader)
    {
        m_File = reader;
    }

    void SoundDecoderAL::GetInfo( long& rate,int& channels,int& encodeing)
    {
        if(m_pMpgHandle==NULL)
        {
            int error = 0;
            m_pMpgHandle = mpg123_new(mpg123_decoders()[0],&error);
            
            mpg123_replace_reader_handle(m_pMpgHandle, mp3fileread, mp3fileseek, mp3cleanup);
            mpg123_open_handle(m_pMpgHandle,m_File);
            
        }
        mpg123_getformat(m_pMpgHandle ,&rate, &channels, &encodeing);
    }
    
    
    void SoundDecoderAL::Decode(void* outBuffer,unsigned int size,unsigned long& byteswritten )
    {
        if(m_pMpgHandle==NULL)
        {
            int error = 0;
            m_pMpgHandle = mpg123_new(mpg123_decoders()[0],&error);
            
            mpg123_replace_reader_handle(m_pMpgHandle, mp3fileread, mp3fileseek, mp3cleanup);
            mpg123_open_handle(m_pMpgHandle,m_File);
            
        }
        mpg123_read(m_pMpgHandle,(unsigned char*)outBuffer,size,(size_t*)&byteswritten);
    }

    void SoundDecoderAL::Stop()
    {
        mpg123_seek(m_pMpgHandle, 0, 0);
    }
}