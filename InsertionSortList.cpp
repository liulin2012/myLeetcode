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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode*  dummy = new ListNode(INT32_MIN);
        dummy->next = head;
        
        ListNode* iter = head;
        while (iter->next) {
            if (iter->next->val < iter->val) {
                ListNode* tmp = dummy;
                while (tmp->next->val < iter->next->val) tmp = tmp->next;
                ListNode* tmpIter = iter->next;
                iter->next = iter->next->next;
                tmpIter->next = tmp->next;
                tmp->next = tmpIter;
                
            } else iter = iter->next;
        }
        return dummy->next;
    }
};