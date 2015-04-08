class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        int begin = 0;
        int end = s.size() - 1;
        while (begin != end && begin != end + 1) {
            if (!isalnum(s[begin])) begin++;
            else if (!isalnum(s[end])) end--;
            else if (tolower(s[begin]) == tolower(s[end])) {begin++; end--;}
            else return false;
        }
        return true;
    }
};