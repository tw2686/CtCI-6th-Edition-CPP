/*
 * Problem:
 * Why does a destructor in base class need to be declared virtual?
 *
 * hints:
 * 421, 460
 *
 * solution:
 * destructors are used to clean up memory and resources
 * destructors of the most derived class need to be called
 * must make parent destructor virtual so that it would keep looking
 */

#include <iostream>
using namespace std;



int main()
{

	return 0;
}
