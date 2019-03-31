#ifndef __STACK_H__
#define __STACK_H__


namespace myStk 
{
	template <class Var>
	struct Node
	{
		Node *next;
		Var data;
	};


	template <class T>
	class Stack 
	{
		public:
			Stack();
			~Stack();
	
			bool is_empty();
			void push(T data);
			T pop();
			void dump();
		private:
			Node<T> *sp;
	};

}
#include "stack.cpp"
#endif
