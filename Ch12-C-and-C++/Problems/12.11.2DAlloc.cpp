/*
 * Problem:
 * Write a function in C called my2DAlloc which allocates a 2-D array.
 * Minimize the number of calls to malloc and make sure that the memory is
 * accessible by the notation arr[i][j]
 *
 * hints:
 * 406, 418, 426
 *
 * solution:
 */

#include <iostream>
using namespace std;

int** my2DAlloc0(int R, int C)
{
	int **arr;
	arr = (int **)malloc(R * sizeof(int *));
	for (int i = 0; i < R; ++i)
		arr[i] = (int *) malloc(C * sizeof(int));
	return arr;
}

int** my2DAlloc(int R, int C)
{
	int header = R * sizeof(int *);
	int data = R * C * sizeof(int);
	int **arr = (int **)malloc(header + data);

	if (arr == NULL) return NULL;

	int *buf = (int *)(arr + R);
	for (int i = 0; i < R; ++i)
		arr[i] = buf + i * C;

	return arr; 
}

int main()
{
//	int** arr = my2DAlloc(3, 3);
	cout << sizeof(int) << '\n';
	cout << sizeof(int *) << '\n';
	cout << sizeof(int **) << '\n';
	return 0;
}
