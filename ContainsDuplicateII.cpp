class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;

       if (k <= 0) return false;

       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }

       return false;
    }
};


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numsSet;
        for (int i = 0; i < nums.size(); i++) {
            if (numsSet.find(nums[i]) == numsSet.end()) numsSet.insert({nums[i], i});
            else if (numsSet.find(nums[i])->second >= (i - k)) return true;
            else numsSet.find(nums[i])->second = i;
        }
        return false;
    }
};