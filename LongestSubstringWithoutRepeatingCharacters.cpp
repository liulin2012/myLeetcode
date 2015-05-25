class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int result = 0, tmp = 0;
        int begin = 0, end = 0;
        bool index[128] = {false};
        while (end != s.length()) {
            if (index[ s[end] ]) {
                while (s[begin] != s[end]) {
                    index[ s[begin] ] = false;
                    tmp--;
                    begin++;
                }
                begin++; 
                end++;
            }
            else {
                index[ s[end] ] = true;
                end++;
                tmp++;
                result = max(result, tmp);
            }
        }
        return result;
    }
};