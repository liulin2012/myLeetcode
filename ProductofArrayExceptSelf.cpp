class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int product = 1;
        for (auto i : nums) {
            product *= i;
            res.push_back(product);
        }
        product = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            res[i] = res[i - 1] * product;
            product *= nums[i];
        }
        res[0] = product;
        return res;
    }
};