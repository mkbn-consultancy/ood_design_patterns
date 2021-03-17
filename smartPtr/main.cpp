#include "SPtr.h"
#include "myString.h"

int main()
{
	//int i;
	//SPtr<int>* p = new SPtr<int>(&i); 
	//		ERROR: 'new' : cannot access private member declared in class 'SPtr<int>'
	SPtr<String> spStr;
	std::cout<<"Please enter a word: ";
	spStr = GetTokenGood(std::cin);

/*	SPtr<String> spStr = &(GetTokenBad(cin));
*/
	return 0;
}
