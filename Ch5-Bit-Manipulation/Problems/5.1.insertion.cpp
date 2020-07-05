#include <iostream>
#include <string>

/*
 * Hints:
 * 137, 169, 215
 *
 * Solution:
 * - get mask of 0's between i and j
 * - & with M
 * left shift N i times
 * or both together
 *
 * Time Complexity:
 * 
 * Space Complexity:
 */

std::string insertion(int N, int M, int i, int j)
{
	std::string resStr;
	int res;
	int ones = ~0;
	int Mmask = M << i;

	int left = ones << (j+1);
	int right = ones << ((1 << i) - 1);

	int Nmask = left | right;

	res = (N & Nmask) | Mmask;

	while (res) {
		int tmp = res & 1;
		resStr = std::to_string(tmp) + resStr;
		res >>= 1;
	}
	return resStr;
}

int main()
{
	std::string bin1 = "10000000000";
	std::string bin2 = "10011";
	int N1 = 0;
	int M1 = 0;
	
	N1 = std::stoi(bin1, 0, 2);
	M1 = std::stoi(bin2, 0, 2);

	std::cout << insertion(N1, M1, 2, 6) << std::endl;	
	
	return 0;
}
