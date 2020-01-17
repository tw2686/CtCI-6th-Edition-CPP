#include <iostream>
#include <queue>
#include <vector>

/*
 * Hints:
 * 10, 16, 28, 36, 46, 70, 80, 96
 *
 * Solution:
 * 1. with parent links, intersection prob, walkup and check subtrees until we
 * found both nodes
 * 2. without parent links, need to recursively check subtrees, optimization
 * is tricky, if nodes lies on different side of current node, then we have
 * common ancestor
 *
 * Time Complexity:
 * O(D), d is the depth of the node
 * 
 * Space Complexity:
 * O(1)
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* parent link, scan tree twice, switch */
TreeNode* commonAncestor1(TreeNode *n1, TreeNode *n2)
{
	TreeNode *p1 = n1;
	TreeNode *p2 = n2;

	while (p1->parent != p2->parent) {
		p1 = p1->parent;
		p2 = p2->parent;
		if (!p1) p1 = n2;
		if (!p2) p2 = n1;
	}
	return p1->parent;
}

/* helper function that checks whether n1 includes n2 */
bool includes(TreeNode *n1, TreeNode *n2)
{
	if (!n1) return false;
	if (n1 == n2) return true;
	return includes(n1->left, n2) || includes(n1->right, n2);
}

/* helper function that returns sibling of node n */
TreeNode* getSibling(TreeNode *n)
{
	if (!n || !n->parent) return nullptr;
	TreeNode *par = n->parent;
	return par->left == n ? par->right : par->left;
}

/* parent link, uncover subtrees as we go up */
TreeNode* commonAncestor2(TreeNode *p, TreeNode *q)
{
	/* check if p includes q */
	if (includes(p, q)) return p;
	/* check if q includes p */
	if (includes(q, p)) return q;

	/* go up until we find a node that includes q */
	TreeNode *sib = getSibling(p);
	TreeNode *par = p->parent;
	while (!includes(sib, q)) {
		sib = getSibling(par);
		par = par->parent;
	}
	return par;
}

/* helper function to print tree (inorder) */
void preOrder(TreeNode *root)
{
	if (root) {
		std::cout << root->val << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* helper function to convert vector to bst */
TreeNode* vectorToTreeNode(std::vector<int> vec)
{
	if (!vec.size()) return nullptr;

	TreeNode *root = new TreeNode(vec[0]);
	std::queue<TreeNode *> q;
	q.push(root);
	int i = 0;
	while (1) {
		TreeNode *node = q.front(); q.pop();
		if (i == vec.size()) break;
		if (vec[++i] != 0) {
			node->left = new TreeNode(vec[i]);
			node->left->parent = node;
			q.push(node->left);
		}
		if (i == vec.size()) break;
		if (vec[++i] != 0) {
			node->right = new TreeNode(vec[i]);
			node->right->parent = node;
			q.push(node->right);
		}
	}
	return root;
}

int main()
{
	std::vector<int> v1 = { 1, 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 10 };

	TreeNode *root = vectorToTreeNode(v1);

	std::cout << "PreOrder Traversal:" << std::endl;
	preOrder(root);
	std::cout << std::endl;

	TreeNode *n1 = root->left->left->left->right;	// 10
	TreeNode *n2 = root->left->right->right;	// 9

	std::cout << "Common Ancestor between " << n1->val;
	std::cout << " and " << n2->val << " is" << std::endl;
	TreeNode *a1 = commonAncestor1(n1, n2);
	std::cout << a1->val << std::endl;
	TreeNode *a2 = commonAncestor2(n1, n2);
	std::cout << a2->val << std::endl;
	

	return 0;
}
