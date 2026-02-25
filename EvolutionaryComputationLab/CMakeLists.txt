project("EvolutionaryComputationLab" LANGUAGES CXX)

add_executable(
    ${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    CommonLib
    NetworkLib
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/settings.json $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
