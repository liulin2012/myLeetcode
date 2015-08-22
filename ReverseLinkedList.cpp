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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (head->next != nullptr) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        head->next = pre;
        return head;
    }
};