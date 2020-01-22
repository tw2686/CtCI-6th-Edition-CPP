#include <iostream>
#include <cmath>
#include <vector>

/* iterate through 2 to n-1 */
bool primeNaive(int n)
{
	if (n < 2) return false;
	for (int i = 2; i < n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

/* iterate only up through square root of n */
bool primeSlightlyBetter(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= (int)std::sqrt(n); ++i) {
		if (n % i == 0)
			return false;

	}
	return true;
}

/* sieve of eratosthenes */
std::vector<bool> sieveOfEratosthenes(int n)
{
	std::vector<bool> flags(n+1, true);
	flags[0] = false; flags[1] = false;
	int count = 0;
	int prime = 2;

	while (prime <= std::sqrt(n)) {

		/* cross off remaining multiples of prime */
		for (int i = prime * prime; i < flags.size(); i += prime)
			flags[i] = false;

		/* find next value which is true */
		int next = prime + 1;
		while (next < flags.size() && !flags[next])
			++next;
		prime = next;
	}

	return flags;
}

int main()
{
	int n1 = 11;
	
	std::cout << "Input: " << n1 << std::endl;
	std::cout << "Naive: " << primeNaive(n1) << std::endl;
	std::cout << "SlightlyBetter: " << primeSlightlyBetter(n1) << std::endl;
	
	std::vector<bool> sieve = sieveOfEratosthenes(20);
	for (int i = 0; i < sieve.size(); ++i)
		std::cout << i << ": " << sieve[i] << std::endl;

	return 0;
}
