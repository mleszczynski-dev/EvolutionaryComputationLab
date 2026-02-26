

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
        id: rectangle
        width: 150
        height: 150
        color: "#ffffff"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 0
        anchors.topMargin: 0

        Image {
            id: image
            width: 100
            height: 100
            source: "images/nodes.png"
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: text1
            width: 92
            height: 16
            text: qsTr("Computing nodes")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Rectangle {
        id: rectangle2
        width: 150
        height: 150
        color: "#ffffff"
        anchors.left: parent.left
        anchors.top: rectangle.bottom
        anchors.leftMargin: 0
        anchors.topMargin: 0
        Image {
            id: image1
            width: 100
            height: 100
            source: "images/tasks.png"
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }

        Text {
            id: text2
            width: 92
            height: 16
            text: qsTr("Computing tasks")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
