class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int index[26] = {0};
        for (auto i = s.begin(); i != s.end(); i++) index[*i - 'a']++;
        for (auto i = t.begin(); i != t.end(); i++) {
            if (index[*i - 'a'] == 0) return false;
            else index[*i - 'a']--;
        }
        return true;
    }
};