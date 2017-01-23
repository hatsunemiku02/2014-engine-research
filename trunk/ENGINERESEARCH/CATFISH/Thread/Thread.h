//
//  Thread.h
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__Thread__
#define __Catfish__Thread__
#include "LinuxThread.h"

namespace Threads
{
    class Thread:public LinuxThread
    {
    public:
        Thread()
        {
            
        }
        virtual ~Thread()
        {
            
        }
    };
}

#endif /* defined(__Catfish__Thread__) */
