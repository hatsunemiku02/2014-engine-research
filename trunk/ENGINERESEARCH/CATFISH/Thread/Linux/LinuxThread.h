//
//  LinuxThread.h
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__LinuxThread__
#define __Catfish__LinuxThread__
#include <string>
#include "LinuxEvent.h"

typedef void* (*ThreadFoo)(void*);


namespace Threads
{
    class LinuxThread
    {
    public:
        enum Priority
        {
            Low,
            Normal,
            High,
        };
        /// constructor
        LinuxThread();
        /// destructor
        virtual ~LinuxThread();
        /// set the thread priority
        void SetPriority(Priority p);
        /// get the thread priority
        Priority GetPriority() const;
        /// set stack size in bytes (default is 4 KByte)
        void SetStackSize(unsigned int s);
        /// get stack size
        unsigned int GetStackSize() const;
        /// set thread name
        void SetName(const std::string& n);
        /// get thread name
        const std::string& GetName() const;
        /// start executing the thread code, returns when thread has actually started
        void Start(ThreadFoo foo,void* p);
        /// request threading code to stop, returns when thread has actually finished
        void Stop();
        /// return true if thread has been started
        bool IsRunning() const;
        
        /// yield the thread (gives up current time slice)
        static void YieldThread();
        
        static void SetupMyThreadRunTime( const char* threadName );
        static void DestoryThreadRunTime( bool isMainThread = false );


        
    protected:
        /// override this method if your thread loop needs a wakeup call before stopping
        virtual void EmitWakeupSignal();
      
        /// check if stop is requested, call from DoWork() to see if the thread proc should quit
        bool ThreadStopRequested() const;
        
    private:
        /// thread states
        enum ThreadState
        {
            Initial,
            Running,
            Stopped,
        };
       
        pthread_t threadHandle;
        LinuxEvent threadStartedEvent;
        LinuxEvent stopRequestEvent;
        Priority priority;
        unsigned int stackSize;
        std::string name;

        ThreadFoo  threadFoo;
        ThreadState volatile threadState;
    };
    
    
    
    //------------------------------------------------------------------------------
    /**
     */
    inline void
    LinuxThread::SetPriority(Priority p)
    {
        this->priority = p;
    }
    
    //------------------------------------------------------------------------------
    /**
     */
    inline LinuxThread::Priority
    LinuxThread::GetPriority() const
    {
        return this->priority;
    }
    
    //------------------------------------------------------------------------------
    /**
     */
    inline void
    LinuxThread::SetStackSize(unsigned int s)
    {
        this->stackSize = s;
    }
    
    //------------------------------------------------------------------------------
    /**
     */
    inline unsigned int
    LinuxThread::GetStackSize() const
    {
        return this->stackSize;
    }
    
    //------------------------------------------------------------------------------
    /**
     If the derived DoWork() method is running in a loop it must regularly
     check if the process wants the thread to terminate by calling
     ThreadStopRequested() and simply return if the result is true. This
     will cause the thread to shut down.
     */
    inline bool
    LinuxThread::ThreadStopRequested() const
    {
        return this->stopRequestEvent.Peek();
    }
    
    //------------------------------------------------------------------------------
    /**
     Set the thread's name.
     */
    inline void
    LinuxThread::SetName(const std::string& n)
    {
        
        this->name = n;
    }
    
    //------------------------------------------------------------------------------
    /**
     Get the thread's name. This is the vanilla method which
     returns the name member.
     */
    inline const std::string&
    LinuxThread::GetName() const
    {
        return this->name;
    }

}

#endif /* defined(__Catfish__LinuxThread__) */
