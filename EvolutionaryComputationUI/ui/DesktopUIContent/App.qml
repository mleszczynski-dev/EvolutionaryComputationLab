import QtQuick
import DesktopUI

Window {
    readonly property int defaultWidth: 1280
    readonly property int defaultHeight: 960

    width: defaultWidth
    height: defaultHeight

    minimumWidth: defaultWidth * 0.75
    minimumHeight: defaultHeight * 0.75

    visible: true

    title: "Evolutionary Computation UI"

    MainScreen {
        id: mainScreen
        anchors.fill: parent
    }
}
