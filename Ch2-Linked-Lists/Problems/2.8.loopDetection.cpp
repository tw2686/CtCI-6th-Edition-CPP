#include <iostream>
#include <vector>

/*
 * hints:
 * 50, 69, 83, 90
 *
 * ask:
 *
 * solutions:
 * 1. use hashing
 * 2. floyd cycle finding algo: move slow/fast pointers
 */

/* Definition for singly-linked list */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* loopDetect(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}
	if (!fast || !fast->next) return nullptr;

	std::cout << "Collision: " << slow->val << std::endl;

	slow = head;	
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	return fast;
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
	std::vector<int> v1 = { 1, 2, 3, 4, 5 };
	ListNode *l1 = vectorToListNode(v1);

	// make circular linked list
	// 5 points to 3
	ListNode *cur = l1;
	while (cur->next)
		cur = cur->next;
	cur->next = l1->next->next;

	ListNode *res = loopDetect(l1);
	std::cout << "Loop Start: " << res->val << std::endl;

	cur->next = nullptr;
	deleteList(l1);
	
	return 0;
}
