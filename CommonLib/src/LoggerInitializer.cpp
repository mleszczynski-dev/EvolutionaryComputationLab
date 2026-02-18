#include "LoggerInitializer.h"

#include <nlohmann/json.hpp>
#pragma warning(push)
#pragma warning(disable: 26819 6294 6385 26819 26498 26800 26495)
#include <spdlog/async.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#pragma warning(pop)

#include <string>
#include <vector>

bool LoggerInitializer::initialized = false;

LoggerInitializer::LoggerInitializer(const nlohmann::json& settings)
{
    if (initialized)
        return;

    initialized = true;

    nlohmann::json logger_console = settings.value("console", nlohmann::json::object());
    nlohmann::json logger_file = settings.value("file", nlohmann::json::object());

    std::vector<spdlog::sink_ptr> log_sinks;
    std::string log_pattern = "[%Y-%m-%d %H:%M:%S.%f] [%^%l%$] [T%t] [%s:%#] [%!] %v";

    if (logger_console.value("active", true))
    {
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::from_str(logger_console.value("level", "info")));
        console_sink->set_pattern(log_pattern);

        log_sinks.push_back(console_sink);
    }

    if (logger_file.value("active", false))
    {
        auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("app.log", 0, 0, false);
        file_sink->set_level(spdlog::level::from_str(logger_file.value("level", "info")));
        file_sink->set_pattern(log_pattern);

        log_sinks.push_back(file_sink);
    }

    std::shared_ptr<spdlog::logger> multi_sink_logger = nullptr;

    if (settings.value("async", true))
    {
        spdlog::init_thread_pool(8192, 1);
        multi_sink_logger =
            std::make_shared<spdlog::async_logger>("logger", log_sinks.begin(), log_sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
    }
    else
    {
        multi_sink_logger =
            std::make_shared<spdlog::logger>("logger", log_sinks.begin(), log_sinks.end());
    }

    multi_sink_logger->set_level(spdlog::level::trace);
    spdlog::set_default_logger(multi_sink_logger);
}

LoggerInitializer::~LoggerInitializer()
{
    spdlog::shutdown();

    initialized = false;
}
