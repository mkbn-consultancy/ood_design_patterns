#include "zipParser.h"
#include <iostream>

void ZipParser::parse(const std::string& a_fileName)
{
	if (canHandleFile(a_fileName, ".zip")) {
		std::cout << "ZIP parser extracting files from : "
			<< a_fileName << std::endl;
		m_rFileList.push_back("file1.txt");
		m_rFileList.push_back("file2.html");
		// note that I do not continue the chain
	}
	else { parseNext(a_fileName); }
}
