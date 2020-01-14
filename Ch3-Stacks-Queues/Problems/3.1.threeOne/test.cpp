#include <iostream>

#include "FixedMultiStack.h"

int main()
{
	std::cout << "Test: constructor" << std::endl;
	Stack<int> s2 (3);

	std::cout << "Test: push" << std::endl;
	s2.push(0, 1);
	s2.push(0, 2);
	s2.push(0, 3);
	s2.push(1, 4);
	s2.push(1, 5);
	s2.push(1, 6);
	s2.push(2, 7);
	s2.push(2, 8);
	s2.push(2, 9);

	std::cout << "Test: top" << std::endl;
	std::cout << s2.top(0) << std::endl;
	std::cout << s2.top(1) << std::endl;
	std::cout << s2.top(2) << std::endl;

	std::cout << "Test: pop" << std::endl;
	s2.pop(1);
	s2.pop(2);
	s2.pop(2);
	s2.pop(2);
	
	std::cout << "Test: isEmpty" << std::endl;
	std::cout << s2.isEmpty(2) << std::endl;

	std::cout << "Test: isFull" << std::endl;
	std::cout << s2.isFull(0) << std::endl;

	return 0;
}
