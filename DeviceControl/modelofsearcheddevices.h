#ifndef MODELOFSEARCHEDDEVICES_H
#define MODELOFSEARCHEDDEVICES_H

#include <QAbstractListModel>
//The idea of how to make a combobox in qml with device addresses comes from:
//https://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
//
class  ModelOfSDList;

class ModelOfSearchedDevices : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ModelOfSDList *list READ list WRITE setList  )

public:
    explicit ModelOfSearchedDevices(QObject *parent = nullptr);

    enum{

        DescriptionRole
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    ModelOfSDList *list() const;
    void setList(ModelOfSDList *list);

private:
    ModelOfSDList *mList;


};

#endif // MODELOFSEARCHEDDEVICES_H
