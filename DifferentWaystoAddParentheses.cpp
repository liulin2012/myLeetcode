class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int index = 0;
        while (index < input.size()) {
            if (input[index] == '+' || input[index] == '-' || input[index] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, index));
                vector<int> right = diffWaysToCompute(input.substr(index + 1));
                for (int m : left)
                    for (int n : right) {
                        if (input[index] == '+') res.push_back(m+n);
                        else if (input[index] == '-') res.push_back(m-n);
                        else if (input[index] == '*') res.push_back(m*n);
                    }
            }
            index++;
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};