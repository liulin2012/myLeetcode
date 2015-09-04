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
    int po = 0;
    int io = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if (ps > pe) {
            return nullptr;
        } else {
            TreeNode* t = new TreeNode(preorder[ps]);
            int i = is;
            while (inorder[i] != t->val) i++;
                
            t->left = create(preorder, inorder, ps + 1, ps + i - is, is, i - 1);
            t->right = create(preorder, inorder, ps + i - is + 1, pe, i + 1, ie);
            return t;
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0, j = 0;
        TreeNode *root=new TreeNode(0x80000000);
        TreeNode *pp=NULL,*ptr=root;
        stack<TreeNode*> sn;sn.push(root);
        while (i < preorder.size()) {
            if (inorder[j] == sn.top()->val) {
                pp = sn.top();
                sn.pop();
                j++;
            } else if (pp) {
                pp->right = new TreeNode(preorder[i]);
                sn.push(pp->right);
                pp = nullptr;
                i++;
            } else {
                sn.top()->left = new TreeNode(preorder[i]);
                sn.push(sn.top()->left);
                i++;
            }
        }
        return root->left;
    }
    
};