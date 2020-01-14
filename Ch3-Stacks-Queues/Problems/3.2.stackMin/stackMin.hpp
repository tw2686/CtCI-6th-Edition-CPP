// stackMin.hpp

// constructor
StackMin::StackMin()
{
}

// destructor
StackMin::~StackMin()
{
}

// push
void StackMin::push(const int val)
{
	s1.push(val);
	if (val <= min())
		s2.push(val);
}

// pop
void StackMin::pop()
{
	if (s1.top() == min())
		s2.pop();
	s1.pop();
}

// top
int StackMin::top() const
{
	return s1.top();
}

// min
int StackMin::min() const
{
	if (s2.empty()) return INT_MAX;
	return s2.top();
}

// empty
bool StackMin::empty() const
{
	return s1.empty();
}

// size
int StackMin::size() const
{
	return s1.size();
}
