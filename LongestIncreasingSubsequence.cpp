class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        vector<int> DP(nums.size(), 1);
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    DP[i] = max(DP[i], DP[j]+1);
                }
            }
            res = max(res, DP[i]);
        }
        return res;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = lower_bound(res.begin(), res.end(), nums[i]);
            if (iter == res.end()) res.push_back(nums[i]);
            else *iter = nums[i];
        }
        return res.size();
    }
};