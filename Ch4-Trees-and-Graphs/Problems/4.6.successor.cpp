#include <iostream>
#include <queue>
#include <vector>

/*
 * Hints:
 * 79, 91
 *
 * Solution:
 * - if there is right child, return left most child of right subtree
 * - else go up parents until we end up at the left side of a subtree
 *
 * Time Complexity:
 * O(log(N)). In worst case, we traverse parents up to root
 * 
 * Space Complexity:
 * O(1) not storing anything
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

/* helper function to find leftmost child of node */
TreeNode* leftMostChild(TreeNode *node)
{
	if (!node) return nullptr;
	while (node->left)
		node = node->left;
	return node;
}

/* in order successor */
TreeNode* successor(TreeNode *root)
{
	if (!root) return nullptr;
	
	if (root->right) {
		return leftMostChild(root->right);
	} else {
		TreeNode *cur = root;
		TreeNode *par = root->parent;
		// go up until on left
		while (cur && par->left != cur) {
			cur = par;
			par = par->parent;
		}
		return par;
	}
}

/* helper function to print tree (inorder) */
void InOrder(TreeNode *root)
{
	if (root) {
		InOrder(root->left);
		std::cout << root->val << " ";
		InOrder(root->right);
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
	std::vector<int> v1 = { 8, 4, 10, 2, 12, 0, 20 };

	TreeNode *root = vectorToTreeNode(v1);

	std::cout << "InOrder Traversal:" << std::endl;
	InOrder(root);
	std::cout << std::endl;

	TreeNode *nextNode = leftMostChild(root);
	for (int i = 0; i < v1.size()-2; ++i) {
		std::cout << nextNode->val << "-->" << successor(nextNode)->val << std::endl;
		nextNode = successor(nextNode);
	}

	return 0;
}
