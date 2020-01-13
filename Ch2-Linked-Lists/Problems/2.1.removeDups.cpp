#include <iostream>
#include <vector>
#include <unordered_set>

/*
 * hints:
 * 9, 40
 *
 * ask:
 *
 * solutions:
 * 1. use hash set
 * Follow Up: use runner ptr to remove any future duplicates, but will be O(n^2)
 */

/* Definition for singly-linked list */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* for sorted lists only */
void removeDupsSorted(ListNode *head)
{
	ListNode *cur = head;
	while (cur->next) {
		if (cur->val == cur->next->val) {
			ListNode *tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
		} else {
			cur = cur->next;
		}
	}
}

/* using hash set */
void removeDups1(ListNode *head)
{
	std::unordered_set<int> set;
	
	ListNode *cur = head;
	while (cur->next) {
		set.insert(cur->val);
		if (set.find(cur->next->val) != set.end()) {
			ListNode *tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
		} else {
			cur = cur->next;
		}
	}
}

/* no buffer, runner ptr, O(n^2) */
void removeDups2(ListNode *head)
{
	ListNode *cur = head;
	while (cur) {
		ListNode *run = cur;
		while (run->next) {
			if (run->next->val == cur->val) {
				ListNode *tmp = run->next;
				run->next = run->next->next;
				delete tmp;
			} else {
				run = run->next;
			}
		}
		cur = cur->next;
	}
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
	std::vector<int> v1 = { 3, 1, 5, 3, 2, 2, 1, 3, 6, 4, 8, 1 };

	ListNode *l1 = vectorToListNode(v1);
	ListNode *l2 = vectorToListNode(v1);

	printList(l1);
	removeDups1(l1);
	printList(l1);

	printList(l2);
	removeDups2(l2);
	printList(l2);

	deleteList(l1);
	deleteList(l2);

	return 0;
}
