#include "textFile.h"
#include "ivisitor.h"

TextFile::TextFile(const std::string& name, int numOfWords, const std::string& text) :
	FileImpl(name), _numOfWords(numOfWords), _text(text) {}

void TextFile::accept(IFileVisitor* p) {
	p->visit(this);
}

int TextFile::getNumOfWords() const { return _numOfWords; }

