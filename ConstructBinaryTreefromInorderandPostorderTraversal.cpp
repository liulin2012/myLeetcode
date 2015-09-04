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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* create(vector<int>& postorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if (ps > pe) {
            return nullptr;
        } else {
            TreeNode* t = new TreeNode(postorder[pe]);
            int i = is;
            while (inorder[i] != t->val) i++;
                
            t->left = create(postorder, inorder, ps, pe + i - ie - 1, is, i - 1);
            t->right = create(postorder, inorder, pe + i - ie, pe - 1, i + 1, ie);
            return t;
        }
        
    }
    
};