// stackMin.h

#ifndef __STACKMIN_H__
#define __STACKMIN_H__

#include "stack.h"
#include <iostream>
#include <cstdlib>


/*
 * hints:
 * 27, 59 78
 *
 * ask:
 *
 * solutions:
 * 1. Use nodes for each item that keeps track of min seen
 * 2. Use second stack to keep track of mins
 */

class StackMin
{
	public:
		StackMin();
		virtual ~StackMin();

		void push(const int val);
		void pop();
		int min() const;
		int top() const;
		bool empty() const;
		int size() const;

	private:
		Stack s1;
		Stack s2;
};

#include "stackMin.hpp"
#endif
