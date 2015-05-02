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
    int deepth(TreeNode* a) {
        if (a == nullptr) return 0;
        else {
            int m = deepth(a->left) + 1;
            int n = deepth(a->right) + 1;
            if (m == -4 || abs(m - n) > 1) return -5; 
            else return max(m , n);
        }
    }
    
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) return true;
        else return deepth(root) == -5 ? false : true;
    }
};