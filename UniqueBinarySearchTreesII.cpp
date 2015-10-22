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

    TreeNode* clone(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *rootNew = new TreeNode(root->val);
        rootNew->left = clone(root->left);
        rootNew->right = clone(root->right);
        return rootNew;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {{nullptr}};
        vector<TreeNode*> res;
        vector<TreeNode*> tmpres;
        res.push_back(new TreeNode(1));
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < res.size(); j++) {
                TreeNode* tmpnode = new TreeNode(i);
                TreeNode* oldtree = clone(res[j]);
                tmpnode->left = oldtree;
                tmpres.push_back(tmpnode);
                
                oldtree = res[j];
                TreeNode* rightnode = oldtree;
                while (rightnode->right != nullptr) {
                    tmpnode = new TreeNode(i);
                    tmpnode->left = rightnode->right;
                    rightnode->right = tmpnode;
                    tmpres.push_back(clone(oldtree));
                    rightnode->right = tmpnode->left;
                    rightnode = rightnode->right;
                }
                tmpnode = new TreeNode(i);
                rightnode->right = tmpnode;
                tmpres.push_back(clone(oldtree));
            }
            swap(tmpres, res);
            tmpres.clear();
        }
        return res;
    }
};