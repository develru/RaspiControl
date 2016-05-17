import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.3

Item {
    id: mainItem
//    anchors.fill: parent
    Row {
        spacing: 15
        Column {
            id: currentWeather
            width: mainItem.width / 2
            Component.onCompleted: weather.viewIsReaddy()
            Component.onDestruction: if (weather != null)
            weather.stopTimer()
            spacing: 15

            Image {
                height: 200
                width: 200
                anchors.horizontalCenter: parent.horizontalCenter
                source: weather.icon
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

        ListView {
            anchors.left: currentWeather.right
            model: weather.forecastList
            delegate: Label {
                text: modelData
            }
        }
    }
}
