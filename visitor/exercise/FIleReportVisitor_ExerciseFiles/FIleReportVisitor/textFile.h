#pragma once
#include "fileImpl.h"

class TextFile : public FileImpl
{
public:
	TextFile(const std::string& name, int numOfWords, const std::string& text = {});


	int getNumOfWords() const;
private:
	int _numOfWords;
	std::string	_text;
};

