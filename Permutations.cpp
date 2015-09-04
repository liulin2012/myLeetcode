class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size() ; i++) {
            vector<int> one(nums.size(), INT32_MAX);
            one[i] = nums[0];
            bt(nums, 1, one);
        }
        return res;
    }
    
    void bt(vector<int>& nums, int index, vector<int> one) {
        if (index == nums.size()) res.push_back(one);
        else {
            for (int i = 0; i < one.size(); i++) {
                if (one[i] == INT32_MAX) {
                    one[i] = nums[index];
                    bt(nums, index + 1, one);
                    one[i] = INT32_MAX;
                }
            }
        }
    }
};


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;

        permuteRecursive(num, 0, result);
        return result;
    }

    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
};