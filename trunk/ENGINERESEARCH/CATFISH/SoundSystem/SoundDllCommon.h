#ifndef GDLLCOMMON_H_
#define GDLLCOMMON_H_
#if __IOS__
#include "Catfish-Prefix.pch"
#endif

#if __ANDROID__||__IOS__
#define SOUND_API
#else
#define SOUND_API __declspec(dllexport)
#endif

#endif
