#include <iostream>
#include <vector>

int lockers(int n)
{
	std::vector<bool> locks(n+1, false);
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j+=i) {
			locks[j] = !locks[j];
		}
	}
	int open = 0;
	for (int i = 1; i <= n; ++i) {
		if (locks[i]) ++open;
		std::cout << locks[i] << " ";
	}
	std::cout << std::endl;

	return open;
}

int main()
{
	int n = 100;
	int res = lockers(n);

	std::cout << "Open: " << res << std::endl;

	return 0;
}
