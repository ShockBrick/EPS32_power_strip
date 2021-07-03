#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


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




    SerchBtDevice *device1= new SerchBtDevice();
    ModelOfSDList *l1 = new ModelOfSDList;
    QQmlContext *context=engine.rootContext();

    QVector<DeviceAddressItem> apom = l1->items();
//qDebug()<<apom.first().addressBL;
 context->setContextProperty("lll",l1);
   context->setContextProperty("_Device1",device1);




   const QUrl url(QStringLiteral("qrc:/main.qml"));
   QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                    &app, [url](QObject *obj, const QUrl &objUrl) {
       if (!obj && url == objUrl)
           QCoreApplication::exit(-1);
   }, Qt::QueuedConnection);
  engine.load(url);

int a=0;
int b=5;
int suma= a+b;
    return app.exec();
}
