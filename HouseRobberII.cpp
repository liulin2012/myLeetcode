class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int first = 0;
        int second = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            int temp = second;
            second = max(second, first+nums[i]);
            first = temp;
        }
        int res = second;
        first = 0;
        second = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            int temp = second;
            second = max(second, first+nums[i]);
            first = temp;
        }
        res = max(res, second);
        return res;
    }
};