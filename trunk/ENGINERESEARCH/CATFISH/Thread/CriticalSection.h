//
//  CriticalSection.h
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__CriticalSection__
#define __Catfish__CriticalSection__
#include "LinuxCriticalSection.h"
namespace Threads
{
    class CriticalSection:public LinuxCriticalSection
    {
        
    };
}

#endif /* defined(__Catfish__CriticalSection__) */
