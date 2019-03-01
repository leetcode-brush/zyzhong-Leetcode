/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (root->left == nullptr || root->right == nullptr) {
            if (root->left)
                return minDepth(root->left);
            if (root->right)
                return minDepth(root->right);
        }
        return 1 + min(minDepth(root->left),  minDepth(root->right));
    }
};