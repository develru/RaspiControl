import QtQuick 2.4
import QtQuick.Controls 1.3


ApplicationWindow {
    visible: true
    width: 800
    height: 480
    title: qsTr("Pi control")

    //    menuBar: MenuBar {
    //        Menu {
    //            title: qsTr("File")
    //            MenuItem {
    //                text: qsTr("&Open")
    //                onTriggered: console.log("Open action triggered");
    //            }
    //            MenuItem {
    //                text: qsTr("Exit")
    //                onTriggered: Qt.quit();
    //            }
    //        }
    //    }
    toolBar: ToolBar {
        ToolButton {
            visible: stackView.depth > 1 ? true : false
            height: parent.height
            text: qsTr("Back")
            onClicked: stackView.pop()
        }

        ToolButton {
            height: parent.height
            anchors.right: parent.right
            text: qsTr("Quit")
            onClicked: Qt.quit()
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent

        // Implements back key navigation
        focus: true
        Keys.onReleased: if (event.key === Qt.Key_Back && stackView.depth > 1) {
                             stackView.pop()
                             event.accepted = true
                         }

        initialItem: Item {
            width: parent.width
            height: parent.height

            Column {
                anchors.centerIn: parent
                spacing: 15
                Button {
                    height: 50
                    text: qsTr("Weather")
                    onClicked: stackView.push(Qt.resolvedUrl("/WeatherPage.qml"))
                }

                Button {
                    height: 50
                    text: qsTr("Camera")
                    onClicked: stackView.push(Qt.resolvedUrl("/CameraPage.qml"))
                }
            }
        }
    }
}
