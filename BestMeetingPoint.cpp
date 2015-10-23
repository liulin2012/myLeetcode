class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        vector<int> row;
        vector<int> col;
        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) 
                if (grid[i][j] == 1) {
                    row.push_back(i);
                    col.push_back(j);
                }
        
        sort(row.begin(), row.end());
        sort(col.begin(), col.end());
        int res = 0;
        int begin = 0;
        int end = row.size() - 1;
        while (begin < end) {
            res += row[end--] - row[begin++];
        }
        begin = 0;
        end = col.size() - 1;
        while (begin < end) {
            res += col[end--] - col[begin++];
        }
        return res;
            
    }
};