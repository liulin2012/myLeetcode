class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res( n, vector<int>(n) );
        if (n == 0) return res;
        int a = n - 1;
        int b = n;
        int way = 1;
        int m = 0;
        int r = -1;
        int x = 1;
        while (x <= n*n) {
            if (way == 1) {
                for (int i = 0; i < b; i++) {
                    r++;
                    res[m][r] = x;
                    x++;
                }
                b--;
                way = 2;
            } else if (way == 2) {
                for (int i = 0; i < a; i++) {
                    m++;
                    res[m][r] = x;
                    x++;
                    
                }
                a--;
                way = 3;
            } else if (way == 3) {
                for (int i = 0; i < b; i++) {
                    r--;
                    res[m][r] = x;
                    x++;
                    
                }
                b--;
                way = 4;
            } else if (way == 4) {
                
                for (int i = 0; i < a; i++) {
                    m--;
                    res[m][r] = x;
                    x++;
                    
                }
                a--;
                way = 1;
            }
        }
        return res;
    }
};