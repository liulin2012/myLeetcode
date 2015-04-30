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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        vector<int> oneRow;
        while (!q.empty()) {
            if (level == 0) {
                result.push_back(oneRow);
                oneRow.clear();
                level = q.size();
            }
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->left != nullptr) q.push(tmp->left);
            if (tmp->right != nullptr) q.push(tmp->right);
            oneRow.push_back(tmp->val);
            level--;
        }
        result.push_back(oneRow);
        return vector<vector<int> > (result.rbegin(), result.rend());
    }
};