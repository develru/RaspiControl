import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    Column {
        Component.onCompleted: weather.requestWeatherData()
        anchors.centerIn: parent
        spacing: 15

        Label {
            text: weather.temp
        }

        Label {
            text: weather.description
        }

        Label {
            text: weather.location
        }
    }

    //        Button {
    //            text: "Get Weather Data"
    //            onClicked: weather.requestWeatherData()
    //        }
}
