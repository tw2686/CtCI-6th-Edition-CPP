#include <iostream>
#include <queue>
#include <vector>

/*
 * Hints:
 * 21, 33, 49, 105, 124
 *
 * Solution:
 * 1. on each node, recur to get left and right heights to check for
 * difference, slow O(N log N) since each node is touched
 * 2. check for height as we recur, if we encouter unbalanced height, return
 * error_code
 *
 * Time Complexity:
 * O(N), touch every node
 * 
 * Space Complexity:
 * O(H), h is the height of the tree
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int checkHeight(TreeNode *root)
{
	if (!root) return 0;

	int left = checkHeight(root->left);
	if (left == -1) return -1;

	int right = checkHeight(root->right);
	if (right == -1) return -1;

	if (std::abs(left-right) > 1)
		return -1;
	else
		return std::max(left, right) + 1;
}

/* check height as recur */
bool checkBalanced1(TreeNode *root)
{
	return checkHeight(root) != -1;
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
			q.push(node->left);
		}
		if (i == vec.size()) break;
		if (vec[++i] != 0) {
			node->right = new TreeNode(vec[i]);
			q.push(node->right);
		}
	}
	return root;
}

int main()
{
	std::vector<int> v1 = { 3, 9, 20, 0, 0, 15, 7 };
	std::vector<int> v2 = { 1, 2, 3, 4, 5, 0, 0, 6, 7, 8 };

	TreeNode *root = vectorToTreeNode(v1);
	TreeNode *root2 = vectorToTreeNode(v2);

	std::cout << "PreOrder Traversal:" << std::endl;
	preOrder(root);
	std::cout << std::endl;
	
	bool isBalanced = checkBalanced1(root);
	std::cout << "Tree is balanced: " << isBalanced << std::endl;

	std::cout << std::endl;

	std::cout << "PreOrder Traversal:" << std::endl;
	preOrder(root2);
	std::cout << std::endl;
	
	bool isBalanced2 = checkBalanced1(root2);
	std::cout << "Tree is balanced: " << isBalanced2 << std::endl;

	return 0;
}
