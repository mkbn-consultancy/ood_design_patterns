#include "MobilePhone.h"
#include "MobileManufactorer.h"
#include "MobileDefs.h"

#include <iostream> //for debugging

int main()
{
	std::cout<<"\n[main] ask to create ANDROID phone named MyAndroid1\n";
	MobilePhone* phone1 = MobileManufactorer::createPhone(PhoneType_e::ANDROID,"MyAndroid1");

	std::cout<<"\n[main] ask to create WINPHONE phone named MyWinPhone\n";
	MobilePhone* phone2 = MobileManufactorer::createPhone(PhoneType_e::WINPHONE, "MyWinPhone");
	return 0;
}