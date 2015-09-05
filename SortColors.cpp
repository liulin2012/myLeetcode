class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin < end) {
            if (nums[begin] == 0) begin++;
            else if (nums[end] != 0) end--;
            else swap(nums[begin], nums[end]);
        }
        end = nums.size() - 1;
        while (begin < end) {
            if (nums[begin] == 1) begin++;
            else if (nums[end] != 1) end--;
            else swap(nums[begin], nums[end]);
        }
    }
};