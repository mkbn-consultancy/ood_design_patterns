#pragma once
#include "IPhoneBuilder.h"
#include "MobilePhone.h"

class PhoneBuilderImp : public IPhoneBuilder
{
public:
	virtual MobilePhone* phone() { return _phone; }

protected:
	std::string					_phoneName;
	MobilePhone::ScreenType_e	_phoneScreen;
	MobilePhone::BatteryType_e	_phoneBattery;
	MobilePhone::OperatingSystem_e _phoneOS;
	MobilePhone::Stylus_e		_phoneStylus;
	MobilePhone*				_phone;

};