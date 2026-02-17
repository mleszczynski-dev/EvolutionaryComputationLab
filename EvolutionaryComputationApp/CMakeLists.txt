set(TargetName "EvolutionaryComputationApp")

add_executable(
    ${TargetName}
    "src/main.cpp")

target_link_libraries(
    ${TargetName}
    PRIVATE
    NetworkLib)

target_include_directories(
    ${TargetName}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
    ${ASIO_DIR}/include
    ${NLOHMANN_JSON_DIR}/include
    ${SPDLOG_DIR}/include)

add_custom_command(
    TARGET
    ${TargetName}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/settings.json
            $<TARGET_FILE_DIR:${TargetName}>/settings.json
    COMMENT "Copying settings.json"
)
