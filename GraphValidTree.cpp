class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n == 0) return true;
        vector<bool> index(n, false);
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
                graph[edges[i].first].push_back(edges[i].second);
                graph[edges[i].second].push_back(edges[i].first);
        }
        if(!DFS(index, graph, 0, 0)) return false;
        for (int i = 1; i < index.size(); i++) {
            if (!index[i]) return false;
        }
        return true;
    }
    
    bool DFS(vector<bool> &index, vector<vector<int>> &graph, int cur, int past) {
        if (index[cur]) return false;
        index[cur] = true;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (graph[cur][i] != past && !DFS(index, graph, graph[cur][i], cur)) return false;
        }
        return true;
    }
};