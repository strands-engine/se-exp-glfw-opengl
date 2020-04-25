#pragma once

#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"

namespace oglexp 
{
	class OXP_API log
	{
	public:
		using logger_ptr = std::shared_ptr<spdlog::logger>;

		static void init();
		inline static logger_ptr& core_logger() { return s_core_logger_p; }
		inline static logger_ptr& client_logger() { return s_client_logger_p; }

	private:
		static logger_ptr s_core_logger_p;
		static logger_ptr s_client_logger_p;
	};
}


#define OXP_CORE_TRACE(...)		::oglexp::log::core_logger()->trace(__VA_ARGS__)
#define OXP_CORE_INFO(...)		::oglexp::log::core_logger()->info(__VA_ARGS__)
#define OXP_CORE_WARN(...)		::oglexp::log::core_logger()->warn(__VA_ARGS__)
#define OXP_CORE_ERROR(...)		::oglexp::log::core_logger()->error(__VA_ARGS__)
#define OXP_CORE_FATAL(...)		::oglexp::log::core_logger()->fatal(__VA_ARGS__)

#define OXP_TRACE(...)			::oglexp::log::client_logger()->trace(__VA_ARGS__)
#define OXP_INFO(...)			::oglexp::log::client_logger()->info(__VA_ARGS__)
#define OXP_WARN(...)			::oglexp::log::client_logger()->warn(__VA_ARGS__)
#define OXP_ERROR(...)			::oglexp::log::client_logger()->error(__VA_ARGS__)
#define OXP_FATAL(...)			::oglexp::log::client_logger()->fatal(__VA_ARGS__)
