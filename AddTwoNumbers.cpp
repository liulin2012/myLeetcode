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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res;
        ListNode *tmpNode = new ListNode(0);
        res = tmpNode;
        bool upDigit = false;
        while (l1 || l2) {
            int tmp;
            if (!l1) tmp = l2->val, l2 = l2->next;
            else if (!l2) tmp = l1->val, l1 = l1->next;
            else tmp = l1->val + l2->val, l1 = l1->next, l2 = l2->next;
            if (upDigit) tmp++;
            if (tmp > 9) 
                tmp -= 10, upDigit = true;
            else upDigit = false;
            tmpNode->next = new ListNode(tmp);
            tmpNode = tmpNode->next;
            
        }
        if (upDigit) tmpNode->next = new ListNode(1);
        return res->next;
    }
};