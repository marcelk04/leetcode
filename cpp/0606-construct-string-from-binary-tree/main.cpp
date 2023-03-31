#include <string>

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
	std::string tree2str(TreeNode *root)
	{
		std::string res = std::to_string(root->val);

		if (root->left != nullptr)
		{
			res = res + "(" + tree2str(root->left) + ")";
		}
		else if (root->right != nullptr)
		{
			res += "()";
		}

		if (root->right != nullptr)
		{
			res = res + "(" + tree2str(root->right) + ")";
		}

		return res;
	}
};