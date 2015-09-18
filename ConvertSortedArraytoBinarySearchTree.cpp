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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        else if (nums.size() == 1) return new TreeNode(nums[0]);
        else return sortedArray(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArray(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        else if (left == right) return new TreeNode(nums[left]);
        else {
            int mid = (left + right) / 2;
            TreeNode* tmp = new TreeNode(nums[mid]);
            tmp->left = sortedArray(nums, left, mid - 1);
            tmp->right = sortedArray(nums, mid+1, right);
            return tmp;
        }
    }
};