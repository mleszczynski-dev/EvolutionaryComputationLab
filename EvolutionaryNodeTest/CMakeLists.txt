set(TargetName "EvolutionaryNodeTest")

add_executable(
    ${TargetName}
    "src/main.cpp")

target_link_libraries(
    ${TargetName}
    PRIVATE
    EvolutionaryNodeLib)

target_include_directories(
    ${TargetName}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
    ${ASIO_DIR}/include
    ${NLOHMANN_JSON_DIR}/include
    ${SPDLOG_DIR}/include)
