class Solution {
public:
    bool canPermutePalindrome(string s) {
        int index[256] = {0};
        for (int i = 0; i < s.size(); i++)
            index[s[i]]++;
        int odd = 0;
        for (int i = 0; i < 256; i++) {
            if (index[i]%2) odd++;
        }
        return odd < 2;
    }
};