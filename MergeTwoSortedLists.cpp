//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//


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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *result = new ListNode(0);
        ListNode *tmp = result;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                tmp->next = l1;
                tmp = tmp->next;
                l1 = l1->next;
            }
            else {
                tmp->next = l2;
                tmp = tmp->next;
                l2 = l2->next;
            }
        }
        if (l1 == NULL) tmp->next = l2;
        else tmp->next = l1;
        return result->next;
        
    }
};