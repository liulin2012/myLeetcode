class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums[nums.size() - 1] < target) return {-1, -1};
        int begin = 0;
        int end = nums.size() - 1;
        int mid = (begin + end) / 2;
        while (begin < end && nums[mid] != target) {
            if (nums[mid] < target) begin = mid + 1;
            else end = mid;
            mid = (begin + end) / 2;
        }
        
        if (nums[mid] != target) return {-1, -1};
        if (begin == end) return {begin, begin};
        else {
            
            int left = 0, right = 0;
            left = begin;
            int tmp = mid;
            int a = (left + tmp) / 2;
            while (left < tmp) {
                if (nums[a] != target) left = a + 1;
                else tmp = a;
                a = (left + tmp) / 2;
            }
            
            right = end;
            tmp = mid;
            a = (tmp + right) / 2;
            while (tmp < right) {
                if (nums[a] == target) tmp = a + 1;
                else right = a;
                a = (right + tmp) / 2;
            }
            if (nums[right] == target) return {left, right};
            else return {left, right - 1};
            // return nums[right] == target ? {left, right} : {left, right - 1};
        }
    }
};