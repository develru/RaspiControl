import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.3

Label {
    property string textColor: "white" //"#6ac3b2"
    color: textColor
}

//Item {
//    id: myLabel
//    property string textColor: "#6ac3b2"
//    property alias text: label.text
//    property alias font: label.font
//    Label {
//        id: label
//        color: textColor
//    }
//}
