import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
Window {
    id : r
    visible: true
    width: 1920
    height: 1060
    title: qsTr("Hello World")
    property int total_width   : 22440
    property int ratio         : 12
    property int window_length : windowLength.value    / r.ratio;
    property int window_sep    : windowSep.value   / r.ratio;
    property int window_side   : (total_width - (windowCount.value*windowLength.value+(windowCount.value-1)*windowSep.value))/2   / r.ratio;
    property int window_count  : windowCount.value

    property int window_length2 : 970    / r.ratio;
    property int window_sep2    : 1600   / r.ratio;
    property int window_side2   : 1740   / r.ratio;
    property int window_count2  : 8
    Rectangle{
        width:total_width/r.ratio;
        height:300;
        color:'grey';
        opacity: 0.2;
    }

    Repeater{
        model : [6550, 6750, 7850, 8000, 11127, 11277, 15715, 15865, 18459, 18563, 20708, 20812]
        Rectangle{
            y : 0
            x : modelData/r.ratio;
            width:1;
            height:300;
            color:"yellow";
        }
    }
    Repeater{
        model:r.window_count;
        Rectangle{
            y : 200;
            x : r.window_side + (r.window_length+r.window_sep)*index;
            height : 10;
            width:r.window_length;
            color:"green";
            onWidthChanged: {
                var array = [6550, 6750, 7850, 8000, 11127, 11277, 15715, 15865, 18459, 18563, 20708, 20812]
                var red = false
                color='green'
                for(var i=0;i<array.length;i++){
                    var value = array[i]/r.ratio;
                    if(x < value && x+width > value){
                        red = true;
                        break;
                    }
                }
                color=red?'red':'green';
            }
            onXChanged: {
                var array = [6550, 6750, 7850, 8000, 11127, 11277, 15715, 15865, 18459, 18563, 20708, 20812]
                var red = false
                color='green'
                for(var i=0;i<array.length;i++){
                    var value = array[i]/r.ratio;
                    if(x < value && x+width > value){
                        red = true;
                        break;
                    }
                }
                color=red?'red':'green';
            }
        }
    }
//    Repeater{
//        model:r.window_count2;
//        Rectangle{
//            y : 250;
//            x : r.window_side2 + (r.window_length2+r.window_sep2)*index;
//            height : 10;
//            width:r.window_length2;
//            color:"green";
//        }
//    }
    Grid{
        y:320;
        width:600;
        height:400;
        columns:2;
        columnSpacing: 0;
        property int itemWidth : width/columns;
        Button{
            text:"Window Length : " + parseInt(windowLength.value);
            width:parent.itemWidth;
        }
        Slider{
            id:windowLength;
            width:parent.itemWidth;
            from:500;
            to:2000;
        }
        Button{
            text:"Window Sep   : " + parseInt(windowSep.value);
            width:parent.itemWidth;
        }
        Slider{
            id:windowSep;
            width:parent.itemWidth;
            from:800;
            to:2000;
        }
        Button{
            text:"Window Count"
            width:parent.itemWidth;
        }
        SpinBox{
            id:windowCount;
            width:parent.itemWidth;
            from:8;
            to:20;
        }
    }
}
