#pragma once
#include <string>

class MobilePhone
{
public:
	enum class ScreenType_e {
		ScreenType_TOUCH_CAPACITIVE,
		ScreenType_TOUCH_RESISTIVE,
		ScreenType_NON_TOUCH
	};

	enum class BatteryType_e
	{
		MAH_1000,
		MAH_1500,
		MAH_2000
	};

	enum class OperatingSystem_e{
		ANDROID,
		WINDOWS_MOBILE,
		WINDOWS_PHONE,
		SYMBIAN
	};

	enum class Stylus_e
	{
		YES,
		NO
	};

	friend class MobileManufactorer;

private:
	MobilePhone(const MobilePhone& mobile) {
		
	}

	//TODO: what if we do not wish to give set methods after the phone is created?
private:
	std::string		_phoneName;
	ScreenType_e	_phoneScreen;
	BatteryType_e	_phoneBattery;
	OperatingSystem_e _phoneOS;
	Stylus_e		_phoneStylus;
};

