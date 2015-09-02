class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0]) return false;
        int l = 0;
        int r = matrix.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            // if (matrix[mid][0] == target || matrix[r][0] == target) return true;
            if (matrix[mid][0] <= target) l = mid;
            else r = mid - 1;
        }
        
        int x = l;
        l = 0;
        r = matrix[0].size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (matrix[x][mid] < target) l = mid + 1;
            else r = mid;
        }
        
        return matrix[x][l] == target ? true : false;
    }
};


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if(matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m*n - 1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int e = matrix[mid/n][mid%n];
        if(target < e)
        {
            end = mid - 1;
        }
        else if(target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}