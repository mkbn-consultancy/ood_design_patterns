#include "MobileManufactorer.h"
#include "MobilePhone.h"
#include "IPhoneBuilder.h"
#include "PhoneBuilderFactory.h"

MobilePhone* MobileManufactorer::createPhone(PhoneType_e type, const std::string& name)
{
	IPhoneBuilder* pBuilder = PhoneBuilderFactory::getPhoneFactoryBuilder(type);
	pBuilder->setName(name);
	pBuilder->buildScreen();
	pBuilder->buildBattery();
	pBuilder->buildOS();
	pBuilder->buildStylus();
	return new MobilePhone(*(pBuilder->phone()));
}
