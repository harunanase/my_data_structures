#ifndef __STACK_IMPL__
#define __STACK_IMPL__

#include "stack.h"
#include <iostream>
#include <cstdlib>


using namespace myStk;

template <class T>
Stack<T>::Stack()
{
	sp = nullptr;
}


template <class T>
bool Stack<T>::is_empty()
{
	return (sp == nullptr);
}

template <class T>
void Stack<T>::push(T data)
{

	Node<T> *n = new Node<T>;
	n->data = data;

	if( sp == nullptr )
	{
		n->next = nullptr;
		sp = n;
	}
	else
	{
		n->next = sp;
		sp = n;
	}
}



template <class T>
T Stack<T>::pop()
{
	if( sp == nullptr )
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		Node<T>	*tmp = sp;
		T returned = tmp->data;
		sp = sp->next;
		delete tmp;

		return returned;
	}
}

template <class T>
void Stack<T>::dump()
{
	for(Node<T> *i=sp; i!=nullptr; i=i->next)
	{
		std::cout << i->data << std::endl;
	}
}


template <class T>
Stack<T>::~Stack()
{
	while( sp != nullptr )
	{
		Node<T> *tmp = sp;
		sp = sp->next;
		delete tmp;
	}
}
#endif
