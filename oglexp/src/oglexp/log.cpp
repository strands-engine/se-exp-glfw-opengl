#include "log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace oglexp
{
	log::logger_ptr log::s_core_logger_p;
	log::logger_ptr log::s_client_logger_p;

	void log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_core_logger_p = spdlog::stdout_color_mt("OGLEXP");
		s_core_logger_p->set_level(spdlog::level::trace);
		s_client_logger_p = spdlog::stdout_color_mt("APP");
		s_client_logger_p->set_level(spdlog::level::trace);
	}
}