#pragma once

#ifdef KK_PLATFORM_WINDOWS
	#ifdef KK_BUILD_DLL
		#define KRUSTYKRENGINE_API __declspec(dllexport)
	#else
		#define KRUSTYKRENGINE_API __declspec(dllimport)
	#endif // KK_BUILD_DLL
#else
	#error KrustyKrEngine only supports Windows!
#endif // KK_PLATFORM_WINDOWS
