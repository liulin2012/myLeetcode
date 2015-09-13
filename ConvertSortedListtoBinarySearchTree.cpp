/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        else if (!head->next) return new TreeNode(head->val);
        ListNode* fast = head->next, *slow = head, *lastSlow = head;
        while (fast && fast->next) 
            fast = fast->next->next, lastSlow = slow, slow = slow->next;
        TreeNode* pa = new TreeNode(slow->val);
        pa->right = sortedListToBST(slow->next);
        lastSlow->next = nullptr;
        if (head != slow) pa->left = sortedListToBST(head);
        return pa;
    }
};