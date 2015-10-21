class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<bool> appear(26, false); 
        vector<int> res;
        vector<int> index(26, 0);
        vector<unordered_set<int>> graph(26);
        string ans;
        
        for (int i = 0; i < words.size(); i++) {
            for (auto ch : words[i])
                appear[ch - 'a'] = true;
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < min(words[i].size(), words[i+1].size()); j++)
                if (words[i][j] != words[i + 1][j]) {
                    graph[words[i][j] - 'a'].insert(words[i+1][j] - 'a');
                    break;
                }
        }
        for (int i = 0; i < graph.size(); i++) {
            if (index[i] == 0 && !graph[i].empty() && !DFS(index, graph, i, res)) return "";
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            ans.push_back(res[i] + 'a');
            
        for (int i = 0; i< appear.size(); i++) {
            if (index[i] == 0 && appear[i] == true)
                ans.push_back(i + 'a');
        }
        return ans;
    }
    
    bool DFS(vector<int> &index, vector<unordered_set<int>> &graph, int cur, vector<int> &res) {
        index[cur] = 1;
        for (auto i : graph[cur]) {
            if (index[i] == 1) return false;
            else if (index[i] == 0 && !DFS(index, graph, i, res)) return false;
        }
        res.push_back(cur);
        index[cur] = 2;
        return true;
    }
};