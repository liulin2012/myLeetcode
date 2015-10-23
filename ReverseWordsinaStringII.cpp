class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() < 2) return;
        reverse(s.begin(), s.end());
        int begin = 0;
        int end = -1;
        s.push_back(' ');
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') end++;
            else {
                while (begin < end) 
                    swap(s[begin++], s[end--]);
                begin = i+1;
                end = i;
            }
        }
        s.pop_back();
    }
};