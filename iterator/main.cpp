#include "list.h"
#include <iostream>

class Obj
{
public:
	void print() { std::cout << "printing\n"; }
};


int main()
{
	List <Obj> ls;
	
	for(int j=0; j<5; ++j)
	{
		ls.Add(Obj());
	}
	
	//TODO: implement Add in order this loop to work

	List<Obj>::iterator itr = ls.begin();
	while(itr != ls.end())
	{
		itr->print();
		(*itr).print();
		++itr;
	}
}