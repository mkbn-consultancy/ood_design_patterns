#include "textParser.h"
#include <iostream>

void TextParser::parse(const std::string& a_fileName)
{
	if (canHandleFile(a_fileName, ".txt")) {
		std::cout << "Text parser extracting search	keywords from "
			<< a_fileName << std::endl;
	}
	else {
		parseNext(a_fileName);
	}
}
