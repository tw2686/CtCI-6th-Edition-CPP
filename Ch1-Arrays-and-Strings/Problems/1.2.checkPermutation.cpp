#include <iostream>
#include <cstring>

/*
 * hints:
 * 1, 84, 122, 131
 *
 * ask:
 * 1. whether its case sensitive
 * 2. whether whitespace is significant
 *
 * solutions:
 * 1. sort each string, compare
 * 2. count letters
 */

/* array of ASCII booleans */
bool permutations1(std::string s1, std::string s2)
{
	if (s1.length() != s2.length()) return false;

	bool chars[256] = { false };

	for (int i = 0; i < s1.length(); ++i) {
		int v1 = (int)s1[i];
		int v2 = (int)s2[i];

		chars[v1] = !chars[v1];
		chars[v2] = !chars[v2];
	}

	for (int i = 0; i < 256; ++i)
		if (chars[i] == true) return false;

	return true;
}

/* binary representation */
bool permutations2(std::string s1, std::string s2)
{
	if (s1.length() != s2.length()) return false;

	int bit1 = 0, bit2 = 0;

	for (int i = 0; i < s1.length(); ++i) {
		bit1 |= 1 << (s1[i] - 'a');
	}
	for (int i = 0; i < s2.length(); ++i) {
		bit2 |= 1 << (s2[i] - 'a');
	}
	return (bit1 ^ bit2) == 0;
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

	for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
		std::cout << tests[i][0] << ", " << tests[i][1] << ", ";
		std::cout << permutations2(tests[i][0], tests[i][1]);
		std::cout << std::endl;
	}

	return 0;
}
