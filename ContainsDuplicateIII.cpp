class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0 || nums.size() < 2 || t < 0) return false;

        set<int> numsSet;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) numsSet.erase(nums[i - k - 1]);
            if (numsSet.find(nums[i]) != numsSet.end()) return true;
            else numsSet.insert(nums[i]);
            
            auto it = numsSet.find(nums[i]);
            if (it != numsSet.begin()) {
                it--;
                if ((*it + t) >= nums[i]) return true;
                else it++;
            }
            it++;
            if (it != numsSet.end()) {
                if ((*it - t) <= nums[i]) return true;
            }
        }
        return false;
    }
};