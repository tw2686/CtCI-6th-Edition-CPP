#include <iostream>
#include <vector>

/*
 * hints:
 * 72: picture list 1->5->9->12
 *     remove 9 makes 1->5->12
 *     you only have access to 9
 *
 * ask:
 * 1. problem cannot be solved if the node to be deleted is the last node
 * - mark node as dummy
 *
 * solutions:
 */

/* Definition for singly-linked list */
struct ListNode {
	char val;
	ListNode *next;
	ListNode(char x) : val(x), next(NULL) {}
};

/* copy data, and delete */
bool deleteMid1(ListNode *mid)
{
	if (mid == nullptr || mid->next == nullptr)
		return false;

	ListNode *tmp = mid->next;
	mid->val = tmp->val;
	mid->next = tmp->next;
	delete tmp;

	return true;	
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
ListNode* vectorToListNode(std::vector<char> vec)
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

int main()
{
	std::vector<char> v1 = { 'a', 'b', 'c', 'd', 'e', 'f' };

	ListNode *list1 = vectorToListNode(v1);
	ListNode *mid = list1->next->next;

	printList(list1);
	std::cout << mid->val << std::endl;
	deleteMid1(mid);
	printList(list1);

	return 0;
}
