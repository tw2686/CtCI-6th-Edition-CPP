#include <iostream>
#include <string>

/*
 * Hints:
 * 336, 369
 *
 * Solution:
 * XOR A and B
 * 1. right shift and count 1s
 * 2. n & (n-1) to clear least significant bit
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

/* right shift */
int conversion1(int A, int B)
{
	int n = A ^ B;
	int flips = 0;

	while (n) {
		flips += n & 1;
		n >>= 1;
	}
	
	return flips;
}

/* clear least significant bit using n & (n-1) */
int conversion2(int A, int B)
{
	int n = A ^ B;
	int flips = 0;

	while (n) {
		++flips;
		n = n & (n-1);
	}
	
	return flips;
}

int main()
{
	int n1 = 29;
	int n2 = 15;

	std::cout << "A: " << n1;
	std::cout << "\tBinary: " << intToStr(n1) << std::endl;
	std::cout << "B: " << n2;
	std::cout << "\tBinary: " << intToStr(n2) << std::endl;
	std::cout << "Output:\t" << conversion2(n1, n2) << std::endl;

	return 0;
}
