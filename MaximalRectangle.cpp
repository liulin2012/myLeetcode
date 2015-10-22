class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<int> height(matrix[0].size() + 1, 0);
        int res = 0;
        for(int i = 0; i < matrix.size(); i++) {
            stack<int> col;
            for(int j = 0; j < matrix[0].size() + 1; j++) {
                if (j < matrix[0].size()){
                    if (matrix[i][j] == '1') height[j]++;
                    else height[j] = 0;
                }
                while(!col.empty() && height[col.top()] > height[j]) {
                    int h = height[col.top()];
                    col.pop();
                    int length = col.empty() ? -1 : col.top();
                    res = max(res, h*(j-length-1));
                }
            col.push(j);
            }
        }
        return res;
    }
};