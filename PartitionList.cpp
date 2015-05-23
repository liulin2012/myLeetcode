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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode* dummyBig = new ListNode(0);
        ListNode* dummyLess = new ListNode(0);
        ListNode* tmpB = dummyBig, *tmpL = dummyLess;
        while (head) {
            if (head->val >= x) {tmpB->next = head; tmpB = tmpB->next;}
            else {tmpL->next = head; tmpL = tmpL->next;}
            head = head->next;
        }
        tmpL->next = dummyBig->next;
        tmpB->next = nullptr;
        return dummyLess->next;
    }
};