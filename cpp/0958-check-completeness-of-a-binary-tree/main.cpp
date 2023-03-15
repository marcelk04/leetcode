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
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);

        bool end = false;

        while (!q.empty()) {
            auto n = q.front();
            q.pop();

            if (n->left != nullptr) {
                if (end) return false;

                q.push(n->left);
            } else {
                end = true;
            }

            if (n->right != nullptr) {
                if (end) return false;

                q.push(n->right);
            } else {
                end = true;
            }
        }

        return true;
    }
};