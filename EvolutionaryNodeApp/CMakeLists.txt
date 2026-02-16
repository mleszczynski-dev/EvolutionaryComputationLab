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

add_custom_command(
    TARGET
    EvolutionaryNodeApp
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/settings.json
            $<TARGET_FILE_DIR:EvolutionaryNodeApp>/settings.json
    COMMENT "Kopiowanie pliku input.json do katalogu build"
)
