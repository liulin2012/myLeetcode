class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i]+nums[i+1]+nums[i+2] >= target) break;
            int begin = i+1;
            int end = nums.size() - 1;
            while (begin < end) {
                while (begin < end && nums[i] + nums[begin] + nums[end] >= target) end--;
                res += end - begin;
                begin++;
            }
        }
        return res;
    }
};