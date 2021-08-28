#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace ZEngine {
	class ZENGINE_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> _core_logger;
		static std::shared_ptr<spdlog::logger> _client_logger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _core_logger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _client_logger; }
	};
}

// Core logging macros
#define ZE_CORE_FATAL(...)		::ZEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define ZE_CORE_ERROR(...)		::ZEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZE_CORE_WARN(...)		::ZEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZE_CORE_INFO(...)		::ZEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZE_CORE_TRACE(...)		::ZEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define ZE_FATAL(...)			::ZEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define ZE_ERROR(...)			::ZEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZE_WARN(...)			::ZEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZE_INFO(...)			::ZEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZE_TRACE(...)			::ZEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
