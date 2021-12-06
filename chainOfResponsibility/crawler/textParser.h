#pragma once
#include "parser.h"

class TextParser : public Parser {
public:
	TextParser(Parser *a_pSuccessor) {
		setSuccessor(a_pSuccessor);
	}
	virtual void parse(const std::string& a_fileName);
};

