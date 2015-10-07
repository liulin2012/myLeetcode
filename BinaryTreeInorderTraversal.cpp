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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Traversal(root, res);
        return res;
    }
    
    void Traversal(TreeNode* root, vector<int> &res) {
        if (root != nullptr) {
            Traversal(root->left, res);
            res.push_back(root->val);
            Traversal(root->right, res);
        }
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root == nullptr) return res;
        
        TreeNode *cur = root;
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        
        while (!st.empty()) {
            res.push_back(st.top()->val);
            cur = st.top()->right;
            st.pop();
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (!st.empty() || cur != nullptr) {
            if (cur == nullptr) {
                res.push_back(st.top()->val);
                cur = st.top()->right;
                st.pop();
            } else {
                st.push(cur);
                cur = cur->left;
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        while(root) {
            if (root->left) {
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root)
                    pre = pre->right;
                if (pre->right != root) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = nullptr;
                    res.push_back(root->val);
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