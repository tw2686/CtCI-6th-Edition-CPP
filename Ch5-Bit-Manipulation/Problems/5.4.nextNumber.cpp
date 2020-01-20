#include <iostream>
#include <vector>
#include <string>

/*
 * Hints:
 * 147, 175, 242, 312, 339, 358, 375, 390
 *
 * Solution:
 * Larger: get trailing 0, ones following, get p, flip p, move ones-1 to the
 * right
 * Smaller: get trailing ones, zeroes following, get p, flip p, move ones+1
 * right after p
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

std::vector<int> nextNumber(int number)
{
	std::vector<int> res;

	/* larger */
	int n = number;
	int p = 0;
	int trail0 = 0;
	int ones = 0;

	while ((n & 1) == 0) {
		++trail0;
		n >>= 1;
	}
	while ((n & 1) == 1) {
		++ones;
		n >>= 1;
	}
	p = trail0 + ones;
	n = (number ^ (1 << p)) & (~0 << p);
	n |= (1 << (ones-1)) - 1;
	res.push_back(n);

	/* smaller */
	n = number;
	int trail1 = 0;
	int zeroes = 0;

	while ((n & 1) == 1) {
		++trail1;
		n >>= 1;
	}
	while ((n & 1) == 0) {
		++zeroes;
		n >>= 1;
	}
	p = trail1 + zeroes;
	n = (number ^ (1 << p)) & (~0 << p);
	n |= ((1 << (trail1+1)) - 1) << (zeroes-1);
	res.push_back(n);

	return res;
}

int main()
{
	std::string bin1 = "11011001111100";
	std::string bin2 = "10011110000011";
	int n1 = std::stoi(bin1, 0, 2);
	int n2 = std::stoi(bin2, 0, 2);
	
	std::cout << "Input:\t\t" << n1 << std::endl;
	std::cout << "Binary:\t\t" << intToStr(n1) << std::endl;

	std::vector<int> r1 = nextNumber(n1);
	std::cout << "Larger:\t\t" << r1[0] << std::endl;
	std::cout << "Binary:\t\t" << intToStr(r1[0]) << std::endl;
	std::cout << "Smaller:\t" << r1[1] << std::endl;
	std::cout << "Binary:\t\t" << intToStr(r1[1]) << std::endl;

	std::cout << std::endl;

	std::cout << "Input:\t\t" << n2 << std::endl;
	std::cout << "Binary:\t\t" << intToStr(n2) << std::endl;

	std::vector<int> r2 = nextNumber(n2);
	std::cout << "Larger:\t\t" << r2[0] << std::endl;
	std::cout << "Binary:\t\t" << intToStr(r2[0]) << std::endl;
	std::cout << "Smaller:\t" << r2[1] << std::endl;
	std::cout << "Binary:\t\t" << intToStr(r2[1]) << std::endl;

	return 0;
}
