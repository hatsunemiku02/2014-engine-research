//
//  Job.cpp
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#include "Job.h"
namespace Threads
{
    Job::Job(JobFoo foo,void* param)
    :m_Foo(foo)
    ,m_State(Wait)
    ,m_pParam(param)
    {
        
    }

    Job::~Job()
    {
        
    }
    
    void Job::Execute()
    {
        m_State = Doing;
        m_Foo(m_pParam);
        m_State = Done;
    }
}