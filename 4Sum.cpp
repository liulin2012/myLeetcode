class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        int start, end;
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int target2 = target - nums[i] - nums[j];
                start = j + 1;
                end = nums.size() - 1;
                while (start < end) {
                    if (nums[start] + nums[end] > target2) end--;
                    else if (nums[start] + nums[end] < target2) start++;
                    else {
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                        while (start != nums.size() - 1 && nums[start] == nums[start - 1]) start++;
    					while (end > start && nums[end] == nums[end + 1]) end--;
                    }
                }
                while(j != nums.size() - 1 && nums[j] == nums[j + 1]) j++;
            }
            while(i != nums.size() - 2 && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};