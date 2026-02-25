project("EvolutionaryComputationNodeTest" LANGUAGES CXX)

add_executable(
    ${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    CommonLib
    EvolutionaryComputationNodeLib
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
