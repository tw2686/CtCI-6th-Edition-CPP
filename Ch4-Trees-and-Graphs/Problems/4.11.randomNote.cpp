#include <iostream>
#include <vector>
#include <ctime>

/*
 * Hints:
 * 42, 54, 62, 75, 89, 99, 112, 119
 *
 * Solution:
 * 1. copy all nodes to array, return random element in array O(N)
 * 2. main array at all times of tree, will need to remove nodes from array O(N)
 * 3. label all nodes with index from 1 to N, label them in BST order, can use
 * binary search to find index. insert/delete need to update all indices O(N)
 * 4. depth of tree, pick random depth, traverse left/right randomly until
 * depth. but unequal trees will lead problems
 * 5. traverse randomly down tree 1/3 for each path, not even distribution
 * 6. from 5. probability of each node should be 1/N. keep track of number of
 * nodes at each subtree, store size var in each node.
 * 7. random number calls are expensive, reduce number of random number calls
 *
 * Time Complexity:
 * O(logN) in a balanced tree, or O(D), D is the max depth of tree
 * 
 * Space Complexity:
 * O(1)
 */

/* Definition of a binary tree node */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	int size;
	TreeNode(int x) : val(x), left(NULL), right(NULL), size(1) {}
};

/* binary tree class using option 6 */
class BST
{
	public:
		BST() {}
		BST(int val) { root = new TreeNode(val); }
		~BST() {}

		/* insert */
		void insert(int val) {
			if (!root) root = new TreeNode(val);
			else insert(root, val);
		}
		void insert(std::vector<int> vec) {
			int N = vec.size();
			if (!root) {
				root = new TreeNode(vec[0]);
				for (int i = 1; i < N; ++i)
					if (vec[i]) insert(root, vec[i]);
			} else {
				for (int i = 0; i < N; ++i)
					if (vec[i]) insert(root, vec[i]);
			}
		}
		void insert(TreeNode *node, int val) {
			if (val <= node->val) {
				if (!node->left)
					node->left = new TreeNode(val);
				else
					insert(node->left, val);
			} else {
				if (!node->right)
					node->right = new TreeNode(val);
				else
					insert(node->right, val);
			}
			++node->size;
		}

		/* find */
		TreeNode* find(int val) {
			return find(root, val);
		}

		TreeNode* find(TreeNode *node, int val) {
			if (node->val == val)
				return node;
			else if (val < node->val)
				return find(node->left, val);
			else if (val > node->val)
				return find(node->right, val);
			else {
				std::cout << "Found no such node." << std::endl;
				return NULL;
			}
		}

		/* option 6 */
		TreeNode* getRandomNode6() {
			return getRandomNode6(root);
		}
		TreeNode* getRandomNode6(TreeNode *node) {
			int leftSize = 0;
			if (node->left) leftSize = node->left->size;
			int random = std::rand() % node->size;
			if (random < leftSize)
				return getRandomNode6(node->left);
			else if (random == leftSize)
				return node;
			else
				return getRandomNode6(node->right);
		}

		/* option 7 */
		TreeNode* getRandomNode7() {
			return getRandomNode7(root);
		}
		TreeNode* getRandomNode7(TreeNode *node) {
			int random = std::rand() % node->size;
			return getIthNode(random);
		}

		TreeNode* getIthNode(int i) {
			return getIthNode(root, i);
		}
		TreeNode* getIthNode(TreeNode *node, int i) {
			int leftSize = 0;
			if (node->left) leftSize = node->left->size;
			if (i < leftSize)
				return getIthNode(node->left, i);
			else if (i == leftSize)
				return node;
			else
				return getIthNode(node->right, i-(leftSize+1));
		}

		/* print */
		void printBST() {
			std::cout << "PreOrder: " << std::endl;
			printBST(root);
			std::cout << std::endl;
		}
		void printBST(TreeNode *root) {
			if (root) {
				std::cout << root->val << " ";
				printBST(root->left);
				printBST(root->right);
			}
		}
	
		/* size */
		int size() {
			if (root) return root->size;
			else return -1;
		}

	private:
		TreeNode *root;
};

int main()
{
	srand(time(NULL));
	std::vector<int> v1 = { 20, 10, 30, 5, 15, 0, 0, 3, 7, 17 };

	BST bst1;
	bst1.insert(v1);
	bst1.printBST();
	std::cout << std::endl;

	std::cout << "Option 6: " << std::endl;
	for (int i = 1; i <= 10; ++i) {
		TreeNode *rand = bst1.getRandomNode6();
		std::cout << "Random Node " << i << ": ";
		std::cout << rand->val << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Option 7: " << std::endl;
	for (int i = 1; i <= 10; ++i) {
		TreeNode *rand = bst1.getRandomNode7();
		std::cout << "Random Node " << i << ": ";
		std::cout << rand->val << std::endl;
	}

	return 0;
}
