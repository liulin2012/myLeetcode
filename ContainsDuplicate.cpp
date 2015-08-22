class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> numsSet;
        for (int i : nums) {
            if (numsSet.find(i) == numsSet.end()) numsSet.insert(i);
            else return true;
        }
        return false;
    }
};