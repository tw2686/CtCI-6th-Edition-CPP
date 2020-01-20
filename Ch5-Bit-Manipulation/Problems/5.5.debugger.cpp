#include <iostream>
#include <string>

/*
 * Hints:
 * 151, 202, 261, 302, 346, 372, 383, 398
 *
 * Solution:
 * checks whether number is a power of 2
 *
 * Time Complexity:
 * 
 * Space Complexity:
 */

/* helper function that converts integer to bin string */
std::string intToStr(int n)
{
	std::string str;
	while (n) {
		int tmp = n & 1;
		str = std::to_string(tmp) + str;
		n >>= 1;
	}
	return str;
}

bool debugger(int n)
{
	return ((n & (n-1)) == 0);
}

int main()
{
	for (int i = 0; i < 21; ++i)
		std::cout << i << ": " << debugger(i) << std::endl;

	return 0;
}
