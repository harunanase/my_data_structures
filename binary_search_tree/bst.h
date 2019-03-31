#ifndef __BST_H__
#define __BST_H__

#include "queue.h"

namespace mybst
{
		template <class Var>
		struct Node 
		{
			Node *left;
			Node *right;
			Var data;
		};



		template <class T>
		class BSTree
		{
			
			public:
				BSTree();	// default consturctor
				~BSTree(); 	// destructor

				Node<T>* get_root();
				void destroy_tree(Node<T> *leaf);

				/* basic operation */
				void insert(const T key);
				void remove(const T key);
				Node<T>* search(const T key);
				Node<T>* find_min(Node<T> *n);
				Node<T>* find_max(Node<T> *n);

				void traversal(const int type);


			private:
				Node<T> *root;
				
				
				Node<T>* __node_initialize(T key, Node<T> *n);
				Node<T>* __insert(T key, Node<T> *leaf);
				Node<T>* __remove(T key, Node<T> *leaf);
				Node<T>* __search(T key, Node<T> *leaf);

				void __preorder(Node<T> *n, myQue::Queue<T> *q);
				void __inorder(Node<T> *n, myQue::Queue<T> *q);
				void __postorder(Node<T> *n, myQue::Queue<T> *q);
				void __level_order(Node<T> *n, myQue::Queue<T> *record);
		};

};

#include "bst.cpp"	
#endif


