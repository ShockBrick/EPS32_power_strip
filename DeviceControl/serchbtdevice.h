#ifndef SERCHBTDEVICE_H
#define SERCHBTDEVICE_H

#include <QBluetoothDeviceDiscoveryAgent>
#include <QObject>
#include <QList>
#include <QVector>
#include <QQmlListProperty>

class  ModelOfSDList;

class SerchBtDevice : public QObject
{

    Q_OBJECT
    Q_PROPERTY(QList<QString> comboList MEMBER comboList  NOTIFY comboListChanged );

//
public:
    SerchBtDevice();
     QList<QString> getComboList();
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
