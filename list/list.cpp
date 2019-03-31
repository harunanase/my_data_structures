#ifndef __LIST_IMPL__
#define __LIST_IMPL__

#include "list.h"
#include <iostream>
#include <cstdlib>


using namespace myList;

template <class T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
}

template <class T>
T* List<T>::front()
{
	return head->data;
}


template <class T>
bool List<T>::is_empty()
{
	return (head == nullptr) && (tail == nullptr);
}

template <class T>
void List<T>::insert_at_head(T data)
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
		n->next = head;
		head = n;
	}
}


template <class T>
void List<T>::insert_at_tail(T data)
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
T List<T>::pop_from_head()
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
T List<T>::pop_from_tail()
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
		Node<T> *walk = head;
		while( walk->next != tail)
			walk = walk->next;
		
		T returned = tail->data;
		walk->next = nullptr;
		delete tail;
		tail = walk;

		return returned;
	}
}



template <class T>
void List<T>::dump()
{
	for(Node<T> *i=head; i!=nullptr; i=i->next)
	{
		std::cout << i->data << std::endl;
	}
}


template <class T>
List<T>::~List()
{
	while( head != nullptr )
	{
		Node<T> *tmp = head;
		head = head->next;
		delete tmp;
	}
}
#endif
