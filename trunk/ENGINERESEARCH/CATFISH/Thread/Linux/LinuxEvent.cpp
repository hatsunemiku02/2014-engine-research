//
//  LinuxEvent.cpp
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "LinuxEvent.h"

#include <sys/time.h>
#include <sys/errno.h>

extern HANDLE Linux_CreateEvent(void* pSec,bool manulReset,bool initialState,char *pStr)
{
    HANDLE ret = new LinuxHandle;
    pthread_cond_init(&ret->cond,0);
    pthread_mutex_init(&ret->mtx,NULL);
    ret->manual_reset = manulReset;
    ret->signaled = initialState;
    return ret;
}
extern void   Linux_CloseHandle(HANDLE handle)
{
    if(handle==NULL)
    {
        return;
    }
    pthread_cond_destroy(&handle->cond);
    pthread_mutex_destroy(&handle->mtx);
    delete handle;
}
extern void   Linux_SetEvent(HANDLE handle)
{
    if(handle==NULL)
    {
        return;
    }
    
    CLocker lock(&handle->mtx);
    
    if(handle->manual_reset)
    {
        pthread_cond_broadcast(&handle->cond);
    }
    else
    {
        pthread_cond_signal(&handle->cond);
    }
    
    handle->signaled = true;
}
extern void   Linux_ResetEvent(HANDLE handle)
{
    if(handle==NULL)
    {
        return;
    }
    
    CLocker lock(&handle->mtx);
    handle->signaled = false;
    
}
extern int    Linux_WaitForSingleObject(HANDLE handle,unsigned int timeout)
{
 	if(NULL == handle)
	{
		return 0;
	}
    
	CLocker lock(&handle->mtx);
	int ret = 0;
	if(!handle->signaled)
	{
		if(!timeout) ///no time for waiting
		{
			return WAIT_TIMEOUT;
		}
		else
		{
			timespec tm;
			if (INFINITE != timeout)
			{
				/// set timeout
				timeval now;
				gettimeofday(&now, 0);
				tm.tv_sec = now.tv_sec + timeout / 1000 + (((timeout % 1000) * 1000 + now.tv_usec) / 1000000);
				tm.tv_nsec = (((timeout % 1000) * 1000 + now.tv_usec) % 1000000) * 1000;
			}
			/// wait until condition thread returns control
			do
			{
				ret = (INFINITE == timeout ? pthread_cond_wait(&handle->cond,&handle->mtx) :
                       pthread_cond_timedwait(&handle->cond, &handle->mtx, &tm));
			}
			while (!ret && !handle->signaled);
		}
	}
	/// adjust signaled member
	switch(ret)
	{
        case 0: // success
            if (!handle->manual_reset)
            {
                handle->signaled = false;
            }
            return WAIT_OBJECT_0;
            
        case ETIMEDOUT:
            
        default:
            return WAIT_TIMEOUT;
	}
}



namespace Threads
{

}