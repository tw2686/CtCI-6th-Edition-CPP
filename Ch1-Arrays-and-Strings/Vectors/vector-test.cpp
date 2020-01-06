#include <iostream>

#include "vector.h"

int main()
{
	
	std::cout << "Test: default constructor" << std::endl;
	Vector<int> v1;
	Vector<int> v2;

	std::cout << "Test: constructor" << std::endl;
	Vector<int> v3 (20);
	for (int i = 0; i < 20; ++i)
		v3[i] = 8;
	std::cout << v3.size() << std::endl;

	std::cout << "Test: copy constructor" << std::endl;
	Vector<int> v4 (v3);
	for (int i = 0; i < v4.size(); ++i)
		std::cout << v4[i] << ' ';
	std::cout << std::endl;

	std::cout << "Test: push_back" << std::endl;
	for (int i = 0; i < 20; ++i)
		v1.push_back(i);
	for (int i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << ' ';
	std::cout << std::endl;

	std::cout << "Test: capacity()" << std::endl;
	std::cout << v1.capacity() << std::endl;

	std::cout << "Test: copy assignment" << std::endl;
	v2 = v1;
	for (int i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << ' ';
	std::cout << std::endl;
	std::cout << v2.capacity() << std::endl;
	
	std::cout << "Test: insert(10, -1)" << std::endl;
	v2.insert(10, -1);
	for (int i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << ' ';
	std::cout << std::endl;
	std::cout << v2.capacity() << std::endl;

	std::cout << "Test: erase(10)" << std::endl;
	v2.erase(10);
	for (int i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << ' ';
	std::cout << std::endl;

	return 0;
}
