//
//  JobMgr.cpp
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "JobMgr.h"
#include "JobThread.h"
namespace Threads
{

    JobMgr::JobMgr()
    {
       
    }
    
    JobMgr::~JobMgr()
    {
        
    }
    
    void JobMgr::Init()
    {
        m_pAllThreads.push_back(new JobThread());
        m_pAllThreads.push_back(new JobThread());
    }
    
    void JobMgr::AddJob(Job* pj)
    {
        m_pAllThreads[0]->AddJob(pj);
    }
}