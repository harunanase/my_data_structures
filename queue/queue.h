#ifndef __QUEUE_H__
#define __QUEUE_H__


namespace myQue
{
	template <class Var>
	struct Node
	{
		Node *next;
		Var data;
	};


	template <class T>
	class Queue 
	{
		public:
			Queue();
			~Queue();
	
			bool is_empty();
			void enqueue(T data);
			T dequeue();
			void dump();
			T& front();
		private:
			Node<T> *head;
			Node<T> *tail;
	};

}
#include "queue.cpp"
#endif
