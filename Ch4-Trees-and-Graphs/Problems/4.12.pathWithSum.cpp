#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

/*
 * Hints:
 * 6, 14, 52, 68, 77, 87, 94, 103, 108, 115
 *
 * Solution:
 * 1. for each node, recursive down all paths downwards and check against sum.
 * Will be O(NlogN) with a lot of repeated calculations
 * 2. Use Hash Table to cache previous accumulated sums, simialr to subarray
 * sum problem, but we need to decrement values after we move onto different
 * branch
 *
 * Time Complexity:
 * O(N), N is the number of nodes
 * 
 * Space Complexity:
 * Space is O(logN) due to hash table, can grow to O(N) in an unbalanced tree
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* helper function do traverse tree in inorder fashion */
void findPaths(TreeNode *root, int target,
	       std::unordered_map<int, int>& map,
	       int& count, int accum)
{
	if (root) {
		accum += root->val;
		int diff = accum - target;

		count += map.count(diff) ? map[diff] : 0;
		++map[accum];

		findPaths(root->left, target, map, count, accum);
		findPaths(root->right, target, map, count, accum);

		/* remove pathsums when we move to different branch */
		--map[accum];
	}
}

/* use hash table to keep track of accumulated paths */
int pathSums1(TreeNode *root, int target)
{
	int count = 0;
	std::unordered_map<int, int> map;
	map[0] = 1;

	findPaths(root, target, map, count, 0);

	return count;
}

/* helper function to print tree (preorder) */
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
	std::vector<int> v1 = { 10, 5, -3, 3, 2, 0, 11, 3, -2, 0, 1 };

	TreeNode *r1 = vectorToTreeNode(v1);

	std::cout << "PreOrder Traversal:" << std::endl;
	preOrder(r1);
	std::cout << std::endl;
	
	int target = 8;
	int paths1 = pathSums1(r1, target);
	std::cout << "Number of Paths that Sum to ";
	std::cout << target << " is " << paths1 << std::endl;

	return 0;
}
