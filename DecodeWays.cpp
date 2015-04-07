class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        if (s[0] == '0') return 0;
        vector<int> res(s.size() + 1, 1);
        for (int i = 2; i <= s.size(); i++) {
            int num = stoi(s.substr(i - 2, 2));
            if (num%10 == 0 && (num == 0 || (num/10 > 2))) return 0;
            if (s.substr(i - 1, 1) == "0" || s.substr(i - 2, 1) == "0") {
                res[i] = res[i - 2];
            }
            else
                res[i] = res[i - 1] + (num <= 26 ? res[i - 2] : 0);
        }
        return res[s.size()];
    }
};