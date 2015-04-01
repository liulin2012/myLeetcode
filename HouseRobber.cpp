//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

//VolumesGiven a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
//



class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) return NULL;
        if (num.size() == 1) return num[0];
        if (num.size() == 2) {
            return num[0] > num[1] ? num[0] : num[1];
        }
        num[1] = num[0] > num[1] ? num[0] : num[1];
        for (int i = 2; i< num.size(); i++) {
            num[i] = max(num[i] + num[i - 2], num[i - 1]);
        }
        return num[num.size() - 1];
    }
};