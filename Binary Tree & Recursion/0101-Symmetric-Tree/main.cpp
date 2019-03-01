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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        right = revert(right);
        return is_identical(left, right);
    }
private:
    TreeNode* revert(TreeNode* root){
        if (!root)
            return root;

        swap(root->left, root->right);
        revert(root->left);
        revert(root->right);
        return root;
    }

    bool is_identical(TreeNode* root1, TreeNode* root2){
        if (!root1 && !root2)
            return true;

        if (!root1 || !root2)
            return false;

        if (root1->val != root2->val)
            return false;
        
        return is_identical(root1->left, root2->left) &&
               is_identical(root1->right, root2->right);
    }
};