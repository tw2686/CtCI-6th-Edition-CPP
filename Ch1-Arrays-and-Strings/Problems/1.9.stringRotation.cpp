#include <iostream>
#include <cstring>

/*
 * hints:
 * 34, 88, 104
 *
 * ask:
 *
 * solutions:
 */

bool checkSub(std::string s1, std::string s2)
{
	int j = 0;
	for (int i = 0; i < s2.length(); ++i) {
		if (s2[i] == s1[j]) {
			if (++j == s1.length()) return true;
		} else {
			j = 0;
		}
	}
	return false;
}

bool isSubstring(std::string s1, std::string s2)
{
	int diff = s1.length() - s2.length();
	return diff < 0 ? checkSub(s1, s2) : checkSub(s2, s1);
}

/* observe that s2 will always have a substring in s1s1 */
bool stringRotation1(std::string s1, std::string s2)
{
	if (s1.length() != s2.length()) return false;

	std::string s1s1 = s1.append(s1);
	
	return isSubstring(s2, s1s1);
}

int main()
{
	std::string subtests[5][2] = {
		{"fat", "fatboi"},
		{"fat", "boifat"},
		{"faboifatboiat", "fat"},
		{"a", "b"},
		{"fat", "fafafafa"}
	};

	std::string tests[2][2] = {
		{"waterbottle", "erbottlewat"},
		{"nany", "anyn"}
	};
	for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
		std::cout << tests[i][0] << ", " << tests[i][1] << " -> ";
		//std::cout << isSubstring(tests[i][0], tests[i][1]);
		std::cout << stringRotation1(tests[i][0], tests[i][1]);
		std::cout << std::endl;
	}

	return 0;
}
