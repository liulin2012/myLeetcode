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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        else if (root == p) return root;
        else if (root == q) return root;
        else {
            TreeNode* a = lowestCommonAncestor(root->left, p, q);
            TreeNode* b = lowestCommonAncestor(root->right, p, q);
            if (a != nullptr && b != nullptr) return root;
            else if (a != nullptr) return a;
            else if (b != nullptr) return b;
            else return nullptr;
        }
    }
};