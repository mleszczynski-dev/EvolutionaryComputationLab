

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import DesktopUI
import backend 1.0

Item {
    RowLayout {
        anchors.fill: parent
        spacing: 0
        Layout.fillWidth: true
        Layout.fillHeight: true

        ModeButtonBar {
            Layout.fillHeight: true
            width: 120

            welcome.onClicked: layout.currentIndex = 0
            nodes.onClicked: layout.currentIndex = 1
            tasks.onClicked: layout.currentIndex = 2
        }

        Rectangle {
            // Layout.fillWidth: true
            Layout.fillHeight: true
            width: 1
            color: "black"
        }

        StackLayout {
            id: layout

            //Item { Text { text: "Home" } }
            //Item { Text { text: "Settings" } }

            Rectangle {
                id: welcomePage
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "white"
                Text {
                    anchors.centerIn: parent
                    text: "Welcome"
                }
            }

            Rectangle {
                id: nodesPage
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "white"
                Text {
                    anchors.centerIn: parent
                    text: "Nodes"
                }
            }

            Rectangle {
                id: tasksPage
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "white"
                Text {
                    anchors.centerIn: parent
                    text: "Tasks"
                }
            }
        }


    }
}
