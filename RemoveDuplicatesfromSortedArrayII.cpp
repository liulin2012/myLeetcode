class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int p = 0;
        bool dup = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[p] == nums[i] && dup == false) {
                p++;
                nums[p] = nums[i];
                dup = true;
            } else if (nums[p] != nums[i]) {
                p++;
                nums[p] = nums[i];
                dup = false;
            }
        }
        return p + 1;
    }
};

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}