class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        BFS(s, 0, res, {});
        return res;
        
    }
    
    void BFS(string s, int begin, vector<vector<string>>& res, vector<string> one) {
        if (begin == s.size()) res.push_back(one);
        else {
            for (int i = begin; i < s.size(); i++) {
                if (isPalindrome(s, begin, i)) {
                    // string tmp(s[begin], s[i + 1]);
                    one.push_back(s.substr(begin, i - begin + 1));
                    BFS(s, i + 1, res, one);
                    one.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
}; 