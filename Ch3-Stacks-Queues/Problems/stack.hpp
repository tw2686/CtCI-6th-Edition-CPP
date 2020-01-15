// stack.hpp

#include <iostream>

template <class T>
class Stack
{
	public:
		// default constructor
		Stack() : topOfStack(nullptr), stackSize(0) {}

		// copy constructor
		Stack(Stack&& src) : topOfStack(std::move(src.topOfStack)), stackSize(std::move(src.stackSize)) {}

		// destructor
		~Stack() { while (!empty()) pop(); }

		// push
		template <class U>
		void push(U&& item) {
			Node *n = new Node(std::forward<T>(item), topOfStack);
			topOfStack = n;
			++stackSize;
		}

		// top
		T& top() {
			if (topOfStack == nullptr)
				throw StackIsEmptyException();
			return topOfStack->val;
		}

		// pop
		void pop() {
			if (topOfStack == nullptr)
				throw StackIsEmptyException();
			Node *tmp = topOfStack;
			topOfStack = topOfStack->next;
			delete tmp;
			--stackSize;
		}

		// empty
		bool empty() const {
			return topOfStack == nullptr;
		}

		// size
		size_t size() const {
			return stackSize;
		}

		// stackIsEmptyException
		class StackIsEmptyException {};

	private:
		struct Node {
			T val;
			Node *next;
			//Node(T v) : val(v), next(nullptr) {}
			Node(T&& v, Node *n) : val(std::move(v)), next(n) {}
			Node(const T& v, Node *n) : val(v), next(n) {}
		};
		Node *topOfStack;
		size_t stackSize;
};
