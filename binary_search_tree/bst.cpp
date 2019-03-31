#ifndef __BST_IMPL__
#define __BST_IMPL__

#include "bst.h"
#include "queue.h"
#include <iostream>

using namespace mybst;


template <class T> 
BSTree<T>::BSTree()
{
	root = nullptr;
}

template <class T>
BSTree<T>::~BSTree()
{
	destroy_tree(root);
}

template <class T>
mybst::Node<T>* BSTree<T>::get_root()
{
	return this->root;
}

template <class T>
void BSTree<T>::destroy_tree(Node<T> *leaf)
{
	if( leaf != nullptr )
	{
		destroy_tree( leaf->left );
		destroy_tree( leaf->right );
		delete leaf;
	}
}




/* ================ */
/* Basic Operations */
/* ================ */
template <class T>
void BSTree<T>::insert(const T key)
{
	if( root == nullptr )
	{
		/* empty tree, inserted at root, that is, 
		 * initialize the root with key value */
		this->root = __node_initialize(key, root);
	}
	else
	{
		/* tree is not empty, invoke inner insert method */
		this->root = __insert(key, root);
	}
}

template <class T>
void BSTree<T>::remove(const T key)
{
	this->root = __remove(key, this->root);
}

template <class T>
mybst::Node<T>* BSTree<T>::search(const T key)
{
	return __search(key, this->root);
}

template <class T>
mybst::Node<T>* BSTree<T>::find_min(Node<T> *n)
{
	if(n == nullptr)
	{
		return nullptr;
	}
	else if(n->left != nullptr)
	{
		return find_min(n->left);
	}
	else
	{
		return n;
	}
}

template <class T>
mybst::Node<T>* BSTree<T>::find_max(Node<T> *n)
{
	if(n == nullptr)
	{
		return nullptr;
	}
	else if(n->right != nullptr)
	{
		return find_min(n->right);
	}
	else
	{
		return n;
	}
}


template <class T>
void BSTree<T>::traversal(const int type)
{
	/* traversal the tree 
	 * type = (0, 1, 2, 3)
	 * 0: predorder
	 * 1: inorder
	 * 2: postorder
	 * 3: level-order */

	/* queue is used to record nodes */
	
	myQue::Queue<T> *q = new myQue::Queue<T>;
	typedef void (BSTree<T>::*switchTraversalFuncPtr) (Node<T> *n, myQue::Queue<T> *q);
	switchTraversalFuncPtr fptr[4] = \
			{ &BSTree<T>::__preorder, &BSTree<T>::__inorder, &BSTree<T>::__postorder, &BSTree<T>::__level_order };
	(this->*fptr[type]) (this->root, q); // invoke

	q->dump();

	delete q;
}










/* ================================ */
/* INNER METHODS */
/* DO NOT INVOKE THESE EXPLICITLY ! */
/* ================================ */
template <class T>
mybst::Node<T>* BSTree<T>::__node_initialize(T key, Node<T> *n)
{
	n = new Node<T>;
	n->data = key;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

template <class T>
mybst::Node<T>* BSTree<T>::__insert(T key, Node<T> *leaf)
{
	/* inner method, check the key value to determine 
	 * where to insert, the left/right leaf node. 
	 *
	 * If the left/right node is empty, inserted to it
	 * directly.
	 * Otherwise, move to the next node and recursivly 
	 * invokes this function */

	if(key < leaf->data)
	{
		if( leaf->left != nullptr )
		{
			leaf->left = __insert( key, leaf->left );
		}
		else
		{
			leaf->left = __node_initialize( key, leaf->left );
		}
	}
	else
	{
		if( leaf->right != nullptr )
		{
			leaf->right = __insert( key, leaf->right );
		}
		else
		{
			leaf->right = __node_initialize( key, leaf->right );
		}
	}
	return leaf;
}


template <class T>
mybst::Node<T>* BSTree<T>::__remove(T key, Node<T> *leaf)
{
	if(leaf == nullptr) return nullptr;
	

	if(key < leaf->data)
	{
		/* not found, go to left */
		leaf->left = __remove(key, leaf->left);
	}
	else if(key > leaf->data)
	{
		/* not found, go to right */
		leaf->right = __remove(key, leaf->right);
	}
	else if(leaf->left != nullptr && leaf->right != nullptr)
	{
		/* founded && both left, right childs exist,
		 * need to integrate the tree */
		Node<T> *temp = find_min(leaf->right);
		leaf->data = temp->data;
		leaf->right = __remove(leaf->data, leaf->right);
	}	
	else 
	{
		/* founded && (only exist one child || no child) */
		Node<T> *temp = leaf;
		if(leaf->left == NULL)
        	leaf = leaf->right;
        else if(leaf->right == NULL)
            leaf = leaf->left;
        delete temp;
	}	
	return leaf;
}

		
template <class T>
mybst::Node<T>* BSTree<T>::__search(T key, Node<T> *leaf)
{
	if(leaf == nullptr)
	{
		return nullptr;
	}
	else if(key < leaf->data)
	{
		return __search(key, leaf->left);
	}
	else if(key > leaf->data)
	{
		return __search(key, leaf->right);
	}
	else
	{
		return leaf;
	}
}


template <class T>
void BSTree<T>::__preorder(Node<T> *n, myQue::Queue<T> *q)
{
	/* DFS */
	if( n == nullptr )
	{
		return ; 
	}

	q->enqueue( n->data );
	__preorder( n->left, q );
	__preorder( n->right, q );

}

template <class T>
void BSTree<T>::__inorder(Node<T> *n, myQue::Queue<T> *q)
{
	/* DFS */
	if( n == nullptr )
	{
		return ; 
	}

	__inorder( n->left, q );
	q->enqueue( n->data );
	__inorder( n->right, q );

}

template <class T>
void BSTree<T>::__postorder(Node<T> *n, myQue::Queue<T> *q)
{
	/* DFS */
	if( n == nullptr )
	{	
		return ; 
	}
	
	__postorder( n->left, q );
	__postorder( n->right, q );
	q->enqueue( n->data );
}

template <class T>
void BSTree<T>::__level_order(Node<T> *n, myQue::Queue<T> *record)
{
	/* BFS */
	if( n == nullptr )
	{
		return ;
	}

	myQue::Queue< mybst::Node<T>* > *q = new myQue::Queue< mybst::Node<T>* >;
	q->enqueue( n );
	while ( ! q->is_empty() )
	{
		mybst::Node<T> *current = q->front();
		record->enqueue( current->data );
		q->dequeue();

		if( current->left != nullptr )
		{
			q->enqueue( current->left );
		}	
		if( current->right != nullptr )
		{
			q->enqueue( current->right );
		}
	}
	delete q;
}

#endif
