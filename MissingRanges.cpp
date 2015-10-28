class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (lower == upper && !nums.empty()) return {};
        else if (lower == upper) return {to_string(lower)};
        
        vector<string> res;
        nums.push_back(upper+1);
        int begin = lower;
        for (int i = 0; i < nums.size(); i++) {
            if (begin == nums[i]) begin++;
            else {
                if (begin+1 == nums[i]) { res.push_back(to_string(begin)); begin += 2;}
                else {
                    string tmp = to_string(begin);
                    tmp += "->";
                    tmp += to_string(nums[i]-1);
                    res.push_back(tmp);
                    begin = nums[i] + 1;
                }
            }
        }
        nums.pop_back();
        return res;
    }
};