class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (auto i : nums)
            arr.push_back(to_string(i));
        sort(arr.begin(), arr.end(), [](string &a1, string &a2) {return a1 + a2 > a2 + a1;});
        string res;
        for (auto i : arr)
            res += i;
        while (res[0] == '0' && res.length() > 1)
            res.erase(0, 1);
        return res;
        
    }
};