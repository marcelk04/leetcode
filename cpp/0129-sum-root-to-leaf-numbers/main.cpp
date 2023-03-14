#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root, int parentVal) {
		if (root->left == nullptr && root->right == nullptr) return parentVal * 10 + root->val;

		int res = 0;

		if (root->left != nullptr)
			res += sumNumbers(root->left, root->val + parentVal * 10);

		if (root->right != nullptr)
			res += sumNumbers(root->right, root->val + parentVal * 10);

		return res;
	}

	int sumNumbers(TreeNode* root) {
		return sumNumbers(root, 0);
	}
};

int main() {
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* tree1 = new TreeNode(1, node1, node2);

	TreeNode* node3 = new TreeNode(5);
	TreeNode* node4 = new TreeNode(1);
	TreeNode* node5 = new TreeNode(9, node3, node4);
	TreeNode* node6 = new TreeNode(0);
	TreeNode* tree2 = new TreeNode(4, node5, node6);

	Solution s;

	std::cout << s.sumNumbers(tree1) << '\n';
	std::cout << s.sumNumbers(tree2) << '\n';

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;
	delete tree1;
	delete tree2;
}