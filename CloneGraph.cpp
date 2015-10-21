/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<int, UndirectedGraphNode*> index;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        if (index.find(node->label) != index.end()) return index[node->label];
        UndirectedGraphNode *tmp = new UndirectedGraphNode(node->label);
        index.insert({node->label, tmp});
        for (int i = 0; i < node->neighbors.size(); i++) {
            tmp->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return tmp;
    }
};