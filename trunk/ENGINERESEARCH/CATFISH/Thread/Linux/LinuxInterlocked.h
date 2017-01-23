//
//  LinuxInterlocked.h
//  Catfish
//
//  Created by zhaohang on 14-6-20.
//  Copyright (c) 2014年 zh. All rights reserved.
//

#ifndef __Catfish__LinuxInterlocked__
#define __Catfish__LinuxInterlocked__

namespace Threads
{
    class LinuxInterlocked
    {
    public:
        static int Increment(int volatile& var)
        {
            return __sync_add_and_fetch(&var,1);
        }
        
        static int Decrement(int volatile& var)
        {
            return __sync_sub_and_fetch(&var,1);
        }
        
        static int Add(int volatile& var,int add)
        {
            return __sync_add_and_fetch(&var,add);
        }

        static int Exchange(int volatile* dest,int value)
        {
            return __sync_lock_test_and_set(dest,value);
        }
        
        static int CompareExchange(int volatile* dest,int exchange,int comparand)
        {
            return __sync_val_compare_and_swap(dest,comparand,exchange);
        }
    };
    
    
}

#endif /* defined(__Catfish__LinuxInterlocked__) */
