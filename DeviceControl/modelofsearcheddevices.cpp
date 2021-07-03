#include "modelofsearcheddevices.h"


#include "modelofsdlist.h"
#include <iostream>
ModelOfSearchedDevices::ModelOfSearchedDevices(QObject *parent)
    : QAbstractListModel(parent)
    ,mList(nullptr)
{
}

int ModelOfSearchedDevices::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    // FIXME: Implement me!
    return mList->items().size();
}

QVariant ModelOfSearchedDevices::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const DeviceAddressItem item = mList->items().at(index.row());

    switch (role){
    case DoneRole:
            return QVariant(item.done);
    case DescriptionRole:
        return  QVariant(item.addressBL);
    }
//    const DeviceAddressItem item = mList->items().at(index.row());
//    return QVariant(item.addressBL);

    return QVariant();
}

bool ModelOfSearchedDevices::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
        return false;


    DeviceAddressItem item = mList->items().at(index.row());
     item.addressBL=value.toString();


     switch (role){
     case DoneRole:
            item.done=value.toBool();
          //  qDebug()<<item.done;
         break;
     case DescriptionRole:
         item.addressBL=value.toString();
        // qDebug()<<item.addressBL;
         break;
     }



    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ModelOfSearchedDevices::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> ModelOfSearchedDevices::roleNames() const
{
    QHash<int, QByteArray> names;
    names [DoneRole] = "done";
    names[DescriptionRole] = "description";
    return names;
}

ModelOfSDList *ModelOfSearchedDevices::list() const
{
    return mList;
}

void ModelOfSearchedDevices::setList(ModelOfSDList *list)
{
    beginResetModel();
    if(mList)
        mList->disconnect(this);



    mList = list;


    if(mList){
        connect(mList, &ModelOfSDList::preItemAppended, this, [=](){
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(),index,index);
        });


        connect(mList, &ModelOfSDList::postIteamAppended, this, [=](){
           endInsertRows();
        });

        connect(mList, &ModelOfSDList::preItemRemoved, this, [=](int index){
           beginRemoveRows(QModelIndex(),index,index);
        });

        connect(mList, &ModelOfSDList::postItemRemoved, this, [=](){
           endRemoveRows();
        });

    }



    endResetModel();
}
