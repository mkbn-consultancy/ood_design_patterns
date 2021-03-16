#pragma once

#include "PhoneBuilderImp.h"

class AndroidPhoneBuilder : public PhoneBuilderImp
{
public:
    virtual void setName(const std::string& name);
    virtual void buildScreen();
    virtual void buildBattery();
    virtual void buildOS();
    virtual void buildStylus();
};

