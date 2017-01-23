#ifndef GRAPHICDLLCOMMON_H_
#define GRAPHICDLLCOMMON_H_

#if __ANDROID__
#define GRAPHIC_API
#elif __IOS__
#define GRAPHIC_API
#include "Catfish-Prefix.pch"
#else
#define GRAPHIC_API __declspec(dllexport)
#endif

#endif