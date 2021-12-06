#include "parser.h"
#include <iostream>

void Parser::parseNext(const std::string& a_fileName)
{
	if (nullptr != getSuccessor()) {
		getSuccessor()->parse(a_fileName);
	}
	else {
		std::cout << "Unable to find the correct parser for the file : "
			<< a_fileName << std::endl;
	}
}

bool Parser::canHandleFile(const std::string& a_fileName,
	const std::string& a_format)
{
	return hasEnding(a_fileName, a_format);
}

bool Parser::hasEnding(const std::string &fullString,
	const std::string &ending)
{
	return (fullString.length() >= ending.length()) &&
		(0 == fullString.compare(fullString.length() - ending.length(),
			ending.length(), ending));
}

std::string Parser::replaceEnding(const std::string &fullString,
	const std::string &oldEnding,
	const std::string &newEnding)
{
	return fullString.substr(0,
		fullString.length() - oldEnding.length()) + newEnding;
}

