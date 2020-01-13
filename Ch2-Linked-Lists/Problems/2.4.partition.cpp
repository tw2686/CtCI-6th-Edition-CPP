#include <iostream>
#include <vector>

/*
 * hints:
 * 3, 24
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

/* two new lists for less/greater elements */
ListNode* partition1(ListNode *head, int x)
{
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(0);
	ListNode *l1head = l1;
	ListNode *l2head = l2;
	ListNode *cur = head;

	while (cur) {
		if (cur->val < x) {
			l1->next = cur;
			l1 = l1->next;
		} else {
			l2->next = cur;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	l2->next = nullptr;
	ListNode *l1start = l1head->next;
	ListNode *l2start = l2head->next;
	l1->next = l2start;
	delete l1head;
	delete l2head;

	return l1start;
}

/* move smaller to left */
ListNode* partition2(ListNode *node, int x)
{
	ListNode *head = node;
	ListNode *tail = node;

	while (node) {
		ListNode *tmp = node->next;
		if (node->val < x) {
			node->next = head;
			head = node;
		} else {
			tail->next = node;
			tail = node;
		}
		node = tmp;
	}
	tail->next = nullptr;
	return head;
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
	std::vector<int> v1 = { 3, 5, 8, 5, 10, 2, 1 };

	ListNode *list1 = vectorToListNode(v1);

	std::cout << "Link two lists:" << std::endl;
	printList(list1);
	ListNode *pList1 = partition1(list1, 5);
	printList(pList1);
	std::cout << "Move smaller to left:" << std::endl;
	printList(list1);
	ListNode *pList2 = partition2(list1, 5);
	printList(pList2);

	deleteList(list1);

	return 0;
}
