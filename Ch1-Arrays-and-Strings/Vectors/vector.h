// vector.h

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <cstdlib>

template <class T>
class Vector
{
	public:

		// default constructor
		Vector();

		// constructor
		Vector(const size_t s);
		
		// destructor
		~Vector();

		// copy constructor
		Vector(const Vector& src);

		// copy assignment
		Vector& operator=(const Vector& rhs);

		// size()
		size_t size() const;

		// capacity()
		size_t capacity() const;

		// push_back
		void push_back(const T& val);

		// insert
		T* insert(const size_t pos, const T& val);

		// erase
		T* erase(const size_t pos);

		// overwrite index []
		T& operator [](const size_t idx);


	private:
		
		T *data;
		size_t cap;	// length of actual vector
		size_t sze;	// number of items in the vector
		void resize();	// resizes vector by doubling capacity
};

#include "vector.hpp"
#endif

