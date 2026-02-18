#include "Application.h"
#include "AppInfo.h"
#include "LoggerInitializer.h"

#include <spdlog/spdlog.h>

#include <format>
#include <fstream>
#include <iostream>
#include <string>

nlohmann::json load_json_settings(std::filesystem::path path)
{
    nlohmann::json settings = nlohmann::json::object();

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
    std::cout << AppInfo::toString() << std::endl;

    nlohmann::json settings = load_json_settings("settings.json");

    LoggerInitializer logger(settings.value("logger", nlohmann::json::object()));

    SPDLOG_INFO("\n{}", settings.dump(4));

    return Application::exec(argc, argv);
}
