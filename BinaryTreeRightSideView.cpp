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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> res;
        if (root == nullptr) return res;
        
        qu.push(root);
        while (!qu.empty()) {
            int num = qu.size();
            for (int i = 0; i < num; i++) {
                TreeNode* tmp = qu.front();
                qu.pop();
                if (tmp->left) qu.push(tmp->left);
                if (tmp->right) qu.push(tmp->right);
                if (i == num - 1) res.push_back(tmp->val);
            }
        }
        
        return res;
    }
};