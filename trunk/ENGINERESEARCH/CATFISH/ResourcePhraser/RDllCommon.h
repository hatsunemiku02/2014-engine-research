#ifndef RDLLCOMMON_H_
#define RDLLCOMMON_H_
#if __ANDROID__||__IOS__
#include "Catfish-Prefix.pch"
#define RES_API
#else
#define RES_API __declspec(dllexport)
#endif

#endif