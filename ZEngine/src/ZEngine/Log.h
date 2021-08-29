#pragma once

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
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return _core_logger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return _client_logger; }
	};
}

// Core logging macros
#define ZE_CORE_FATAL(...)		::ZEngine::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define ZE_CORE_ERROR(...)		::ZEngine::Log::getCoreLogger()->error(__VA_ARGS__)
#define ZE_CORE_WARN(...)		::ZEngine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define ZE_CORE_INFO(...)		::ZEngine::Log::getCoreLogger()->info(__VA_ARGS__)
#define ZE_CORE_TRACE(...)		::ZEngine::Log::getCoreLogger()->trace(__VA_ARGS__)

#define ZE_FATAL(...)			::ZEngine::Log::getClientLogger()->fatal(__VA_ARGS__)
#define ZE_ERROR(...)			::ZEngine::Log::getClientLogger()->error(__VA_ARGS__)
#define ZE_WARN(...)			::ZEngine::Log::getClientLogger()->warn(__VA_ARGS__)
#define ZE_INFO(...)			::ZEngine::Log::getClientLogger()->info(__VA_ARGS__)
#define ZE_TRACE(...)			::ZEngine::Log::getClientLogger()->trace(__VA_ARGS__)