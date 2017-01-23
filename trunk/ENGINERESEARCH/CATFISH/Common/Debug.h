#ifndef DEBUG_H_
#define DEBUG_H_
#ifdef _DEBUG
#include <stdlib.h>
#define  MERROR \
	abort();
#else
#define  MERROR
#endif

#ifdef _DEBUG
#include <stdlib.h>
#define  IFERROR(exp) \
	if(exp) \
	{ \
	abort(); \
	}
#else
#define  IFERROR(exp)
#endif

#ifdef _DEBUG
#ifdef __ANDROID__
#include <android/log.h>
#define  LOG(exp) \
	__android_log_print(ANDROID_LOG_INFO,"CATFISH LOG",exp);
#else
#define LOG(exp)
#endif
#else
#define  LOG(exp)
#endif
#endif