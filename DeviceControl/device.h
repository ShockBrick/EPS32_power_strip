#ifndef DEVICE_H
#define DEVICE_H



#include <iostream>

class device
{
    int deviceNumber{};

    bool OnOff;

    std::string messageFromDevice;
    std::string messageToDevice;
public:
    device();

    virtual bool getOnOff() const;
    virtual void setOnOff(bool value);

    virtual std::string getMessageFromDevice() const  =0;
    virtual void setMessageFromDevice(const std::string &value)  =0;

    virtual std::string getMessageToDevice() const  =0;
    virtual void setMessageToDevice(const std::string &value) =0;

    virtual int getDeviceNumber() const  =0;
    virtual void setDeviceNumber(int value) =0;
};
#endif // DEVICE_H
