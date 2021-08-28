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

#define MARK_BIT(i) (1 << i)