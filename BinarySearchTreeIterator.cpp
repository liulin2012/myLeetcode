/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
        if (root != nullptr) {
            st.push(root);
            while (root->left) {
                st.push(root->left);
                root = root->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = st.top();
        st.pop();
        int res = tmp->val;
        if (tmp->right) {
            st.push(tmp->right);
            tmp = tmp->right;
            while (tmp->left) {
                st.push(tmp->left);
                tmp = tmp->left;
            }
        }
        
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */