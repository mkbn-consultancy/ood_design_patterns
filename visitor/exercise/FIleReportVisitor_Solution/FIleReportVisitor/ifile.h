#pragma once
#include <iostream>
#include <string>

//forward declaration
class IFileVisitor;

class IFile
{
public:
	virtual std::string getFileName() const = 0;
	virtual void accept(IFileVisitor*) = 0;
};

