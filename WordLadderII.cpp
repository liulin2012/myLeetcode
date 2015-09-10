class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        if (start.empty() || end.empty()) return res;
        unordered_map<string, vector<vector<string>>> head = {{start, {{start}}}};
        unordered_map<string, vector<vector<string>>> tail = {{end, {{end}}}};
        int headLen = 1, tailLen = 1, round = 2;
        bool done = false;
        while (headLen && tailLen) {
            if (headLen > tailLen) {
                swap(head, tail);
                swap(headLen, tailLen);
            }
            unordered_map<string, vector<vector<string>>> tmpMap;
            for (auto str = head.begin(); str != head.end(); str++) {
                string s(str->first);
                for (int i = 0; i < s.size(); i++) {
                    char a = s[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (s[i] == c) continue;
                        s[i] = c;
                        if (tail.find(s) != tail.end()) {
                            done = true;
                            for (auto x : str->second) {
                                for (auto y : tail.find(s)->second) {
                                    if (x[0] == start) {
                                        vector<string> tmp(x);
                                        for (auto it = y.rbegin(); it != y.rend(); it++)
                                            tmp.push_back(*it);
                                        res.push_back(tmp);
                                    } else {
                                        vector<string> tmp(y);
                                        for (auto it = x.rbegin(); it != x.rend(); it++)
                                            tmp.push_back(*it);
                                        res.push_back(tmp);
                                    }
                                }
                                    
                            }
                        }
                        else if (wordList.find(s) != wordList.end()) {
                            if (tmpMap.find(s) != tmpMap.end()) {
                                vector<vector<string>> tmp = tmpMap.find(s)->second;
                                for (auto x : str->second) {x.push_back(s); tmp.push_back(x);}
                            } else {
                                vector<vector<string>> tmp;
                                for (auto x : str->second) {x.push_back(s); tmp.push_back(x);}
                                tmpMap.insert({s, tmp});
                            }
                        }
                    }
                    s[i] = a;
                }
            }
            if (done) return res;
            for (auto m = tmpMap.begin(); m != tmpMap.end(); m++) wordList.erase(m->first);
            swap(head, tmpMap);
            headLen = head.size();
            round++;
        }
        return res;
    }
};