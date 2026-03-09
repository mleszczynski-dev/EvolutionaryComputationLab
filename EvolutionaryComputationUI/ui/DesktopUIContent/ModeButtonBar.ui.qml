

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls

Rectangle {
    /* default values */
    width: 100

    property int buttonSizePx: 96
    property int buttonIconSizePx: 48

    property alias welcome: buttonWelcome

    Button {
        id: buttonWelcome
        height: buttonSizePx
        width: buttonSizePx
        text: qsTr("Welcome")
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0
        icon.height: buttonIconSizePx
        icon.width: buttonIconSizePx
        display: AbstractButton.TextUnderIcon
        icon.source: "images/welcome.png"
    }

    Button {
        id: buttonNodes
        height: buttonSizePx
        width: buttonSizePx
        text: qsTr("Nodes")
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: buttonWelcome.bottom
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0
        icon.height: buttonIconSizePx
        icon.width: buttonIconSizePx
        display: AbstractButton.TextUnderIcon
        icon.source: "images/nodes.png"
    }

    Button {
        id: buttonTasks
        height: buttonSizePx
        width: buttonSizePx
        text: qsTr("Tasks")
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: buttonNodes.bottom
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0
        icon.height: buttonIconSizePx
        icon.width: buttonIconSizePx
        display: AbstractButton.TextUnderIcon
        icon.source: "images/tasks.png"
    }
}
