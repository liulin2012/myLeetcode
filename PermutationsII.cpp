class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        
        permuteRecursive(nums, 0, result);
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
        unordered_set<int> st;
        for (int i = begin; i < num.size(); i++) {
            if (st.count(num[i]) == 1) { continue; }
            st.insert(num[i]);
                swap(num[begin], num[i]);
                permuteRecursive(num, begin + 1, result);
                // reset
                swap(num[begin], num[i]);
            
        }
    }
};