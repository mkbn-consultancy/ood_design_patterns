#include <string>

class MobilePhone
{
public:
	enum class ScreenType_e {
		ScreenType_TOUCH_CAPACITIVE, ScreenType_TOUCH_RESISTIVE, ScreenType_NON_TOUCH,NO_VALUE
	};

	enum class BatteryType_e
	{
		MAH_1000, MAH_1500, MAH_2000, NO_VALUE
	};

	enum class OperatingSystem_e {
		ANDROID, WINDOWS_MOBILE, WINDOWS_PHONE, SYMBIAN, NO_VALUE
	};

	enum class Stylus_e
	{
		YES, NO, NO_VALUE
	};
public:
	MobilePhone() : _phoneName(""), _phoneScreen(ScreenType_e::NO_VALUE), _phoneBattery(BatteryType_e::NO_VALUE), _phoneOS(OperatingSystem_e::NO_VALUE), _phoneStylus(Stylus_e::NO_VALUE) {}

	void setPhoneName(const std::string& name) { _phoneName = name; }
	void setScreen(ScreenType_e screen) { _phoneScreen = screen; }
	void setBettery(BatteryType_e bettery) { _phoneBattery = bettery; }
	void setOS(OperatingSystem_e os) { _phoneOS = os; }
	void setStylus(Stylus_e stylus) { _phoneStylus = stylus; }
private:
	std::string		_phoneName;
	ScreenType_e	_phoneScreen;
	BatteryType_e	_phoneBattery;
	OperatingSystem_e _phoneOS;
	Stylus_e		_phoneStylus;
};


int main_old()
{
	//creating an android mobile phone:
	MobilePhone mp;
	mp.setPhoneName("MyAndroid1");
	mp.setOS(MobilePhone::OperatingSystem_e::ANDROID);
	mp.setScreen(MobilePhone::ScreenType_e::ScreenType_TOUCH_CAPACITIVE);
	mp.setBettery(MobilePhone::BatteryType_e::MAH_1500);
	mp.setStylus(MobilePhone::Stylus_e::YES);

	return 0;
}