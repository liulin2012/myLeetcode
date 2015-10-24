class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if (s.empty()) return {};
        vector<string> res;
        int index[256] = {0};
        for (int i = 0; i < s.size(); i++)
            index[s[i]]++;
        int odd = 0;
        char ch = -1;
        string tmp;
        for (int i = 0; i < 256; i++) {
            if (index[i]%2) {
                odd++;
                ch = i;
                index[i]--;
                while (index[i]) {
                    tmp.push_back(i);
                    index[i] -= 2;
                }
            } else if (index[i] > 0) {
                while (index[i]) {
                    tmp.push_back(i);
                    index[i] -= 2;
                }
            }
        }
        if (odd > 1) return {};
        if (tmp.empty()) {
            tmp.push_back(ch);
            res.push_back(tmp);
            return res;
        }
        sort(tmp.begin(), tmp.end());
        
        do {
            string r = tmp;
            if (ch != -1) r.push_back(ch);
            reverse(tmp.begin(), tmp.end());
            r += tmp;
            reverse(tmp.begin(), tmp.end());
            res.push_back(r);
        } while (next_permutation(tmp.begin(), tmp.end()));
        return res;
        
    }
};