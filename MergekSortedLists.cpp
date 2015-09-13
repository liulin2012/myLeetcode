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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, ListNode*> index;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        for (auto i : lists)
             if (i != nullptr) index.insert({i->val, i});
        
        while (!index.empty()) {
            auto iter = index.begin();
            head->next = iter->second;
            head = head->next;
            index.erase(iter);
            if (head->next) index.insert({head->next->val, head->next});
        }
        return dummy->next;
    }
};