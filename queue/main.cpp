#include "queue.h"
#include <iostream>
using std::cout; 
using std::endl;


int main()
{
	myQue::Queue<int> *q = new Queue<int>;
	cout << q->is_empty() << endl;
	for(int i=0;i<20;i++)
		q->enqueue(i);
	q->dump();
	cout << "========: " << q->front() << endl;
	cout << "= =: " << q->is_empty() << endl;
	for(int i=0;i<20;i++)
		cout << q->dequeue() << endl;
	q->dump();
	cout << "...:" << q->is_empty() << endl;
	
	
	for(int i=99;i<120;i++)
		q->enqueue(i);
	q->dump();
	cout << "fdsafasf\n";
	
	delete q;

	
	return 0;
}
