#ifndef GLESDLLCOMMON_H_
#define GLSEDLLCOMMON_H_

#if __ANDROID__
#define RENDERER_API
#elif __IOS__
#define RENDERER_API
#include "Catfish-Prefix.pch"
#else
#define RENDERER_API __declspec(dllexport)
#endif

#endif
