import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    Column {
        anchors.centerIn: parent
        spacing: 15
        Button {
            text: "Get Weather Data"
            onClicked: weather.requestWeatherData()
        }

        Label {
            text: weather.location
        }
    }
}
