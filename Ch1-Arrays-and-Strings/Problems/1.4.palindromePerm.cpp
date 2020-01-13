#include <iostream>
#include <cstring>
#include <unordered_map>

/*
 * hints:
 * 106, 121, 134, 136
 *
 * ask:
 *
 * solutions:
 * 1. count the odd frequencies, both even/odd strings can have at most 1 odd
 */

/* store counts in array of alphabet length */
bool palindromePerm1(std::string s)
{
	int ascii[26] = { 0 };

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != ' ')
			++ascii[tolower(s[i]) - 'a'];
	}

	int oddCnt = 0;
	for (const auto &c : ascii)
		if (c % 2 != 0) ++oddCnt;

	return oddCnt <= 1;
}

/* get number of odd counts on one pass */
bool palindromePerm2(std::string s)
{
	int ascii[26] = { 0 };
	int oddCnt = 0;

	for (int i = 0; i < s.length(); ++i) {
		int n = tolower(s[i]) - 'a';
		if (n >= 0) {
			if (++ascii[n] % 2 != 0)
				++oddCnt;
			else
				--oddCnt;
		}
	}
	return oddCnt <= 1;
}

/* use hash table instead of array */
bool palindromePerm3(std::string s)
{
	std::unordered_map<char, int> map;
	int oddCnt = 0;

	for (int i = 0; i < s.length(); ++i) {
		char c = tolower(s[i]);
		if (c != ' ') {
			if (++map[c] % 2 != 0)
				++oddCnt;
			else
				--oddCnt;
		}
	}
	return oddCnt <= 1;
}

/* use bit vector, XOR, and count all 1's/odds */
bool palindromePerm4(std::string s)
{
	int bit = 0;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != ' ')
			bit ^= 1 << (tolower(s[i]) - 'a');
	}

	int oddCnt = 0;
	while (bit) {
		oddCnt += bit & 1;
		bit >>= 1;
	}

	return oddCnt <= 1;
}

/* use -1 and & to check for exactly one 1 */
bool palindromePerm5(std::string s)
{
	int bit = 0;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != ' ')
			bit ^= 1 << (tolower(s[i]) - 'a');
	}

	return (bit & (bit - 1)) == 0;
}

int main()
{
	std::string tests[3] = {
		"abcdefgz",
		"Tact Coa",
		"aabb"
	};

	for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
		std::cout << tests[i] << ", ";
		std::cout << palindromePerm1(tests[i]);
		std::cout << palindromePerm2(tests[i]);
		std::cout << palindromePerm3(tests[i]);
		std::cout << palindromePerm4(tests[i]);
		std::cout << palindromePerm5(tests[i]);
		std::cout << std::endl;
	}

	return 0;
}
