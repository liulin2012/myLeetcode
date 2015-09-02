class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if (index != candidates.size() - 1) {
                int index2 = index;
                while (index2 != candidates.size() - 1 && candidates[index2] == candidates[index2 + 1]) index2++;
                if (index2 != candidates.size() - 1) CSum(candidates, target, vec, index2 + 1);
                
                vec.push_back(candidates[index]);
                CSum(candidates, target - candidates[index], vec, index + 1);
            }
        }
    }
};