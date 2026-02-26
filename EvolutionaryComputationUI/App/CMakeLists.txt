
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "include/Application.h"
    "src/main.cpp"
    "src/Application.cpp"
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    CommonLib
    NetworkLib
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Qml
)

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}"/settings.json" $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
)

#if(WIN32)
#    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
#        COMMAND "${Qt6_DIR}/../../../bin/windeployqt6.exe" --qmldir $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}> --no-translations $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
#    )
#endif()
