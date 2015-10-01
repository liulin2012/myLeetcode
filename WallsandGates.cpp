class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0)
                q.push({i, j});
            }
        }
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            int x = rooms[row][col] + 1;
            q.pop();
            
            if (row > 0 && rooms[row - 1][col] == INT32_MAX)
                {rooms[row - 1][col] = x; q.push({row - 1, col});}
            if (col > 0 && rooms[row][col - 1] == INT32_MAX)
                {rooms[row][col - 1] = x; q.push({row, col - 1});}
            if ((row + 1) < rooms.size() && rooms[row + 1][col] == INT32_MAX)
                {rooms[row + 1][col] = x; q.push({row + 1, col});}
            if ((col+1) < rooms[0].size() && rooms[row][col + 1] == INT32_MAX)
                {rooms[row][col + 1] = x; q.push({row, col + 1});}
        }
    }
};