class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int pivot;
        int left = 1;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            int num = mid - left + 1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid && nums[i] >= left) num--;
            }
            if (num >= 0) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

//http://keithschwarz.com/interesting/code/?dir=find-duplicate
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=nums.size();
        int slow =l-1;int fast = l-1;
        while(1){
            slow=nums[slow]-1;
            fast=nums[nums[fast]-1]-1;
            if(slow == fast){
                break;
            }
        }
        fast = l-1;
        while(1){
            slow=nums[slow]-1;
            fast=nums[fast]-1;
            if(slow==fast)return slow+1;
        }
    }
};