/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        else {
            int a = maxDepth(root->left) + 1;
            int b = maxDepth(root->right) + 1;
            return a > b ? a : b;
        }
    }
};