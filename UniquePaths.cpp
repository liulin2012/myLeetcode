/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 */


class Solution {
public:
    int uniquePaths(int m, int n) {
        int A[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0) A[i][j] = 1;
                else A[i][j] = A[i - 1][j] + A[i][j - 1];
            }
            
        return A[m - 1][n - 1];
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n , m);
        
        vector<int> cur(m, 1);
        for (int i = 1; i < n; i++) 
            for (int j = 1; j < m; j++)
                cur[j] += cur[j - 1];
        
        return cur[m - 1];
    }
};