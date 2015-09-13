/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) return nullptr;
        RandomListNode* res, *tmp = head, *restmp = new RandomListNode(0);
        res = restmp;
        while (tmp) {
            restmp->next = new RandomListNode(tmp->label);
            tmp = tmp->next;
            restmp = restmp->next;
        }
        tmp = head;
        res = res->next;
        restmp = res;
        unordered_map<RandomListNode*, vector<RandomListNode* >> index;
        while (tmp) {
            if (tmp->random) {
                if (index.find(tmp->random) == index.end()) {
                    index.insert({tmp->random, {restmp}});
                } else {
                    auto iter = index.find(tmp->random);
                    iter->second.push_back(restmp);
                }
            }
            tmp = tmp->next;
            restmp = restmp->next;
        }
        
        tmp = head;
        restmp = res;
        while (tmp) {
            if (index.find(tmp) != index.end()) {
                auto iter = index.find(tmp);
                for (auto i : iter->second)
                    i->random = restmp;
            }
            tmp = tmp->next;
            restmp = restmp->next;
        }
        
        return res;
    }
};