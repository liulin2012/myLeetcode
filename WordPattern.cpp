class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_set<string> contain;
        vector<string> index(26);
        stringstream ss(str);
        string tmp;
        int i = 0;
        while (getline(ss, tmp, ' ')) {
            if (i == pattern.size()) return false;
            if (index[pattern[i]-'a'].empty()) {
                index[pattern[i]-'a'] = tmp;
                if (contain.find(tmp) != contain.end())
                    return false;
                else contain.insert(tmp);
            } else if (index[pattern[i]-'a'] != tmp)
                return false;
                
            i++;
        }
        return i == pattern.size() ? true : false;
    }
};