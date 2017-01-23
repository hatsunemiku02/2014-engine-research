#ifndef GDEBUG_H_
#define GDEBUG_H_
#include "../Common/Debug.h"



void CheckError();
#if 1
#define  CHECKGLERROR CheckError()
#else
#define  CHECKGLERROR 
#endif


#endif