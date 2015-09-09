class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        int res = 0;
        height.push_back(0);
        stack<vector<int>> col;
        for (int i = 0; i < height.size(); i++) {
            if (col.empty() && height[i] != 0) col.push({height[i], i});
            else if (col.empty()) ;
            else if (col.top()[0] < height[i]) col.push({height[i], i});
            else if (col.top()[0] > height[i]) {
                int tmp;
                while (!col.empty() && col.top()[0] > height[i]) {
                    res = std::max(res, col.top()[0] * (i - col.top()[1]));
                    tmp = col.top()[1];
                    col.pop();
                }
                if (height[i] == 0) ;
                else if (col.empty()) col.push({height[i], tmp});
                else if (col.top()[0] != height[i]) col.push({height[i], tmp});
            }
        }
        return res;
    }
};