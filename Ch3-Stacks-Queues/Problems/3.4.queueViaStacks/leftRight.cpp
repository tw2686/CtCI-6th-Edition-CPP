#include <iostream>
#include <stack>

/*
 * hints:
 * 98, 114
 *
 * ask:
 *
 * solutions:
 */

class Queue
{
	public:
		Queue() { }

		~Queue() { }

		void push(const int v) {
			move(right, left);
			left.push(v);
		}

		void pop() {
			move(left, right);
			if (!right.empty()) right.pop();
		}

		int front() {
			move(left, right);
			if (!right.empty()) return right.top();
			return 0;
		}

		int back() {
			move(right, left);
			if (!left.empty()) return left.top();
			return 0;
		}

		bool empty() const {
			return (left.empty() && right.empty());
		}
		
		int size() const {
			return left.size() + right.size();
		}

	private:
		void move(std::stack<int> &src, std::stack<int> &dst) {
			while (!src.empty()) {
				dst.push(src.top());
				src.pop();
			}
		}
		std::stack<int> left;
		std::stack<int> right;
};

int main()
{
	Queue q;
	for (int i = 0; i < 10; ++i) {
		q.push(i);
		std::cout << "Queued value " << q.back() << std::endl;
	}

	for (int i = 0; i < 5; ++i) {
		std::cout << "Removed value " << q.front() << std::endl;
		q.pop();
	}

	for (int i = 10; i < 15; ++i) {
		q.push(i);
		std::cout << "Queued value " << q.back() << std::endl;
	}

	while (!q.empty()) {
		std::cout << "Removed value " << q.front() << std::endl;
		q.pop();
	}
	
	return 0;
}
