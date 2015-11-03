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
    int longestConsecutive(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(helper(root->left, 1, root->val), helper(root->right, 1, root->val));
    }
    
    int helper(TreeNode* root, int num, int parentVal) {
        if (root == nullptr) return num;
        int tmp;
        if (root->val == parentVal+1) { num++; tmp = num; }
        else {tmp = num; num = 1;}
        return max(tmp, max(helper(root->left, num, root->val), helper(root->right, num, root->val)));
    }
};