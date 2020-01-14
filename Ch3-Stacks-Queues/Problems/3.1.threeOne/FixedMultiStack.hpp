// FixedMultiStack.hpp

// constructor
template <class T>
Stack<T>::Stack(const int s)
{
	cap = s;
	sizeList = new int[numOfStack];
	data = new T[numOfStack * cap];
}

// destructor
template <class T>
Stack<T>::~Stack()
{
	delete[] data;
	delete[] sizeList;
}

// push
template <class T>
void Stack<T>::push(const int num, const T& val)
{
	if (isFull(num)) {
		std::cout << "Stack " << num << " is full." << std::endl;
	} else {
		++sizeList[num];
		data[indexOfTop(num)] = val;
	}
}

// pop
template <class T>
void Stack<T>::pop(const int num)
{
	if (isEmpty(num)) {
		std::cout << "Stack " << num << " is empty." << std::endl;
	} else {
		data[indexOfTop(num)] = 0;
		--sizeList[num];
	}
}

// top
template <class T>
T& Stack<T>::top(const int num) const
{
	if (isEmpty(num)) {
		std::cout << "Stack " << num << " is empty." << std::endl;
		exit(1);
	} else {
		return data[indexOfTop(num)];
	}
}

// isEmpty
template <class T>
bool Stack<T>::isEmpty(const int num) const
{
	return sizeList[num] == 0;
}

// isFull
template <class T>
bool Stack<T>::isFull(const int num) const
{
	return sizeList[num] == cap;
}

// indexOfTop
template<class T>
int Stack<T>::indexOfTop(const int num) const
{
	return (num * cap) + sizeList[num] - 1;
}
