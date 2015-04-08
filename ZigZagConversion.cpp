class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string res(s.size(), 0);
        int n = 2 * nRows;
        int row = 0;
        for (int i = 1; i <= nRows; i++) {
            int index = i - 1;
            int a = n - 2*i;
            int b = 2 * (i - 1);
            while (index < s.size()) {
                res[row++] = s[index];
                if (i == 1) {
                    index += a;
                }
                else if (i == nRows) {
                    index += b;
                }
                else {
                    index += a;
                    swap(a,b);
                }
            }
        }
        
        return res;
    }
};