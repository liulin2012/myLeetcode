class NumMatrix {
public:
    vector<vector<int>> sum_matrix;
    NumMatrix(vector<vector<int>> &matrix) {
        sum_matrix = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                sum_matrix[i][j] += sum_matrix[i][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            if (col1 == 0) sum += sum_matrix[i][col2];
            else sum += sum_matrix[i][col2] - sum_matrix[i][col1-1];
        }
        return sum;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);