class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> res;
        for (int i = 0; i < s.size(); i++) {
            if (res.empty()) res.push(s[i]);
            else if (res.top() == '(' && s[i] == ')') res.pop();
            else if (res.top() == '{' && s[i] == '}') res.pop();
            else if (res.top() == '[' && s[i] == ']') res.pop();
            else res.push(s[i]);
        }
        if (res.empty()) return true;
        else return false;
    }
};