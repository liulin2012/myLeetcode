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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *begin = dummy, *first, *second, *tmp;
        
        n -= m;
        int x = m;
        m -= 1;
        
        while (m--) begin = begin->next;
        first = begin->next;
        second = first->next;
        while (n--) {
            tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }
        
        begin->next->next = second;
        begin->next = first;
        if (x == 1) return first;
        else return head;
    }
};