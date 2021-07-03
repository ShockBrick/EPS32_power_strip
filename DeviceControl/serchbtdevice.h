#ifndef SERCHBTDEVICE_H
#define SERCHBTDEVICE_H

#include <QBluetoothDeviceDiscoveryAgent>
#include <QObject>
#include <QList>
#include <QQmlListProperty>
class SerchBtDevice : public QObject
{

    Q_OBJECT
    Q_PROPERTY(QList<QString> comboList MEMBER comboList  NOTIFY comboListChanged );

//
public:
    SerchBtDevice();
public slots:
    void startSearching();

signals:
    void searched();
    void comboListChanged();
private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
   // QList<QString> *DeviceInformation{};
    QList<QString> comboList;
   // QList<QString> *comboList{};



private slots:
  void captureDeviceProperties(const QBluetoothDeviceInfo &device);
  void searchingFinished();

};

#endif // SERCHBTDEVICE_H
