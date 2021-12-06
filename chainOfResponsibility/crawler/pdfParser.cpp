#include "pdfParser.h"
#include <iostream>

void PdfParser::parse(const std::string& a_fileName)
{
	if (canHandleFile(a_fileName, ".pdf")) {
		std::cout << "PDF parser converting file : " << a_fileName << std::endl;
		parseNext(replaceEnding(a_fileName, ".pdf", ".txt"));
	}
	else {
		parseNext(a_fileName);
	}
}
