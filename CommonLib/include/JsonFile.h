#pragma once

#include <nlohmann/json.hpp>

#include <filesystem>

class JsonFile
{
public:
    JsonFile() = delete;

    static nlohmann::json load(const std::filesystem::path& path);
};
