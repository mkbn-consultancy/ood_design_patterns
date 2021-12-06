#include "htmlParser.h"
#include <iostream>

void HtmlParser::parse(const std::string& a_fileName) {
	if (canHandleFile(a_fileName, ".html")) {
		std::cout << "HTML parser extracting URLs from : " << a_fileName << std::endl;
		std::cout << "HTML parser converting file : "
			<< a_fileName << std::endl;
		parseNext(replaceEnding(a_fileName, ".html", ".txt"));
	}
	else { parseNext(a_fileName); }
}
