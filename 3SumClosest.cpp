class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int a = i + 1;
            int b = nums.size() - 1;
            int tmp = target - nums[i];
            while (a != b) {
                if (nums[a] + nums[b] < tmp) {
                    res = abs(res - target) < (tmp - nums[a] - nums[b]) ? res : nums[a] + nums[b] + nums[i];
                    a++;
                } else if (nums[a] + nums[b] > tmp) {
                    res = abs(res - target) < (nums[a] + nums[b] - tmp) ? res : nums[a] + nums[b] + nums[i];
                    b--;
                } else return target;
            }
        }
        return res;
    }
};