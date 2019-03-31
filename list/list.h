#ifndef __LIST_H__
#define __LIST_H__


namespace myList
{
	template <class Var>
	struct Node
	{
		Node *next;
		Var data;
	};


	template <class T>
	class List 
	{
		public:
			List();
			~List();
	
			bool is_empty();
			void enlist(T data);
			T delist();
			void dump();
			Node<T>* front();
		private:
			Node<T> *head;
			Node<T> *tail;
	};

}
#include "list.cpp"
#endif
