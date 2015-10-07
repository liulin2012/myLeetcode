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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* pre = nullptr;
        while(1) {
            if (root->val < p->val) {
                root = root->right;
            } else if (root->val > p->val) {
                pre = root;
                root = root->left;
            } else {
                if (root->right) {
                    root = root->right;
                    while (root->left) root = root->left;
                    return root;
                }
                else return pre;
            }
        }
    }
};