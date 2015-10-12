class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        
        vector<string> res;
        if (s.size() == 0) return res;
        vector<vector<string>> index(s.size());
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (wordDict.find(s.substr(j, i-j+1)) != wordDict.end()) {
                    if (j == 0 || !index[j - 1].empty()) {
                        index[i].push_back(s.substr(j, i-j+1));
                    }
               }
            }
        }
        stack<string> tmp;
        DFS(index, index.size() - 1, res, tmp);
        
        return res;
    }
    
    void DFS(vector<vector<string>> &index, int cur, vector<string> &res, stack<string> one) {
        if (cur == -1) {
            string tmp;
            while (!one.empty()) {
                tmp += one.top() + " ";
                one.pop();
            }
            tmp.pop_back();
            res.push_back(tmp);
        } else {
            for (int i = 0; i < index[cur].size(); i++) {
                one.push(index[cur][i]);
                DFS(index, cur - index[cur][i].size(), res, one);
                one.pop();
            }
        }
    }
};