class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num[0] == '0') {
            DFS(num, target, 1, 0, "0", res);
        } else {
            for (int i = 0; i < num.size(); i++) {
                long tmpnum = stol(num.substr(0, i + 1));
                DFS(num, target, i + 1, tmpnum, to_string(tmpnum), res);
            }
        }
        return res;
    }
    void DFS(string num, long target, int begin, long tmp, string one, vector<string>& res) {
        if (target == tmp && begin == num.size()) res.push_back(one);
        else if (num[begin] != '0' && begin < num.size()){
            for (int i = begin; i < num.size(); i++) {
                long tmpnum = stol(num.substr(begin, i + 1 - begin));
                DFS(num, target - tmp, i + 1, tmpnum, one + "+" + to_string(tmpnum), res);
                DFS(num, target - tmp, i + 1, tmpnum * (-1), one + "-" + to_string(tmpnum), res);
                DFS(num, target, i + 1, tmpnum * tmp, one + "*" + to_string(tmpnum), res);
            }
        } else if (begin < num.size()) {
            DFS(num, target - tmp, begin + 1, 0, one + "+0", res);
            DFS(num, target - tmp, begin + 1, 0, one + "-0", res);
            DFS(num, target, begin + 1, 0, one + "*0", res);
        }
    }
};