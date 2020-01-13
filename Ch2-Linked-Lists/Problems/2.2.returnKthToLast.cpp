#include <iostream>
#include <vector>

/*
 * hints:
 * 8, 25, 41, 67, 126
 *
 * ask:
 *
 * solutions:
 * 1. recursion: plus 1 coming back
 * 2. iterative: 2 ptrs of length k
 */

/* Definition for singly-linked list */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* iterative, use two ptrs of length k */
ListNode* kthLast3(ListNode *head, int k)
{
	ListNode *p1 = head;
	ListNode *p2 = head;
	
	for (int i = 0; i < k; ++i) {
		if (p2 == nullptr) return nullptr;
		p2 = p2->next;
	}
	
	while (p2) {
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}

/* Approach A: recursive, don't return element */
int kthLast1(ListNode *head, int k)
{
	if (head == nullptr)
		return 0;

	int i = kthLast1(head->next, k) + 1;
	if (i == k) {
		std::cout << k << "th to last node is " << head->val;
		std::cout << std::endl;
	}
	return i;
}

/* Approach B: c++ specific, O(n) */
ListNode *kthLast2(ListNode *head, int k, int &i)
{
	if (head == nullptr)
		return nullptr;
	
	ListNode *node = kthLast2(head->next, k, i);
	++i;
	if (i == k)
		return head;
	return node;
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
	ListNode *list1 = vectorToListNode(v1);

	printList(list1);
	int k = 4;
	ListNode *res1 = kthLast3(list1, k);
	std::cout << k << "th to last node is " << res1->val << std::endl;

	deleteList(list1);

	return 0;
}
