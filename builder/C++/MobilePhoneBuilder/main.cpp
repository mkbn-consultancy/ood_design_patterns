#include "MobilePhone.h"
#include "MobileManufactorer.h"
#include "MobileDefs.h"

int main()
{
	MobilePhone* phone1 = MobileManufactorer::createPhone(PhoneType_e::ANDROID,"MyAndroid1");
	MobilePhone* phone2 = MobileManufactorer::createPhone(PhoneType_e::WINPHONE, "MyWinPhone");
	return 0;
}