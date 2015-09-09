class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_map<int, int> index;
        int res = 1;
        for (int i : nums) {
            if (index.find(i) == index.end()) {
                if (index.find(i + 1) == index.end() && index.find(i - 1) == index.end()) {
                    index.insert({i, 1});
                    // res = max(res, 1);
                }
                else if (index.find(i + 1) == index.end() && index.find(i - 1) != index.end()) {
                    int m = index.find(i - 1)->second;
                    index.insert({i, m + 1});
                    (index.find(i - m)->second)++;
                    res = max(res, m + 1);
                } else if (index.find(i + 1) != index.end() && index.find(i - 1) == index.end()) {
                    int m = index.find(i + 1)->second;
                    index.insert({i, m + 1});
                    (index.find(i + m)->second)++;
                    res = max(res, m + 1);
                } else {
                    int m = index.find(i + 1)->second;
                    int n = index.find(i - 1)->second;
                    index.find(i + m)->second = m + n + 1;
                    index.find(i - n)->second = m + n + 1;
                    index.insert({i, 1});
                    res = max(res, n + m + 1);
                } 
            }
        }
        return res;
    }
};