#include "electricalsocket.h"

bool electricalSocket::getOnOff() const
{
    return OnOff;
}

void electricalSocket::setOnOff(bool value)
{
    OnOff = value;
}



std::string electricalSocket::getMessageFromDevice() const
{
    return messageFromDevice;
}

void electricalSocket::setMessageFromDevice(const std::string &value)
{
    messageFromDevice = value;
}

std::string electricalSocket::getMessageToDevice() const
{
    return messageToDevice;
}

void electricalSocket::setMessageToDevice(const std::string &value)
{
    messageToDevice = value;
}

int electricalSocket::getDeviceNumber() const
{
    return electricalSocketnumber;
}

void electricalSocket::setDeviceNumber(int value)
{
    electricalSocketnumber = value;
}

electricalSocket::electricalSocket()
{
    
}
