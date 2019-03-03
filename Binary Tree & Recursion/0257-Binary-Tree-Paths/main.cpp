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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)
            return res;
        if (!root->left && !root->right)
            res.push_back(to_string(root->val));
        vector<string> LeftPaths = binaryTreePaths(root->left);
        for (auto path : LeftPaths)
            res.push_back(to_string(root->val) + "->" + path);
         vector<string> RightPaths = binaryTreePaths(root->right);
        for (auto path : RightPaths)
            res.push_back(to_string(root->val) + "->" + path);
        return res;
    }
};