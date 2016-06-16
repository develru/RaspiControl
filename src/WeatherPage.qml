import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.3

Item {
    id: mainItem
    //anchors.fill: parent

    RowLayout {
        spacing: 50
        anchors.centerIn: mainItem
//            anchors.fill: parent
        Rectangle {
            anchors.fill: parent
            color: "blue"

        //anchors.fill: parent
        ColumnLayout {
            id: currentWeather
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            //Layout.preferredWidth: 400 //mainItem.width / 2
            //Layout.preferredHeight: 400
            //width: mainItem.width / 2
            Component.onCompleted: weather.viewIsReaddy()
            Component.onDestruction: if (weather != null)
                                         weather.stopTimer()
            spacing: 15

            Image {
                Layout.preferredWidth: 200
                Layout.preferredHeight: 200
                //height: 200
                //width: 200
                anchors.horizontalCenter: parent.horizontalCenter
                source: weather.icon
            }
            MyLabel {
                text: weather.temp + "°C"
                font.bold: true
                font.pointSize: 22
                anchors.horizontalCenter: parent.horizontalCenter
            }

            MyLabel {
                text: weather.description
                font.pointSize: 18
                anchors.horizontalCenter: parent.horizontalCenter
            }

            MyLabel {
                text: weather.location
                font.italic: true
                font.pointSize: 18
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Component {
            id: forecastDelegate
            RowLayout {
                spacing: 10
                Image {
                    source: model.icon
                    Layout.preferredWidth: 50
                    Layout.preferredHeight: 50
                    //width: 50
                    //height: 50
//                    anchors.rightMargin: 10
                }
                ColumnLayout {
                    MyLabel {
                        text: model.temp
                    }
                    MyLabel {
                        text: model.description
                    }
                    MyLabel {
                        anchors.bottomMargin: 10
                        text: model.time
                    }
                }
            }
        }

        ColumnLayout {
            //width: mainItem.width / 2
            //height: mainItem.height
            //anchors.left: currentWeather.right
            ListView {
                spacing: 10
                //anchors.verticalCenter: parent.verticalCenter
                width: parent.width
                height: 4*60
                model: weather.dataModel
                delegate: forecastDelegate
            }
        }
    }

    }

/*    Row {
        id: mainRow
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
            MyLabel {
                text: weather.temp + "°C"
                font.bold: true
                font.pointSize: 22
                anchors.horizontalCenter: parent.horizontalCenter
            }

            MyLabel {
                text: weather.description
                font.pointSize: 18
                anchors.horizontalCenter: parent.horizontalCenter
            }

            MyLabel {
                text: weather.location
                font.italic: true
                font.pointSize: 18
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Component {
            id: forecastDelegate
            Row {
                spacing: 10
                Image {
                    source: model.icon
                    width: 50
                    height: 50
//                    anchors.rightMargin: 10
                }
                Column {
                    MyLabel {
                        text: model.temp
                    }
                    MyLabel {
                        text: model.description
                    }
                    MyLabel {
                        anchors.bottomMargin: 10
                        text: model.time
                    }
                }
            }
        }

        Column {
            width: mainItem.width / 2
            height: mainItem.height
            anchors.left: currentWeather.right
            ListView {
                spacing: 10
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width
                height: 4*60
                model: weather.dataModel
                delegate: forecastDelegate
            }
        }
    }*/
}
