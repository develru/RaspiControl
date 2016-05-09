import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    Button {
        text: "Get Weather Data"
        onClicked: weather.requestWeatherData()
    }
}
