class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int res[m + 1][n + 1];
        for (int i = 0; i <= n; i++) res[0][i] = 0;
        for (int i = 0; i <= m; i++) res[i][0] = 0;
        res[1][0] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i - 1][j - 1] == 0) res[i][j] = res[i - 1][j] + res[i][j - 1];
                else res[i][j] = 0;
            }
        }
        return res[m][n];
    }
};


//no extra space
//
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                if (i == 0) {
                    if (j == 0) 
                        obstacleGrid[0][0] = 1 - obstacleGrid[0][0];
                    else
                        obstacleGrid[0][j] = obstacleGrid[0][j] ? 0 : obstacleGrid[0][j - 1];
                }
                else {
                    if (j == 0)
                        obstacleGrid[i][0] = obstacleGrid[i][0] ? 0 : obstacleGrid[i - 1][0];
                    else 
                        obstacleGrid[i][j] = obstacleGrid[i][j] ? 0 : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
            }
        }
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};