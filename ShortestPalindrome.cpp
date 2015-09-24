class Solution {
public:
    string shortestPalindrome(string s) {
        vector<int> index = computerArray(s);
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end) {
            if (s[begin] == s[end]) {
                begin++;
                end--;
            } else {
                if (begin == 0) end--;
                else begin = index[begin - 1];
            }   
        }
        int x = begin == end ? end * 2 + 1 : (end + 1) * 2;
        string m = s.substr(x);
        reverse(m.begin(), m.end());
        return m + s;
    }
    
    vector<int> computerArray(string needle) {
        vector<int> index(needle.size(), 0);
        int len = 0;
        int i = 1;
        while (i < needle.size()) {
            if (needle[i] == needle[len]) {
                len++;
                index[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = index[len - 1];
                } else {
                    needle[i] = 0;
                    i++;
                }
            }
        }
        return index;
    }
};