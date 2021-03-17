#pragma once

#include "DB.h"
#include <iostream>

class Producer
{
public:
	void putDataOnDB(const std::string& str) {
		std::cout << "put data " << str << std::endl;
		DB::instance()->putData(str);	//notify for a new data
	}
};
