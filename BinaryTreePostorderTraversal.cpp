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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* dum = new TreeNode(0);
        dum->left = root;
        root = dum;
        while(root) {
            if (root->left) {
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root)
                    pre = pre->right;
                if (pre->right != root) {
                    pre->right = root;
                    root = root->left;
                } else {
                    reverseAddNodes(root->left, pre, res);
                    pre->right = nullptr;
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }
        return res;
    }
    
    void reverseNodes(TreeNode* start, TreeNode* end) {
        if (start == end) return;
        TreeNode* x = start;
        TreeNode* y = start -> right;
        TreeNode* z;
        while (x != end) {
            z = y -> right;
            y -> right = x;
            x = y;
            y = z;
        }
    }
    void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& nodes) {
        reverseNodes(start, end);
        TreeNode* node = end;
        while (true) {
            nodes.push_back(node -> val);
            if (node == start) break;
            node = node -> right;
        }
        reverseNodes(end, start);
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* tmp = nullptr;
                while(!(st.top()->right) || st.top()->right == tmp) {
                    res.push_back(st.top()->val);
                    tmp = st.top();
                    st.pop();
                    if (st.empty()) break;
                }
                if (st.empty()) break;
                cur = st.top()->right;
            }
        }
        return res;
    }
};

//http://www.geeksforgeeks.org/iterative-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while (!st1.empty()) {
            TreeNode* tmp = st1.top();
            st1.pop();
            if (tmp->left) st1.push(tmp->left);
            if (tmp->right) st1.push(tmp->right);
            st2.push(tmp);
        }
        while (!st2.empty()) {
            res.push_back(st2.top()->val);
            st2.pop();
        }
        
        return res;
    }
};

