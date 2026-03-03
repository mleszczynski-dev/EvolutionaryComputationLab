project(EvolutionaryComputationUI LANGUAGES CXX)

add_subdirectory("ui")

find_package(Qt6 6.8 REQUIRED COMPONENTS Core Gui Widgets Qml Quick)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME})

set(conf_file ${CMAKE_CURRENT_SOURCE_DIR}/ui/qtquickcontrols2.conf)

set_source_files_properties(${conf_file}
    PROPERTIES
        QT_RESOURCE_ALIAS qtquickcontrols2.conf
)

qt_add_resources(${PROJECT_NAME}
    "configuration"
    PREFIX ""
    FILES
        ${conf_file}
)
target_sources(${PROJECT_NAME} PUBLIC
    "include/Application.h"
    "src/main.cpp"
    "src/Application.cpp"
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


#add_subdirectory(DesktopUI)
#add_subdirectory(DesktopUIContent)
#add_subdirectory(App)
#add_subdirectory(Dependencies)

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

#list(APPEND QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/qml/imports")
#list(APPEND QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/qml/cppImports")
#set(QML_IMPORT_PATH ${QML_IMPORT_PATH}
#    CACHE STRING "Qt Creator 4.1 extra qml import paths"
#    FORCE
#)

#qt_add_resources(${PROJECT_NAME} "configuration"
#    PREFIX "/"
#    FILES
#        qtquickcontrols2.conf
#)
