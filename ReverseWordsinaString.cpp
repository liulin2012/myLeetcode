class Solution {
public:
    void reverseWords(string &s) {
        while (s[0] == ' ') s.erase(0, 1);
        reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.size()) {
            while (s[i] == ' ') s.erase(i, 1);
            int tmp = i + 1;
            while (tmp != s.size() && s[tmp] != ' ') tmp++;
            reverse(s.begin() + i, s.begin() + tmp);
            i = tmp + 1;
        }
        while (s[0] == ' ') s.erase(0, 1);
    }
};