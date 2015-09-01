class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int begin = 0, end = 0;
        int min = INT32_MAX;
        int length;
        int num = 0;
        while (end != nums.size() || num >= s){
            if (num < s) {
                num += nums[end];
                end++;
            } else {
                length = end - begin;
                min = std::min(length, min);
                num -= nums[begin];
                begin++;
            }
        }
        return min == INT32_MAX ? 0 : min;
    }
};