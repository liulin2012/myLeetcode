Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *fast = head , *slow = head;
        while (fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == nullptr) return false;
            if (fast == slow || fast ->next == slow) return true;
        }
        return false;
    }
};