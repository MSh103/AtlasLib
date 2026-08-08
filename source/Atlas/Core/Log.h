#pragma once

#include "Core.h"

#define FMT_UNICODE 0
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/fmt/fmt.h"

#include <filesystem>

template <>
struct fmt::formatter<std::filesystem::path> : fmt::formatter<std::string>
{
	auto format(const std::filesystem::path& p, fmt::format_context& ctx) const
	{
		return fmt::formatter<std::string>::format(p.string(), ctx);
	}
};

namespace Atlas
{
	class Log
	{
	public:
		static void Init();

		struct Core
		{
		public:
			template<typename... Args>
			static void Error(fmt::format_string<Args...> string, Args&&... args)
			{
				Log::s_CoreLogger->error(string, std::forward<Args>(args)...);
			}

			template<typename... Args>
			static void Info(fmt::format_string<Args...> string, Args&&... args)
			{
				Log::s_CoreLogger->info(string, std::forward<Args>(args)...);
			}

			template<typename... Args>
			static void Warn(fmt::format_string<Args...> string, Args&&... args)
			{
				Log::s_CoreLogger->warn(string, std::forward<Args>(args)...);
			}

			template<typename... Args>
			static void Trace(fmt::format_string<Args...> string, Args&&... args)
			{
				Log::s_CoreLogger->trace(string, std::forward<Args>(args)...);
			}
		};
		
		template<typename... Args>
		static void Error(fmt::format_string<Args...> string, Args&&... args)
		{
			Log::s_ClientLogger->error(string, std::forward<Args>(args)...);
		}

		template<typename... Args>
		static void Info(fmt::format_string<Args...> string, Args&&... args)
		{
			Log::s_ClientLogger->info(string, std::forward<Args>(args)...);
		}

		template<typename... Args>
		static void Warn(fmt::format_string<Args...> string, Args&&... args)
		{
			Log::s_ClientLogger->warn(string, std::forward<Args>(args)...);
		}

		template<typename... Args>
		static void Trace(fmt::format_string<Args...> string, Args&&... args)
		{
			Log::s_ClientLogger->trace(string, std::forward<Args>(args)...);
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
