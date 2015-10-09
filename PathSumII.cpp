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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        DFS(root, sum, res, {});
        return res;
    }
    
    void DFS(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> one){
        if (root->left == nullptr && root->right == nullptr && sum == root->val) {one.push_back(root->val); res.push_back(one);}
        else {
            one.push_back(root->val);
            if (root->left) DFS(root->left, sum - root->val, res, one);
            if (root->right) DFS(root->right, sum - root->val, res, one);
        }
    }
};