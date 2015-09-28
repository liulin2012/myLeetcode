class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        if (nums.empty()) return res;
        int cur = k;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.front()] <= nums[i]) dq.pop_front();
            dq.push_front(i);
        }
        res.push_back(nums[dq.back()]);
        
        while (cur < nums.size()) {
            if (dq.back() == cur - k) dq.pop_back();
            while (!dq.empty() && nums[dq.front()] <= nums[cur]) dq.pop_front();
            dq.push_front(cur);
            res.push_back(nums[dq.back()]);
            cur++;
        }
        return res;
    }
};