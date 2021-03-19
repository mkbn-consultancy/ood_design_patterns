#pragma once

#include "ifile.h"

class FileImpl : public IFile
{
public:
	FileImpl(const std::string& name) : _name(name) {}
	virtual std::string getFileName() const {
		return _name;
	}
private:
	std::string	_name;
};

