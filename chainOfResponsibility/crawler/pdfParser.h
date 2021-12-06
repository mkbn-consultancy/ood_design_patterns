#pragma once
#include "parser.h"

class PdfParser : public Parser
{
public:
	PdfParser(Parser* a_pSuccessor) {
		setSuccessor(a_pSuccessor);
	}
	void parse(const std::string& a_fileName);
};

