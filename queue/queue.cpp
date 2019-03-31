#ifndef __QUEUE_IMPL__
#define __QUEUE_IMPL__

#include "queue.h"
#include <iostream>
#include <cstdlib>


using namespace myQue;

template <class T>
Queue<T>::Queue()
{
	head = nullptr;
	tail = nullptr;
}

template <class T>
T& Queue<T>::front()
{
	return (head->data);
}


template <class T>
bool Queue<T>::is_empty()
{
	return (head == nullptr) && (tail == nullptr);
}

template <class T>
void Queue<T>::enqueue(T data)
{

	Node<T> *n = new Node<T>;
	n->data = data;

	if( this->is_empty() )
	{
		n->next = nullptr;
		head = tail = n;
	}
	else
	{
		n->next = nullptr;
		tail->next = n;
		tail = n;
	}
}



template <class T>
T Queue<T>::dequeue()
{
	if( this->is_empty() )
	{
		exit(EXIT_FAILURE);
	}
	else if( head == tail )
	{
		/* only left one element */
		Node<T> *tmp = head;
		T returned = tmp->data;
		head = tail = nullptr;
		delete tmp;

		return returned;
	}
	else
	{
		Node<T>	*tmp = head;
		T returned = tmp->data;
		head = head->next;
		delete tmp;

		return returned;
	}
}

template <class T>
void Queue<T>::dump()
{
	for(Node<T> *i=head; i!=nullptr; i=i->next)
	{
		std::cout << i->data << std::endl;
	}
}


template <class T>
Queue<T>::~Queue()
{
	while( head != nullptr )
	{
		Node<T> *tmp = head;
		head = head->next;
		delete tmp;
	}
}
#endif
