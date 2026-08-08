#include "Log.h"

#include "spdlog/sinks/ansicolor_sink.h"

void Atlas::Log::Init()
{
	auto sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();

	sink->set_color(spdlog::level::trace, "\033[38;2;60;115;168m");
	sink->set_color(spdlog::level::info, "\033[38;2;152;195;121m");
	sink->set_color(spdlog::level::warn, "\033[38;2;255;165;0m");
	sink->set_color(spdlog::level::err, "\033[38;2;255;0;0m");

	spdlog::set_pattern("%^[%D %T] [%n] [%l]:%$ %v");

	s_CoreLogger = std::make_shared<spdlog::logger>("Atlas", sink);
	s_CoreLogger->set_level(spdlog::level::trace);
	spdlog::register_logger(s_CoreLogger);

	s_ClientLogger = std::make_shared<spdlog::logger>("App", sink);
	s_ClientLogger->set_level(spdlog::level::trace);
	spdlog::register_logger(s_ClientLogger);
}


std::shared_ptr<spdlog::logger> Atlas::Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Atlas::Log::s_ClientLogger;
