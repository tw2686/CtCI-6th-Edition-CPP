#include <iostream>
#include <vector>

/*
 * hints:
 * 5, 13, 29, 61, 101
 *
 * ask:
 *
 * solutions:
 * 1. reverse list then compare
 * 2. use stack, and slow/fast to find mid
 * 3. recursion
 * 4. reverse first half of list then compare
 */

/* Definition for singly-linked list */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* helper function that reverses linked list */
ListNode* reverseList(ListNode *head)
{
	ListNode *pre = nullptr;
	ListNode *cur = head;
	ListNode *nxt;
	
	while (cur) {
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	return pre;
}

/* reverse second half */
bool palindrome1(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;
	ListNode *cur = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast) slow = slow->next;

	// reverse second half of string
	ListNode *rev = reverseList(slow);

	while (rev) {
		if (rev->val != cur->val)
			return false;
		rev = rev->next;
		cur = cur->next;
	}
	return true;
}

/* reverse first half while finding middle */
bool palindrome2(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;
	ListNode *rev = nullptr;
	ListNode *tmp;

	while (fast && fast->next) {
		fast = fast->next->next;
		
		tmp = rev;
		rev = slow;
		slow = slow->next;
		rev->next = tmp;
	}
	if (fast) slow = slow->next;

	while (rev) {
		if (rev->val != slow->val)
			return false;
		rev = rev->next;
		slow = slow->next;
	}
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
	std::cout << palindrome2(l1) << std::endl;

	deleteList(l1);

	return 0;
}
