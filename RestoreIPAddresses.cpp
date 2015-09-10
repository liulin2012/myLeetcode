class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) return res;
        BFS(s, 0, 0, "", res);
        return res;
    }
    
    void BFS(string s, int begin, int finish, string one, vector<string>& res) {
        if (begin == s.size() && finish == 4) res.push_back(one);
        else if (begin + 3*(4 - finish) >= s.size() && begin + (4 - finish) <= s.size()) {
            if (finish != 0) one += ".";
            if (begin + 1 <= s.size())
                BFS(s, begin + 1, finish + 1, one + s[begin], res);
            if (begin + 2 <= s.size() && s[begin] != '0')
                BFS(s, begin + 2, finish + 1, one + s.substr(begin, 2), res);
            if (begin + 3 <= s.size() && stoi(s.substr(begin, 3)) <= 255 && s[begin] != '0')
                BFS(s, begin + 3, finish + 1, one + s.substr(begin, 3), res);
        }
    }
}; 