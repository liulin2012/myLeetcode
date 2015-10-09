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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        while (root) {
            if (root->left) {
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root)
                    pre = pre->right;
                if (pre->right != root) {
                    pre->right = root;
                    root = root->left;
                } else {
                    if (--k == 0) res = root->val;
                    
                    pre->right = nullptr;
                    root = root->right;
                }
            } else {
                if (--k == 0) res = root->val;
                root = root->right;
            }
        }
        return res;
    }
};