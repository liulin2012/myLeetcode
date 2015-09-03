class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int i = nums.size() - 2;
        int step = 0;
        while (i >= 0) {
            if (step) {
                if (nums[i] <= step) step++;
                else step = 0;
            } else {
                if (nums[i] == 0) step = 1;
            }
            i--;
        }
        return !step;
    }
};