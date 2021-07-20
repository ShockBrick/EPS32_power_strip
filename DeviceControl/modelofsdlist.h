#ifndef MODELOFSDLIST_H
#define MODELOFSDLIST_H


#include "serchbtdevice.h"
//The idea of how to make a combobox in qml with device addresses comes from:
//https://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
//
#include <QObject>
#include <QVector>
struct DeviceAddressItem
{

    QString addressBL;
};


class ModelOfSDList : public QObject
{
    Q_OBJECT
public:
    explicit ModelOfSDList(QObject *parent = nullptr);

    QVector<DeviceAddressItem> items() const;

    bool setItemAt(int index, const DeviceAddressItem &item);

// SerchBtDevice *device1= new SerchBtDevice();



//a

signals:
    void preItemAppended();
    void postIteamAppended();

    void preItemRemoved(int index);
    void postItemRemoved();




public slots:
    void appendItem(QList<QString> comboList);
    void removeCompletedItems();
    void updatedItems(  QList<QString> comboList);
 //void updatedItems( );
private:
    QVector<DeviceAddressItem> mItems;

};

#endif // MODELOFSDLIST_H
