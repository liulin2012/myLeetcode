class Solution {
public:
    int numSquares(int n) {
        if (n == 0) return 0;
        int index[n+1];
        int res;
        index[1] = 1;
        int m = 2;
        for (int i = 2; i < n+1; i++) {
            if (i == m*m) {
                index[i] = 1;
                m++;
                continue;
            }
            res = INT32_MAX;
            int tmp = m - 1;
            while (tmp) {
                res = min(res, index[tmp*tmp] + index[i - tmp*tmp]);
                tmp--;
            }
            index[i] = res;
        }
        return index[n];
    }
};