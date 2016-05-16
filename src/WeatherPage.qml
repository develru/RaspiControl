import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    Column {
        Component.onCompleted: weather.viewIsReaddy()
        Component.onDestruction: if (weather != null)  weather.stopTimer()
        anchors.centerIn: parent
        spacing: 15

        Image {
            source: weather.icon
            height: 200
            width: 200
//            antialiasing: true
        }
        Label {
            text: weather.temp + "°C"
            font.bold: true
            font.pointSize: 22
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Label {
            text: weather.description
            font.pointSize: 18
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Label {
            text: weather.location
            font.italic: true
            font.pointSize: 18
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
