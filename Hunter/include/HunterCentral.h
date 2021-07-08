#pragma once
#include "pch.h"

#ifdef HUNTER_DLL_BUILD
#define HUNTER_API _declspec(dllexport)
#else
#define HUNTER_API _declspec(dllimport)
#endif

#ifdef _DEBUG
#define HLOG(msg) std::cout << msg << std::endl;
#else
#define HLOG(msg)
#endif