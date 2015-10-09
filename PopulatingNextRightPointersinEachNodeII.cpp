/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> qu;
        if (root == nullptr) return ;
        
        qu.push(root);
        while (!qu.empty()) {
            int num = qu.size();
            TreeLinkNode* pre;
            TreeLinkNode* tmp;
            for (int i = 0; i < num; i++) {
                tmp = qu.front();
                qu.pop();
                if (tmp->left) qu.push(tmp->left);
                if (tmp->right) qu.push(tmp->right);
                
                if (i == 0) { pre = tmp; tmp->next = nullptr;}
                else if (i == num - 1) {pre->next = tmp; tmp->next = nullptr;}
                else {
                    pre->next = tmp;
                    pre = tmp;
                }
            }
        }
    }
};