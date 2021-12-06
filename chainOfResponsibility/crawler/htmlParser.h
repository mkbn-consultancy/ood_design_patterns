#pragma once
#include "parser.h"

class HtmlParser : public Parser
{
public:
	HtmlParser(Parser* a_pSuccessor) {
		setSuccessor(a_pSuccessor);
	}
	virtual void parse(const std::string& a_fileName);
};
