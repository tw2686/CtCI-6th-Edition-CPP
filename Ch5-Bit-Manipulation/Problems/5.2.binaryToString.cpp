#include <iostream>
#include <string>

/*
 * Hints:
 * 143, 167, 173, 269, 297
 *
 * Solution:
 * multiply by 2, compare to 1, if less than 1 add 0
 * else add 1, and minus 1, go until number becomes 0
 *
 * Time Complexity:
 * 
 * Space Complexity:
 */

std::string binToString(double a)
{

	if (a == 1) return "1.0";

	std::string res = "0.";
	double tmp = a;
	while (tmp) {
		tmp *= 2;
		if (tmp < 1) {
			res += '0';
		} else {
			res += '1';
			--tmp;
		}
		if (res.length() > 32)
			return "ERROR";
	}

	return res;
}

int main()
{
	double a1 = 0.375;
	double a2 = 0.72;

	std::cout << "Double: " << a1 << std::endl;
	std::cout << binToString(a1) << std::endl;
	std::cout << "Double: " << a2 << std::endl;
	std::cout << binToString(a2) << std::endl;

	return 0;
}
