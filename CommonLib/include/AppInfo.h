#pragma once

#include <nlohmann/json.hpp>
#include <string>

class AppInfo
{
public:
    AppInfo() = delete;

    static const std::string compiler_name;
    static const std::string compiler_version;
    static const std::string build_type;
    static const std::string cpu_architecture;

    static const std::string asio_version;
    static const std::string nlohmann_json_version;
    static const std::string spdlog_version;

    static nlohmann::ordered_json toJson();
    static std::string toString();
};
