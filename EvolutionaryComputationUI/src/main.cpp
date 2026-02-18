#include "Application.h"
#include "AppInfo.h"
#include "JsonFile.h"
#include "LoggerInitializer.h"

#include <spdlog/spdlog.h>

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << AppInfo::toString() << std::endl;

    nlohmann::json settings = JsonFile::load("settings.json");

    LoggerInitializer logger(settings.value("logger", nlohmann::json::object()));

    SPDLOG_INFO("\n{}", settings.dump(4));

    return Application::exec(argc, argv);
}
