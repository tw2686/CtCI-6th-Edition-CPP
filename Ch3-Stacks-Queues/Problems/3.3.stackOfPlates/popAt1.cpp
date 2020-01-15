#include <iostream>
#include <vector>
#include <stack>

/*
 * hints:
 * 64, 81
 *
 * ask:
 *
 * solutions:
 * 1. use array of stacks, or stack of stacks
 * trade off between being okay with not full capacity sub stacks
 * or full capacity with shifting/rollback
 */

/* Using std vector of stacks */
class SetOfStacks
{
	public:
		SetOfStacks(int capa) {
			cap = capa;
			stacks.push_back(std::stack<int>());
		}

		~SetOfStacks() { }

		void push(int v) {
			if (stacks.empty() || stacks.back().size() >= cap) {
				stacks.push_back(std::stack<int>());
				getSetSize();
			}
			stacks.back().push(v);
		}

		int top() const {
			return stacks.back().top();
		}

		void pop() {
			stacks.back().pop();
			if (stacks.back().size() == 0) {
				stacks.pop_back();
				getSetSize();
			}
		}

		bool empty() const {
			return stacks.size() == 0;
		}

		void popAt(int index) {
			stacks[index].pop();
			if (stacks[index].size() == 0) {
				stacks.erase(stacks.begin()+index);
				getSetSize();
			}
		}

		void getSetSize() {
			std::cout << "There are now ";
			std::cout << stacks.size();
			std::cout << " set(s) of stacks.";
			std::cout << std::endl;
		}

	private:
		std::vector<std::stack<int>> stacks;
		int cap;
};

int main()
{
	SetOfStacks s1 (3);

	std::cout << "pushing..." << std::endl;
	for (int i = 1; i < 10; ++i)
		s1.push(i);

	std::cout << "popAt(1)..." << std::endl;
	s1.popAt(1);

	std::cout << "popAt(0)..." << std::endl;
	s1.popAt(0);

	std::cout << "popping..." << std::endl;
	while (!s1.empty()) {
		std::cout << s1.top() << std::endl;
		s1.pop();
	}

	return 0;
}
