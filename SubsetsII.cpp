class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> one;
        DFS(nums, 0, one, res);
        return res;
    }
    
    void DFS(vector<int>& nums, int begin, vector<int>& one, vector<vector<int>>& res) {
        res.push_back(one);
        for (int i = begin; i < nums.size(); i++) {
            if (i == begin || nums[i] != nums[i - 1]) {
                one.push_back(nums[i]);
                DFS(nums, i + 1, one, res);
                one.pop_back();
            }
        }
    }
};