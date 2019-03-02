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
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;

        return findPath(root, sum)
                + pathSum(root->left , sum)
                + pathSum(root->right , sum);
    }

private:
    int findPath(TreeNode* node, int num){
        if (!node)
            return 0;

        int res = 0;
        if (node->val == num)
            res += 1;

        res += findPath(node->left , num - node->val);
        res += findPath(node->right , num - node->val);

        return res;
    }
};