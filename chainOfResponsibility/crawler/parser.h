#pragma once

#include <string>

class Parser {
public:
	virtual void parse(const std::string& fileName) = 0;
	Parser* getSuccessor() { return _successor; }
	void setSuccessor(Parser* successor) {
		_successor = successor;
	}
	void parseNext(const std::string& a_fileName);
protected:
	bool canHandleFile(const std::string& a_fileName,
		const std::string& a_format);
	bool hasEnding(const std::string &fullString,
		const std::string &ending);
	std::string replaceEnding(const std::string &fullString,
		const std::string &oldEnding,
		const std::string &newEnding);
private:
	Parser* _successor;
};
