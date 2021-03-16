#pragma once

#include <string>
#include "MobileDefs.h"

//forward declaration
class MobilePhone;

class MobileManufactorer
{
public:
	static MobilePhone* createPhone(PhoneType_e type, const std::string& name);
};

