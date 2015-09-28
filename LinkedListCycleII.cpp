Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *fast = head , *slow = head, *cycle;
        while (fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == nullptr) return NULL;
            if (fast == slow) {
                cycle = fast;
                break;
            }
        }
        if (fast->next == nullptr) return NULL;
        
        int count = 1;
        fast = fast->next;
        while (fast != cycle) {
            count++;
            fast = fast->next;
        }
        
        fast = head;
        slow = head;
        while (count--) fast = fast->next;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * https://leetcode.com/discuss/16567/concise-solution-using-with-detailed-alogrithm-description
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
        return NULL;

        ListNode *slow  = head;
        ListNode *fast  = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // there is a cycle
                fast = head;
                while(slow != fast) {               // found the entry location
                slow  = slow->next;
                fast = fast->next;
            }
            return fast;
            }
        }
        return NULL;                      
    }
};