#include <iostream>
#include <cstring>
#include <unordered_set>

/*
 * hints:
 * 44: hash table
 * 117: vector
 * 132: O(N log N) time
 *
 * ask:
 * ASCII string or Unicode string
 */

/* hash set */
bool isUnique1(std::string s)
{
	std::unordered_set<char> set;

	for (int i = 0; i < s.length(); ++i)
		set.insert(s[i]);
	return set.size() == s.length();
}

/* array, assume extended ASCII */
bool isUnique2(std::string s)
{
	if (s.length() > 256) return false;

	bool char_seen[256] = { false };

	for (int i = 0; i < s.length(); ++i) {
		int v = (int)s[i];

		if (char_seen[v]) return false;
		char_seen[v] = true;
	}
	return true;
}

/* bit vector, reduce space usage, assumes a-z only */
bool isUnique3(std::string s)
{
	int bit = 0;
	
	for (int i = 0; i < s.length(); ++i) {
		int mask = 1 << (s[i] - 'a');
		
		if (bit & mask) return false;
		bit |= mask;
	}
	return true;
}

/* 
 * brute force: compare every char with every other char, O(n^2) time
 * sort: sort string and linearly check neighbors, O(N log N)
 */

int main()
{
	std::string tests[4] = { "abcd", "aabb",
				 "", "aaaa" };

	for (int i = 0; i < 4; ++i) {
		std::cout << isUnique1(tests[i]);
		std::cout << isUnique2(tests[i]);
		std::cout << isUnique3(tests[i]);
		std::cout << std::endl;
	}

	return 0;
}
