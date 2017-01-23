//
//  LinuxEvent.h
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__LinuxEvent__
#define __Catfish__LinuxEvent__
#include <pthread.h>

typedef struct
{
    pthread_mutex_t mtx;
    pthread_cond_t  cond;
    bool            manual_reset;
    bool            signaled;
}LinuxHandle,*HANDLE;

#define INFINITE       0xFFFFFFFF
#define WAIT_TIMEOUT   0x00000102L
#define WAIT_OBJECT_0  0

extern HANDLE Linux_CreateEvent(void* pSec,bool manulReset,bool initialState,char *pStr);
extern void   Linux_CloseHandle(HANDLE handle);
extern void   Linux_SetEvent(HANDLE handle);
extern void   Linux_ResetEvent(HANDLE handle);
extern int    Linux_WaitForSingleObject(HANDLE handle,unsigned int timeout);

class CLocker
{
public:
    explicit CLocker(pthread_mutex_t *lock=NULL):m_lock(lock)
    {
        pthread_mutex_lock(m_lock);
    }
    ~CLocker()
    {
        pthread_mutex_unlock(m_lock);
    }
private:
    pthread_mutex_t *m_lock;
    CLocker();
    CLocker& operator=(const CLocker& rhs);
};

namespace Threads
{
    class LinuxEvent
    {
    public:
        LinuxEvent(bool manualReset = true)
        {
            m_event = Linux_CreateEvent(NULL, manualReset, false, NULL);
        }
        ~LinuxEvent()
        {
            Linux_CloseHandle(m_event);
            m_event = 0;
        }
        
        
        void Signal()
        {
            Linux_SetEvent(m_event);
        }
        
        void Reset()
        {
            Linux_ResetEvent(m_event);
        }
        
        void Wait() const
        {
            Linux_WaitForSingleObject(m_event, INFINITE);
        }
        
        bool WaitTimeout(int ms) const
        {
            int res = Linux_WaitForSingleObject(m_event, ms);
            return (WAIT_TIMEOUT == res)? false: true;
        }
        
        bool Peek() const
        {
            int res = Linux_WaitForSingleObject(m_event, 0);
            return (WAIT_TIMEOUT == res)? false: true;
        }
        
    protected:
        
        HANDLE m_event;
        
    };
    
}

#endif /* defined(__Catfish__LinuxEvent__) */
