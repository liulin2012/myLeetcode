class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        int start, end;
        for (int i = 0; i < nums.size() - 2; i++) {
            start = i + 1;
            end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum > 0) end--;
                else if (sum < 0) start++;
                else {
                    result.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while (start != nums.size() - 1 && nums[start] == nums[start - 1]) start++;
					while (end > start && nums[end] == nums[end + 1]) end--;
                }
            }
            while(i != nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};