class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty()) return 0;
        int res = 0;
        char first;
        int num1 = -1;
        char second;
        int num2 = -1;
        int begin;
        
        for (int i = 0; i < s.size(); i++) {
            if (num1 == -1) { first = s[i]; res = 1; num1 = 0; begin = 0; continue;}
            if (first == s[i]) { num1 = i; res = max(res, i-begin+1); continue;} 
            
            if (num2 == -1) { second = s[i]; num2 = i; res = max(res, i-begin+1); continue;}
            if (second == s[i]) {num2 = i; res = max(res, i-begin+1); continue;}
            
            if (num1 < num2) {begin = num1+1; num1 = i; first = s[i]; continue;}
            if (num1 > num2) {begin = num2+1; num2 = i; second = s[i]; continue;}
            
        }
        
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty()) return 0;

        int dict[256]; 
        fill_n(dict,256,0);
        int start = 0, len = 1, count = 0;
        for(int i=0; i<s.length(); i++) {
            dict[s[i]]++;
            if(dict[s[i]] == 1) { // new char
                count++;
                while(count > 2) {
                    dict[s[start]]--;
                    if(dict[s[start]] == 0) count--; 
                    start++;
                }
            }
            len = max(len, i-start+1);
        }
        return len;
        }
};