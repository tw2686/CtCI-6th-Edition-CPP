// arraylist.h

#define ARRAYLIST_H

template <class T>
class arraylist
{
	private:
		T *data;
		int arrlength;		// length of actual array
		int listsize;		// number of elements in the list
		void resize();		// reisze array if necessary
		bool needResize;	// determine if we need to resize

	public:
		// constructor
		arrayList() {
			data = new T[5];
			arrlength = 5;
			listsize = 0;
		}
		
		// accessor methods
		bool contains(T item);	// contains
		int indexOf(T item);	// index of
		int lastindexOf(T item);	// last
		T get(int index); 	// get item form index
		int size();		// get size of array

		// modifiers
		void add(T item);	// add item
		void add(int index, T item);
		void set(int index, T item);
		void remove(int index);
		void remove(T item);
};


