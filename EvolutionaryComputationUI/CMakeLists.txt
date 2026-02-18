set(TargetName "EvolutionaryComputationUI")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(
    ${TargetName}
    "include/Application.h"
    "src/Application.cpp"
    "src/main.cpp"
)

qt_standard_project_setup()
qt_finalize_target(${TargetName} TARGET_PLUGINS platforms)

target_link_libraries(
    ${TargetName}
    PRIVATE
    CommonLib
    NetworkLib
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

target_include_directories(
    ${TargetName}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_custom_command(
    TARGET ${TargetName} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/settings.json $<TARGET_FILE_DIR:${TargetName}>
)

if(WIN32)
    add_custom_command(TARGET ${TargetName} POST_BUILD
        COMMAND "${Qt6_DIR}/../../../bin/windeployqt6.exe" --no-translations $<TARGET_FILE:${TargetName}>
    )
endif()
