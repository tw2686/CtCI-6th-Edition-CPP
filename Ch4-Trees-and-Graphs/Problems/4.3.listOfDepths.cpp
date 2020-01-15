#include <iostream>
#include <vector>
#include <list>

/*
 * Hints:
 * 107, 123, 135
 *
 * Solution:
 * 1. DFS recursion: order of traversal does not matter as long as you keep
 * track of the depth
 * 2. BFS iterative: use linked list as queue to keep track of each depth
 *
 * Time Complexity:
 * O(N), traverse each node
 * 
 * Space Complexity:
 * O(N), store all nodes in vector of linked lists
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* BFS iterative */
std::vector<std::list<TreeNode *>> listOfDepthsBFS(TreeNode *root)
{
	std::vector<std::list<TreeNode *>> res;
	std::list<TreeNode *> curDepth;

	if (root)
		curDepth.push_back(root);

	while (!curDepth.empty()) {
		res.push_back(curDepth);

		std::list<TreeNode *> newDepth;
		for (TreeNode *node : curDepth) {
			if (node->left)
				newDepth.push_back(node->left);
			if (node->right)
				newDepth.push_back(node->right);
		}
		curDepth = newDepth;
	}
	
	return res;
}

/* helper function to do dfs */
void dfs(TreeNode *root, std::vector<std::list<TreeNode *>> &res, int level)
{
	if (root == nullptr)
		return;
	if (res.size() == level) {
		std::list<TreeNode *> newDepth;
		newDepth.push_back(root);
		res.push_back(newDepth);
	} else {
		res[level].push_back(root);
	}
	dfs(root->left, res, level+1);
	dfs(root->right, res, level+1);
}

/* DFS recursion */
std::vector<std::list<TreeNode *>> listOfDepthsDFS(TreeNode *root)
{
	std::vector<std::list<TreeNode *>> res;
	dfs(root, res, 0);
	return res;
}

/* use binary search to get mid */
TreeNode* buildMinTree(std::vector<int> arr, int i, int j)
{
	if (i > j) return nullptr;

	int mid = (i + j) / 2;

	TreeNode *n = new TreeNode(arr[mid]);
	n->left = buildMinTree(arr, i, mid-1);
	n->right = buildMinTree(arr, mid+1, j);
	return n;
}

/* recursion */
TreeNode* minimalTree(std::vector<int> arr)
{
	return buildMinTree(arr, 0, arr.size()-1);	
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

/* helper function to print linked list */
void printList(std::list<TreeNode *> const &l1)
{
	for (auto it = l1.cbegin(); it != l1.cend(); ++it)
		std::cout << (*it)->val << "->";
	std::cout << "nullptr" << std::endl;
}

int main()
{
	std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7 };

	TreeNode *root = minimalTree(v1);

	std::cout << "PreOrder Traversal:" << std::endl;
	preOrder(root);
	std::cout << std::endl;

	std::cout << "List of Depths(BFS):" << std::endl;
	std::vector<std::list<TreeNode *>> resBFS = listOfDepthsBFS(root);
	for (int i = 0; i < resBFS.size(); ++i)
		printList(resBFS[i]);

	std::cout << "List of Depths(DFS):" << std::endl;
	std::vector<std::list<TreeNode *>> resDFS = listOfDepthsDFS(root);
	for (int i = 0; i < resDFS.size(); ++i)
		printList(resDFS[i]);

	return 0;
}
