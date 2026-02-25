import QtQuick
import DesktopUI

Window {
    width: mainScreen.width
    height: mainScreen.height

    visible: true
    title: "DesktopUI"

    Screen01 {
        id: mainScreen

        anchors.centerIn: parent
    }

}

