/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* tmp = dummy;
        while (tmp->next != nullptr) {
            if (tmp->next->val == val) tmp->next = tmp->next->next;
            else tmp = tmp->next;
        }
        return dummy->next;
    }
};