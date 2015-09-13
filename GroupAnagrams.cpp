class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> index;
        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            index[tmp].insert(str);
        }
        vector<vector<string>> res;
        for (auto i = index.begin(); i != index.end(); i++) {
            vector<string> tmp(i->second.begin(), i->second.end());
            res.push_back(tmp);
        }
        return res;
    }
};