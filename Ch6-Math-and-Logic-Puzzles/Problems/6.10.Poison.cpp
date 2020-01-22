#include <iostream>
#include <vector>
#include <ctime>

int detectPoison(std::vector<bool> bottles, std::vector<bool> strips)
{
	int days = 0;

	for (int i = 1; i <= bottles.size(); ++i) {
		int n = i;
		int j = 0;
		while (n) {
			if ((n & 1) == 1)
				strips[j] = strips[j] || bottles[i];
			++j;
			n >>= 1;
		}
	}
	days += 7;

	int bottleNum = 0;

	for (int i = 0; i < strips.size(); ++i) {
		if (strips[i])
			bottleNum |= (1 << i);
	}

	std::cout << "Testing took " << days << " days." << std::endl;

	return bottleNum;
}

int main()
{
	srand(time(NULL));
	int N = 1000;
	std::vector<bool> bottles(N+1, false);
	int pos = std::rand() % 1000;
	bottles[pos] = true;
	std::vector<bool> strips(10, false);

	int res = detectPoison(bottles, strips);
	std::cout << "The " << res << "th bottle is found to be poissoned." << std::endl;
	std::cout << "The " << pos << "th bottle is actually poissoned." << std::endl;

	return 0;
}
