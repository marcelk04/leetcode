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
	int rangeSumBST(TreeNode *root, int low, int high)
	{
		if (root == nullptr)
			return 0;

		int res;

		if (low <= root->val && root->val <= high)
		{
			res = root->val;
		}
		else
		{
			res = 0;
		}

		res += rangeSumBST(root->left, low, high);
		res += rangeSumBST(root->right, low, high);

		return res;
	}
};