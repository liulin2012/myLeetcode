class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0 ; j < grid[0].size(); j++) {
                if (grid[i][j] == '1')
                    {grid[i][j] = '0'; BFS(grid, i, j); result++;}
            }
        }
        return result;
    }
    
    void BFS(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            if (row > 0 && grid[row - 1][col] == '1')
                {grid[row - 1][col] = '0'; q.push({row - 1, col});}
            if (col > 0 && grid[row][col - 1] == '1')
                {grid[row][col - 1] = '0'; q.push({row, col - 1});}
            if ((row + 1) < grid.size() && grid[row + 1][col] == '1')
                {grid[row + 1][col] = '0'; q.push({row + 1, col});}
            if ((col + 1) < grid[0].size() && grid[row][col + 1] == '1')
                {grid[row][col + 1] = '0'; q.push({row, col + 1});}
        }
    }
};