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
    bool issame(TreeNode *a, TreeNode *b) {
        if (a == nullptr && b == nullptr) return true;
        else if (a != nullptr && b != nullptr) {
            if (a->val != b->val) return false;
            else return issame(a->left, b->right) && issame(a->right, b->left);
        }
        else return false;
    }
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return issame(root->left, root->right);
        
    }
};