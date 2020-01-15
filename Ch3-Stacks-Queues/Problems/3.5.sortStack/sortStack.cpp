#include <iostream>
#include <stack>

/*
 * hints:
 * 15, 32, 43
 *
 * ask:
 *
 * solutions:
 * 1. use tmp stack to sort, call sort on push, or on pop/top. Algorithm is
 * O(n^2) and O(N) space
 * 2. unlimited stacks can do modified quicksort or mergesort O(nlogn)
 * mergeSort: create 2 extra stacks and divide the stacks into 2 parts
 * recursively sort each stack, then merge them back together
 * quickSort: create 2 extra stacks and divide the stacks into the 2 based on
 * pivot element. The two stacks would be recursively sorted, merged back
 * togerther into original stack.
 * Both involve creating 2 extra stacks per level of recursion
 */

class StackSort
{
	public:
		StackSort() { }

		~StackSort() { }

		void push(int v) {
			s1.push(v);
			sort(s1);
		}

		void pop() {
			s1.pop();
		}

		int top() const {
			return s1.top();
		}

		bool empty() const {
			return s1.empty();
		}

	private:
		void sort(std::stack<int> &s1) {
			std::stack<int> s2;
			while (!s1.empty()) {
				int tmp = s1.top();
				s1.pop();
				while (!s2.empty() && s2.top() > tmp) {
					s1.push(s2.top());
					s2.pop();
				}
				s2.push(tmp);
			}
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}
		std::stack<int> s1;
};

int main()
{
	StackSort s;
	for (auto v : {5, 10, 4, 9, 3, 3, 8, 1, 2, 2, 7, 6}) {
		s.push(v);
		std::cout << "Pushed value: " << v << std::endl;
	}
	while (!s.empty()) {
		std::cout << "Popped value: " << s.top() << std::endl;
		s.pop();
	}

	return 0;
}
