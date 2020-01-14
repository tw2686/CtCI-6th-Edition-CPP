// stack.h

#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cstdlib>

/*
 * hints:
 * 27, 59 78
 *
 * ask:
 *
 * solutions:
 */

class Stack
{
	public:
		Stack();
		virtual ~Stack();

		void push(const int val);
		void pop();
		int top() const;
		bool empty() const;
		int size() const;

	private:
		int *data;
		int stackSize;
};

#include "stack.hpp"
#endif
