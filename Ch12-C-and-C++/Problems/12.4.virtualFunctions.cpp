/*
 * Problem:
 * How do virtual functions work in C++?
 *
 * hints:
 * 463
 *
 * solution:
 * - Virtual functions depends on a vtable, virtual table
 * - any function of a class can be declared virtual
 * - vtable is constructed which stores addresses of these functions
 * - compiler adds hidden vptr to all such classes that points to the vtable
 * of that class
 * - if virtual function is not overriden, calls parent function
 * - else derived class is used
 * - dynamic binding
 * - most dervied virtual function gets called
 * 
 */

#include <iostream>
using namespace std;

class Shape {
	public:
		int edge;
		virtual void circumference() {
			cout << "Circumference of Base Class: 0 \n";
		}
};

class Square : public Shape {

	public:
		void circumference() {
			edge = 4;
			cout << "Circumference of Square Class: " <<  4 * edge << '\n';
		}
};


int main()
{
	Shape *shape = new Shape();
	shape->circumference();

	Shape *square = new Square();
	square->circumference();

	return 0;
}
