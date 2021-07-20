#ifndef POWERSTRIP_H
#define POWERSTRIP_H

#include <QObject>
#include <iostream>

#include "device.h"
#include "electricalsocket.h"
#include "tempsensor.h"

#include "btdevice.h"
#include "serchbtdevice.h"
class powerStrip
{
   // std::list <device> *listDevice = nullptr;
std::list<device *> listDevice;
    int numberOfElectricalSocket{0};
    int numberOfTempSensor{0};

    BTDevice *dev = nullptr;

public:
    powerStrip(int numES,int numTS);
    ~powerStrip();
    //std::list<device> *getListDevice() const;
   // void setListDevice(std::list<device> *value);
   // std::list<device> getListDevice() const;
   // void setListDevice(const std::list<device> &value);
    std::list<device *> getListDevice() const;
    void setListDevice(const std::list<device *> &value);
};

#endif // POWERSTRIP_H
