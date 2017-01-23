//
//  LinuxCriticalSection.h
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__LinuxCriticalSection__
#define __Catfish__LinuxCriticalSection__
#include <pthread.h>
namespace Threads
{
    class LinuxCriticalSection
    {
    public:
        /// constructor
        LinuxCriticalSection();
        /// destructor
        ~LinuxCriticalSection();
        /// enter the critical section
        void Enter() const;
        /// leave the critical section
        void Leave() const;
    private:
        mutable pthread_mutex_t mutex;
    };
    
    //------------------------------------------------------------------------------
    /**
     */
    inline
    LinuxCriticalSection::LinuxCriticalSection()
    {
        pthread_mutexattr_t mutexAttrs;
        pthread_mutexattr_init(&mutexAttrs);
        pthread_mutexattr_settype(&mutexAttrs, PTHREAD_MUTEX_RECURSIVE);    // allow nesting
        int res = pthread_mutex_init(&this->mutex, &mutexAttrs);
       
        pthread_mutexattr_destroy(&mutexAttrs);
    }
    
    //------------------------------------------------------------------------------
    /**
     */
    inline
    LinuxCriticalSection::~LinuxCriticalSection()
    {
        int res = pthread_mutex_destroy(&this->mutex);
    }
    
    //------------------------------------------------------------------------------
    /**
     */
    inline void
    LinuxCriticalSection::Enter() const
    {
        pthread_mutex_lock(&this->mutex);
    }
    
    //------------------------------------------------------------------------------
    /**
     */
    inline void
    LinuxCriticalSection::Leave() const
    {
        pthread_mutex_unlock(&this->mutex);
    }
}

#endif /* defined(__Catfish__LinuxCriticalSection__) */
