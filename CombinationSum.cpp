class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        CSum(candidates, target, {}, 0);
        return res;
    }
    void CSum(vector<int>& candidates, int target, vector<int> vec, int index) {
        if (candidates[index] == target) {
            vec.push_back(candidates[index]);
            res.push_back(vec);
            return;
        } else if (candidates[index] < target) {
            if (index != candidates.size() - 1) CSum(candidates, target, vec, index + 1);
            vec.push_back(candidates[index]);
            CSum(candidates, target - candidates[index], vec, index);
        }
    }
};