class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int begin = 0;
        int end = nums.size() - 1;
        int m = nums[end];
        
        while (begin < end) {
            int mid = (end + begin) / 2;
            if (nums[end] == nums[mid] && nums[end] == m) end--;
            else if (nums[end] < nums[mid]) begin = mid + 1;
            else end = mid;
        }
        return nums[begin];
    }
};