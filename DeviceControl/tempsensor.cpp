#include "tempsensor.h"

std::string tempSensor::getMessageFromDevice() const
{
    return messageFromDevice;
}

void tempSensor::setMessageFromDevice(const std::string &value)
{
    messageFromDevice = value;
}

std::string tempSensor::getMessageToDevice() const
{
    return messageToDevice;
}

void tempSensor::setMessageToDevice(const std::string &value)
{
    messageToDevice = value;
}

int tempSensor::getDeviceNumber() const
{

}

void tempSensor::setDeviceNumber(int value)
{

}





tempSensor::tempSensor()
{

}
