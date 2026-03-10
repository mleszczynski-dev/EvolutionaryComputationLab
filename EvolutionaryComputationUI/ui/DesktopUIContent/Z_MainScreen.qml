

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import DesktopUI
import backend 1.0

Rectangle {
    id: rectangle1
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    // Text {
    //     id: mainText
    //     text: qsTr("Hello Evolutionary Computation UI")
    //     anchors.centerIn: parent
    //     font.family: Constants.font.family
    // }

    Rectangle {
        id: leftBar
        // border.color: black
        // border.width: 5
        color: "lightblue"

        width: 120
        height: parent.height

        ModeButtonBar {
            id: modeButtonBar
            width: 120
            // color: "#ffffff"
            // anchors.left: parent.left
            // anchors.top: parent.top
            // anchors.bottom: parent.bottom
            // anchors.leftMargin: 0
            // anchors.topMargin: 0
            // anchors.bottomMargin: 0

            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: -20

            welcome.onClicked: {
                //mainText.text = welcome.text;
                //BackendObject.welcomeClicked();
                //modeButtonBar.welcome.text = BackendObject.message
            }

            nodes.onClicked: {
                //mainText.text = nodes.text;
                //BackendObject.welcomeClicked();
                //modeButtonBar.welcome.text = BackendObject.message
            }

            tasks.onClicked: {
                //mainText.text = tasks.text;
                //BackendObject.welcomeClicked();
                //modeButtonBar.welcome.text = BackendObject.message
            }
        }
    }

    Item {
        id: centerWidget
    }


}
