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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        
        ListNode *first = head, *second = first->next, *tmp = second->next;
        head = head->next;
        while (tmp != nullptr && tmp->next != nullptr) {
            first->next = tmp->next;
            second->next = first;
            first = tmp;
            second = first->next;
            tmp = second->next;
            
        }
        first->next = tmp;
        second->next = first;
    
        return head;
    }
};