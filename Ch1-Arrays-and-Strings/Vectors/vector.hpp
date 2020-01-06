// vector.hpp

// default constructor
template <class T>
Vector<T>::Vector():cap(10), sze(0)
{
	data = new T[cap];
}

// constructor
template <class T>
Vector<T>::Vector(const size_t s)
{
	cap = s + 10;
	sze = s; 
	data = new T[cap];
}

// destructor
template <class T>
Vector<T>::~Vector()
{
	delete[] data;
}

// copy constructor
template <class T>
Vector<T>::Vector(const Vector& src)
{
	cap = src.cap;
	sze = src.sze;
	data = new T[cap];
	std::copy(src.data, src.data + cap, data);
}

// copy assignment
template <class T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (data)
		delete[] data;
	cap = rhs.cap;
	sze = rhs.sze;
	data = new T[cap];
	std::copy(rhs.data, rhs.data + cap, data);

	return *this;
}

// size
template <class T>
size_t Vector<T>::size() const
{
	return sze;
}

// capacity
template <class T>
size_t Vector<T>::capacity() const
{
	return cap;
}

// resize
template <class T>
void Vector<T>::resize()
{
	cap *= 2;
	T *newData = new T[cap];
	for (int i = 0; i < sze-1; ++i)
		newData[i] = data[i];
	delete[] data;
	data = newData;	
}

// push_back
template <class T>
void Vector<T>::push_back(const T& val)
{
	++sze;
	if (sze >= cap)
		resize();
	data[sze-1] = val;
}

// insert
template <class T>
T* Vector<T>::insert(const size_t pos, const T& val)
{
	++sze;
	if (sze >= cap)
		resize();
	for (int i = sze-1; i > pos; --i)
		data[i] = data[i-1];
	data[pos] = val;
	return data + pos;
}

// erase
template <class T>
T* Vector<T>::erase(const size_t pos)
{
	if (pos < sze) {
		for (int i = pos; i < sze; ++i)
			data[i] = data[i+1];
		data[sze-1] = 0;
		--sze;
	}
	return data + pos;
}

// overwrite index []
template <class T>
T& Vector<T>::operator [](const size_t idx)
{
	return data[idx];
}
