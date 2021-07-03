import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3



    ListView{

        implicitWidth:lRect.width
        implicitHeight: lRect.height
clip:true

        model: ListModel{
            ListElement{
                device: "iPhone"
            }
            ListElement{
                device: "Samsung"
            }
        }

        delegate: RowLayout{
            width: parent.width
            TextField{

                text: model.device
                Layout.fillWidth: true



            }
        }
    }

