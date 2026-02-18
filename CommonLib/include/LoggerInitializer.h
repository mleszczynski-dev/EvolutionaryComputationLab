#pragma once

#include <nlohmann/json_fwd.hpp>

class LoggerInitializer
{
public:
    explicit LoggerInitializer(const nlohmann::json& settings);

    LoggerInitializer(const LoggerInitializer& other) = delete;
    LoggerInitializer(LoggerInitializer&& other) = delete;

    ~LoggerInitializer();

    LoggerInitializer& operator=(const LoggerInitializer& rhs) = delete;
    LoggerInitializer& operator=(LoggerInitializer&& rhs) = delete;

    static void* operator new(std::size_t) = delete;
    static void* operator new[](std::size_t) = delete;

    static void* operator new(std::size_t, void*) = delete;
    static void* operator new[](std::size_t, void*) = delete;

private:
    static bool initialized;
};
