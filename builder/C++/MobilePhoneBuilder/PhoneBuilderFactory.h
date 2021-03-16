#pragma once

#include "MobileDefs.h"

//forward declaration
class IPhoneBuilder;

class PhoneBuilderFactory
{
public:
	static IPhoneBuilder* getPhoneFactoryBuilder(const PhoneType_e type);
};

