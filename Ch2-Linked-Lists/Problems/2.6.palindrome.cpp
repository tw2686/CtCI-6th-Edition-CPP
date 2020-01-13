#include <iostream>
#include <vector>

/*
 * hints:
 * 5, 13, 29, 61, 101
 *
 * ask:
 *
 * solutions:
 */

/* Definition for singly-linked list */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool palindrome(ListNode *head)
{
	return false;
}

/* helper function to print linked list */
void printList(ListNode *head)
{
	while (head) {
		std::cout << head->val << "->";
		head = head->next;
	}
	std::cout << "nullptr" << std::endl;
}

/* converts vector of numbers to linked list */
ListNode* vectorToListNode(std::vector<int> vec)
{
	ListNode *tmp = new ListNode(0);
	ListNode *p = tmp;
	for (int i = 0; i < vec.size(); ++i) {
		p->next = new ListNode(vec[i]);
		p = p->next;
	}
	p = tmp->next;
	delete tmp;
	return p;
}

/* deallocates list nodes */
void deleteList(ListNode *&head)
{
	ListNode *tmp;
	while (head) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}

int main()
{
	std::vector<int> v1 = { 1, 2, 3, 2, 1 };
	ListNode *l1 = vectorToListNode(v1);

	printList(l1);
	std::cout << palindrome(l1) << std::endl;;

	deleteList(l1);

	return 0;
}
