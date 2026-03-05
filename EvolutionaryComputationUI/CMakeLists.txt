project(EvolutionaryComputationUI LANGUAGES CXX)

add_subdirectory("ui")

find_package(Qt6 6.8 REQUIRED COMPONENTS Core Gui Widgets Qml Quick)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME})

set(QtQuickControls2Conf ${CMAKE_CURRENT_SOURCE_DIR}/ui/qtquickcontrols2.conf)

set_source_files_properties(${QtQuickControls2Conf}
    PROPERTIES
        QT_RESOURCE_ALIAS qtquickcontrols2.conf
)

qt_add_resources(${PROJECT_NAME}
    "configuration"
    PREFIX ""
    FILES
        ${QtQuickControls2Conf}
)

target_sources(${PROJECT_NAME}
    PUBLIC
    "include/Application.h"
    "include/Backend.h"
    PRIVATE
    "include/environment.h"
    "src/Application.cpp"
    "src/Backend.cpp"
    "src/main.cpp"
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    DesktopUIplugin
    DesktopUIContentplugin
    QtQuickDesignerComponents
    CommonLib
    NetworkLib
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Quick
)
