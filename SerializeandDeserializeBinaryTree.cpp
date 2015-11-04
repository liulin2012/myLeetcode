/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        string res;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode* ptr = qu.front();
            qu.pop();
            if (ptr == nullptr) res += "n ";
            else {
                res += to_string(ptr->val) + " ";
                qu.push(ptr->left);
                qu.push(ptr->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        istringstream iss(data);
        queue<TreeNode*> qu;
        int val;
        iss >> val;
        TreeNode* res = new TreeNode(val);
        TreeNode* root;
        qu.push(res);
        while (!qu.empty()) {
            root = qu.front();
            qu.pop();
            string left, right;
            iss >> left;
            iss >> right;
            if (left[0] != 'n') {
                TreeNode* tmp = new TreeNode(stoi(left));
                root->left = tmp;
                qu.push(tmp);
            }
            if (right[0] != 'n') {
                TreeNode* tmp = new TreeNode(stoi(right));
                root->right = tmp;
                qu.push(tmp);
            }
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));