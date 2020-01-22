#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

std::vector<int> birthFamily()
{
	int boys = 0;
	int girls = 0;
	int r;

	while (girls == 0) {
		if ((std::rand() % 2) == 1) ++girls;
		else ++boys;
	}
	std::vector<int> res = { girls, boys };

	return res;
}

double birthFamilies(int n)
{
	int boys = 0;
	int girls = 0;
	std::vector<int> genders;

	for (int i = 0; i < n; ++i) {
		genders = birthFamily();
		girls += genders[0];
		boys += genders[1];
	}

	return girls / (double)(boys + girls);
}

int main()
{
	srand(time(NULL));

	for (int i = 1; i < 6; ++i) {

		int n = std::pow(10, i);
		double ratio = birthFamilies(n);	

		std::cout << n << " Families: " << std::endl;
		std::cout << "Ratio: " << ratio << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
