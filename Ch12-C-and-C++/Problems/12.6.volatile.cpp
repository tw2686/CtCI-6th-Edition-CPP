/*
 * Problem:
 * What is the significant of the keyword "volatile" in C?
 *
 * hints:
 * 456
 *
 * solution:
 * volatile informs compiler that the value of variable it is applied to can
 * change from outside, without any update done by code
 * can be done by OS, hardwware, another thread
 * can change unexpectedly, compiler can reload value each time from memory
 * volatile to prevent compiler form optimizing code that guarentees variable
 * will never be changed
 * Useful for multi-threaded programs have global variables
 * any thread can modify these shared variables
 */

#include <iostream>
using namespace std;

int main()
{

	return 0;
}
