class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        
        while (begin < end) {
            if (nums[begin] == nums[end]) begin++;
            else {
                int mid = (end + begin) / 2;
                if (nums[end] < nums[mid]) begin = mid + 1;
                else end = mid;
            }
        }
        
        int a = begin;
        int b = begin == 0 ? nums.size() - 1 : begin - 1;
        int mid;
        while (nums[a] != target) {
            if (a > b)
                mid = ((a+b+nums.size()) / 2) % nums.size();
            else mid = (a + b) /2;
            if (nums[mid] < target) a = (mid + 1) % nums.size();
            else b = mid;
            if (a == b && nums[a] != target) return false;
        }
        
        
        return true;
    }
};