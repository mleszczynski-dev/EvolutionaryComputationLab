cmake_minimum_required (VERSION 3.12)

project ("EvolutionaryComputationLab")

message(STATUS "C++ compiler path: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ASIO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/asio/asio")
set(GOOGLE_MOCK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/googletest/googlemock")
set(GOOGLE_TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/googletest/googletest")
set(NLOHMANN_JSON_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/json")
set(SPDLOG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/spdlog")

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.3/msvc2022_64")

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_compile_definitions(
    SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE
    SPDLOG_WCHAR_TO_UTF8_SUPPORT)
if (WIN32)
    add_compile_definitions(
        _WIN32_WINNT=0x0601
        UNICODE
        _UNICODE
        WIN32_LEAN_AND_MEAN
        NOMINMAX)
endif()

add_subdirectory(3rd_party)
add_subdirectory(CommonLib)
add_subdirectory(EvolutionaryComputationApp)
add_subdirectory(EvolutionaryComputationUI)
add_subdirectory(EvolutionaryNodeApp)
add_subdirectory(EvolutionaryNodeLib)
add_subdirectory(EvolutionaryNodeTest)
add_subdirectory(MessageAPI)
add_subdirectory(NetworkLib)
