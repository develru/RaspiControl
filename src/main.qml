import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id: mainWin
    property string bgColor: "#078c72"
    property string toolBarColor: "#045d4c"
    property string buttonColor: "#033e32"
    property string buttonColorDown: "#022e26"
    property string buttonColorHover: "#20a58b"
    property string buttonTextColor: "#6ac3b2"
    property string buttonBorderColor: "#056d58"

    visible: true
    width: 800
    height: 480
    title: qsTr("Pi control")
    style: ApplicationWindowStyle {
        background: Rectangle {
            color: mainWin.bgColor
        }
    }

    toolBar: ToolBar {
        style: ToolBarStyle {
            background: Rectangle {
                implicitWidth: mainWin.width
                implicitHeight: 40
                color: mainWin.toolBarColor
            }
        }

        ToolButton {
            style: myButtonStyle
            visible: stackView.depth > 1 ? true : false
            height: parent.height
            text: qsTr("Back")
            onClicked: stackView.pop()
        }

        MyLabel {
            anchors.centerIn: parent
            font.pixelSize: 24
            text: "Test"
        }

        ToolButton {
            style: myButtonStyle
            height: parent.height
            anchors.right: parent.right
            text: qsTr("Quit")
            onClicked: Qt.quit()
        }
    }

    statusBar: StatusBar {
        style: StatusBarStyle {
            background: Rectangle {
                color: mainWin.toolBarColor
            }
        }
        MyLabel {
            text: "Last update: " + weather.lastUpdateTime
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
                    style: myButtonStyle
                    height: 50
                    text: qsTr("Weather")
                    onClicked: stackView.push(Qt.resolvedUrl(
                                                  "/WeatherPage.qml"))
                }

                Button {
                    style: myButtonStyle
                    height: 50
                    text: qsTr("Camera")
                    onClicked: stackView.push(Qt.resolvedUrl("/CameraPage.qml"))
                }
            }
        }
    }

    Component {
        id: myButtonStyle
        ButtonStyle {
            background: Rectangle {
                id: bRect
                implicitWidth: 80
                implicitHeight: 25
                border.width: control.activeFocus ? 3 : 2
                border.color: mainWin.buttonBorderColor
                //                width: control.text.contentWidth
                //                height: control.height
                radius: 2
                color: control.pressed ? mainWin.buttonColorDown : (control.hovered ? mainWin.buttonColorHover : mainWin.buttonColor)
            }
            label: Item {
                id: labelItem
                Label {
                    anchors.leftMargin: 8
                    //                verticalAlignment: Text.AlignVCenter
                    anchors.centerIn: parent
                    color: mainWin.buttonTextColor
                    text: control.text
                }
            }
        }
    }
}
