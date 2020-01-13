#include <iostream>
#include <vector>

/*
 * hints:
 * 7, 30, 71, 95, 109
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

/* sums reverse linked lists */
ListNode* sumListsRev(ListNode *l1, ListNode *l2)
{
	ListNode *c1 = l1;
	ListNode *c2 = l2;
	ListNode *res = nullptr;
	ListNode *rhead = res;
	int v, ones;
	int carry = 0;

	while (c1 || c2) {
		v = carry;
		if (c1) {
			v += c1->val;
			c1 = c1->next;
		}
		if (c2) {
			v += c2->val;
			c2 = c2->next;
		}
		ones = v % 10;
		if (res == nullptr) {
			res = new ListNode(ones);
			rhead = res;
		} else {
			res->next = new ListNode(ones);
			res = res->next;
		}
		carry = v / 10;
	}
	if (carry == 1)
		res->next = new ListNode(carry);
	
	return rhead;
}

/* helper function that finds length of linked list */
int getLength(ListNode *head)
{
	int len = 0;
	while (head) {
		++len;
		head = head->next;
	}
	return len;
}

/* helper function that pads beginning of list with zeroes */
ListNode* padList(ListNode *head, int pad)
{
	for (int i = 0; i < pad; ++i) {
		ListNode *zero = new ListNode(0);
		zero->next = head;
		head = zero;
	}
	return head;
}

/* helper function to insert element before list */
ListNode* insertBefore(ListNode *head, int n)
{
	ListNode *node = new ListNode(n);
	node->next = head;
	head = node;
	return head;
}

/* recursive function that adds two lists */
ListNode* addListsHelper(ListNode *l1, ListNode *l2, int &carry)
{
	if (l1 == nullptr && l2 == nullptr && carry == 0)
		return nullptr;

	ListNode *res = addListsHelper(l1 ? l1->next : nullptr,
				       l2 ? l2->next : nullptr,
				       carry);

	int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
	res = insertBefore(res, val % 10);
	carry = val / 10;
	return res;
}

ListNode* sumListsFor(ListNode *l1, ListNode *l2)
{
	int len1 = getLength(l1);
	int len2 = getLength(l2);

	if (len1 < len2) {
		l1 = padList(l1, len2 - len1);
	} else {
		l2 = padList(l2, len1 - len2);
	}
	
	int carry = 0;
	ListNode *l3 = addListsHelper(l1, l2, carry);

	if (carry != 0) {
		return insertBefore(l3, carry);
	} else {
		return l3;
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
	// reverse order
	std::vector<int> v1 = { 7, 1, 6 };
	std::vector<int> v2 = { 5, 9, 2 };

	ListNode *l1 = vectorToListNode(v1);
	ListNode *l2 = vectorToListNode(v2);

	std::cout << "Reverse: 617 + 295 = 912" << std::endl;
	printList(l1);
	printList(l2);
	ListNode *res1 = sumListsRev(l1, l2);
	printList(res1);

	// forward order
	v1 = { 6, 1, 7 };
	v2 = { 2, 9, 5 };

	ListNode *l3 = vectorToListNode(v1);
	ListNode *l4 = vectorToListNode(v2);

	std::cout << "Forward: 617 + 295 = 912" << std::endl;
	printList(l3);
	printList(l4);
	ListNode *res2 = sumListsFor(l3, l4);
	printList(res2);

	// test unequal length numbers
	v1 = { 1, 2, 3, 4 };
	v2 = { 5, 6, 7 };

	ListNode *l5 = vectorToListNode(v1);
	ListNode *l6 = vectorToListNode(v2);

	std::cout << "Forward: 1234 + 567 = 1801" << std::endl;
	printList(l5);
	printList(l6);
	ListNode *res3 = sumListsFor(l5, l6);
	printList(res3);

	// free memory
	deleteList(l1);
	deleteList(l2);
	deleteList(l3);
	deleteList(l4);
	deleteList(l5);
	deleteList(l6);
	deleteList(res1);
	deleteList(res2);
	deleteList(res3);

	return 0;
}
