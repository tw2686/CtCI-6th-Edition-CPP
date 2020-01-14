// FixedMultiStack.h

#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cstdlib>

/*
 * hints:
 * 2, 12, 38, 58
 *
 * ask:
 *
 * solutions:
 * 1. Fixed Division:
 *    - Divide the array in three equal parts, grow in limited space n/3
 * 2. Flexible Divisions:
 *    - If exceed initial cap, grow cap and shift elements, circular
 */

template <class T>
class Stack
{
	public:

		Stack(const int s);
		virtual ~Stack();

		void push(const int num, const T& val);
		void pop(const int num);
		T& top(const int num) const;
		bool isEmpty(const int num) const;
		bool isFull(const int num) const;

	private:
		T *data;
		int numOfStack = 3;
		int cap;
		int *sizeList;

		int indexOfTop(const int num) const;		
};

#include "FixedMultiStack.hpp"
#endif
