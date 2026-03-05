#pragma once

#include <QGuiApplication>

const char mainQmlFile[] = "qrc:/qt/qml/DesktopUIContent/App.qml";

inline void set_qt_environment() {
    qputenv("QML_COMPAT_RESOLVE_URLS_ON_ASSIGNMENT", "1");
    qputenv("QT_ENABLE_HIGHDPI_SCALING", "0");
    qputenv("QT_LOGGING_RULES", "qt.qml.connections=false");
    qputenv("QT_QUICK_CONTROLS_CONF", ":/qtquickcontrols2.conf");
}
