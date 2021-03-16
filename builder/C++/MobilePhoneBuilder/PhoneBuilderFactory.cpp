#include "PhoneBuilderFactory.h"
#include "AndroidPhoneBuilder.h"
#include "WinPhoneBuilder.h"

IPhoneBuilder* PhoneBuilderFactory::getPhoneFactoryBuilder(const PhoneType_e type) {
	IPhoneBuilder* pBuilder = nullptr;

	switch (type) {
	case PhoneType_e::ANDROID:
		pBuilder = new AndroidPhoneBuilder;
		break;

	case PhoneType_e::WINPHONE:
		pBuilder = new WinPhoneBuilder;
		break;
//	case PhoneType_e::IOS:
//		break;
	}

	return pBuilder;
}