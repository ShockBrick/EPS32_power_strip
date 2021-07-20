#include "modelofsdlist.h"
#include <QDebug>
ModelOfSDList::ModelOfSDList(QObject *parent) : QObject(parent)
{
   mItems.append({ QStringLiteral("Lists of Devices:")});
}

QVector<DeviceAddressItem> ModelOfSDList::items() const
{
    return mItems;
}

bool ModelOfSDList::setItemAt(int index, const DeviceAddressItem &item)
{
    if(index < 0 || index >= mItems.size() )
        return false;


    const DeviceAddressItem &oldItem = mItems.at(index);
    if (item.addressBL==oldItem.addressBL)
        return false;

    mItems[index] = item;
    return true;
}

//void ModelOfSDList::updatedItems(QList<QString> comboList)
void ModelOfSDList::updatedItems( QList<QString> comboList)
{

//    while(mItems.size()!=1)
//    {
//        mItems.pop_back();
//    }
//    qDebug()<<mItems.size();
//    for (const auto &i:comboList)
//    {

//        mItems.append({i});
//         qDebug()<<"Dodane do mItems:    "<<mItems.last().addressBL;
//    }

//    qDebug()<<mItems.size();

}

void ModelOfSDList::appendItem(QList<QString> comboList)
{


if (comboList.size()!=0){
    while(mItems.size()!=1)
    {
         emit preItemRemoved(mItems.size()-1);
        mItems.pop_back();
        emit postItemRemoved();
    }
    qDebug()<<mItems.size();


    for (const auto &i:comboList)
    {
        emit preItemAppended();
qDebug()<<"ComboList size:     "<<comboList.size();
        mItems.append({i});
         qDebug()<<"Dodane do mItems:    "<<mItems.last().addressBL;
         emit postIteamAppended();
    }

    qDebug()<<mItems.size();}

//    DeviceAddressItem  item;
//    item.addressBL=device1->getComboList().first();
//    mItems.append(item);



//    for (const auto &i:device1->getComboList())
//    {

//        DeviceAddressItem  item;
//        item.addressBL=i;
//        mItems.append(item);
//    }


}

void ModelOfSDList::removeCompletedItems()
{


    emit preItemRemoved(1); mItems.removeAt(0); emit postItemRemoved();
}




