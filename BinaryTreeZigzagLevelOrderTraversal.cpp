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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        stack<TreeNode*> st;
        stack<TreeNode*> sttmp;
        bool right = false;
        int count = 1;
        int nextCount = 0;
        st.push(root);
        vector<int> one;
        
        while (!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();
            one.push_back(tmp->val);
            if (right) {
                if (tmp->right) { sttmp.push(tmp->right); nextCount++;}
                if (tmp->left) { sttmp.push(tmp->left); nextCount++;}
            } else {
                if (tmp->left) { sttmp.push(tmp->left); nextCount++;}
                if (tmp->right) { sttmp.push(tmp->right); nextCount++;}
            }
            count--;
            if (count == 0) {
                res.push_back(one);
                one.clear();
                count = nextCount;
                nextCount = 0;
                right = !right;
                swap(st, sttmp);
            }
        }
    
        return res;
        
    }
};