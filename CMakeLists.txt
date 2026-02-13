cmake_minimum_required (VERSION 3.12)

project ("EvolutionaryComputationLab")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ASIO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/asio/asio")
set(NLOHMANN_JSON_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/json")
set(SPDLOG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/spdlog")

add_compile_options(/utf-8)

if (WIN32)
    add_compile_definitions(
        _WIN32_WINNT=0x0601
        UNICODE
        _UNICODE
        WIN32_LEAN_AND_MEAN
        NOMINMAX)
endif()

add_subdirectory(EvolutionaryNodeLib)
add_subdirectory(EvolutionaryNodeApp)
