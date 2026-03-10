

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

        ModeButtonBar {
            width: 120
            Layout.fillHeight: true

            welcome.onClicked: stackLayout.currentIndex = 0
            nodes.onClicked: stackLayout.currentIndex = 1
            tasks.onClicked: stackLayout.currentIndex = 2
        }

        Rectangle {
            width: 1
            Layout.fillHeight: true

            color: "black"
        }

        StackLayout {
            id: stackLayout

            Layout.fillWidth: true
            Layout.fillHeight: true

            WelcomeWidget {
                id: welcomeWidget
                anchors.fill: parent
            }

            NodesWidget {
                id: nodesWidget
                anchors.fill: parent
            }

            TasksWidget {
                id: tasksWidget
                anchors.fill: parent
            }
        }
    }
}
