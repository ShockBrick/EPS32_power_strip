//QT += quickcontrols2
QT += quick
QT += core gui bluetooth

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        btdevice.cpp \
        device.cpp \
        electricalsocket.cpp \
        main.cpp \
        modelofsdlist.cpp \
        modelofsearcheddevices.cpp \
        powerstrip.cpp \
        serchbtdevice.cpp \
        tempsensor.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    btdevice.h \
    device.h \
    electricalsocket.h \
    modelofsdlist.h \
    modelofsearcheddevices.h \
    powerstrip.h \
    serchbtdevice.h \
    tempsensor.h

DISTFILES +=
