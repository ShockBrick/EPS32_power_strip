#ifndef BTDEVICE_H
#define BTDEVICE_H

#include <QObject>


#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>

#include <QVector>
class BTDevice: public QObject
{
    Q_OBJECT
public:
    BTDevice();




private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QVector<QString> *DeviceInformation{};
    QBluetoothSocket *socket;//device 1, for example power strip

    QString DataReadFromSocket{};
    QString selectedDevice{};
public slots:
void setSelectedDevice(QString SlectedDevice1);
 void connectToDevice(QString DeviceInfo);//connection using the first socket
 void connectToDevice();
 void sendMessageToDevice(QString message);
private slots:
  void captureDeviceProperties(const QBluetoothDeviceInfo &device);

  void connectionEstablished();
  void connectionInterrupted();
  void socketReadyToRead();


public:
  QString getDataReadFromSocket() const;

signals:
  void theSocketDataWereRead();

};

#endif // BTDEVICE_H
