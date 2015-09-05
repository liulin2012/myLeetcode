class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int a = matrix.size() - 1;
        int b = matrix[0].size();
        int way = 1;
        int m = 0;
        int n = -1;
        while (res.size() != matrix[0].size()*matrix.size()) {
            if (way == 1) {
                for (int i = 0; i < b; i++) {
                    n++;
                    res.push_back(matrix[m][n]);
                    
                }
                b--;
                way = 2;
            } else if (way == 2) {
                for (int i = 0; i < a; i++) {
                    m++;
                    res.push_back(matrix[m][n]);
                    
                }
                a--;
                way = 3;
            } else if (way == 3) {
                for (int i = 0; i < b; i++) {
                    n--;
                    res.push_back(matrix[m][n]);
                    
                }
                b--;
                way = 4;
            } else if (way == 4) {
                
                for (int i = 0; i < a; i++) {
                    m--;
                    res.push_back(matrix[m][n]);
                    
                }
                a--;
                way = 1;
            }
        }
        return res;
    }
};