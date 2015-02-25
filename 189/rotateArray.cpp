class Solution {
public:
    void rotate(int nums[], int n, int k) {
         int i=k%n;
	 std::reverse(nums,nums+n-i);
	 std::reverse(nums+n-i,nums+n);
	 std::reverse(nums,nums+n);
	}
};
