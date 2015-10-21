class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<int> index(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        for (int i = 0; i < graph.size(); i++) {
            if (index[i] == 0 && !DFS(index, graph, i, res)) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool DFS(vector<int> &index, vector<vector<int>> &graph, int cur, vector<int> &res) {
        index[cur] = 1;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (index[graph[cur][i]] == 1) return false;
            else if (index[graph[cur][i]] == 0 && !DFS(index, graph, graph[cur][i], res)) return false;
        }
        res.push_back(cur);
        index[cur] = 2;
        return true;
    }
};