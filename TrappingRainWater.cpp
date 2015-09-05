class Solution {
public:
    int trap(vector<int>& height) {
        int begin = 0;
        int end = height.size() - 1;
        int sum = 0;
        int base = 0;
        while (begin < end) {
            if (height[begin] < height[end]) {
                if (height[begin] > base) base = height[begin];
                else sum += base - height[begin];
                begin++;
            } else {
                if (height[end] > base) base = height[end];
                else sum += base - height[end];
                end--;
            }
        }
        return sum;
    }
};