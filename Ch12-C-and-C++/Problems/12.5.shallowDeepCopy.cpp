/*
 * Problem:
 * What is the difference between deep copy and shallow copy? Explain how you
 * would use each.
 *
 * hints:
 * 445
 *
 * solution:
 * shallow copy copies all member values from on object to another
 * deep copy does all this and also deep copies any pointer objects
 * shallow copy can have runtime errors
 * no need to pass information about complex structure without actual
 * duplication of data
 * deep copy should be used in most cases, especially when size of structure
 * copied is small
 * 
 */

#include <iostream>
using namespace std;

struct Obj {
	char *ptr;
};

void shallowCopy(Obj &src, Obj &dst)
{
	dst.ptr = src.ptr;
}

void deepCopy(Obj &src, Obj &dst)
{
	// allocate space
	dst.ptr = (char *)malloc(strlen(src.ptr) + 1);
	strcpy(dst.ptr, src.ptr);
}


int main()
{

	char str[] = "fatfatfat";

	Obj *obj = new Obj();
	obj->ptr = str;
	cout << obj->ptr << endl;

	Obj *sCopy = new Obj();
	shallowCopy(*obj, *sCopy);
	cout << sCopy->ptr << endl;

	Obj *dCopy = new Obj();
	deepCopy(*obj, *dCopy);
	cout << dCopy->ptr << endl;

	return 0;
}
