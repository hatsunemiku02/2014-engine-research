//
//  LinuxThread.cpp
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "LinuxThread.h"
namespace Threads
{
    LinuxThread::LinuxThread():
    priority(Normal),
    stackSize(16384),
    threadState(Initial),
    threadHandle(0),
    threadFoo(NULL)
    {
       
    }
    
    //------------------------------------------------------------------------------
    /**
     */
    LinuxThread::~LinuxThread()
    {
        if (this->IsRunning())
        {
            this->Stop();
        }
        
    }
    
    //------------------------------------------------------------------------------
    /**
     */
    void
    LinuxThread::Start(ThreadFoo foo,void* p)
    {
    
        threadFoo = foo;
        pthread_create( &this->threadHandle,NULL,threadFoo, p);
      
        this->threadState = Running;
       
    }
    
    //------------------------------------------------------------------------------
    /**
     This method is called by Thread::Stop() after setting the
     stopRequest event and before waiting for the thread to stop. If your
     thread runs a loop and waits for jobs it may need an extra wakeup
     signal to stop waiting and check for the ThreadStopRequested() event. In
     this case, override this method and signal your event object.
     */
    void
    LinuxThread::EmitWakeupSignal()
    {
        // empty, override in subclass!
    }
    
    //------------------------------------------------------------------------------
    /**
     This stops the thread by signalling the stopRequestEvent and waits for the
     thread to actually quit. If the thread code runs in a loop it should use the
     IsStopRequested() method to see if the thread object wants it to shutdown.
     If so DoWork() should simply return.
     */
    void
    LinuxThread::Stop()
    {
        
        // signal the thread to stop
        this->stopRequestEvent.Signal();
        
        // call the wakeup-thread method, may be derived in a subclass
        // if the threads needs to be woken up, it is important that this
        // method is called AFTER the stopRequestEvent is signalled!
        this->EmitWakeupSignal();
        
        void* threadResult;
        pthread_join(this->threadHandle, &threadResult);
        this->threadState = Stopped;
        this->threadHandle = 0;
    }
    
    //------------------------------------------------------------------------------
    /**
     Returns true if the thread is currently running.
     */
    bool
    LinuxThread::IsRunning() const
    {
        return (Running == this->threadState);
    }
    
    //------------------------------------------------------------------------------
    /**
     Give up time slice.
     */
    void
    LinuxThread::YieldThread()
    {
        //TODO:
        //n_error("OSXThread::YieldThread(): IMPLEMENT ME!");
    }
    
    //------------------------------------------------------------------------------
    /**
     Static method which sets the name of this thread. This is called from
     within ThreadProc. The string pointed to must remain valid until
     the thread is terminated!
     */
    
    void
    LinuxThread::SetupMyThreadRunTime(const char* n)
    {
      //  Threading::ThreadRunTimeInfo::SetupMyThreadRunTime( n );
        
    }
    //------------------------------------------------------------------------
    void
    LinuxThread::DestoryThreadRunTime( bool isMainThread /*= false*/ )
    {
      //  Threading::ThreadRunTimeInfo::DestoryThreadRunTime( isMainThread );
    }
    //------------------------------------------------------------------------------




}