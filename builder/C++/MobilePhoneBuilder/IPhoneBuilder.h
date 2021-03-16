#pragma once

#include <string>

//forward declaration
class MobilePhone;

class IPhoneBuilder
{
public:
    virtual void setName(const std::string&) = 0;
    virtual void buildScreen() = 0;
    virtual void buildBattery() = 0;
    virtual void buildOS() = 0;
    virtual void buildStylus() = 0;
    virtual MobilePhone* phone() = 0;
};
