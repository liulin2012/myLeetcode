class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[nums.size() - 1] < target) return nums.size();
        int begin = 0;
        int end = nums.size() - 1;
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (nums[mid] < target) begin = mid + 1;
            else end = mid;
        }
        
        return begin;
    }
};