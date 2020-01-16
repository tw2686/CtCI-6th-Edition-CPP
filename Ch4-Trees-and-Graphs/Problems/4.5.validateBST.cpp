#include <iostream>
#include <queue>
#include <vector>

/*
 * Hints:
 * 21, 33, 49, 105, 124
 *
 * Solution:
 * 1. inorder traversal
 * use array, or previous to keep track
 * 2. min/max
 * pass min/max values as range limiters
 * branch left, max gets updated
 * branch right, min gets updated
 *
 * Time Complexity:
 * O(N), check every node
 * 
 * Space Complexity:
 * O(H) = O(logN)
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* return boolean using recursion */
bool checkBSTBool(TreeNode *root, int &prev)
{
	if (!root) return true;
	if (!checkBSTBool(root->left, prev)) return false;
	if (prev != 0 && root->val <= prev) return false;
	prev = root->val;
	if (!checkBSTBool(root->right, prev)) return false;
	return true;
}

/* min max */
bool minMax(TreeNode *root, int &min, int &max)
{
	if (!root) return true;
	if ((min && root->val <= min) || (max && root->val > max))
		return false;
	if (!minMax(root->left, min, root->val) || !minMax(root->right, root->val, max))
		return false;
	return true;
}

/* min max check bst */
bool checkBSTMinMax(TreeNode *root)
{
	int min = 0, max = 0;
	return minMax(root, min, max);
}

/* check if cur val is greater than prev value inorder search */
int checkValid(TreeNode *root, int &prev)
{
	if (root) {
		checkValid(root->left, prev);
		if (prev != -1) {
			if (root->val > prev)
				prev = root->val;
			else
				prev = -1;
		}
		checkValid(root->right, prev);
	}
	return prev;	
}

bool checkBSTInt(TreeNode *root)
{
	int prev = 0;
	return checkValid(root, prev) != -1;
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
	std::vector<int> v1 = { 8, 4, 10, 2, 12, 0, 20 };
	std::vector<int> v2 = { 8, 4, 10, 2, 6, 0, 20 };

	TreeNode *root = vectorToTreeNode(v1);
	TreeNode *root2 = vectorToTreeNode(v2);

	std::cout << "PreOrder Traversal:" << std::endl;
	preOrder(root);
	std::cout << std::endl;
	
	int prev = 0;
	std::cout << "BT is a valid BST: " << checkBSTBool(root, prev) << std::endl;
	std::cout << "BT is a valid BST: " << checkBSTMinMax(root) << std::endl;
	std::cout << "BT is a valid BST: " << checkBSTInt(root) << std::endl;

	std::cout << std::endl;

	std::cout << "PreOrder Traversal:" << std::endl;
	preOrder(root2);
	std::cout << std::endl;
	
	prev = 0;
	std::cout << "BT is a valid BST: " << checkBSTBool(root2, prev) << std::endl;
	std::cout << "BT is a valid BST: " << checkBSTMinMax(root2) << std::endl;
	std::cout << "BT is a valid BST: " << checkBSTInt(root2) << std::endl;

	return 0;
}
