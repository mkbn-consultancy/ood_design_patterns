#include "textFile.h"

TextFile::TextFile(const std::string& name, int numOfWords, const std::string& text) :
	FileImpl(name), _numOfWords(numOfWords), _text(text) {}

int TextFile::getNumOfWords() const { return _numOfWords; }

