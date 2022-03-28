#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace KrustyKrEngine {
	class KRUSTYKRENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define KK_CORE_TRACE(...) ::KrustyKrEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KK_CORE_INFO(...)  ::KrustyKrEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KK_CORE_WARN(...)  ::KrustyKrEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KK_CORE_ERROR(...) ::KrustyKrEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KK_CORE_FATAL(...) ::KrustyKrEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KK_TRACE(...)      ::KrustyKrEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KK_INFO(...)       ::KrustyKrEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define KK_WARN(...)       ::KrustyKrEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KK_ERROR(...)      ::KrustyKrEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define KK_FATAL(...)      ::KrustyKrEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)