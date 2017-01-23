#ifndef IODLLCOMMON_H_
#define IODLLCOMMON_H_

#if __ANDROID__
#define IO_API
#else
#define IO_API __declspec(dllexport)
#endif

#endif