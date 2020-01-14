#include <iostream>

#include "stackMin.h"

int main()
{
	std::cout << "Test: default constructor" << std::endl;
	StackMin s;

	std::cout << "Test: push" << std::endl;
	s.push(2);
	s.push(100);
	s.push(300);
	s.push(1);
	s.push(8);

	std::cout << "Test: top" << std::endl;
	std::cout << s.top() << std::endl;

	std::cout << "Test: min (1)" << std::endl;
	std::cout << s.min() << std::endl;

	std::cout << "Test: pop" << std::endl;
	s.pop();
	s.pop();
	
	std::cout << "Test: min (2)" << std::endl;
	std::cout << s.min() << std::endl;

	std::cout << "Test: empty" << std::endl;
	std::cout << s.empty() << std::endl;

	std::cout << "Test: size" << std::endl;
	std::cout << s.size() << std:: endl;

	return 0;
}
