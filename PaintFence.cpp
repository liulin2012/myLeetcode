class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        if (k == 1 && n > 2) return 0;
        else if (k == 1 || n == 1) return k;
        int res = k*k;
        int same = k;
        for (int i = 2; i < n; i++) {
            int tmp = res - same;
            res = (res-same)*k + same*(k-1);
            same = tmp;
        }
        return res;
        
    }
};