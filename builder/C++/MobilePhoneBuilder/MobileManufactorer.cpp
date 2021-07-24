#include "MobileManufactorer.h"
#include "MobilePhone.h"
#include "IPhoneBuilder.h"
#include "PhoneBuilderFactory.h"

#include <iostream> //for debugging

MobilePhone* MobileManufactorer::createPhone(PhoneType_e type, const std::string& name)
{
	std::cout<<"[MobileManufactorer] asking for a builder\n";
	IPhoneBuilder* pBuilder = PhoneBuilderFactory::getPhoneFactoryBuilder(type);
	std::cout<<"[MobileManufactorer] initializaing builder and create a new MobilePhone object\n";
	pBuilder->setName(name);
	pBuilder->buildScreen();
	pBuilder->buildBattery();
	pBuilder->buildOS();
	pBuilder->buildStylus();
	return new MobilePhone(*(pBuilder->phone()));
}
