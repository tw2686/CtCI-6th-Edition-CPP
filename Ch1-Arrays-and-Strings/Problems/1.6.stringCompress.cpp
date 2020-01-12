#include <iostream>
#include <cstring>

/*
 * hints:
 * 92, 110
 *
 * ask:
 *
 * solutions:
 * 1. use StringBuilder, concat string that takes O(n)
 * 2. optimize by checking length of compressed first, but duplicates code
 *    can also set the length of string, instead of dynamically allocating
 */

/* keeps count, only pushes char if at end or sees different */
std::string strCompression1(std::string s)
{
	std::string cmp;
	int cnt = 0;
	
	for (int i = 0; i < s.length(); ++i) {
		++cnt;

		if (i + 1 >= s.length() || s[i] != s[i+1]) {
			cmp.push_back(s[i]);
			cmp.append(std::to_string(cnt));
			cnt = 0;
		}
	}	
	return (s.length() < cmp.length()) ? s : cmp;
}

int main()
{
	std::string tests[3] = {
		"aabcccccaaa",
		"aaaaaa",
		"abcdef"
	};

	for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
		std::cout << tests[i] << ": ";
		std::cout << strCompression1(tests[i]);
		std::cout << std::endl;
	}

	return 0;
}
