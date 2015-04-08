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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || !head || !head->next)  return head;
        
        int size = 1;
        ListNode *tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
            size++;
        }
        
        int rotateNumber = k%size;
        if (rotateNumber == 0) return head;
        
        tmp->next = head;
        ListNode *node = head;
        while (--size > rotateNumber) node = node->next;
        head = node->next;
        node->next = nullptr;
        
        return head; 
    }
};