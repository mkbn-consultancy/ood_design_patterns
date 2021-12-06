#pragma once
#include "parser.h"
#include <list>

class ZipParser : public Parser
{
	std::list<std::string> &m_rFileList;
public:
	ZipParser(Parser* a_pSuccessor,
		std::list<std::string> &a_rFileList)
		: m_rFileList(a_rFileList)
	{
		setSuccessor(a_pSuccessor);
	}

	virtual void parse(const std::string& a_fileName);
};
