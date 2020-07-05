/*
 * Problem:
 * Write an aligned malloc and free function that supports allocating memory
 * such as the memory address returned is divisible by a specific power of
 * two.
 *
 * hints:
 *
 * solution:
 */

#include <iostream>
using namespace std;

void* align_malloc(size_t size, size_t M)
{
	void *p1;
	void *p2;
	int offset = M - 1 + sizeof(void *);
	p1 = (void *)malloc(size + offset);
	if (p1 == NULL) return NULL;

	return p2;
}

void aligned_free(void *addr)
{
	void *p1 = ((void **)addr)[-1];
	free(p1);
}

int main()
{
	// void *addr = align_malloc(100, 16);
	// aligned_free(addr);
	cout << sizeof(size_t) << endl;
	cout << sizeof(void *) << endl;
	cout << sizeof(void **) << endl;
	cout << sizeof(uintptr_t) << endl;

	return 0;
}
