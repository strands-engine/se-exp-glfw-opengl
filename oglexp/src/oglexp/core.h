#pragma once

// handling windows dll shenanigans
#ifdef OXP_PLATFORM_WIN
#ifdef OXP_BUILD_DLL
#define OXP_API __declspec(dllexport)
#else
#define OXP_API __declspec(dllimport)
#endif
#else
#error Only Windows platform is supported.
#endif


namespace oglexp 
{



}