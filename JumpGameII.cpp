class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        if (nums[0] >= nums.size() - 1) return 1;
        int po = nums[0];
        int step = 1;
        int maxpo = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxpo = max(maxpo, i + nums[i]);
            if (maxpo >= nums.size() - 1) return step + 1;
            else if (i == po) {
                step++;
                po = maxpo;
            }
        }
        return nums[nums.size() - 1];
    }
};