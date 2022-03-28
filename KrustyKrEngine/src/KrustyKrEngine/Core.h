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

#ifdef KK_ENABLE_ASSERTS
	#define KK_ASSERT(x, ...) { if(!(x)) { KK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define KK_CORE_ASSERT(x, ...) { if(!(x)) { KK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define KK_ASSERT(x, ...)
	#define KK_CORE_ASSERT(x, ...)
#endif // KK_ENABLE_ASSERTS


#define BIT(x) (1 << x)
