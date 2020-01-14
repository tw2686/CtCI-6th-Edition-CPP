#include <iostream>
#include <vector>

/*
 * hints:
 * 20, 45, 55, 65, 76, 93, 111, 120, 129
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

/* swap list pointers until we reach intersection */
ListNode* intersection(ListNode *l1, ListNode *l2)
{
	ListNode *p1 = l1;
	ListNode *p2 = l2;
	
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
		if (!p1) p1 = l2;
		if (!p2) p2 = l1;
	}	

	return p1;
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
	std::vector<int> v2 = { 6, 7, 8 };
	ListNode *l1 = vectorToListNode(v1);
	ListNode *l2 = vectorToListNode(v2);

	ListNode *l1mid = l1->next->next;
	ListNode *l2end = l2->next;
	l2end->next = l1mid;

	printList(l1);
	printList(l2);
	ListNode *res = intersection(l1, l2);
	std::cout << "Intersection:" << std::endl;
	printList(res);

	l2end->next = nullptr;

	deleteList(l1);
	deleteList(l2);

	return 0;
}
