#include <iostream>
#include <queue>
#include <vector>
#include <list>

/*
 * Hints:
 * 39, 48, 66, 82
 *
 * Solution:
 * find all permutations by recursively weaving left and right children
 * together but keeping the parent/root in front
 *
 * Time Complexity:
 * 
 * Space Complexity:
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* helper function to weave and find all permutations */
void weaveSeqs(std::vector<std::list<int>>& weaves,
	       std::list<int>& prefix,
	       std::list<int>& left,
	       std::list<int>& right)
{
	/* if left or right is empty, add the other to prefix to form permutation */
	if (left.size() == 0 || right.size() == 0) {
		std::list<int> res = prefix;
		res.insert(res.end(), left.begin(), left.end());
		res.insert(res.end(), right.begin(), right.end());
		weaves.push_back(res);
		return;
	}

	/* remove head from left and add to end of prefix */
	int headLeft = left.front();
	left.pop_front();
	prefix.push_back(headLeft);
	weaveSeqs(weaves, prefix, left, right);
	prefix.pop_back();
	left.push_front(headLeft);

	/* remove head from right and add to end of prefix */
	int headRight = right.front();
	right.pop_front();
	prefix.push_back(headRight);
	weaveSeqs(weaves, prefix, left, right);
	prefix.pop_back();
	right.push_front(headRight);
}

std::vector<std::list<int>> bstSequences(TreeNode *root)
{
	std::vector<std::list<int>> res;

	if (root == nullptr) {
		res.push_back(std::list<int>());
		return res;
	}

	std::list<int> prefix;
	prefix.push_back(root->val);

	/* recur on left and right subtrees */
	std::vector<std::list<int>> leftSeq = bstSequences(root->left);
	std::vector<std::list<int>> rightSeq = bstSequences(root->right);

	/* weave together left and right permutations */
	for (std::list<int>& left : leftSeq) {
		for (std::list<int>& right: rightSeq) {
			std::vector<std::list<int>> weaves;
			weaveSeqs(weaves, prefix, left, right);
			res.insert(res.end(), weaves.begin(), weaves.end());
		}
	}
	return res;
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
	std::vector<int> v1 = { 2, 1, 3 };

	TreeNode *root = vectorToTreeNode(v1);

	std::cout << "PreOrder Traversal:" << std::endl;
	preOrder(root);
	std::cout << std::endl;

	std::cout << "BST Sequences: " << std::endl;
	std::vector<std::list<int>> seqs = bstSequences(root);
	for (auto& seq : seqs) {
		for (auto& n : seq)
			std::cout << n << ", ";
		std::cout << std::endl;
	}

	return 0;
}
