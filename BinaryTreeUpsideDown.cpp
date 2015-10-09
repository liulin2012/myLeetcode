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
    TreeNode* res;
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr) return root;
        helper(root);
        return res;
    }
    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) { res = root ; return root;}
        else {
            TreeNode* tmp = helper(root->left);
            tmp->right = root;
            tmp->left = root->right;
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
    }
    
};