//
//  JobThread.cpp
//  Catfish
//
//  Created by zhaohang on 14-6-23.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "JobThread.h"
#include "Thread.h"
#include "Job.h"

namespace Threads
{
    void* JobThreadFoo(void* obj)
    {
        JobThread* pJT = (JobThread*)obj;
        while (1)
        {
            pJT->ExecuteJob();
        }
        
        return NULL;
    }
    
    
    JobThread::JobThread()
    :m_ListOpMutex(NULL)
    {
        m_pThread = new Thread();
        m_pThread->Start(JobThreadFoo, this);
        
    }
    
    JobThread::~JobThread()
    {
        
    }
    
    void JobThread::AddJob(Job* pj)
    {
        m_ListOpMutex->Enter();
        m_JobList.push_back(pj);
        if(m_JobList.size()==1)
        {
            m_ThreadHugEvent.Signal();
        }
        m_ListOpMutex->Leave();
    }
    
    void JobThread::EraseJob(Job* pj)
    {
        
        m_ListOpMutex->Enter();
        std::list<Job*>::iterator itr = m_JobList.begin();
        for(;itr!=m_JobList.end();itr++)
        {
            if (*itr == pj)
            {
                if(pj->GetState()==Job::Doing)
                {
                    return;
                }
                m_JobList.erase(itr);
                if(m_JobList.size()==0)
                {
                    m_ThreadHugEvent.Reset();
                }
                break;
            }
        }
        m_ListOpMutex->Leave();
    }

    void JobThread::ExecuteJob()
    {
        
        m_ThreadHugEvent.Wait();
        
        std::list<Job*>::iterator itr = m_JobList.begin();
        if(itr==m_JobList.end())
        {
            return;
        }
        (*itr)->Execute();
        
        EraseJob((*itr));
    }
    
    const std::list<Job*>& JobThread::GetJobs() const
    {
        return m_JobList;
    }
    
    const int JobThread::GetJobCount() const
    {
        m_ListOpMutex->Enter();
        int ret = (int)m_JobList.size();
        m_ListOpMutex->Leave();
        return ret;
    }

}