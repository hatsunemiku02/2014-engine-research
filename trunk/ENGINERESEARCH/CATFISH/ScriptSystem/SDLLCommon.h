#ifndef SDLLCOMMON_H_
#define SDLLCOMMON_H_

#if __ANDROID__
#define SCRIPT_API
#else
#define SCRIPT_API __declspec(dllexport)
#endif

#endif