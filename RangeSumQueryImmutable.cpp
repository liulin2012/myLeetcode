class NumArray {
public:
    vector<int> sum_num;
    NumArray(vector<int> &nums) {
        sum_num = nums;
        for (int i = 1; i < nums.size(); i++) {
            sum_num[i] += sum_num[i-1];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return sum_num[j];
        else return sum_num[j] - sum_num[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);