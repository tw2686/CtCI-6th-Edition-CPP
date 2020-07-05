/*
 * Problem:
 * Takes a pointer to a node struct as parameter and returns a complete copy
 * of the passed in data structure
 * The Node data structure contains two pointers to other Nodes
 *
 * hints:
 * 427, 462
 *
 * solution:
 */

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node
{
	int val;
	Node *p1;
	Node *p2;
	Node(int x) : val(x), p1(NULL), p2(NULL) {}
};

typedef unordered_map<Node *, Node *> NodeMap;

Node* copyRecur(Node *cur, NodeMap &map)
{
	if (!cur) return NULL;

	if (map.find(cur) != map.end())
		return map[cur];

	Node *copy = new Node(cur->val);
	
	copy->p1 = copyRecur(cur->p1, map);
	copy->p2 = copyRecur(cur->p2, map);
	map[cur] = copy;

	return copy;
}

Node* copyNode(Node *root)
{
	NodeMap map;

	return copyRecur(root, map);
}

void printNodes(Node *root)
{
	queue<Node *> q;

	q.push(root);

	while (!q.empty()) {
		Node *n = q.front(); q.pop();
		cout << n->val << " ";

		if (n->p1) q.push(n->p1);
		if (n->p2) q.push(n->p2);
	}

	cout << '\n';
}

int main()
{
	Node *node = new Node(0);

	node->p1 = new Node(1);
	node->p2 = new Node(2);
	node->p1->p1 = new Node(3);
	node->p1->p2 = new Node(4);
	node->p2->p1 = new Node(5);

	printNodes(node);

	Node *copy = copyNode(node);

	printNodes(copy);

	return 0;
}
