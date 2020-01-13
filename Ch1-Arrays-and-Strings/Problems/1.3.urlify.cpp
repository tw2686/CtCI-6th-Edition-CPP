#include <iostream>
#include <cstring>

/*
 * hints:
 * 53, 118
 *
 * ask:
 *
 * solutions:
 */

/* move string when theres space */
std::string urlify1(std::string s, int len)
{
	int i = 0;
	int j = len - 1;
	
	while (i < len) {
		if (s[i] == ' ') {
			int k = j;
			while (k > i) {
				s[k+2] = s[k];
				--k;
			}
			s[i] = '%';
			s[i+1] = '2';
			s[i+2] = '0';
			i += 2;
			j += 2;
		} 
		++i;
	}
	return s;
}

/* count spaces first, modify from end, keep two pointers */
std::string urlify2(std::string s, int len)
{
	int spaceCnt = 0;
	for (int i = 0; i < len; ++i)
		if (s[i] == ' ') ++spaceCnt;

	int j = len + spaceCnt * 2;
//	if (len < s.length()) s[len] = '\0';
	for (int i = len - 1; i >= 0; --i) {
		if (s[i] == ' ') {
			s[j-1] = '0';
			s[j-2] = '2';
			s[j-3] = '%';
			j -= 3;
		} else {
			s[j-1] = s[i];
			--j;
		}
	}
	return s;
}

int main()
{
	struct Test {
		std::string str;
		int len;
	};

	Test tests[1];
	tests[0].str = "Mr John Smith    ";
	tests[0].len = 13;

	for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
		std::cout << tests[i].str << ", " << tests[i].len << ", ";
		std::cout << std::endl;
		std::cout << urlify1(tests[i].str, tests[i].len) << std::endl;
		std::cout << urlify2(tests[i].str, tests[i].len) << std::endl;
	}

	return 0;
}
