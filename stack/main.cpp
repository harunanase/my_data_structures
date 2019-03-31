#include "stack.h"
#include <iostream>
using std::cout; 
using std::endl;


int main()
{
	myStk::Stack<int> *s = new Stack<int>;
	cout << s->is_empty() << endl;
	for(int i=0;i<20;i++)
		s->push(i);
	s->dump();
	
	cout << "= =: " << s->is_empty() << endl;
	for(int i=0;i<20;i++)
		cout << s->pop() << endl;
	s->dump();
	
	
	delete s;

	
	return 0;
}
