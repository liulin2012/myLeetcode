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
    int res = INT32_MIN;
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        DFS(root);
        return res;
    }
    
    int DFS(TreeNode* root) {
        if (root == nullptr) return 0;
        else {
            int left = DFS(root->left);
            int right = DFS(root->right);
            
            int sum = left + right + root->val;
            left += root->val;
            right += root->val;
            
            res = max(res, sum);
            res = max(res, left);
            res = max(res, right);
            res = max(res, root->val);
            
            return left > right ? (left > root->val ? left : root->val) : (right > root->val ? right : root->val);
        }
    }
};