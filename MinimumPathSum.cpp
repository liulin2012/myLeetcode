class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0) return 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0) {
                    if (j == 0) 
                        grid[0][0] = grid[0][0];
                    else
                        grid[0][j] += grid[0][j - 1];
                }
                else {
                    if (j == 0)
                        grid[i][0] += grid[i - 1][0];
                    else 
                        grid[i][j] += grid[i - 1][j] > grid[i][j - 1] ? grid[i][j - 1] : grid[i - 1][j];
                }
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};