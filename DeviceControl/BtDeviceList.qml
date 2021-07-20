import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

import Devices11 1.0

ListView{
    id: listOfAvailableDevices
    property alias listview: listOfAvailableDevices
    implicitWidth:lRect.width
    implicitHeight: lRect.height
    clip:true

    model: ModelOfSearchedDevices{
        list: lll
    }
    delegate: RowLayout{
        width: parent.width
        TextField{
            id:textFinList
            readOnly: true
            text: model.description
            Layout.fillWidth: true
            //a


            MouseArea{
                id:mouseAreaListView
                anchors.fill:parent
                onClicked:Dev.setSelectedDevice(textFinList.text)
            }
        }


    }


}

