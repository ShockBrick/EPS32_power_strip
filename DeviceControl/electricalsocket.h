#ifndef ELECTRICALSOCKET_H
#define ELECTRICALSOCKET_H
#include "device.h"


class electricalSocket: public device
{
    int electricalSocketnumber{0};

    bool OnOff;

    std::string messageFromDevice{};
    std::string messageToDevice{};

public:
    electricalSocket();

    bool getOnOff() const;
    void setOnOff(bool value);

    std::string getMessageFromDevice() const;
    void setMessageFromDevice(const std::string &value);

    std::string getMessageToDevice() const;
    void setMessageToDevice(const std::string &value);


    int getDeviceNumber() const;
    void setDeviceNumber(int value);
};

#endif // ELECTRICALSOCKET_H
