import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.1


import QtLocation 5.12
import QtPositioning 5.12

import Devices11 1.0

Window {
    id:w1
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Hello World")

    Rectangle{
        x:0
        y:0
        width:  w1.width
        height: w1.height
        color: "lightblue"

    }

    Rectangle {
        x:5
        y:5
        width:  lRect.width+rRect.width+20
        height: lRect.height+10+cbDevice.height+10
        color:"white"
    Rectangle{
        id:lRect
        x:5
        y:5
        width:  w1.width/2 -10
        height: lRectText.height+15
        color:"cadetblue"
        Text{
            id:lRectText
            anchors.centerIn: parent
            text: "Search Devices";font.pixelSize: 15
            color: mouseArea.pressed ? "green" : "black"

            MouseArea{
                id:mouseArea
                anchors.fill:parent
                onClicked: {
                                 _Device1.startSearching();
                                 console.log("clicked lRect")

                                 mouse.accepted = false
                             }
            }
        }
    }

    Rectangle{
        id:rRect
        x:lRect.width+15
        y:5
        width:  w1.width/2 -20
        height: lRect.height
        color:"cadetblue"
//        TextInput{

//            anchors.left:parent.left; y:16
//            anchors.right:parent.right
//            anchors.centerIn: parent
//            text:"Device";
//            font.pixelSize:15
//            color:activeFocus ? "black":"red"
//            focus:true
//            activeFocusOnTab:true

//        }
        MouseArea{

            anchors.fill:parent
onClicked:Dev.sendMessageToDevice("1_1") ;

//a

        }

    }


    Rectangle{
        id:ldRect
        x:5
         y:lRect.height+15
        width: lRect.width
        height: lRect.height
        color:"cadetblue"

        BtDeviceList{
            id: cbDevice

    anchors.centerIn: parent
        }

    }

    Rectangle{
        id:rdRect
        x:ldRect.width+15
        y:rRect.height+15
        width: rRect.width
        height: rdRectText.height+15
        color:"cadetblue"
        Text{
            id:rdRectText
            anchors.centerIn: parent
            text: "Connect";
            font.pixelSize:15
            color: mouseAreaRdRect.pressed ? "green" : "black"

            MouseArea{
                id:mouseAreaRdRect
                anchors.fill:parent
onClicked:Dev.connectToDevice() ;

//a

            }
        }
    }

    }





    Rectangle{
        id:setRec
        x:10
         y:lRect.height+15+ldRect.height+15
        width:  w1.width/2 -20
        height: lRect.height
        color:"cadetblue"
        Text{

            anchors.centerIn: parent
            text: "Set";
            font.pixelSize:15
            color: mouseAreaRdRect.pressed ? "green" : "black"}
        MouseArea{

            anchors.fill:parent
onClicked:Dev.sendMessageToDevice("1_1") ;


        }
    }

    Rectangle{
        id:resetRec
        x:ldRect.width+15
        y:rdRect.height+15+rRect.height+10

        width:  w1.width/2 -20
        height: lRect.height
        color:"cadetblue"
        Text{

            anchors.centerIn: parent
            text: "Reset";
            font.pixelSize:15
            color: mouseAreaRdRect.pressed ? "green" : "black"}
        MouseArea{

            anchors.fill:parent
onClicked:Dev.sendMessageToDevice("1_0") ;

//a

        }
    }
    }


//}



