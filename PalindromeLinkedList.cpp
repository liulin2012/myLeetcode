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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        slow = reverseLink(fast);
        while (head != nullptr) {
            if (head->val != slow->val) return false;
            else {
                head = head->next;
                slow = slow->next;
            }
        }
        return true;
    }
    
    ListNode* reverseLink(ListNode* head) {
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