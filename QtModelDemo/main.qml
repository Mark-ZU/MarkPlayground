import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2
import Tmp 1.0 as Tmp
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Tmp.DataModel{
        id : dataModel;
    }

    ListView {
        anchors.fill: parent;
        model: dataModel
        spacing:1;
        delegate: Rectangle {
            height: 20
            width: mWidth;
            color:"red"
            Text{
                id : text;
                text: ": "+mWidth;
                anchors.centerIn: parent;
            }
//            onWidthChanged: {
//                if(width < 200)
//                    color = "#d9534f"
//                else if(width < 400)
//                    color = "#f0ad4e"
//                else color = "#5cb85c"
//            }
//            Behavior on width {
//                NumberAnimation{ duration: 100}
//            }
//            Behavior on color {
//                ColorAnimation {
//                    duration: 1500
//                }
//            }
        }
    }
}
