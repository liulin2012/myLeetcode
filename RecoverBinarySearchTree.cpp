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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr, *second = nullptr;
        TreeNode *last = new TreeNode(INT32_MIN);
        TreeNode *cur = new TreeNode(INT32_MIN);
        TreeNode *next = new TreeNode(INT32_MIN);
        
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
                    
                    last = cur;
                    cur = next;
                    next = root;
                    if (!first) {
                        if (cur->val > last->val && cur->val > next->val) first = cur;
                    } else {
                        if (cur->val < last->val && cur->val < next->val) second = cur;
                    }
                    
                    root = root->right;
                }
            } else {
                last = cur;
                cur = next;
                next = root;
                if (!first) {
                    if (cur->val > last->val && cur->val > next->val) first = cur;
                } else {
                    if (cur->val < last->val && cur->val < next->val) second = cur;
                }
                
                
                root = root->right;
            }
        }
        last = cur;
        cur = next;
        if (cur->val < last->val) second = cur;
        
        swap(first->val, second->val);
        
    }
};