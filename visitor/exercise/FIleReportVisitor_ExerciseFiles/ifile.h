#pragma once
#include <iostream>
#include <string>


class IFile
{
public:
	virtual std::string getFileName() const = 0;
};

