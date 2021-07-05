#include "modelofsdlist.h"
#include <QDebug>
ModelOfSDList::ModelOfSDList(QObject *parent) : QObject(parent)
{
   mItems.append({ QStringLiteral("IPhone")});
  mItems.append({QStringLiteral("Samsung")});
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

void ModelOfSDList::updatedItems(QList<QString> comboList)
{

    mItems.clear();
    for (const auto &i:comboList)
    {

        mItems.append({i});
         qDebug()<<"Dodane do mItems:    "<<mItems.last().addressBL;
    }
//a
}

void ModelOfSDList::appendItem()
{
    emit preItemAppended();

    DeviceAddressItem  item;
    //item.done = false;
    mItems.append(item);

    emit postIteamAppended();
}

void ModelOfSDList::removeCompletedItems()
{
    emit preItemRemoved(1); mItems.removeAt(1); emit postItemRemoved();
}




