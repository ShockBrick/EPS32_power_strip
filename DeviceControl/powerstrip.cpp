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

void powerStrip::dataFromControlerWereRead()
{
    try {
        std::string pom = dev->getDataReadFromSocket().toUtf8().constData();//data should be : "number;Temp;humidity"
        if(!pom.empty())
        {
            std::string tab[]={"","",""};
            //tab={number,Temp,humidity}
            int iter=0;
            for(auto i:pom)
            {
                if (i==';')
                {
                    iter++;
                }
                else
                {
                    tab[iter]=tab[iter]+i;
                }
            }
             int nr = std::stoi(tab[0]);
             int iterNumber=numberOfElectricalSocket-1+nr;
             for(std::list<device *>::size_type iter=0;iter<listDevice.size();iter++)
             {
                 if(iter==iterNumber)
                 {


                 }

             }
        }

    }  catch (int a) {

    }
}

powerStrip::powerStrip(int numES, int numTS)
{
    numberOfElectricalSocket=numES;
    numberOfTempSensor=numTS;
    BTDevice *dev = new BTDevice();
    //std::list <device> *listDevice = new std::list<device>;
    connect(dev, &BTDevice::theSocketDataWereRead,this,&powerStrip::dataFromControlerWereRead);

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
