/*
 * Problem:
 * Write a smart pointer class
 * A smart pointer is a data type, implemented with templates, simulates a
 * pointer while also providing automatic garbage collection
 * automatically counts the number of references to a smartpointer<T*>object
 * frees object of type T when reference count hits zero
 *
 * hints:
 * 402, 438, 453
 *
 * solution:
 */

#include <iostream>
using namespace std;

template<class T> class SmartPointer
{
	public:
		SmartPointer(T *ptr) {
			cout << "Constructor called.\n";
			ref = ptr;
			ref_count = (unsigned *)malloc(sizeof(unsigned));
			*ref_count = 1;
		}

		SmartPointer(SmartPointer<T>& sptr) {
			cout << "Copy constructor called.\n";
			ref = sptr.ref;
			ref_count = sptr.ref_count;
			++(*ref_count);
		}

		SmartPointer<T> &operator=(SmartPointer<T> &sptr) {
			cout << "Equals override called\n";
			if (this == &sptr) return *this;
	
			if (*ref_count > 0) remove();
			
			ref = sptr.ref;
			ref_count = sptr.ref_count;
			++(*ref_count);
			return *this;
		}

		~SmartPointer() { remove(); }

		T getValue() { return *ref; }

		void getCount() { cout << *ref_count << '\n'; }

	protected:
		void remove() {
			--(*ref_count);
			if (*ref_count == 0) {
				delete ref;
				free(ref_count);
				ref = NULL;
				ref_count = NULL;
			}
		}
		T *ref;
		unsigned *ref_count;
};

int main()
{
	int a = 1, b = 2, c = 3;

	SmartPointer<int> *sp1 = new SmartPointer<int>(&a);
	cout << sp1->getValue() << '\n';
	sp1->getCount();

	SmartPointer<int> *sp2 = new SmartPointer<int>(&b);
	cout << sp2->getValue() << '\n';
	sp2->getCount();

	SmartPointer<int> sp3_obj = *sp1;
	SmartPointer<int> *sp3 = &sp3_obj;
	cout << sp3->getValue() << '\n';
	sp3->getCount();

	SmartPointer<int> sp4_obj = *sp2;	
	SmartPointer<int> *sp4 = &sp4_obj;
	cout << "Counts:\n";
	sp1->getCount();
	sp2->getCount();
	sp3->getCount();
	sp4->getCount();

	*sp3 = *sp4;
	cout << "Counts:\n";
	sp1->getCount();
	sp2->getCount();
	sp3->getCount();
	sp4->getCount();

	return 0;
}

