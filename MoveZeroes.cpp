class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[i] != 0) i++;
            else if (nums[j] == 0 || j <= i) j++;
            else swap(nums[i++], nums[j++]);
        }
    }
};