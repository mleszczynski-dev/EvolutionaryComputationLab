add_executable(
    EvolutionaryAgentApp
    "src/main.cpp")

target_link_libraries(
    EvolutionaryAgentApp
    PRIVATE
    EvolutionaryAgentLib)

target_include_directories(
    EvolutionaryAgentApp
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
    ${ASIO_DIR}/include
    ${NLOHMANN_JSON_DIR}/include
    ${SPDLOG_DIR}/include)
