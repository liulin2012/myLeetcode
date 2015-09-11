class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n == 0) return res;
        vector<string> one (n, string(n, '.'));
        DFS(n, res, 0, one, 0);
        return res;
    }
    
    void DFS(int n, vector<vector<string>>& res, int row, vector<string>& one, int finish) {
        if (finish == n) {
            res.push_back(one);
            return;
        }
            
        for (int i = 0; i < n; i++) {
            if (setChange(n, row, i, one)) {
                one[row][i] = 'Q';
                DFS(n, res, row + 1, one, finish + 1);
                one[row][i] = '.';
            }
        }
    }
    
    bool setChange(int n, int a, int b, vector<string>& one) {
        for (int i = 0; i < n; i++) {
            if (one[i][b] == 'Q') return false;
        }
        int m = a, s = b;
        while (m >= 0 && s >= 0) if (one[m--][s--] == 'Q') return false;
        m = a, s = b;
        while (m < n && s < n) if (one[m++][s++] == 'Q') return false;
        m = a, s = b;
        while (m < n && s >= 0) if (one[m++][s--] == 'Q') return false;
        m = a, s = b;
        while (m >= 0 && s < n) if (one[m--][s++] == 'Q') return false;
        return true;
    }
};


class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        /*
        flag[0] to flag[n - 1] to indicate if the column had a queen before.
        flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
        flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
        */
        std::vector<int> flag(5 * n - 2, 1);
        solveNQueens(res, nQueens, flag, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag, row + 1, n);
                nQueens[row][col] = '.';
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
            }
    }
};