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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2 || head == nullptr) return head;
        int m = k;
        ListNode* nextNode = head;
        while (--m) {
            nextNode = nextNode->next;
            if (!nextNode) return head;
        }
        nextNode = reverseKGroup(nextNode->next, k);
        m = k;
        ListNode* next = head->next, *tmp;
        head->next = nextNode;
        while (--m) {
            tmp = next;
            next = next->next;
            tmp->next = head;
            head= tmp;
        }
        return head;
    }
};