add_executable(
    EvolutionaryNodeApp
    "src/main.cpp" "include/Application.h" "src/Application.cpp")

target_link_libraries(
    EvolutionaryNodeApp
    PRIVATE
    EvolutionaryNodeLib)

target_include_directories(
    EvolutionaryNodeApp
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
    ${ASIO_DIR}/include
    ${NLOHMANN_JSON_DIR}/include
    ${SPDLOG_DIR}/include)
