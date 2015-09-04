class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        while (n != 0 && nums[n] <= nums[n - 1]) n--;
        if (n != 0) { 
            int val = nums[n - 1];
            int m = nums.size() - 1;
            while (nums[m] <= val) m--;
            swap(nums[n - 1], nums[m]);
        }
        reverse(nums.begin() + n, nums.end());
    }
};