#include "bst.h"
#include <iostream>



using std::cout;
using std::endl;


int main()
{
	BSTree<int> *mytree = new BSTree<int>;
	int arr[] = {20, 25, 15, 10, 30};
	for(int i=0;i<5;i++)
		mytree->insert(arr[i]);
	cout << "kkk:" << mytree->search(15)->left->data << endl;

	mytree->traversal(2);
	cout << endl;
	mytree->traversal(1);
	cout << endl;
	mytree->traversal(0);
	cout << endl;
	mytree->traversal(3);
	cout << endl;

	mytree->remove(20);
	mytree->traversal(1);
	cout << endl;

	mytree->remove(25);
	mytree->traversal(1);
	cout << endl;

	mytree->remove(30);
	mytree->traversal(1);
	cout << endl;

	cout << "kkk:" << mytree->search(15)->data << endl;

	delete mytree;


	return 0;
}
