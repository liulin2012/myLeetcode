class Solution {
public:
    int titleToNumber(string s) {
        long long ret=0;
        for (int i=0; i<s.size(); i++){
            int n = s[i] - 'A' + 1;
            ret = ret*26 + n;
         }
        return ret;
    }
};
