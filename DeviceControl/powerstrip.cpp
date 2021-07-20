#include "powerstrip.h"

/*std::list<device> *powerStrip::getListDevice() const
{
    return listDevice;
}

void powerStrip::setListDevice(std::list<device> *value)
{
    listDevice = value;
}*/

/*powerStrip::powerStrip()
{

}*/

/*std::list<device> powerStrip::getListDevice() const
{
    return listDevice;
}

void powerStrip::setListDevice(const std::list<device> &value)
{
    listDevice = value;
}*/

std::list<device *> powerStrip::getListDevice() const
{
    return listDevice;
}

void powerStrip::setListDevice(const std::list<device *> &value)
{
    listDevice = value;
}

powerStrip::powerStrip(int numES, int numTS)
{
    BTDevice *dev = new BTDevice();
    //std::list <device> *listDevice = new std::list<device>;

    for(int iter=0;iter<numES;iter++)
    {
         electricalSocket *pom;
         listDevice.push_back(pom);
    }
    for(int iter=0;iter<numTS;iter++)
    {
        tempSensor *pom;
        listDevice.push_back(pom);
    }
}

powerStrip::~powerStrip()
{
    delete  dev;
   // delete listDevice;
}
