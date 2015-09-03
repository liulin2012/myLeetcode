class Solution {
public:
    vector<string> phone = {{}, {}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        else {
            int a = digits[0] - '0';
            string tmp = phone[a];
            for (auto i : tmp) 
                lcom(digits, 1, string(1, i));
        }
        return res;
    }
    
    void lcom(string digits, int index, string oneRes) {
        if (index == digits.size()) res.push_back(oneRes) ;
        else {
            int a = digits[index] - '0';
            string tmp = phone[a];
            for (auto i : tmp) 
                lcom(digits, index + 1, oneRes + i);
        }
    }
};