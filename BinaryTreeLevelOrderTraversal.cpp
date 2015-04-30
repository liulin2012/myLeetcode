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
    
    vector<vector<int>> ret;

    void buildVector(TreeNode *root, int depth)
    {
        if(root == NULL) return;
        if(ret.size() == depth)
            ret.push_back(vector<int>());
    
        ret[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }
    
    vector<vector<int> > levelOrder(TreeNode *root) {
        buildVector(root, 0);
        return ret;
    }
};

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
    vector<vector<int> > levelOrder(TreeNode *root) {
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
        return result;
    }
};