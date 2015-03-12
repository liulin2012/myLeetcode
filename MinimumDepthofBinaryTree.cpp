/*
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int min=0;
    void depth(TreeNode *root,int number){
        if(root == NULL) return;
        else if(root->left == NULL && root->right == NULL){
            min=number;
        }
        else if(min==0||number!=min){
            number++;
            depth(root->left,number);
            depth(root->right,number);
        }
    }
        
    int minDepth(TreeNode *root) {
        depth(root,1);
        return min;
    }
};