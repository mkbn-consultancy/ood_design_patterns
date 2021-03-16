#include "WinPhoneBuilder.h"

void WinPhoneBuilder::setName(const std::string& name)
{
    _phoneName = name;
}

void WinPhoneBuilder::buildScreen()
{
    _phoneScreen = MobilePhone::ScreenType_e::ScreenType_TOUCH_CAPACITIVE;
}

void WinPhoneBuilder::buildBattery()
{
    _phoneBattery = MobilePhone::BatteryType_e::MAH_2000;
}

void WinPhoneBuilder::buildOS()
{
    _phoneOS = MobilePhone::OperatingSystem_e::WINDOWS_PHONE;
}

void WinPhoneBuilder::buildStylus()
{
    _phoneStylus = MobilePhone::Stylus_e::NO;
}

