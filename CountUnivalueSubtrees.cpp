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
    int res = 0;
    bool same = true;
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) return 0;
        DFS(root);
        return res;
    }
    
    int DFS(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) { same = true; res++; return root->val;}
        else if (root->left && root->right){
            int left = DFS(root->left);
            bool isSame = same;
            int right = DFS(root->right);
            if (!same || !isSame) return 0;
            if (left == right && left == root->val) { same = true; res++; return root->val;}
            else {same = false; return 0;}
        } else if (root->left) {
            int left = DFS(root->left);
            if (!same) return 0;
            if (left == root->val) { same = true; res++; return root->val;}
            else {same = false; return 0;}
        } else if (root->right) {
            int right = DFS(root->right);
            if (!same) return 0;
            if (right == root->val) { same = true; res++; return root->val;}
            else {same = false; return 0;}
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
    int res = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) return 0;
        DFS(root);
        return res;
    }
    
    bool DFS(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {res++; return true;}
        else {
            bool same = true;
            if (root->left) {
                if (!DFS(root->left)) same = false;
                else if (root->val != root->left->val) same = false;
            }
            if (root->right) {
                if (!DFS(root->right)) same = false;
                else if (root->val != root->right->val) same = false;
            }
            if (!same) return false;
            
            res++;
            return true;
        }
    }
};