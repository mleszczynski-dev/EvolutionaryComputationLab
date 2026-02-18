#include "JsonFile.h"

#include <fstream>
#include <iostream>

nlohmann::json JsonFile::load(const std::filesystem::path& path)
{
    nlohmann::json settings = nlohmann::json::object();

    std::ifstream file(path);
    if (file.is_open())
    {
        nlohmann::json tmp;
        file >> tmp;

        if (file)
        {
            settings = std::move(tmp);
        }
    }
    else
    {
        std::wcerr << std::format(L"Cannot open file: {}\n", path.c_str());
    }

    return settings;
}
