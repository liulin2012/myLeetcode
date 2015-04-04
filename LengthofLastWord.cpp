Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.


class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string res(s);
        while (res.back() == ' ') res.pop_back();
        if (res.find_last_of(" ") != string::npos) return res.size() - res.find_last_of(" ") - 1;
        else return res.size();
    }
};