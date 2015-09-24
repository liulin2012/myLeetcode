class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        res.push_back(s[0]);
        int i = 1;
        while (i < (s.size() - 1)) {
            int begin = i - 1;
            int end = i + 1;
            while (begin >= 0 && end < s.size() && s[begin] == s[end]) { begin--; end++;}
            begin++;
            end--;
            if ((end - begin + 1) > res.size()) res = s.substr(begin, end- begin + 1);
            i++;
        }
        
        i = 1;
        while (i < s.size()) {
            int begin = i - 1;
            int end = i;
            while (begin >= 0 && end < s.size() && s[begin] == s[end]) { begin--; end++;}
            begin++;
            end--;
            if ((end - begin + 1) > res.size()) res = s.substr(begin, end- begin + 1);
            i++;
        }
        return res;
    }
};