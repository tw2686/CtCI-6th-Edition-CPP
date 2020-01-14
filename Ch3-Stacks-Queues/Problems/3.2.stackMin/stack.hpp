// stack.hpp

// constructor
Stack::Stack()
{
	data = new int[1000];
	stackSize = 0;
}

// destructor
Stack::~Stack()
{
	delete[] data;
}

// push
void Stack::push(const int val)
{
	data[stackSize] = val;
	++stackSize;
}

// pop
void Stack::pop()
{
	data[--stackSize] = 0;
}

// top
int Stack::top() const
{
	return data[stackSize-1];
}

// empty
bool Stack::empty() const
{
	return stackSize == 0;
}

// size
int Stack::size() const
{
	return stackSize;
}
