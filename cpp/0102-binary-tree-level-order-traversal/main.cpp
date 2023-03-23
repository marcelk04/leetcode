#include <vector>
#include <queue>

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
	std::vector<std::vector<int>> levelOrder(TreeNode *root)
	{
		std::vector<std::vector<int>> res;

		if (root == nullptr)
			return res;

		res.push_back(std::vector<int>({root->val}));
		std::vector<int> currentRes;

		std::queue<TreeNode *> q, nextLevel;
		q.push(root);

		while (!q.empty())
		{
			TreeNode *node = q.front();
			q.pop();

			if (node->left != nullptr)
			{
				currentRes.push_back(node->left->val);
				nextLevel.push(node->left);
			}

			if (node->right != nullptr)
			{
				currentRes.push_back(node->right->val);
				nextLevel.push(node->right);
			}

			if (q.empty())
			{
				q = nextLevel;
				nextLevel = std::queue<TreeNode *>();

				if (!currentRes.empty())
				{
					res.push_back(currentRes);
					currentRes.clear();
				}
			}
		}

		return res;
	}
};