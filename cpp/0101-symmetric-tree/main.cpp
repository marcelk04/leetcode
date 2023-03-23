/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
	bool isSymmetric(TreeNode *root)
	{
		if (root == nullptr)
			return true;

		return checkSymmetry(root->left, root->right);
	}

	bool checkSymmetry(TreeNode *left, TreeNode *right)
	{
		if (left == nullptr || right == nullptr)
		{
			return left == nullptr && right == nullptr;
		}

		if (left->val != right->val)
			return false;

		return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
	}
};