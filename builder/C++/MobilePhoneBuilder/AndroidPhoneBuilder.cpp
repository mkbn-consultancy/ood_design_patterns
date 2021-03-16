#include "AndroidPhoneBuilder.h"

void AndroidPhoneBuilder::setName(const std::string& name)
{
    _phoneName = name;
}

void AndroidPhoneBuilder::buildScreen()
{
    _phoneScreen = MobilePhone::ScreenType_e::ScreenType_TOUCH_RESISTIVE;
}

void AndroidPhoneBuilder::buildBattery()
{
    _phoneBattery = MobilePhone::BatteryType_e::MAH_1500;
}

void AndroidPhoneBuilder::buildOS()
{
    _phoneOS = MobilePhone::OperatingSystem_e::ANDROID;
}

void AndroidPhoneBuilder::buildStylus()
{
    _phoneStylus = MobilePhone::Stylus_e::YES;
}

