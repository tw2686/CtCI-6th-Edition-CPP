#include <iostream>
#include <queue>
#include <vector>
#include <list>

/*
 * Hints:
 * 4, 11, 18, 31, 37
 *
 * Solution:
 * 1. compare substrings, inorder cannot work because both will always print
 * in order, even if they have different structure
 * preorder works as long as you represent NULL with some other variable
 * 2. preorder traverse t1, if matching, preorder traverse that node with t2
 * and check if subtree matches, else continue traverse until we finish t1
 *
 * Time Complexity:
 * O(n + km), k is the number of occurences of T2 in T1, n is number of nodes
 * in T1 and m is number of nodes in T2
 * 
 * Space Complexity:
 * O(n + m) on call stack
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* helper function to traverse pre order and check for matching trees */
bool match(TreeNode *r1, TreeNode *r2)
{
	if (!r1 && !r2) return true;		// nothing left
	if (!r1 || !r2) return false;		// one is empty
	if (r1->val != r2->val) return false;	// values don't match
	return match(r1->left, r2->left) && match(r1->right, r2->right);
}

/* recursive preorder traversal to go through all nodes of r1 */
bool subtreeRecur(TreeNode *r1, TreeNode *r2)
{
	if (!r1) return false;			// finish traversing r1
	else if (r1->val == r2->val && match(r1, r2)) return true;
	else return subtreeRecur(r1->left, r2) || subtreeRecur(r1->right, r2);
}

/* bfs iterative to go through all nodes in r1 */
bool subtreeBFS(TreeNode *r1, TreeNode *r2)
{
	std::queue<TreeNode *> q;
	q.push(r1);
	while (!q.empty()) {
		TreeNode *cur = q.front(); q.pop();
		if (cur->val == r2->val)
			if (match(cur, r2)) return true;
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
	return false;
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
	std::vector<int> v1 = { 3, 4, 0 };
	std::vector<int> v2 = { 3, 0, 4 };

	TreeNode *r1 = vectorToTreeNode(v1);
	TreeNode *r2 = vectorToTreeNode(v2);

	std::cout << "PreOrder Traversal:" << std::endl;
	preOrder(r1);
	std::cout << std::endl;
	preOrder(r2);
	std::cout << std::endl;

	std::cout << "Check Subtree: " << std::endl;
	std::cout << "Recur:\t" << subtreeRecur(r1, r2) << std::endl;
	std::cout << "BFS:\t" << subtreeBFS(r1, r2) << std::endl;

	return 0;
}
