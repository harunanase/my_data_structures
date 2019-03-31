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
			void insert_at_head(T data);
			void insert_at_tail(T data);
			T pop_from_head();
			T pop_from_tail();

			void dump();
			T* front();
		private:
			Node<T> *head;
			Node<T> *tail;
	};

}
#include "list.cpp"
#endif
