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
				std::cout << "New Stack has been created." << std::endl;
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
				std::cout << "Stack has been deleted." << std::endl;
			}
		}

		bool empty() const {
			return stacks.size() == 0;
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

	std::cout << "popping..." << std::endl;
	while (!s1.empty()) {
		std::cout << s1.top() << std::endl;
		s1.pop();
	}

	return 0;
}
