//
//  JobThread.h
//  Catfish
//
//  Created by zhaohang on 14-6-23.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__JobThread__
#define __Catfish__JobThread__
#include <list>
#include "CriticalSection.h"
#include "Event.h"
namespace Threads
{
    class Job;
    class Thread;
    
    class JobThread
    {
    public:
        JobThread();
        ~JobThread();
        
        
        void AddJob(Job* pj);
        void EraseJob(Job* pj);
        void ExecuteJob();
        const std::list<Job*>& GetJobs() const;
        const int GetJobCount() const;
    protected:
        
        
        std::list<Job*> m_JobList;
        CriticalSection* m_ListOpMutex;
        Event m_ThreadHugEvent;
        
        Thread* m_pThread;
    };
}

#endif /* defined(__Catfish__JobThread__) */
