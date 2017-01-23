//
//  JobMgr.h
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__JobMgr__
#define __Catfish__JobMgr__


#include <vector>
#include <list>

namespace Threads
{
    class JobThread;
    class Job;
    class JobMgr
    {
    public:
        static JobMgr& GetInstance()
        {
            static JobMgr instance;
            return instance;
        }
        ~JobMgr();
        
        void Init();
        void AddJob(Job* pj);
    protected:
       
        std::vector<JobThread*> m_pAllThreads;
        std::list<Job*>      m_pJobs;
        
    protected:
        JobMgr();
        static void* Dojobs(void*);
    };
}

#endif /* defined(__Catfish__JobMgr__) */
