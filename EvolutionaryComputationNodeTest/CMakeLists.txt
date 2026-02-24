set(TargetName "EvolutionaryComputationNodeTest")

add_executable(
    ${TargetName}
    "src/main.cpp"
)

target_link_libraries(
    ${TargetName}
    PRIVATE
    CommonLib
    EvolutionaryComputationNodeLib
)

target_include_directories(
    ${TargetName}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
