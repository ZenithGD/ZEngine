#pragma once

#ifdef ZE_PLATFORM_WINDOWS
	#ifdef ZE_BUILD_DLL
		#define ZENGINE_API __declspec(dllexport)
	#else
		#define ZENGINE_API __declspec(dllimport)
	#endif
#else
	#error ZEngine only supports Windows (for now)
#endif

#ifdef ZE_ENABLE_ASSERTS
	#define ZE_ASSERT(x, ...) { if(!(x)) { ZE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } /* end if */ }
	#define ZE_CORE_ASSERT(x, ...) { if(!(x)) { ZE_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } /* end if */ }
#else 
	#define ZE_ASSERT(x, ...)
	#define ZE_CORE_ASSERT(x, ...)
#endif

#define MARK_BIT(i) (1 << i)