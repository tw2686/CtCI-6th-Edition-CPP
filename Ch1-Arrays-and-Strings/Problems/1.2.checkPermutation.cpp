#include <iostream>
#include <cstring>

/*
 * hints:
 * 1
 * 84
 * 122
 * 131
 *
 * ask:
 */


bool permutations(std::string s1, std::string s2)
{
	return false;
}

int main()
{
	std::string tests[5][2] = {
		{ "abc", "acb" },
		{ "acd", "abb" },
		{ "eea", "eae" },
		{ "aaaa", "aa" },
		{ "", "" }
	};

	for (int i = 0; i < tests.size(); ++i) {
		std::cout << permutations(tests[i]);
		std::cout << std::endl;
	}

	return 0;
}
