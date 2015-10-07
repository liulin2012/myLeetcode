http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

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
    bool isValidBST(TreeNode* root) {
        return isBST(root, INT64_MIN, INT64_MAX);
    }
    
    bool isBST(TreeNode* root, int64_t min, int64_t max) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        else return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
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
    bool isValidBST(TreeNode* root) {
        int64_t num = INT64_MIN;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (!st.empty() || cur != nullptr) {
            if (cur == nullptr) {
                if (st.top()->val <= num) return false;
                else num = st.top()->val;
                cur = st.top()->right;
                st.pop();
            } else {
                st.push(cur);
                cur = cur->left;
            }
        }
        return true;
    }
};