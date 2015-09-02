class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        CSum3(k ,n, 1, {});
        return res;
    }
    void CSum3(int k, int n, int begin, vector<int> vec) {
        if (k == 0 && n == 0) { res.push_back(vec); return; }
        else if (k == 0 || n == 0 || begin > 9) return;
        else if (begin <= n){
            CSum3(k, n, begin + 1, vec);
            vec.push_back(begin);
            CSum3(k - 1, n - begin, begin + 1, vec);
        }
    }
};