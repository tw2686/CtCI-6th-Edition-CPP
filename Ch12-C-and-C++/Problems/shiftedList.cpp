#include <iostream>

using namespace std;

template <class T>class ShiftedList
{
	T *array;
	int offset, size;

	public:
		ShiftedList(int sz) : offset(0), size(sz) {
			array = new T[size];
		}

		~ShiftedList() {
			delete [] array;
		}

		void shiftBy(int n) {
			offset = (offset + n) % size;
		}

		T getAt(int i) {
			return array[convertIndex(i)];
		}

		void setAt(T item, int i) {
			array[convertIndex(i)] = item;
		}

		int getSize() {
			return size;
		}

		void printList() {
			for (int i = 0; i < getSize(); ++i)
				cout << getAt(i) << ' ';
			cout << '\n';
		}

	private:
		int convertIndex(int i) {
			int index = (i - offset) % size;
			while (index < 0) index += size;
			return index;

		}
};


int main()
{
	ShiftedList<int> *sl = new ShiftedList<int>(5);


	for (int i = 0; i < sl->getSize(); ++i)
		sl->setAt(i+1, i);

	sl->printList();

	sl->shiftBy(2);

	sl->printList();

	return 0;

}
