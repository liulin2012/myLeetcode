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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return nullptr;
        if(!head->next) return head;
        
        ListNode *p = head, *tmp = nullptr;
        while (p) {
            tmp = p;
            p = p->next;
            while (p&&p->val == tmp->val)
                p = p->next;
            tmp->next = p;
        }
        return head;
    }
};