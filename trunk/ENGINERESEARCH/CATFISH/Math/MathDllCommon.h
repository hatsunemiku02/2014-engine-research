#pragma once
#if __ANDROID__
#define MATH_API
#elif __IOS__
#define MATH_API
#include "Catfish-Prefix.pch"
#else
#define MATH_API __declspec(dllexport)
#endif

