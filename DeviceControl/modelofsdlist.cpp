#include "modelofsdlist.h"

ModelOfSDList::ModelOfSDList(QObject *parent) : QObject(parent)
{
    mItems.append({true, QStringLiteral("IPhone")});
    mItems.append({true, QStringLiteral("Samsung")});
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

void ModelOfSDList::appendItem()
{
    emit preItemAppended();

    DeviceAddressItem  item;
    item.done = false;
    mItems.append(item);

    emit postIteamAppended();
}

void ModelOfSDList::removeCompletedItems()
{
    for(int i=0; i<mItems.size();){
        if(mItems.at(i).done){emit preItemRemoved(i); mItems.removeAt(i); emit postItemRemoved();}
        else{++i;}
    }
}
