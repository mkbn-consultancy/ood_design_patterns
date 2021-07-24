#include "PhoneBuilderFactory.h"
#include "AndroidPhoneBuilder.h"
#include "WinPhoneBuilder.h"

#include <iostream> //for debugging

IPhoneBuilder* PhoneBuilderFactory::getPhoneFactoryBuilder(const PhoneType_e type) {
	IPhoneBuilder* pBuilder = nullptr;

	switch (type) {
	case PhoneType_e::ANDROID:
		pBuilder = new AndroidPhoneBuilder;
		std::cout<<"[PhoneBuilderFactory] creating AndroidPhoneBuilder\n";
		break;

	case PhoneType_e::WINPHONE:
		pBuilder = new WinPhoneBuilder;
		std::cout<<"[PhoneBuilderFactory] creating WinPhoneBuilder\n";
		break;
//	case PhoneType_e::IOS:
//		break;
	}

	return pBuilder;
}