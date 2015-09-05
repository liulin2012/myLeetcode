class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int begin = 0;
        int end = height.size() - 1;
        while (begin < end) {
            int a = (end - begin) * min(height[begin], height[end]);
            res = max(a, res);
            if (height[begin] > height[end]) {
                int x = end;
                while (height[x] >= height[end] && begin < end) end--;
            } else {
                int x = begin;
                while (height[begin] <= height[x] && begin < end) begin++;
            }
        }
        return res;
    }
};