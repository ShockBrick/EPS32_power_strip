#include "btdevice.h"

BTDevice::BTDevice()
{
    this->socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);


    connect(this->socket, SIGNAL(connected()),this, SLOT(connectionEstablished()));
    connect(this->socket, SIGNAL(disconnected()),this, SLOT(connectionInterrupted()));
    connect(this->socket, SIGNAL(readyRead()),this, SLOT(socketReadyToRead()));

}

void BTDevice::setSelectedDevice(QString SlectedDevice1)
{
    selectedDevice=SlectedDevice1;
    qDebug()<<selectedDevice<<"Selected device";
}



void BTDevice::connectToDevice(QString DeviceInfo)
{
    qDebug()<<"DeviceInfo:  "<<DeviceInfo;
//    QStringList portList = DeviceInfo.split(" ");
//    QString deviceAddres = portList.last();

//    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
//    socket->connectToService(QBluetoothAddress(deviceAddres),QBluetoothUuid(serviceUuid),QIODevice::ReadWrite);
//   // this->addToLogs("Rozpoczęto łączenie z urządzeniem o nazwie: " + portList.first() + " i adresie: " + deviceAddres);

}

void BTDevice::connectToDevice()
{
    qDebug()<<"Rozpoczęcie połączenia";
    QStringList portList = selectedDevice.split(" ");
    QString deviceAddres = portList.last();
qDebug()<<"de3viceAdress:   "<<deviceAddres;
    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(deviceAddres),QBluetoothUuid(serviceUuid),QIODevice::ReadWrite);

   // this->addToLogs("Rozpoczęto łączenie z urządzeniem o nazwie: " + portList.first() + " i adresie: " + deviceAddres);

}


void BTDevice::sendMessageToDevice(QString message)
{

    if(socket->isOpen() && socket->isWritable()) {
    qDebug()<<"Wysyłam";
        socket->write(message.toStdString().c_str());
         qDebug()<<"Wysłałem:   "<<message;
      } else {
        qDebug()<<"Jesten w błedach:    "<<socket->isOpen()<<"  "<< socket->isWritable();
      }
}

void BTDevice::captureDeviceProperties(const QBluetoothDeviceInfo &device)
{
    DeviceInformation->push_front(device.name() + " " + device.address().toString());
}

void BTDevice::connectionEstablished()
{

}

void BTDevice::connectionInterrupted()
{

}


void BTDevice::socketReadyToRead()
{
    while(socket->canReadLine()) {
        QString line = socket->readLine();
        //qDebug() << line;

        QString terminator = "\r";
        int pos = line.lastIndexOf(terminator);
        //qDebug() << line.left(pos);

       DataReadFromSocket = line.left(pos);
      }
}
