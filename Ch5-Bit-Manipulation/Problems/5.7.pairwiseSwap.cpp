#include <iostream>
#include <string>

/*
 * Hints:
 * 145, 248, 328, 355
 *
 * Solution:
 * odd mask 0xAAAA
 * even mask 0x5555
 * shift and or
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
		str = std::to_string(n & 1) + str;
		n >>= 1;
	}
	return str;
}

int swapOddEven(int n)
{
	/* odd bits: 1010 */
	/* even bits: 0101 */
	return ( ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1) );
}

int main()
{
	int n1 = 29;

	std::cout << "Input: " << n1;
	std::cout << "\tBinary: " << intToStr(n1) << std::endl;
	std::cout << "Output:\t" << swapOddEven(n1);
	std::cout << "\tBinary: " << intToStr(swapOddEven(n1)) << std::endl;

	return 0;
}
