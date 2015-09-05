class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        int begin = 0;
        while (begin != nums.size()) {
            if (nums[begin] <= 0 || nums[begin] > nums.size()) {nums[begin] = 0; begin++;}
            else if (nums[begin] == begin + 1) begin++;
            else {
                 if (nums[begin] != nums[nums[begin] - 1]) swap(nums[begin], nums[nums[begin] - 1]);
                 else {nums[begin] = 0; begin++;}
            } 
        }
        
        begin = 0;
        while (begin != nums.size() && nums[begin] != 0) begin++;
        if (begin == nums.size()) return nums.size() + 1;
        else return begin + 1;
    }
};