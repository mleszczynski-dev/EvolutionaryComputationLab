#include "Application.h"

#include <asio/version.hpp>

#pragma warning(push)
#pragma warning(disable: 26819)
#include <nlohmann/detail/abi_macros.hpp>
#include <nlohmann/json.hpp>
#pragma warning(pop)

#pragma warning(push)
#pragma warning(disable: 26819 6294 6385 26819 26498 26800 26495)
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#pragma warning(pop)

#include <format>
#include <fstream>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#endif

std::string asio_version()
{
	return std::format("{}.{}.{}", ASIO_VERSION / 100000, ASIO_VERSION / 100 % 1000, ASIO_VERSION % 100);
}

std::string nlohmann_json_version()
{
	return std::format("{}.{}.{}", NLOHMANN_JSON_VERSION_MAJOR, NLOHMANN_JSON_VERSION_MINOR, NLOHMANN_JSON_VERSION_PATCH);
}

std::string spdlog_version()
{
	return std::format("{}.{}.{}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
}

std::string compiler_name()
{
#if defined(__clang__)
    return "clang";
#elif defined(__GNUC__) || defined(__GNUG__)
    return "gcc";
#elif defined(_MSC_VER)
    return "msvc";
#else
    #error "Unknown compiler"
#endif
}

std::string compiler_version()
{
#if defined(__clang__)
	return std::format("{}.{}.{}", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined(__GNUC__) || defined(__GNUG__)
	return std::format("{}.{}.{}", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif defined(_MSC_VER)
	return std::format("{}.{}.{}", _MSC_VER / 100, _MSC_VER % 100, _MSC_FULL_VER % 100000);
#else
    #error "Unknown compiler"
#endif
}

std::string build_type()
{
#if defined(_DEBUG) || !defined(NDEBUG)
	return "debug";
#else
	return "release";
#endif
}

std::string cpu_architecture()
{
#if defined(_MSC_VER)
    #if defined(_M_X64)
	    return "x64";
    #elif defined(_M_IX86)
	    return "x86";
    #elif defined(_M_ARM64)
	    return "ARM64";
    #elif defined(_M_ARM)
	    return "ARM32";
    #else
        #error "Unknown cpu architecture"
#endif
    #else
        #error "Unknown compiler"
#endif
}

nlohmann::json load_json_settings(std::filesystem::path path)
{
    nlohmann::json settings;

    std::ifstream file(path);
    if (file.is_open())
    {
        file >> settings;
    }
    else
    {
        std::wcerr << std::format(L"Cannot open file: {}\n", path.c_str());
    }

    return settings;
}

int main(int argc, char* argv[])
{
	nlohmann::ordered_json app_info;
	app_info["compiler name"] = compiler_name();
	app_info["compiler version"] = compiler_version();
	app_info["cpu architecture"] = cpu_architecture();
	app_info["build type"] = build_type();
	app_info["asio version"] = asio_version();
	app_info["nlohmann/json version"] = nlohmann_json_version();
	app_info["spdlog version"] = spdlog_version();

	std::cout << app_info.dump(4, ' ') << std::endl;

    nlohmann::json settings = load_json_settings("settings.json");

    std::string log_pattern = "[%Y-%m-%d %H:%M:%S.%f] [%^%l%$] [T%t] [%s:%#] [%!] %v";

    try
    {       
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::info);
        console_sink->set_pattern(log_pattern);

        auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("app.log", 0, 0, false);
        file_sink->set_level(spdlog::level::trace);
        file_sink->set_pattern(log_pattern);

        spdlog::logger logger("multi_logger", { console_sink, file_sink });
        logger.set_level(spdlog::level::trace);

        spdlog::set_default_logger(std::make_shared<spdlog::logger>(logger));
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "Log init failed: " << ex.what() << std::endl;
    }

    SPDLOG_INFO("\n{}", settings.dump(4));

    return Application::exec(argc, argv);
}
