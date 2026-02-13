add_executable(
    EvolutionaryNodeTest
    "src/main.cpp")

target_link_libraries(
    EvolutionaryNodeTest
    PRIVATE
    EvolutionaryNodeLib)

target_include_directories(
    EvolutionaryNodeTest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
    ${ASIO_DIR}/include
    ${NLOHMANN_JSON_DIR}/include
    ${SPDLOG_DIR}/include)
