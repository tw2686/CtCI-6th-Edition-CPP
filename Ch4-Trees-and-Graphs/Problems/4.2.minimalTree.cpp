#include <iostream>`
#include <vector>

/*
 * Hints:
 * 19, 73, 116
 *
 * Solution:
 * Use binary search recursively
 *
 * Time Complexity:
 * O(N), add root for every element
 * 
 * Space Complexity:
 * O(N), recursion call stack 
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int main()
{
	std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	TreeNode *root = minimalTree(v1);

	preOrder(root);

	return 0;
}
