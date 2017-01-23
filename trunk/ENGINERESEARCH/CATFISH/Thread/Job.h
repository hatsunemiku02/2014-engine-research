//
//  Job.h
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__Job__
#define __Catfish__Job__

namespace Threads
{
    
    class Thread;
    class JobThread;
    typedef void* (*JobFoo)(void*);
    class Job
    {
    public:
        enum JobState
        {
            Wait = 0,
            Doing,
            Done,
        };
        
        Job(JobFoo foo,void* param);
        ~Job();
        
        
        JobState GetState()
        {
            return m_State;
        }
        
        void Execute();
    protected:
      
        JobFoo m_Foo;
        void*  m_pParam;
        JobState volatile m_State;
        
        
        
        friend class JobThread;
    };
}

#endif /* defined(__Catfish__Job__) */
