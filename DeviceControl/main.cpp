#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "btdevice.h"
#include "serchbtdevice.h"
#include "modelofsearcheddevices.h"
#include "modelofsdlist.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<ModelOfSearchedDevices>("Devices11",1,0,"ModelOfSearchedDevices");
    qmlRegisterUncreatableType<ModelOfSDList>("Devices11",1,0,"ModelOfSDList",QStringLiteral("List should not be created in QML"));

    QQmlApplicationEngine engine;



  SerchBtDevice *Sdevice1= new SerchBtDevice();
   ModelOfSDList *l1 = new ModelOfSDList;
    QQmlContext *context=engine.rootContext();
BTDevice *dev = new BTDevice();
      //    QVector<DeviceAddressItem> apom = l1->items();
//    qDebug()<<apom.first().addressBL;
//    QObject::connect(device1, &SerchBtDevice::comboListChanged,l1,[=](){
//        l1->updatedItems(device1->getComboList());
//    });

//    context->setContextProperty("lll",l1);


    QVector<DeviceAddressItem> apom =l1->items();
    qDebug()<<apom.first().addressBL;
    QObject::connect(Sdevice1, &SerchBtDevice::comboListChanged,l1,[=](){
        l1->appendItem(Sdevice1->getComboList());
    });

    context->setContextProperty("lll",l1);


    context->setContextProperty("_Device1",Sdevice1);
    context->setContextProperty("Dev",dev);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
