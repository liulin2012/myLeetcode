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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while(root) {
            if (root->left) {
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root)
                    pre = pre->right;
                if (pre->right != root) {
                    pre->right = root;
                    res.push_back(root->val);
                    root = root->left;
                } else {
                    pre->right = nullptr;
                    root = root->right;
                }
            } else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};


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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur) {
            if (cur) {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top()->right;
                st.pop();
            }
        }
        return res;
    }
};