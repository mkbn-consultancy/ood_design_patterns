// SPtr.cpp: implementation of the SPtr class.
//
//////////////////////////////////////////////////////////////////////

#include "SPtr.h"
#include <string.h>

class String
{
private:
	char* m_str;
public:
	String(char* str) 
	{
		m_str = new char[strlen(str)+1]; 
		memmove(m_str,str, strlen(str) + 1);
	}
	String(const String& str)
	{
		m_str = new char[strlen(str.m_str)+1];
		memmove(m_str, str.m_str, strlen(str.m_str) + 1);
	}
	~String() 
	{
		delete [] m_str; 
		m_str=nullptr;
	}
	//...
};


/* 
	You have to remember to delete the object, and this may be a problem if you pass
	the pointer around to other procedures and the "ownership" of the object becomes
	unclear. You have to remember to delete the object later, and also make sure that
	you didn't put the pointer into a data structure somewhere that could result in a
	pointer pointing to an object that you deleted too soon (called a "dangling pointer").
*/
String/***/ GetTokenBad(std::istream& in)
{
	char buffer[100];
	in>>buffer;
	String* token = new String(buffer);
	return *token;	//who is suppose to delete this one???
}

SPtr<String> GetTokenGood(std::istream& in)
{
	char buffer[100];
	in>>buffer;
	String* token = new String(buffer);
	return token; //converted to sptr: calls SPtr<String>(String*) with token.
}

