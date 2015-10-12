class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        vector<string> index(26);
        unordered_set<string> contain;
        return DFS(pattern, 0, str, 0, contain, index);
    }
    
    bool DFS(string &pattern, int pIndex, string &str, int sIndex, unordered_set<string> &contain, vector<string> &index) {
        if (sIndex == str.size() && pIndex == pattern.size()) return true;
        else if (pIndex == pattern.size()) return false;
        else {
            for (int i = sIndex; i < str.size(); i++) {
                string tmp = str.substr(sIndex, i - sIndex + 1);
                if (index[pattern[pIndex] - 'a'].empty()) {
                    if (contain.find(tmp) != contain.end())
                        continue;
                    else {
                        contain.insert(tmp);
                        index[pattern[pIndex] - 'a'] = tmp;
                        if(DFS(pattern, pIndex + 1, str, i + 1, contain, index)) return true;
                        index[pattern[pIndex] - 'a'] = "";
                        contain.erase(tmp);
                    }
                } else if (index[pattern[pIndex] - 'a'] != tmp) continue;
                else {
                    if(DFS(pattern, pIndex + 1, str, i + 1, contain, index)) return true;
                }
            }
        }
        return false;
    }

};