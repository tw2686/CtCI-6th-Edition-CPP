/*
 * Problem:
 * Implement a function void reverse(char *str) in C or C++ which reverses a
 * null-terminated string
 *
 * hints:
 * 410, 452
 *
 * solution:
 */

#include <iostream>
using namespace std;

/* for loop C */
void reverse1(char *str)
{
	int n = strlen(str);

	for (int i = 0, j = n-1; i < j; ++i, --j) {
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

/* pointer C */
void reverse2(char *str)
{
	if (str == NULL)
		return;

	/* find end of string */
	char *end = str;
	while (*end) ++end;
	--end;

	/* swap start and end until pointers meet in middle */
	while (str < end) {
		char tmp = *str;
		*str = *end;
		*end = tmp;

		++str; --end;
	}
}

/* C++ swap */
void reverse3(char *str)
{
	int n = strlen(str);

	for (int i = 0, j = n-1; i < j; ++i, --j)
		swap(str[i], str[j]);
}


/* C++ reverse */
void reverse4(char *str)
{
	reverse(str, str + strlen(str));
}

/* C++ swap */
void reverse5(char *str)
{
	const size_t n = strlen(str);

	for (size_t i = 0; i < n / 2; ++i)
		swap(str[i], str[n-i-1]);
}

int main()
{	
	char str[] = "Hello";	

	printf("%s\n", str);
	reverse5(str);
	printf("%s\n", str);

	/* size_t could be any unsigned type (char, int, long, long long) */
	cout << sizeof(size_t) << endl;
	cout << sizeof(unsigned int) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;

	return 0;
}
