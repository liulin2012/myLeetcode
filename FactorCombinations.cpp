class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        if (n < 4) return {};
        vector<vector<int>> res;
        DFS(n, 2, res, {});
        return res;
    }
    
    void DFS(int n, int begin, vector<vector<int>> &res, vector<int> one) {
        if (n == 1) res.push_back(one);
        else {
            for (int i = begin; i <= n; i++) {
                if (i == n && one.empty()) continue;
                
                if (!(n%i)) {
                    one.push_back(i);
                    DFS(n/i, i, res, one);
                    one.pop_back();
                }
            }
        }
    }
};


class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> line;
        getFHelp(n, 2, line);
        return res;
    }

    void getFHelp(int n, int bottom, vector<int> line) {
        for(int i=bottom; i<=sqrt(n); i++){
            if(n%i == 0) {
                vector<int> new_line = line;
                new_line.push_back(i);
                getFHelp(n/i, i, new_line);
                new_line.push_back(n/i);
                res.push_back(new_line);
            }
        }
    }
};