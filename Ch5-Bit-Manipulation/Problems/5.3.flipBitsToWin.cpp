#include <iostream>
#include <string>

/*
 * Hints:
 * 159, 226, 314, 352
 *
 * Solution:
 * keep track of cur and prev ones length, check for max at every bit
 * use & 2 to get next bit when encouter 0 to see if its the only 0
 *
 * Time Complexity:
 * O(b), length of binary string
 * 
 * Space Complexity:
 * O(1)
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

/* keep track of cur and prev ones length */
int flipBit(int n)
{
	if (~n == 0) return 32;

	int maxLen = 1;
	int cur = 0;
	int prev = 0;

	while (n) {
		if ((n & 1) == 1) {
			++cur;
		} else {
			prev = (n & 2) == 0 ? 0 : cur;
			cur = 0;
		}
		maxLen = std::max(maxLen, cur + prev + 1);
		n >>= 1;
	}

	return maxLen;
}

int main()
{
	int n = 1775;

	std::cout << "Input:\t" << n << std::endl;
	std::cout << "Binary:\t" << intToStr(n) << std::endl;
	std::cout << "Output:\t" << flipBit(n) << std::endl;

	return 0;
}
