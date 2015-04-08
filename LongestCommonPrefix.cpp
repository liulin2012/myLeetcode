class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        if (strs[0].size() == 0) return "";
        string res = "";
        int index = 0;
        while (1) {
            if (index >= strs[0].size()) return res;
            
            char tmp = strs[0][index];
            for (int i = 1; i < strs.size(); i++) {
                if (index > strs[i].size() - 1) return res;
                else if (strs[i][index] != tmp) {
                    return res;
                }
            }
            res.push_back(tmp);
            index++;
        }
        return res;
    }
};