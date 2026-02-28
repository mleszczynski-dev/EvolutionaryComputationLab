

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import DesktopUI

Rectangle {
    id: rectangle1
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    Text {
        text: qsTr("Hello Evolutionary Computation UI")
        anchors.centerIn: parent
        font.family: Constants.font.family
    }

    Rectangle {
        id: leftButtonBar
        width: 120
        color: "#ffffff"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.bottomMargin: 0

        Button {
            id: buttonTasks
            height: buttonTasks.width
            text: qsTr("Tasks")
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: buttonNodes.bottom
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            icon.height: Constants.buttonImageHeight
            icon.width: Constants.buttonImageWidth
            display: AbstractButton.TextUnderIcon
            icon.source: "images/tasks.png"
        }

        Button {
            id: buttonNodes
            y: 578
            height: buttonNodes.width
            text: qsTr("Nodes")
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            icon.width: Constants.buttonImageWidth
            icon.source: "images/nodes.png"
            icon.height: Constants.buttonImageHeight
            display: AbstractButton.TextUnderIcon
        }

        Button {
            id: buttonWelcome
            height: buttonWelcome.width
            text: qsTr("Welcome")
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: buttonNodes.bottom
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            icon.width: Constants.buttonImageWidth
            icon.source: "images/welcome.png"
            icon.height: Constants.buttonImageHeight
            display: AbstractButton.TextUnderIcon
        }
    }
}
