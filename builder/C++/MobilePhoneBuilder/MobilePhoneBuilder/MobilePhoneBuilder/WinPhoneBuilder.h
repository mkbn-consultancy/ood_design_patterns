#pragma once
#include "PhoneBuilderImp.h"

class WinPhoneBuilder : public PhoneBuilderImp
{
public:
    virtual void setName(const std::string&);
    virtual void buildScreen();
    virtual void buildBattery();
    virtual void buildOS();
    virtual void buildStylus();
};

