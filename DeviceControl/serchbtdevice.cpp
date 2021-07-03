#include "serchbtdevice.h"
#include <QDebug>






SerchBtDevice::SerchBtDevice()
{


    discoveryAgent = new QBluetoothDeviceDiscoveryAgent;
   //comboList = new  QQmlListProperty<QString>;// DeviceInformation = new QList<QString>;
    connect(this->discoveryAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this, SLOT(captureDeviceProperties(QBluetoothDeviceInfo)));


    connect(this->discoveryAgent, SIGNAL(finished()),this, SLOT(searchingFinished()));



}


void SerchBtDevice::startSearching()
{
//     qDebug() << "Custom coordinate type:" ;
if(comboList.size()!=0) comboList.clear(); // if(DeviceInformation->size()!=0) DeviceInformation->clear();

    this->discoveryAgent->start();//start searching

}



void SerchBtDevice::captureDeviceProperties(const QBluetoothDeviceInfo &device)
{
 qDebug() << "Custom coordinate type:" ;
//    DeviceInformation->push_back(device.name() + " " + device.address().toString());
// qDebug() << DeviceInformation->last() ;


 comboList.append(device.name() + " " + device.address().toString());
qDebug() << comboList.last();
emit comboListChanged();
}

void SerchBtDevice::searchingFinished()
{
emit searched();
}

