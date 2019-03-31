#include "list.h"
#include <iostream>
using std::cout; 
using std::endl;


int main()
{
	myList::List<int> *l = new myList::List<int>;

	for(int i=0;i<10;i++)
		l->insert_at_tail(i);
	l->dump();
	cout << endl;
	l->pop_from_head();
	l->pop_from_tail();
	l->dump();

	delete l;
	
	return 0;
}
