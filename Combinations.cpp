class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> one;
        com(n, k, 1, one, res);
        return res;
    }
    
    void com(int n, int k, int begin, vector<int>& one, vector<vector<int>>& res) {
        if (k == 0) res.push_back(one);
        else {
            for (int i = begin; i + k <= n + 1; i++) {
                one.push_back(i);
                com(n, k - 1, i + 1, one, res);
                one.pop_back();
            }
        }
    }
};