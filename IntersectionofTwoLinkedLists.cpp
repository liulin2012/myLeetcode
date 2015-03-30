//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists:
//
//A:          a1 → a2
//                   ↘
//                     c1 → c2 → c3
//                   ↗            
//B:     b1 → b2 → b3
//begin to intersect at node c1.
//
//
//Notes:
//
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.



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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return NULL;
        int a = 1;
        int b = 1;
        ListNode *tmpA = headA;
        ListNode *tmpB = headB;
        while (tmpA -> next != nullptr) {
            tmpA = tmpA -> next;
            a++;
        }
        while (tmpB -> next != nullptr) {
            tmpB = tmpB -> next;
            b++;
        }
        if (tmpA != tmpB) return NULL;
        if (b > a) {
            int i = b - a;
            while (i != 0) {
                headB = headB -> next;
                i--;
            }
        }
        else {
            int i = a - b;
            while (i != 0) {
                headA = headA -> next;
                i--;
            }
        }
        while (headA != headB) {
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};