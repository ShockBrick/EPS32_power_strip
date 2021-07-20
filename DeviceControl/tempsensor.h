#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H
#include "device.h"


class tempSensor: public device
{
    int tempNumber{0};


    std::string messageFromDevice{};
    std::string messageToDevice{};
public:
    tempSensor();

    std::string getMessageFromDevice() const;
    void setMessageFromDevice(const std::string &value);

    std::string getMessageToDevice() const;
    void setMessageToDevice(const std::string &value);

    int getDeviceNumber() const;
    void setDeviceNumber(int value);


};

#endif // TEMPSENSOR_H
