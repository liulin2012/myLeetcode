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
    vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return result;
        // if (!(root->left) && !(root->right)) result.push_back(to_string(root->val));
        tree(root, "");
        return result;
    }
    
    void tree(TreeNode* treePath, string path) {
        if (!treePath->left && !treePath->right) result.push_back(path + to_string(treePath->val));
        if (treePath->left) tree(treePath->left, path + to_string(treePath->val) + "->");
        if (treePath->right) tree(treePath->right, path + to_string(treePath->val) + "->");
    }
};