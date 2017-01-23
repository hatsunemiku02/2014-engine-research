#ifndef FONTDLLCOMMON_H_
#define FONTDLLCOMMON_H_

#if __ANDROID__
#define FONT_API
#elif __IOS__
#define FONT_API
#include "Catfish-Prefix.pch"
#else
#define FONT_API __declspec(dllexport)
#endif

#endif