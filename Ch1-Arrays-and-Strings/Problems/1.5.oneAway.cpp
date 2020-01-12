#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unordered_map>

/*
 * hints:
 * 23, 97, 130
 *
 * ask:
 *
 * solutions:
 */

bool oneAway(std::string s1, std::string s2)
{
	int diff = s1.length() - s2.length();
	if (std::abs(diff) > 1) return false;

	std::unordered_map<char, int> map;

	for (int i = 0; i < s1.length(); ++i)
		++map[s1[i]];
	for (int i = 0; i < s2.length(); ++i)
		--map[s2[i]];

	int x = 0;
	int negCnt = 0;
	for (std::pair<char, int> e : map) {
		if (e.second < 0)
			++negCnt;
		x += e.second;
	}

	if (negCnt > 1) return false;
	return abs(x) <= 1;
}

bool checkInsRem(std::string s1, std::string s2)
{
	int i = 0, j = 0;
	bool firstDiff = false;

	while (i < s1.length() && j < s2.length()) {
		if (s1[i] != s2[j]) {
			if (firstDiff == true) return false;
			firstDiff = true;
			++i;
		} else {
			++i;
			++j;
		}
	}
	return true;
}

bool checkReplace(std::string s1, std::string s2)
{
	bool firstDiff = false;
	for (int i = 0; i < s1.length(); ++i) {
		if (s1[i] != s2[i]) {
			if (firstDiff == true) return false;
			firstDiff = true;
		}
	}
	return true;
}

bool oneAway2(std::string s1, std::string s2)
{
	int diff = s1.length() - s2.length();
	if (std::abs(diff) > 1) return false;

	// replace
	if (s1.length() == s2.length())
		return checkReplace(s1, s2);

	// insert/remove
	return diff > 0 ? checkInsRem(s1, s2) : checkInsRem(s2, s1);
}

int main()
{
	std::string tests[9][2] = {
		{"pale", "ple"},
		{"pales", "pale"},
		{"pale", "bale"},
		{"pale", "bake"},
		{"pale", "pales"},
		{"p", "pp"},
		{"pp", "p"},
		{"ppp", "p"},
		{"abb", "acc"}
	};

	for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
		std::cout << tests[i][0] << ", " << tests[i][1] << " -> ";
		std::cout << oneAway2(tests[i][0], tests[i][1]);
		std::cout << std::endl;
	}

	return 0;
}
