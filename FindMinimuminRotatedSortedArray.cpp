class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums[0] < nums[nums.size() - 1]) return nums[0];
        int begin = 0;
        int end = nums.size() - 1;
        int mid = (end - begin) / 2;
        while (nums[mid] > nums[mid - 1]) {
            if (begin + 1 == end) {
                if (nums[begin] < nums[begin - 1]) return nums[begin];
                else return nums[end];
            }
            if (nums[mid] > nums[begin]) {
                begin = mid;
                mid = begin + (end - begin) / 2;
            } else {
                end = mid;
                mid = begin + (end - begin) / 2;
            }
        }
        
        return nums[mid];
    }
};