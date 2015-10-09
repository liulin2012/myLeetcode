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
    int closestValue(TreeNode* root, double target) {
        int left = INT32_MAX;
        int right = INT32_MIN;
        while(root) {
            if (root->val > target) {
                right = root->val;
                root = root->left;
            } else {
                left = root->val;
                root = root->right;
            }
        }
        if (left == INT32_MAX) return right;
        else if (right == INT32_MIN) return left;
        else {
            return (target - left) < (right - target) ? left : right;
        }
        
    }
};