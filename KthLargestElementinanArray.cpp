class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, k, 0 ,nums.size() - 1);
    }
    
    int helper(vector<int>& nums, int k, int begin, int end) {
        if (begin == end && k == 1) return nums[begin];
        else {
            int a = begin;
            int b = end;
            int pivot = nums[begin];
            while (a < b) {
                if (nums[b] > pivot) b--;
                else if (nums[a] <= pivot) a++;
                else swap(nums[a], nums[b]);
            }
            swap(nums[begin], nums[b]);
            int right = end - b;
            if (k <= right) return helper(nums, k, b + 1, end);
            else if (k == right + 1) return nums[b];
            else return helper(nums, k - right - 1, begin, b - 1);
        }
    }
};