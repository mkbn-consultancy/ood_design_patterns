#include <list>
#include <string>

#include "htmlParser.h"
#include "pdfParser.h"
#include "textParser.h"
#include "zipParser.h"

std::list<std::string> populateFiles()
{
	std::list<std::string> fileList;
	fileList.push_back("someFile.txt");
	fileList.push_back("otherFile.pdf");
	fileList.push_back("webpage.html");
	fileList.push_back("zipFile.zip");
	fileList.push_back("wordFile.doc");

	return fileList;
}

int main()
{
	std::list<std::string> fileList = populateFiles();

	// Chain is built in reverse order. Last in chain 	
	// has no successor.
	TextParser textParser(nullptr);
	HtmlParser htmlParser(&textParser);
	PdfParser pdfParser(&htmlParser);
	ZipParser zipParser(&pdfParser, fileList);

	std::list<std::string>::iterator itr =
		fileList.begin();
	for (; itr != fileList.end(); ++itr) {
		zipParser.parse(*itr);
	}
}
