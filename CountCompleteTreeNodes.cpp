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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = 0;
        int right = 0;
        TreeNode* tmp = root;
        while (tmp) { right++; tmp = tmp->right; }
        tmp = root;
        while (tmp) { left++; tmp = tmp->left;}
        if (right == left) return pow(2, right) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};