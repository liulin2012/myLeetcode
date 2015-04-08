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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy, *q = p->next, *tmp;
        bool ifdupl = false;
        
        while (q) {
            int val = q->val;
            tmp = q->next;
            while (tmp && tmp->val == val) {
                ifdupl = true;
                tmp = tmp->next;
            }
            if (ifdupl) {
                ifdupl = false;
                //tmp = tmp ? tmp->next : nullptr;
            }
            else {
                p->next = q;
                p = q;
            }
            q = tmp;
            
        }
        p->next = tmp;
        
        
        return dummy->next;
    }
};


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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode **pp = &head;
        while (*pp) {
            if ((*pp)->next && (*pp)->val == (*pp)->next->val ) {
                ListNode *tmp = (*pp)->next->next;
                while (tmp&&tmp->val == (*pp)->val) tmp = tmp->next;
                *pp = tmp;
            }
            else 
                pp = &(*pp)->next;
        }
        return head;
    }
};